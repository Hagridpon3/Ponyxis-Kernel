#include "parser.h"
#include "lvgl.h"

static char parseArray[4][60];
extern lv_obj_t * console;

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
                lv_ta_add_text(console, "Author: Ponyxis\n");
                lv_ta_add_text(console, "Platform: Teensy 4.0\n");
                lv_ta_add_text(console, "Now with LittlevGL engine");
                eraseParserArray();
                break;
            case CMD_HELP:
                lv_ta_add_text(console,"help screen work :)");
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
                    lv_ta_add_text(console,"please enter frequency or duration bigger than zero");
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
