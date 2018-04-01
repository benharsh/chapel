
class C {
  type t;
  var x : t;
  var y = (x,x);
}

var c = new C(int);
writeln("c = ", c);
delete c;
