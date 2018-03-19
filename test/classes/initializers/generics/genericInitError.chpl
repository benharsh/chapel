class C {
  type t;

  proc init(type t) {
    complete;
    this.t = t;
  }
}

var myC = new C(real);
