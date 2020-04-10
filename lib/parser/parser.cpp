#include "parser.h"
#include "display.h"

static char parseArray[4][60];

void parserParse(char input[60]){
        sscanf(input, "%s%s%s%s", parseArray[0], parseArray[1], parseArray[2], parseArray[3]);
        switch(parserGetCmdId(parseArray[0])){
            case CMD_NOT_FOUND:
                displayPrintf("%s :command not found :(\n", parseArray[0]);
                break;
            case CMD_INFO:
                displayPrintf("Author: Ponyxis\n");
                displayPrintf("Version: %s\n", VERSION);
                displayPrintf("Platform: Teensy 4.0\n");
                displayPrintf(("USB Host support now!\n"));
                break;
            case CMD_HELP:
                displayPrintf("help screen work :)\n");
                break;
        }
}

int parserGetCmdId(char input[20]){
    if(!strcmp("info", input)) return CMD_INFO;
    if(!strcmp("help", input)) return CMD_HELP;
    return CMD_NOT_FOUND;
}