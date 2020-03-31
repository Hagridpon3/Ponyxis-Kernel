#include <Arduino.h>
#include <SerialFlash.h>
#include "Nextion.h"
#include "keyboard.h"
#include "display.h"

char line[60];
char _ch;
uint8_t _pos;

SerialFlashFile file;

void setup() {
	Serial.begin(9600);
	nexInit();
	SerialFlash.begin(6);
	registrButtons();

	displayPrintf("Ponyxis kernel v0.4.0.0\n");
	displayPrintf(">");
}

void loop() {
	nexLoop(nex_listen_list);
}
