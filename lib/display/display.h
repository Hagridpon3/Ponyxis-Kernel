#pragma once
#include <Arduino.h>
#include "Nextion.h"

extern void displaySaveLines();
extern void displayLoadLines();
extern void displayScroolUp();
extern void displayPrintf(char *fmt, ...);
