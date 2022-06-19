//-- Funcion para inicializar sonda 1
bool inicializa_sonda1() {
	for (byte i = 0; i < 10; i++) {
		Serial.print(F("S_1 intento # ")); Serial.println(i);
		sensor_1.begin();

		if ((sensor_1.getDeviceCount() < 1) || (!sensor_1.getAddress(dir_sensor1, 0))) {
			Serial.println(F("Error sensor1"));
			errorSonda1 = true;
			return false;
		}
		else {
			sensor_1.setResolution(dir_sensor1, 12);
			return true;
		}
	}
}

//-- Funcion para inicializar sonda 2
bool inicializa_sonda2() {
	for (byte i = 0; i < 10; i++) {
		Serial.print(F("S_2 intento # ")); Serial.println(i);
		sensor_2.begin();

		if ((sensor_2.getDeviceCount() < 1) || (!sensor_2.getAddress(dir_sensor2, 0))) {
			Serial.println(F("Error sensor2"));
			errorSonda2 = true;
			return false;
		}
		else {
			sensor_2.setResolution(dir_sensor2, 12);
			return true;
		}
	}
}

//-- Funcion para inicializar sonda 3
bool inicializa_sonda3() {
	for (byte i = 0; i < 10; i++) {
		Serial.print(F("S_3 intento # ")); Serial.println(i);
		sensor_3.begin();

		if ((sensor_3.getDeviceCount() < 1) || (!sensor_3.getAddress(dir_sensor3, 0))) {
			Serial.println(F("Error sensor3"));
			errorSonda3 = true;
			return false;
		}
		else {
			sensor_3.setResolution(dir_sensor3, 12);
			return true;
		}
	}
}