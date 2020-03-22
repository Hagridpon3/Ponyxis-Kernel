#include <Arduino.h>
#include <SerialFlash.h>
#include "Nextion.h"
#include "keyboard.h"
#include "display.h"

char line[60];
char _ch;
uint8_t _pos;

SerialFlashFile file;

char buff[60];
void setup() {
	nexInit();
	SerialFlash.begin(6);
	
	registrButtons();

	displayPrintf(0, "Ponyxis kernel v0.2.0.0");
	displayPrintf(1, ">");
}

void loop() {
	nexLoop(nex_listen_list);
}
