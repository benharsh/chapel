use Sqlite3;

proc main() {
  var db = Connection.open(":memory:", iomode.rw);
  db.exec("create table scores (id int primary key, score int)");
  db.exec("insert into scores values (?, ?)", 1, 2);
  db.exec("insert into scores values (?, ?)", 1, 2, 3);
}
