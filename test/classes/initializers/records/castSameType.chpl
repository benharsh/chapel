record R {
  var x : int;

  proc init() {
    this.x = 0;
    writeln("R.init(): x = ", x);
  }
  proc init(r:R) {
    this.x = 10 * r.x;
    writeln("R.init(R): x = ", x);
  }
  proc deinit() {
    writeln("R.deinit: x = ", x);
  }
}

proc bad(n:int) {
  var err_args = new R();
  err_args.x += 1;

  // Casting from R to R shouldn't eliminate the copy.
  const ret = err_args:R;
  return ret;
}

proc main() {
  var b = bad(10);
  writeln("b = ", b);
}

