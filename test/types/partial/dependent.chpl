
record D {
  type T;
  param b : bool;
  const x;
  param p : if b then T else x.type;
}

proc main() {
  type X = D(int, p=1024);
  writeln(X:string);
}
