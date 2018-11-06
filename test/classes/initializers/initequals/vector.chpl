
record Vector {
  type T;
  var D : domain(1);
  var A : [D] T;

  proc init(type T) {
    writeln("regular init from type");
    this.T = T;
  }

  proc init(data : []) {
    writeln("regular init from array");
    this.T = data.eltType;
    this.D = data.domain;
    this.A = data;
  }

  // Classic copy-initializer
  proc initequals(type ThisType, other : ThisType) {
    writeln("classic copy init");
    this.T = other.T;
    this.D = other.D;
    this.A = other.A;
  }
}

writeln("----- Classic Initialization -----");
{
  var A : Vector(int);
  var B = A;
  var C = new Vector([1, 2, 3]);
}

writeln("\n\n\n");

// Initialize a particular Vector type from an array of the same eltType
proc Vector.initequals(type ThisType, data : [] ThisType.T) {
  writeln("typed init= from array");
  this.T = ThisType.T;
  this.D = data.domain;
  this.A = data;
}

writeln("----- Initialize Typed Generic from Expr -----");
{
  var A : Vector(int) = [1, 2, 3];
  writeln(A);
}

writeln("\n\n\n");

// Infer generic information from RHS
proc Vector.initequals(data : [] ) {
  writeln("init= infer from array");
  this.T = data.eltType;
  this.D = data.domain;
  this.A = data;
}

writeln("----- Initialize Generic Inferred from Expr -----");
{
  var A : Vector = [1, 2, 3];
  writeln(A.type:string);
  writeln(A);

  writeln();
  
  var B : Vector = ["hello", "world"];
  writeln(B.type:string);
  writeln(B);
}
