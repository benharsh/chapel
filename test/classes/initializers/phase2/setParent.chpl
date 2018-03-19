class Parent {
  var parentInt : int;

  proc init() {
  }
}

class Child : Parent {
  var foo : int;

  proc init() {
    complete;
    parentInt = 5;
  }
}
