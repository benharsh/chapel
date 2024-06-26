// Tracks calling a static method defined on a parent type from a child type
class Parent {
  proc type foo() param {
    return 3;
  }
}

class Child: Parent {
}

record Wrapper {
  var x;
}

var ownP = new owned Parent();
var p = ownP.borrow();
var ownC = new owned Child();
var c = ownC.borrow();
var w1 = new Wrapper(p);
var w2 = new Wrapper(c);

writeln(w1.x.type: string);
writeln(w2.x.type: string);
writeln(w1.x.type.foo());
writeln(w2.x.type.foo());
