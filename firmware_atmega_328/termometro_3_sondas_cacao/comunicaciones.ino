void enviarMensaje() {
  Serial.println("enviando mensaje:");
  char mensaje[80];
  data.toCharArray(mensaje, 80);
  Serial.println(mensaje);
  rf95.send((uint8_t*)mensaje, 80);                     //--- Inicia envio de informacion
  rf95.waitPacketSent(5000);                                      //--- Espera respuesta de ACK
  uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
  uint8_t len = sizeof(buf);
  if (rf95.waitAvailableTimeout(3000)) {                          //--- Devuelve true si llega un mensaje
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
