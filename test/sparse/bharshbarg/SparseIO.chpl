
use IO;
use LayoutCS;

//
// File format:
//
// rowStart,numRows
// colStart,numCols
// numElements
//
// 'numElements' lines of the format:
// rowIdx,colIdx,value
//

//
// Returning just the array from a read* function would not allow users
// to modify the domain. This simple wrapper stores the domain so it can
// be modified later.
record SparseData {
  type eltType;
  type idxType;
  var parentDom : domain(2, idxType=idxType);
  var spsDom    : sparse subdomain(parentDom) dmapped CS();
  var arr       : [spsDom] eltType;

  proc getDomain() ref {
    return spsDom;
  }

  proc getArray() ref {
    return arr;
  }
}

proc readCSV(fname : string, type eltType=real, type idxType=int, delim=",") {
  var fi  = open(fname, iomode.r);
  var rdr = fi.reader(locking=false);
  
  var rowStart, numRows, colStart, numCols : idxType;
  var numElts : int;

  const dimFormat = "%i" + delim + "%i\n";
  const idxValFormat = delim.join("%i", "%i", "%r") + "\n";

  rdr.readf(dimFormat, rowStart, numRows);
  rdr.readf(dimFormat, colStart, numCols);
  rdr.readf("%i\n", numElts);
  rdr.readln();

  const parent = {rowStart..#numRows, colStart..#numCols};
  var ret = new SparseData(eltType, idxType, parentDom=parent);
  ref sparseDom = ret.getDomain();
  ref sparseArr = ret.getArray();

  const chunk = numElts / 10;

  var inds : [1..chunk] (idxType, idxType);
  var vals : [1..chunk] eltType;

  for start in 1..numElts by chunk {
    const end = min(start + chunk - 1, numElts);
    const len = end - start + 1;

    for i in 1..len {
      var rt, ct : idxType;
      rdr.readf(idxValFormat, rt, ct, vals[i]);
      inds[i] = (rt, ct);
    }
    sparseDom.bulkAdd(inds, dataSorted=true, isUnique=true);
    forall (i, v) in zip(inds[1..len], vals[1..len]) {
      sparseArr[i] = v;
    }
  }

  fi.close();
  rdr.close();

  return ret;
}

proc writeCSV(fname : string, A : [], delim=",") {
  var fi  = open(fname, iomode.cw);
  var wrt = fi.writer(locking=false);

  const dims = A.domain.dims();

  wrt.writeln(dims(1).first, delim, dims(1).size);
  wrt.writeln(dims(2).first, delim, dims(2).size);
  wrt.writeln(A.size);
  wrt.writeln();

  for ((i, j), v) in zip(A.domain, A) {
    wrt.writeln(i, delim, j, delim, v);
  }

  wrt.close();
  fi.close();
}

private proc arrayIO(fname:string, ref myArr, ref offset, doRead = true) {
  const ioHints = QIO_METHOD_PREADPWRITE | QIO_CH_ALWAYS_UNBUFFERED;

  // Returns stripe count and stripe size
  // TODO: reading by aligned stripe sizes didn't seem to help, why?
  proc getLustreInfo(fname) {
    use Spawn;
    if CHPL_COMM == 'ugni' then return (0, 0);

    proc helper(arg:string) {
      var err : syserr;
      var ret : int;
      var sub = spawn(["lfs", "getstripe", arg, fname], stdout=PIPE);
      sub.wait(err);
      if err == ENOERR && sub.exit_status == 0 {
        ret = sub.stdout.read(int);
      }
      return ret;
    }

    const count = helper("--stripe-count");
    const size  = helper("--stripe-size");

    return (count, size);
  }

  const (lustreCount, lustreSize) = getLustreInfo(fname);
  const numTasks = if lustreCount != 0 then lustreCount
                   else if dataParTasksPerLocale == 0 then here.maxTaskPar
                   else dataParTasksPerLocale;

  const startOffset = offset;
  const chunk = myArr.size / numTasks;
  const bytes = numBytes(myArr.eltType);
  const first = myArr.domain.first;
  const last  = myArr.domain.last;

  coforall tid in 0..#numTasks {
    const i = first + (tid * chunk);
    const hi = if tid == numTasks-1 then last else i+chunk-1;
    const len = hi - i + 1;
    const start = startOffset + (i-first) * bytes;
    const end = start + len * bytes;

    if doRead {
      var locFi = open(fname, iomode.r, hints=ioHints);
      var locR = locFi.reader(locking=false, kind=iokind.native, start=start, end=end, hints=ioHints);
      locR.read(myArr[i..hi]);
    } else {
      var locFi = open(fname, iomode.rw, hints=ioHints);
      var locW = locFi.writer(locking=false, kind=iokind.native, start=start, end=end, hints=ioHints);
      locW.write(myArr[i..hi]);
    }
  }

  offset += myArr.size * bytes;
}

proc writeBinary(fname:string, A : []) {
  var value    = A._value;
  var dom      = value.dom;
  ref data     = value.data;
  param rank   = value.rank;
  type idxType = dom.idxType;

  use IO, LayoutCS;
  var fi = open(fname, iomode.cw);
  var w = fi.writer(locking=false, kind=iokind.native);

  const dims = dom.parentDom.dims();
  w.write(rank);
  w.write(dom.compressRows:int);

  for i in 1..rank {
    w.write(dims(i).low);
    w.write(dims(i).high);
  }
  w.write(dom.nnz:idxType);
  w.write(dom.nnzDom.size:idxType);
  w.write(dom.startIdx.size:idxType);

  const nnz  = dom.nnz;
  var offset = w.offset();
  arrayIO(fname, dom.startIdx, offset, doRead=false);
  arrayIO(fname, dom.idx[..nnz], offset, doRead=false);
  arrayIO(fname, data[..nnz], offset, doRead=false);

  w.close();
  fi.close();
}

proc readBinary(fname:string, param compressRows=true, type eltType=real, type idxType=int) {
  param rank = 2;
  const ioHints = QIO_METHOD_PREADPWRITE | QIO_CH_ALWAYS_UNBUFFERED;
  var fi = open(fname, iomode.r, hints=ioHints);
  var r = fi.reader(locking=false, kind=iokind.native, hints=ioHints);

  {
    const rk = r.read(int);
    assert(rk == rank, "Expected rank ", rk, ", got ", rank);
    const c = r.read(int) == 1;
    assert(c == compressRows, "compressRows does not match file");
  }

  var ranges : rank*range(idxType=idxType);
  for i in 1..rank {
    const lo = r.read(idxType);
    const hi = r.read(idxType);
    ranges(i) = lo..hi;
  }
  var parent : domain(rank) = ranges;

  var ret = new SparseData(eltType, idxType, parentDom=parent);
  ref dom = ret.getDomain();
  ref arr = ret.getArray();

  const nnz          = r.read(idxType);
  const nnzDomSize   = r.read(idxType);
  const startIdxSize = r.read(idxType);
  
  dom._value.nnz = nnz;
  dom._value.nnzDom = {1..nnzDomSize};

  var offset = r.offset();
  arrayIO(fname, dom._value.startIdx, offset);
  arrayIO(fname, dom._value.idx[..nnz], offset);

  arrayIO(fname, arr._value.data[..nnz], offset);

  r.close();
  fi.close();

  return ret;
}
