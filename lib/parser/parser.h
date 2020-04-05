#pragma once

#include "Arduino.h"

#define CMD_NOT_FOUND 0
#define CMD_INFO 1
#define CMD_HELP 2

extern void parserParse(char input[60]);
extern int parserGetCmdId(char input[20]);