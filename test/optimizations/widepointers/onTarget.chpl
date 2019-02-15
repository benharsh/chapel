
class C {
  var x : int;
}

proc main() {
  if numLocales < 2 then
    halt("This test needs multiple locales");

  testSimple();
  testRef();
  testBegin();

  writeln("SUCCESS");
}

proc testSimple() {
  var target = new unmanaged C();

  on target {
    assert(__primitive("is wide pointer", target) == false);
    assert(target.locale == Locales.head());
  }

  delete target;
}

proc testRef() {
  var zero = new unmanaged C();
  var last : unmanaged C();
  on Locales.tail() do last = new unmanaged C();

  var target = zero;
  ref tref = target;

  on target {
    assert(__primitive("is wide pointer", target) == true);
    assert(target.locale == Locales.head());

    tref = last;

    assert(target.locale == Locales.tail());
  }

  assert(target.locale == Locales.tail());

  delete zero, last;
}

proc testBegin() {
  var zero = new unmanaged C();
  var last : unmanaged C();
  on Locales.tail() do last = new unmanaged C();

  var lock : atomic int;
  const REASSIGN = 1, DONE = 2;

  var target = zero;

  begin with (ref target) on Locales.tail() {
    lock.waitFor(REASSIGN);
    target = last;
    lock.write(DONE);
  }

  on target {
    assert(__primitive("is wide pointer", target) == true);
    assert(target.locale == Locales.head());

    lock.write(REASSIGN);
    lock.waitFor(DONE);

    assert(target.locale == Locales.tail());
  }

  assert(target.locale == Locales.tail());

  delete zero, last;
}
