use SQLite3;

config const sql = "SELECT * FROM Customers";

var con = Connection.open("test.db", OpenFlags.ReadWrite);
var stmt = con.prepare("SELECT * FROM Customers");

for r in stmt.rows() {
  writeln(r);
}
