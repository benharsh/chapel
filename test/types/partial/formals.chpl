
record R {
  type T;
  param p : T;
}

proc foo(x : R(int)) {
  writeln("int version");
  writeln(x.type:string);
  writeln();
}

proc foo(x : R(real)) {
  writeln("real version");
  writeln(x.type:string);
  writeln();
}

proc foo(x : R) {
  writeln("generic version");
  writeln(x.type:string);
  writeln();
}

foo(new R(int, 100));
foo(new R(real, 123.456));
foo(new R(string, "hello"));

writeln("--------------------");

record P {
  type T;
  param x : T;
  type U;
  param y : U;

  proc init(type T, param x : T, type U, param y : U) {
    this.T = T;
    this.x = x;
    this.U = U;
    this.y = y;
  }

  proc init(param x : ?T, param y : ?U) {
    this.T = T;
    this.x = x;
    this.U = U;
    this.y = y;
  }
}

proc bar(x : P(int, U=int)) {
  writeln("bar(P(int,U=int))");
  writeln(x.type:string);
  writeln();
}

proc bar(x : P(U=bool)) {
  writeln("bar(P(U=bool))");
  writeln(x.type:string);
  writeln();
}

proc bar(x : P) {
  writeln("bar(P)");
  writeln(x.type:string);
  writeln();
}

bar(new P(100, 100));         // P(int,U=int)
bar(new P(100, false));       // P(U=bool)
bar(new P("hello", true));    // P(U=bool)
bar(new P("hello", "world")); // P

writeln("--------------------");

proc baz(x : P(U=real, y=1.0)) {
  writeln("baz(P(U=real,y=1.0))");
  writeln(x.type:string);
  writeln();
}

proc baz(x : P) {
  writeln("baz(P)");
}

// TODO: Compiler currently generates a call to '==' when comparing the desired
// param value against the field's instantiated value. This call fails to
// resolve when the types are different. Once this bug is fixed, this test
// should add more overloads of 'baz' with different param instantiations.
baz(new P(123, 1.0));
baz(new P(123, 99.99));
