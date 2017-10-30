use SQLite3;

config const sql = "SELECT * FROM Customers";

var con = new Connection("test.db", OpenFlags.ReadWrite);
//con.exec(sql);

for row in con.rows(sql, real) {
  writeln(row);
}
