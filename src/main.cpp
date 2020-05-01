#include <Arduino.h>
#include "keyboard.h"
#include "USBHost_t36.h"
#include "display.h"

USBHost myusb;
KeyboardController keyboard(myusb);

void setup() {
    Serial.begin(115200);
    Serial1.begin(115200);

    display_hw_init();
    display_gl_init();
    display_gl_keypad_init();
    display_ui_draw();

    keyboard.attachPress(PressKey);

}

void loop() {
    myusb.Task();
    display_gl_task();
    delay(5);
}
