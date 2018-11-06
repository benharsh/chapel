
record R {
  type T;
  var x : T;

  proc init(type T, x : T) {
    writeln("regular initializer");
    this.T = T;
    this.x = x;
  }

  proc init(x : ?T) {
    writeln("regular initializer");
    this.T = T;
    this.x = x;
  }
}

writeln("----- User-Defined Copy Initialization -----");

proc R.initequals(type ThisType, other : ThisType) {
  writeln("copy-init from: ", other.type:string);
  this.T = other.T;
  this.x = other.x;
}

{
  var A = new R(10);
  var B = A;
  var C : R(int) = B;
  // var D : R(real) = C; // Compiler error!
}
writeln("\n\n");

writeln("----- Init= from non-record -----");

proc R.initequals(type ThisType, other : ThisType.T) {
  writeln("init= from ", other.type:string);
  this.T = ThisType.T;
  this.x = other;
}

{
  var A : R(int) = 5;
  var B : R(real) = 3.0;
  writeln(A);
  writeln(B);
}

