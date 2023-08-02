use IO;

const stdout = (new file(1)).writer(serializer=new BinarySerializer(), locking=false);

stdout.write(">foo bar\n");
stdout.writef("%s", ">foo bar\n");
