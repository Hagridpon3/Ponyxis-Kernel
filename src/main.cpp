#include <Arduino.h>
#include "keyboard.h"
#include "USBHost_t36.h"

USBHost myusb;
KeyboardController keyboard(myusb);

void setup() {
	Serial.begin(9600);
	Serial1.begin(250000);
	myusb.begin();
	keyboard.attachPress(PressKey);

    Serial1.printf("Ponyxis kernel %s\n",VERSION);
    Serial1.printf(">");
}

void loop() {
    myusb.Task();
}
