#include "keyboard.h"
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
        Serial1.printf("\n");
        parserParse(lineBuffer);
        clearLineBuffer();
        Serial1.printf(">");
    }else{
        tone(2, 400, 50);
        Serial1.printf("%c", tmpKey);
        lineBuffer[position] = tmpKey;
        position++;
    }
}
