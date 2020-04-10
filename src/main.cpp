#include <Arduino.h>
#include "Nextion.h"
#include "keyboard.h"
#include "display.h"
#include "USBHost_t36.h"

USBHost myusb;
KeyboardController keyboard(myusb);

void setup() {
	Serial.begin(9600);
	myusb.begin();

    nexInit();
	keyboard.attachPress(PressKey);

	displayPrintf("Ponyxis kernel %s\n",VERSION);
	displayPrintf(">");
}

void loop() {
    myusb.Task();
}
