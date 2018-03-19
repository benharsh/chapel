class C {
  param rank: int;
  var x: D;

  class D {
  }

  proc init() {
    rank = 2;
    complete;
    x = new D();
  }
}

var myC = new C();
writeln(myC);
