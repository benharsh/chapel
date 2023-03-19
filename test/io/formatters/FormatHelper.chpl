

module FormatHelper {
  use Json;
  use BinaryIO;
  use IO;

  enum FormatKind {
    default,
    json,
    binaryLittle,
    binaryBig
  }

  config param format : FormatKind = FormatKind.default;

  proc getFormatType(param writing : bool) type {
    select format {
      when FormatKind.default {
        if writing then return IO.DefaultSerializer;
        else return IO.DefaultDeserializer;
      }
      when FormatKind.json {
        if writing then return JsonWriter;
        else return JsonReader;
      }
      when FormatKind.binaryLittle {
        if writing then return BinarySerializer;
        else return BinaryDeserializer;
      }
      when FormatKind.binaryBig {
        if writing then return BinarySerializer;
        else return BinaryDeserializer;
      }
      otherwise return nothing;
    }
  }

  type FormatReader = getFormatType(false);
  type FormatWriter = getFormatType(true);
}
