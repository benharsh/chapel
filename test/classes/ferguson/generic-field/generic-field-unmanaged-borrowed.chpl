class ClassA {
  var a:int;
}

class ClassB {
  var b:real;
}

class GenericClassUnmanaged {
  var f:unmanaged;
  proc init(arg:unmanaged) {
    this.f = arg;
  }
}

class GenericClassBorrowed {
  var f:borrowed;
  proc init(arg:borrowed) {
    this.f = arg;
  }
}

proc test1a() {
  var a = new unmanaged ClassA(1);
  var b = new unmanaged ClassA(2);
  var c = new unmanaged ClassA(3);
  var x = new borrowed GenericClassUnmanaged(a);
  var y:GenericClassUnmanaged = new borrowed GenericClassUnmanaged(b);
  var z:GenericClassUnmanaged(unmanaged ClassA) = new borrowed GenericClassUnmanaged(c);

  writeln(x.type:string, " ", x);
  writeln(y.type:string, " ", y);
  writeln(z.type:string, " ", z);

  delete a;
  delete b;
  delete c;
}

test1a();

proc test1b() {
  var a = new unmanaged ClassB(1);
  var b = new unmanaged ClassB(2);
  var c = new unmanaged ClassB(3);
  var x = new owned GenericClassUnmanaged(a);
  var y:GenericClassUnmanaged = new owned GenericClassUnmanaged(b);
  var z:GenericClassUnmanaged(unmanaged ClassB) = new owned GenericClassUnmanaged(c);

  writeln(x.type:string, " ", x);
  writeln(y.type:string, " ", y);
  writeln(z.type:string, " ", z);

  delete a;
  delete b;
  delete c;
}

test1b();


proc test2a() {
  var a = (new owned ClassA(1)).borrow();
  var b = (new owned ClassA(2)).borrow();
  var c = (new owned ClassA(3)).borrow();
  var x = new unmanaged GenericClassBorrowed(a);
  var y:GenericClassBorrowed = new borrowed GenericClassBorrowed(b);
  var z:GenericClassBorrowed(borrowed ClassA) = new borrowed GenericClassBorrowed(c);

  writeln(x.type:string, " ", x);
  writeln(y.type:string, " ", y);
  writeln(z.type:string, " ", z);

  delete x;
}

test2a();

proc test2b() {
  var a = (new owned ClassB(1)).borrow();
  var b = (new owned ClassB(2)).borrow();
  var c = (new owned ClassB(3)).borrow();
  var x = new borrowed GenericClassBorrowed(a);
  var y:GenericClassBorrowed = new owned GenericClassBorrowed(b);
  var z:GenericClassBorrowed(borrowed ClassB) = new owned GenericClassBorrowed(c);

  writeln(x.type:string, " ", x);
  writeln(y.type:string, " ", y);
  writeln(z.type:string, " ", z);
}

test2b();
