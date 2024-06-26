use IO;
use oneofs;

var messageObj = new Foo();
var file = open("out", ioMode.r);
var readingChannel = file.reader(locking=false);

messageObj.deserialize(readingChannel);

writeln(messageObj.co == color.red);
writeln(messageObj.name == b"chapel");

writeln(messageObj.mfield.a == 0);
writeln(messageObj.ifield == 45);
