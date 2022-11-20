//-- Activa el mosfet Q3 para proporcionar energia a los sensores de temperatura
void encender_vcc_dev() {
  digitalWrite(PIN_DRIVE_VCC, LOW);
  digitalWrite(PIN_LED, HIGH);
  delay(1000);
}

//-- Activa el mosfet Q3 para proporcionar energia a los sensores de temperatura
void apagar_vcc_dev() {
  digitalWrite(PIN_DRIVE_VCC, HIGH);
  digitalWrite(PIN_LED, LOW);
}

//-- indicador led
void parpadeo(byte veces) {
  for (byte i = 0; i < veces; i++) {
    digitalWrite(PIN_LED, HIGH);
    delay(80);
    digitalWrite(PIN_LED, LOW);
    delay(80);
  }
}

//-- Apaga el circuito durante CICLOS_AHORRO_ENERGIA_8S x 8 segundos (aprox 15 min)
void ahorro_energia_15min() {
  apagar_vcc_dev();
  delay(200);
  for (byte i = 0; i < CICLOS_AHORRO_ENERGIA_8S; i++) {
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    delay(100);
    yield();
  }
  encender_vcc_dev();
  delay(200);
}
