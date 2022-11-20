//-- Lectura de 10 caracteres de la memoria EEPROM
String leerEEPROM(int addr) {
  byte lectura;
  String strLectura;
  for (int i = addr; i < addr + 10; i++) {
    lectura = EEPROM.read(i);
    if (lectura != 255) {
      strLectura += (char)lectura;
    }
  }
  return strLectura;
}
