
module RepliVar {
  private use ReplicatedDist;
  private use IO;
  private use Map;

  //
  // TODO: the language might one day support a 'replicated' keyword of
  // some sort. Should we rename this type, and then propose users do something
  // like:
  //   use RepliVar;
  //   type replicated = RepliVar.replivar;
  //
  // TODO: Should we have some kind of 'param warnAssign = false' field
  // in this type, so that users can optionally request warnings for something
  // like:
  //   myReplicated = 5; // only applies to one copy
  //
  // TODO: with FCF-support, would it be possible to do something like:
  //   var x = new replicated(int, proc() { return localCompute(); });
  //
  // Note: does not support replicated FCFs... which is probably fine.
  //
  // TODO: should we disallow owned/shared? What happens if we use them?
  //
  // TODO: this-intents being ref?
  //

  record replicated {
    type T;
    var _instance : unmanaged _replicatedClass(T);
    var _pid : int;

    inline proc _value {
      return chpl_getPrivatizedCopy(_instance.type, _pid);
    }

    forwarding _value except chpl__serialize, chpl__deserialize;

    proc init(type T, locs=Locales) {
      this.T = T;
      this._instance = new unmanaged _replicatedClass(T, locs);
      this._pid = _newPrivatizedClass(_instance);
    }

    proc init=(other:replicated) {
      this.T = other.T;
      this._instance = new unmanaged _replicatedClass(other._instance);
      this._pid = _newPrivatizedClass(_instance);
    }

    proc init=(other:?) {
      this.init(T);
      _value.broadcast(other);
    }

    proc writeThis(w) throws {
      w.write(_value.get(w.readWriteThisFromLocale()));
    }

    proc printAll(withLocales=false, w=stdout) throws {
      for loc in _value.targetLocales do on loc {
        if withLocales then
          w.write(here, ": ");
        w.writeln(_value.get(loc));
      }
    }

    proc deinit() {
      _freePrivatizedClass(_pid, _instance);
      delete _instance;
    }
  }

  inline operator :(value:?T, type R:replicated(T)) {
    var ret : R = value;
    return ret;
  }

  // TODO: throw if locales don't match
  inline operator replicated.=(ref LHS : replicated(?T),
                               const ref RHS: replicated(T)) {
    halt("unimplemented right now...");
  }

  inline operator replicated.=(ref LHS : replicated(?T),
                               const RHS: T) {
    LHS.get(here) = RHS;
  }
  
  // TODO: other operators between 'T' and 'replicated(T)'

  class _replicatedClass {
    type T;
    var locsDom : domain(1);
    var targetLocales : [locsDom] locale;
    var copies : [locsDom] unmanaged _replicatedVal(T)?;
    var _myCopy : unmanaged _replicatedVal(T)?;
    var pid : int = nullPid;
    var locidx : map(locale, int);
    var isPrivatized = false;

    forwarding _myCopy!;

    proc init(type T, locs : [] locale, allocate=true) {
      this.T = T;
      this.locsDom = {0..<locs.size};
      this.targetLocales = locs;
      this.complete();

      setupLocidx();

      if allocate {
        const orig = here;
        for (locid, loc) in zip(locsDom, targetLocales) do on loc {
          copies[locid] = new unmanaged _replicatedVal(T);
          if loc == orig then
            _myCopy = copies[locid];
        }
      }
    }

    proc init(other: unmanaged _replicatedClass) {
      this.T = other.T;
      this.locsDom = other.locsDom;
      this.targetLocales = other.targetLocales;
      this.complete();

      setupLocidx();

      const orig = here;
      for (locid, loc) in zip(locsDom, targetLocales) do on loc {
        var from = other.copies[locid];
        copies[locid] = new unmanaged _replicatedVal(T, from!.value);
        if loc == orig then
          _myCopy = copies[locid];
      }
    }

    proc setupLocidx() {
      for (locid, loc) in zip(locsDom, targetLocales) {
        locidx.add(loc, locid);
      }
    }

    proc dsiGetPrivatizeData() {
      return 0;
    }

    proc dsiPrivatize(data) {
      var ret = new unmanaged _replicatedClass(T, targetLocales, allocate=false);
      ret.copies = copies;
      ret.isPrivatized = true;

      // not guaranteed that we're privatizing on a locale in 'targetLocales'
      const orig = here;
      for (locid, loc) in zip(locsDom, targetLocales) do
        if loc == orig then
          ret._myCopy = ret.copies[locid];

      return ret;
    }

    proc get(id: locale = here) ref : T {
      const idx = locidx.get(id, 0);
      return copies[idx]!.value;
    }

    // TODO: should 'broadcast' accept an array of locales?
    proc broadcast(value: T) {
      for (locid, loc) in zip(locsDom, targetLocales) do on loc {
        copies[locid]!.value = value;
      }
    }

    proc broadcast(fn: proc(): T) {
      for (locid, loc) in zip(locsDom, targetLocales) do on loc {
        copies[locid]!.value = fn();
      }
    }

    proc update(fn: proc(ref _:T): void) {
      for (locid, loc) in zip(locsDom, targetLocales) do on loc {
        fn(copies[locid]!.value);
      }
    }

    iter replicands() ref : T {
      // TODO: should we guarantee any order here?
      for (locid, loc) in zip(locsDom, targetLocales) do on loc {
        yield copies[locid]!.value;
      }
    }

    proc deinit() {
      if !isPrivatized {
        for copy in copies do delete copy;
      }
    }
  }

  class _replicatedVal {
    type T;
    var value : T;
    forwarding value except chpl__serialize, chpl__deserialize;

    proc init(type T) {
      this.T = T;
      this.complete();
    }

    proc init(type T, value: T) {
      this.T = T;
      this.value = value;
    }
  }
}
