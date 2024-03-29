//-- realiza medicion de temperatura segun la sonda seleccionada 
float tomar_medida(byte sonda) {
  float medida;
  if (sonda == 1) {
    Serial.println(F("Midiendo sonda 1: "));
    sensor_1.requestTemperatures();
    medida = sensor_1.getTempC(dir_sensor1);
    if ((medida == 0.00) || isnan(medida) || medida < -40 || medida == 85.00 || medida > 100) {
      Serial.print(F("Error midiendo sonda: ")); Serial.println(sonda);
      errorMedidaSonda1 = true;
      return 999.99;
    }
  }
  else if (sonda == 2) {
    Serial.println(F("Midiendo sonda 2: "));
    sensor_2.requestTemperatures();
    medida = sensor_2.getTempC(dir_sensor2);
    if ((medida == 0.00) || isnan(medida) || medida < -40 || medida == 85.00 || medida > 100) {
      Serial.print(F("Error midiendo sonda: ")); Serial.println(sonda);
      errorMedidaSonda2 = true;
      return 999.99;
    }
  }
  else if (sonda == 3) {
    Serial.println(F("Midiendo sonda 3: "));
    sensor_3.requestTemperatures();
    medida = sensor_3.getTempC(dir_sensor3);
    if ((medida == 0.00) || isnan(medida) || medida < -40 || medida == 85.00 || medida > 100) {
      Serial.print(F("Error midiendo sonda: ")); Serial.println(sonda);
      errorMedidaSonda3 = true;
      return 999.99;
    }
  }
  errorMedidaSonda1 = false;
  errorMedidaSonda2 = false;
  errorMedidaSonda3 = false;
  Serial.print(medida); Serial.println(F(" C"));
  return medida;
}

//-- Medicion de la bateria
byte medir_bateria() {
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  delay(2);
  ADCSRA |= _BV(ADSC);
  while (bit_is_set(ADCSRA, ADSC));
  uint8_t low = ADCL;
  uint8_t high = ADCH;
  long result = (high << 8) | low;
  result = 1125300L / result; // Calcula Vcc (en mV); 1125300 = 1.1*1023*1000
  if (result < B_MIN) result = B_MIN;
  if (result > B_MAX) result = B_MAX;
  byte bateria = map(result, B_MIN, B_MAX, 0, 100);
  return bateria;
}
