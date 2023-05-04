record R {
  param stridable: bool = false;
  var str: if stridable then int else nothing;
}

var myR = new R(true);
var myR2 = new R(false);

writeln(myR);
writeln(myR2);
