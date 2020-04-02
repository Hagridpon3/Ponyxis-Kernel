#include "display.h"
#include <string.h>  
#include <stdarg.h>

NexText line0 = NexText(0, 1, "line0");
NexText line1 = NexText(0, 1, "line1");
NexText line2 = NexText(0, 1, "line2");
NexText line3 = NexText(0, 1, "line3");
NexText line4 = NexText(0, 1, "line4");
NexText line5 = NexText(0, 1, "line5");
NexText line6 = NexText(0, 1, "line6");
NexText line7 = NexText(0, 1, "line7");
NexText line8 = NexText(0, 1, "line8");
NexText line9 = NexText(0, 1, "line9");
NexText line10 = NexText(0, 1, "line10");
NexText line11 = NexText(0, 1, "line11");
NexText line12 = NexText(0, 1, "line12");
NexText line13 = NexText(0, 1, "line13");
NexText line14 = NexText(0, 1, "line14");
NexText line15 = NexText(0, 1, "line15");
NexText line16 = NexText(0, 1, "line16");
NexText line17 = NexText(0, 1, "line17");

NexText lcdLines[18] = {
    line0, line1, line2, line3, line4,
    line5, line6, line7, line8, line9,
    line10, line11, line12, line13, line14,
    line15, line16, line17
};

char displayLines[17][60] = {0};
uint8_t lineNumber = 0;

void displaySaveLines(){
    for(uint8_t i = 0; i <=17; i++){
        lcdLines[i].getText(displayLines[i], 60);
    }
}

void displayLoadLines(){
    char temp[20];    
    for(uint8_t i = 0; i <=17; i++){
        sprintf(temp, "line%d.txt=\"\"", i);
        sendCommand(temp);
        lcdLines[i].setText(displayLines[i]);
    }
}

void displayScroolUp(){

    char actualLine[60] = {0};
    char clearLine[20];

    for(uint8_t i = 0; i <=16; i++){
        lcdLines[i + 1].getText(actualLine, 60);
        sprintf(clearLine, "line%d.txt=\"\"", i);
        sendCommand(clearLine);
        lcdLines[i].setText(actualLine);
        memset(actualLine, 0, 60);
		delay(60);
    }

    sendCommand("line17.txt=\"\"");
}

void displayPrintf(char *fmt, ...){
    char text[60];
    va_list va;
    va_start(va, fmt);
    vsprintf(text, fmt, va);
    va_end(va);

    lcdLines[lineNumber].setText(text);
	if(strchr(text, '\n')){
		lineNumber++;
	}

    if(lineNumber == 17){
        displayScroolUp();
		lineNumber = 16;
    }
}

