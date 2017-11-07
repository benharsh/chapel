
use Sqlite3;

config const mode = 0;

proc main() {
  var db = Connection.open(":memory:", iomode.rw);
  db.exec("create table scores (id int, scores float)");
  db.close();
  if mode == 0 then
    db.exec("select * from scores");
  else if mode == 1 then
    for r in db.rows("select * from scores") do writeln(r);
  else if mode == 2 then
    db.prepare("select * from scores");
}
