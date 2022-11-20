/*
  Archivo:     termometro_3_sondas_cacao.ino
  Created:     19/04/2022 14:40:56
  Author:      Leon David Valderrama
  Proyecto:    SGPS-9828-2022-PDF-20211214105708
  Nombre Proyecto: Sistema de monitoreo iot de curva de fermentacion del cacao para mejorar la calidad del proceso
  Version:     V0.0.1
*/
#include "variables.h"

//-- Lireria de LoRa
#include <SPI.h>
#include <RH_RF95.h>

//-- Libreria de sonda de temperatura
#include <OneWire.h>
#include <DallasTemperature.h>

//-- Libreria EEPROM
#include <EEPROM.h>

//-- Libreria para bajo consumo de energia
//#include "LowPower.h"

//-- DECLARACIONES
//-- Sesores de temperatura
OneWire oneWire_1(PIN_SENSOR1);
OneWire oneWire_2(PIN_SENSOR2);
OneWire oneWire_3(PIN_SENSOR3);

DallasTemperature sensor_1(&oneWire_1);
DallasTemperature sensor_2(&oneWire_2);
DallasTemperature sensor_3(&oneWire_3);

DeviceAddress dir_sensor1, dir_sensor2, dir_sensor3;

//-- LoRa
RH_RF95 rf95(RFM95_CS, RFM95_INT);




void setup() {
  Serial.begin(9600);
  Serial.println("\nMedicion de temperatura V0.0.2 - 3 Sondas");
  //-- Inicializa pines digitales I/O
  pinMode(PIN_DRIVE_VCC, OUTPUT);
  pinMode(PIN_LED, OUTPUT);
  pinMode(RFM95_RST, OUTPUT);
  pinMode(PIN_ALARMA1, OUTPUT);
  pinMode(PIN_ALARMA2, OUTPUT);

  //-- inicializa la red VCC administrada por uC
  encender_vcc_dev();

  //-- inicializa las sondas de temperatura
  if (!inicializa_sonda1()) Serial.println(F("Error inicializando sonda 1"));
  if (!inicializa_sonda2()) Serial.println(F("Error inicializando sonda 2"));
  if (!inicializa_sonda3()) Serial.println(F("Error inicializando sonda 3"));

  //-- Inicializa sistema de comunicaciones
  if (!inicializa_lora()) Serial.println(F("Error inicializando LoRa"));

  millisMedidas = millis();

}


void loop() {

  if (millis() - millisMedidas  > 1800000 || !primer_ingreso) {
  //if (millis() - millisMedidas > 600000 || !primer_ingreso) {
    encender_vcc_dev();
    delay(200);

    primer_ingreso = true;
    float t1, t2, t3;
    for (byte i = 0; i < INTENTOS_MEDICION; i++) {
      t1 = tomar_medida(SONDA_1);
      if (!errorMedidaSonda1) i = INTENTOS_MEDICION;
    }
    for (byte i = 0; i < INTENTOS_MEDICION; i++) {
      t2 = tomar_medida(SONDA_2);
      if (!errorMedidaSonda2) i = INTENTOS_MEDICION;
    }
    for (byte i = 0; i < INTENTOS_MEDICION; i++) {
      t3 = tomar_medida(SONDA_3);
      if (!errorMedidaSonda3) i = INTENTOS_MEDICION;
    }

    data = "{\"id\":\"";
    data.concat(leerEEPROM(0));
    data.concat("\",\"tipo\":\"TEMP_3\",\"b\":");
    data.concat(medir_bateria());

    if (!errorMedidaSonda1) {
      data.concat(",\"t1\":");
      data.concat(String(t1, 1));
    }

    if (!errorMedidaSonda2) {
      data.concat(",\"t2\":");
      data.concat(String(t2, 1));
    }

    if (!errorMedidaSonda3) {
      data.concat(",\"t3\":");
      data.concat(String(t3, 1));
    }

    data.concat("}");

    //Serial.println(data);

    enviarMensaje();

    apagar_vcc_dev();
    millisMedidas = millis();

  }

}
