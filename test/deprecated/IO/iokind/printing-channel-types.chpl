use IO;

proc main() {
  writeln(fileReader(iokind.native, false, DefaultDeserializer):string);
  writeln(fileWriter(iokind.native, false, DefaultSerializer):string);
}

