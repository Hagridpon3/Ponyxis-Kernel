#include "keyboard.h"
#include "display.h"
#include "parser.h"

static char lineBuffer[60] = { 0 };
static int position = 0;

void clearLineBuffer(){
	for(int i = 0; i <= 59; i++){
		lineBuffer[i] = '\0';
	}
	position = 0;
}

void PressKey(int key){
    char tmpKey = (char) key;

    if(key == '\n'){
        tone(2, 400, 50);
        displayPrintf("\n");
        parserParse(lineBuffer);
        clearLineBuffer();
        displayPrintf(">");
    }else{
        tone(2, 400, 50);
        displayPrintf("%c", tmpKey);
        lineBuffer[position] = tmpKey;
        position++;
    }
}
