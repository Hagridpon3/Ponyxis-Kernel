#include <Arduino.h>
#include <SerialFlash.h>
#include "Nextion.h"
#include "keyboard.h"
#include "display.h"

SerialFlashFile file;

void setup() {
	Serial.begin(9600);
	nexInit();
	SerialFlash.begin(6);
	registrButtons();

	displayPrintf("Ponyxis kernel %s\n",VERSION);
	displayPrintf(">");
}

void loop() {
	nexLoop(nexListenList);
}
