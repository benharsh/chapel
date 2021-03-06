pragma "use default init"
class GenericClass {
  type t;
  var v: int;
}

pragma "use default init"
class OtherGenericClass {
  type t;
  var v: int;
}

pragma "use default init"
record Wrapper {
  var f;
}

proc f(x: Wrapper(GenericClass)) {
  writeln(x);
}
proc g(x: Wrapper(GenericClass(?))) {
  writeln(x);
}


var a = new Wrapper(new borrowed GenericClass(int, 3));
var b = new Wrapper(new borrowed GenericClass(real, 4));
var c = new Wrapper(new borrowed OtherGenericClass(int, 3));
var d = new Wrapper(new borrowed OtherGenericClass(real, 4));

// these should work
f(a);
f(b);
g(a);
g(b);

f(c); // error -- mismatch
