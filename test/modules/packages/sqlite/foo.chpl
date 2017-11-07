use Sqlite3;

config const seed = 19283;
//config const sql = "SELECT * FROM Customers";
//
//var con = Connection.open("test.db", iomode.rw);
////var stmt = con.prepare("SELECT * FROM Customers WHERE SCORE > :2 AND ID > :1");
//var stmt = con.prepare("SELECT * FROM Customers WHERE SCORE >= ?2 AND ID > ?1");
//stmt.bind(0, 1.0);
//for r in stmt {
//  writeln(r);
//}

use Random;

var db = Connection.open(":memory:", iomode.rw);
db.exec("CREATE TABLE SCORES (ID INT PRIMARY KEY, SCORE FLOAT)"); 
var stmt = db.prepare("INSERT INTO SCORES VALUES (?, ?)");
var rand = new RandomStream(real, seed);

for i in 1..20 {
  stmt.run(i, rand.getNext());
}

writeln("--- SCORES ---");
var sel = db.prepare("SELECT * FROM SCORES WHERE SCORE > ?");
sel.printHeader();
for r in sel.bind(0.5) {
  writeln(r);
}
writeln("--------------");

for r in db.rows("PRAGMA table_info(SCORES)") do writeln(r);
