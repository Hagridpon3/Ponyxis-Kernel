#pragma once

#include "Arduino.h"

#define CMD_NOT_FOUND 0
#define CMD_INFO 1
#define CMD_HELP 2
#define CMD_BEEP 3

extern void parserParse(char input[60]);

void eraseParserArray();

int parserGetCmdId(char input[20]);
