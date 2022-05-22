/*
 Archivo:			termometro_3_sondas_cacao.ino
 Created:			19/04/2022 14:40:56
 Author:			Leon David Valderrama
 Proyecto:			SGPS-9828-2022-PDF-20211214105708
 Nombre Proyecto:	Sistema de monitoreo iot de curva de fermentacion del cacao para mejorar la calidad del proceso
 Version:			V0.0.1
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
#include "LowPower.h"


void setup() {
	Serial.begin(9600);
	Serial.println("\nMedicion de temperatura V0.0.1 - 3 Sondas");

}

// the loop function runs over and over again until power down or reset
void loop() {
  
}
