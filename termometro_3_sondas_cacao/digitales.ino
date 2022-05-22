//-- Activa el mosfet Q3 para proporcionar energia a los sensores de temperatura
void encender_vcc_dev() {
	digitalWrite(PIN_DRIVE_VCC, LOW);
	delay(500);
}

void apagar_vcc_dev() {
	digitalWrite(PIN_DRIVE_VCC, HIGH);
}

void parpadeo(byte veces) {
	for (byte i = 0; i < veces; i++) {
		digitalWrite(PIN_LED, HIGH);
		delay(80);
		digitalWrite(PIN_LED, LOW);
		delay(80);
	}
}
