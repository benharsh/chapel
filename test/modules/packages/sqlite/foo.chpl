use SQLite3;

config const sql = "SELECT * FROM Customers";

var con = Connection.open("test.db", OpenFlags.ReadWrite);
type row = (int, string, string, real);
var stmt = con.prepare("SELECT * FROM Customers", row);

for i in 1..20 do writeln(stmt.step());
