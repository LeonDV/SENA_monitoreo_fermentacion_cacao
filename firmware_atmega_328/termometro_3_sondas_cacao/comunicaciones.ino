//-- Funcion para enviar mensajes a través de radio LoRa
void enviarMensaje() {
  Serial.println("enviando mensaje:");
  char mensaje[LONGITUD_MSG];
  data.toCharArray(mensaje, LONGITUD_MSG);
  Serial.println(mensaje);
  rf95.send((uint8_t*)mensaje, LONGITUD_MSG);
  rf95.waitPacketSent(5000);
  uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
  uint8_t len = sizeof(buf);
  if (rf95.waitAvailableTimeout(3000)) {
    if (rf95.recv(buf, &len)) {
      String data_ajustar = (char*)buf;
      Serial.print(data_ajustar);
      if (data_ajustar.equals(leerEEPROM(0))) {
        enviadoOk = true;
      }
      else {
        enviadoOk = false;
      }
    }
    else {
      Serial.println(F("R-Fallo"));
      enviadoOk = false;
    }
  }
  else {
    Serial.println(F("No rta LORA"));
    enviadoOk = false;
  }
}
