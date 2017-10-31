use SQLite3;

config const sql = "SELECT * FROM Customers";

var con = new Connection("test.db", OpenFlags.ReadWrite);
type row = (int, string, string, real);
var stmt = con.prepare("SELECT * FROM Customers", row);

//while stmt.done == false {
//  var ret = stmt.step();
//  writeln(ret);
//}

for i in 1..20 do writeln(stmt.step());
