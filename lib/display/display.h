#pragma once

#include "Arduino.h"
#include "lvgl.h"
#include "SPI.h"
#include "RA8875.h"

#define RA8875_CS 10

void display_hw_init(void);
void display_gl_init(void);
void display_gl_keypad_init(void);
void display_ui_draw(void);
void display_gl_task(void);
