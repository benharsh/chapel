
use RepliVar;
use CTypes;

extern {
  extern void chpl_printer(char* ptr);

  static char* myFunc(uint64_t id) {
    char* str = calloc(10, 1);
    sprintf(str, "myFunc%lld", id);
    chpl_printer(str);
    return str;
  }

  static void printer(char* str) {
    chpl_printer(str);
  }

  static void cleanup(char* str) {
    free(str);
  }
}

export proc chpl_printer(in ptr : c_string) : void {
  writef("%n :: %s\n", here.id, ptr:string);
}

extern proc myFunc(id:int) : c_string;
extern proc printer(str:c_string) : void;
extern proc cleanup(str:c_string) : void;

var name : replicated(c_string);

proc main() {
  coforall loc in Locales do on loc {
    work();
  }
}

proc work() {
  name = myFunc(here.id);
  printer(name.get());
  cleanup(name.get());
}
