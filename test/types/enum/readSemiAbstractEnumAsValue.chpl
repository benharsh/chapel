use IO;

config const dontskip = 0;

proc trybad(fmt, ref val) {
  readf(fmt, val);
  writeln(val);
}

proc readit(ref x) {
  readf("%?\n", x);
  writeln(x);
  readf("%s\n", x);
  writeln(x);
  if dontskip == 0 then
    trybad("%i", x);
  if dontskip == 1 then
    trybad("%u", x);
  if dontskip == 2 then
    trybad("%xi", x);
  if dontskip == 3 then
    trybad("%r", x);
  if dontskip == 4 then
    trybad("%er", x);
  if dontskip == 5 then
    trybad("%n", x);

  writeln();
}

enum G { F1, F2 = 5};
var g = G.F1;
readit(g);
