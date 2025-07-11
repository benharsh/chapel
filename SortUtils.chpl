module SortUtils {
  use Sort;
  use BlockDist;
  use BitOps;
  use CopyAggregation;

  /* Pulled from Arkouda. Used as the comparator for arrays made of tuples. */
  record contrivedComparator: keyPartComparator {
    const dc = new defaultComparator();
    proc keyPart(a, i: int) {
      if canResolveMethod(dc, "keyPart", a, 0) {
        return dc.keyPart(a, i);
      } else if isTuple(a) {
        return tupleKeyPart(a, i);
      } else {
        compilerError("No keyPart method for eltType ", a.type:string);
      }
    }
    proc tupleKeyPart(x: _tuple, i:int) {
      proc makePart(y): uint(64) {
        var part: uint(64);
        // get the part, ignore the section
        const p = dc.keyPart(y, 0)(1);
        // assuming result of keyPart is int or uint <= 64 bits
        part = p:uint(64); 
        // If the number is signed, invert the top bit, so that
        // the negative numbers sort below the positive numbers
        if isInt(p) {
          const one:uint(64) = 1;
          part = part ^ (one << 63);
        }
        return part;
      }
      var part: uint(64);
      if isTuple(x[0]) && (x.size == 2) {
        for param j in 0..<x[0].size {
          if i == j {
            part = makePart(x[0][j]);
          }
        }
        if i == x[0].size {
          part = makePart(x[1]);
        }
        if i > x[0].size {
          return (keyPartStatus.pre, 0:uint(64));
        } else {
          return (keyPartStatus.returned, part);
        }
      } else {
        for param j in 0..<x.size {
          if i == j {
            part = makePart(x[j]);
          }
        }
        if i >= x.size {
          return (keyPartStatus.pre, 0:uint(64));
        } else {
          return (keyPartStatus.returned, part);
        }
      }
    }
  }
  const myDefaultComparator = new contrivedComparator();

  // Pulled from Arkouda, used within radix sort for merging arrays
  config param RSLSD_bitsPerDigit = 16;
  private param bitsPerDigit = RSLSD_bitsPerDigit;

  // Pulled from Arkouda, these need to be const for comms/performance reasons
  private param numBuckets = 1 << bitsPerDigit;
  private param maskDigit = numBuckets-1;

  /* Pulled from Arkouda, gets the maximum bit width of the array and if there 
    are any negative numbers. */
  inline proc getBitWidth(a: [?aD] int): (int, bool) {
    var aMin = min reduce a;
    var aMax = max reduce a;
    var wPos = if aMax >= 0 then numBits(int) - clz(aMax) else 0;
    var wNeg = if aMin < 0 then numBits(int) - clz((-aMin)-1) else 0;
    const signBit = if aMin < 0 then 1 else 0;
    const bitWidth = max(wPos, wNeg) + signBit;
    const negs = aMin < 0;

    return (bitWidth, negs);
  }

  /* Pulled from Arkouda, for two arrays returns array with bit width and 
    negative information. */
  proc getNumDigitsNumericArrays(arr1, arr2) {
    var bitWidths: [0..<2] int;
    var negs: [0..<2] bool;
    var totalDigits: int;

    (bitWidths[0], negs[0]) = getBitWidth(arr1);
    totalDigits += (bitWidths[0] + (bitsPerDigit-1)) / bitsPerDigit;

    (bitWidths[1], negs[1]) = getBitWidth(arr2);
    totalDigits += (bitWidths[1] + (bitsPerDigit-1)) / bitsPerDigit;

    return (totalDigits, bitWidths, negs);
  }

  /* Pulled from Arkouda, get the digits for the current rshift. Signbit needs 
    to be inverted for negative values */
  inline proc getDigit(key: int, rshift: int, last: bool, negs: bool): int {
    const invertSignBit = last && negs;
    const xor = (invertSignBit:uint << (RSLSD_bitsPerDigit-1));
    const keyu = key:uint;

    return (((keyu >> rshift) & (maskDigit:uint)) ^ xor):int;
  }

  /* Pulled from Arkouda to merge and sort two arrays. */
  proc coargsort(in row, in col) {
    var (totalDigits,bitWidths,negs) = getNumDigitsNumericArrays(row, col);
    var m = row.size;

    /* Pulled from Arkouda to merge two arrays into one for radix sort. */
    proc mergeNumericArrays(param numDigits,size,totalDigits,bitWidths,negs) {
      var merged = blockDist.createArray(
        {0..<size}, 
        numDigits*uint(bitsPerDigit)
      );
      var curDigit = numDigits - totalDigits;

      var nBits = bitWidths[0];
      var neg = negs[0];
      const r = 0..#nBits by bitsPerDigit;
      for rshift in r {
        const myDigit = (nBits-1 - rshift) / bitsPerDigit;
        const last = myDigit == 0;
        forall (m, a) in zip(merged, row) {
          m[curDigit+myDigit]=getDigit(a,rshift,last,neg):uint(bitsPerDigit);
        }
      }
      curDigit += r.size;
      nBits = bitWidths[1];
      neg = negs[1];
      for rshift in r {
        const myDigit = (nBits-1 - rshift) / bitsPerDigit;
        const last = myDigit == 0;
        forall (m, a) in zip(merged, col) {
          m[curDigit+myDigit]=getDigit(a,rshift,last,neg):uint(bitsPerDigit);
        }
      }
      curDigit += r.size;

      return merged;
    }

    /* Pulled from Arkouda, runs merge and then sort */
    proc mergedArgsort(param numDigits) {
      var merged = mergeNumericArrays(
        numDigits, 
        m, 
        totalDigits, 
        bitWidths, 
        negs
      );

      var AI = blockDist.createArray(merged.domain, (merged.eltType,int));
      var iv = blockDist.createArray(merged.domain, int);

      AI = [(a, i) in zip(merged, merged.domain)] (a, i);
      Sort.TwoArrayDistributedRadixSort.twoArrayDistributedRadixSort(
        AI, comparator=myDefaultComparator
      );
      iv = [(_, i) in AI] i;

      return iv;
    }

    var iv = blockDist.createArray({0..<m}, int);
    if totalDigits <=  4 { iv = mergedArgsort( 4); }
    else if totalDigits <=  8 { iv = mergedArgsort( 8); }
    else if totalDigits <= 16 { iv = mergedArgsort(16); }

    return iv;
  }

  /* Pulled from Arkouda. Given an array, `sorted`, generates the unique values
    of the array and the counts of each value, if `needCounts` is set to 
    `true`. */
  proc uniqueFromSorted(sorted: [?aD] ?t, param needCounts = true) {
    var truth = blockDist.createArray(aD, bool);
    truth[0] = true;
    [(t,s,i) in zip(truth,sorted,aD)] if i > aD.low { t = (sorted[i-1] != s); }
    var allUnique: int = + reduce truth;

    if allUnique == aD.size {
      var u = blockDist.createArray(aD, t);
      u = sorted;
      if needCounts {
        var c = blockDist.createArray(aD, int);
        c = 1;
        return (u, c);
      } else {
        return u;
      }
    }

    var iv: [truth.domain] int = (+ scan truth);
    var pop = iv[iv.size - 1];

    var segs = blockDist.createArray({0..<pop}, int);
    var ukeys = blockDist.createArray({0..<pop}, t);

    forall i in truth.domain with (var agg = new DstAggregator(int)){
      if truth[i] == true {
        var idx = i; 
        agg.copy(segs[iv[i]-1], idx);
      }
    }

    forall (_,uk,seg) in zip(segs.domain, ukeys, segs) 
      with (var agg = new SrcAggregator(t)) do agg.copy(uk, sorted[seg]);

    if needCounts {
      var counts = blockDist.createArray({0..<pop}, int);
      forall i in segs.domain {
        if i < segs.domain.high then counts[i] = segs[i+1] - segs[i];
        else counts[i] = sorted.domain.high+1 - segs[i];
      }
      return (ukeys, counts);
    } else {
      return ukeys;
    }
  }
}