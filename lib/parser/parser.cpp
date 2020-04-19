#include "parser.h"

static char parseArray[4][60];

void eraseParserArray(){
    memset(parseArray[0], 0x00, 60);
    memset(parseArray[1], 0x00, 60);
    memset(parseArray[2], 0x00, 60);
    memset(parseArray[3], 0x00, 60);
}

void parserParse(char input[60]){
        sscanf(input, "%s%s%s%s", parseArray[0], parseArray[1], parseArray[2], parseArray[3]);

        switch(parserGetCmdId(parseArray[0])){
            case CMD_NOT_FOUND:
                Serial1.printf("%s :command not found :(\n", parseArray[0]);
                eraseParserArray();
                break;
            case CMD_INFO:
                Serial1.printf("Author: Ponyxis\n");
                Serial1.printf("Version: %s\n", VERSION);
                Serial1.printf("Platform: Teensy 4.0\n");
                Serial1.printf(("USB Host support now!\n"));
                eraseParserArray();
                break;
            case CMD_HELP:
                Serial1.printf("help screen work :)\n");
                eraseParserArray();
                break;
            case CMD_BEEP:
                int freq = 0;
                int dur = 0;
                sscanf(parseArray[1], "%d", &freq);
                sscanf(parseArray[2], "%d", &dur);
                if(freq > 0 && dur > 0){
                    tone(2, freq, dur);
                }else{
                    Serial1.printf("please enter frequency or duration bigger than zero\n");
                }

                eraseParserArray();
                break;
        }
}

int parserGetCmdId(char input[20]){
    if(!strcmp("info", input)) return CMD_INFO;
    if(!strcmp("help", input)) return CMD_HELP;
    if(!strcmp("beep", input)) return CMD_BEEP;
    return CMD_NOT_FOUND;
}
