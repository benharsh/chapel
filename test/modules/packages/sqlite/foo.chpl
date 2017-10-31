use SQLite3;

config const sql = "SELECT * FROM Customers";

var con = new Connection("test.db", OpenFlags.ReadWrite);
type row = (int, string, string, real);
var stmt = con.prepare("SELECT * FROM Customers WHERE SCORE > ?", row);
stmt.bind(5.0);

while stmt.done == false {
  var ret = stmt.step();
  if stmt.done == false then writeln(ret);
}
