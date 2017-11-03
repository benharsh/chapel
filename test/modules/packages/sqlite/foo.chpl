use SQLite3;

config const sql = "SELECT * FROM Customers";

var con = Connection.open("test.db", OpenFlags.ReadWrite);
type row = (int, string, string, real);
var stmt = con.prepare("SELECT * FROM Customers", row);

for r in stmt.rows() {
  writeln(r);
}
