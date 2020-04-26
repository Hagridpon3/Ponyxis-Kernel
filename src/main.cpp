#include <Arduino.h>
#include "keyboard.h"
#include "USBHost_t36.h"
#include "display.h"

USBHost myusb;
KeyboardController keyboard(myusb);
//RA8875 tft = RA8875(RA8875_CS, NULL);//Teensy

void setup() {
    Serial.begin(115200);
    Serial1.begin(115200);

    display_hw_init();
    display_gl_init();
    display_gl_touch_init();
    display_ui_draw();

    keyboard.attachPress(PressKey);

    Serial1.printf("Ponyxis kernel v%s\n", VERSION);
    Serial1.printf(">");
}

void loop() {
    myusb.Task();
    display_gl_task();
    delay(5);
}
