use Sqlite3;

config const sql = "SELECT * FROM Customers";

var con = Connection.open("test.db", iomode.rw);
for r in con.rows(sql) do writeln(r);
//var stmt = con.prepare(sql);
//
//for r in stmt.rows() {
//  writeln(r);
//}
