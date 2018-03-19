class C {
  const x: int;

  proc init(x) {
    this.x = x;
    complete;
    //    this.x = 36;  can't do this
  }
}

class D : C {
  proc init(x) {
    super.init(x);
    complete;
    this.x = 42;   // but can do this...
  }
}

var myD = new D(10);
writeln(myD);
delete myD;
