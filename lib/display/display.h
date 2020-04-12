#pragma once
#include <Arduino.h>
#include "Nextion.h"

extern void displaySaveLines();

extern void displayLoadLines();

void displayScrollUp();

extern void displayPrintf(char *fmt, ...);
