#include "display.h"
#include <string.h>  
#include <stdarg.h>

static NexText line0 = NexText(0, 1, "line0");
static NexText line1 = NexText(0, 1, "line1");
static NexText line2 = NexText(0, 1, "line2");
static NexText line3 = NexText(0, 1, "line3");
static NexText line4 = NexText(0, 1, "line4");
static NexText line5 = NexText(0, 1, "line5");
static NexText line6 = NexText(0, 1, "line6");
static NexText line7 = NexText(0, 1, "line7");
static NexText line8 = NexText(0, 1, "line8");
static NexText line9 = NexText(0, 1, "line9");
static NexText line10 = NexText(0, 1, "line10");
static NexText line11 = NexText(0, 1, "line11");
static NexText line12 = NexText(0, 1, "line12");
static NexText line13 = NexText(0, 1, "line13");
static NexText line14 = NexText(0, 1, "line14");
static NexText line15 = NexText(0, 1, "line15");
static NexText line16 = NexText(0, 1, "line16");
static NexText line17 = NexText(0, 1, "line17");

static NexText lcdLines[18] = {
    line0, line1, line2, line3, line4,
    line5, line6, line7, line8, line9,
    line10, line11, line12, line13, line14,
    line15, line16, line17
};

static char displayLines[17][60] = {0};
static int lineNumber = 0;

void displaySaveLines(){
    for(int i = 0; i <=17; i++){
        lcdLines[i].getText(displayLines[i], 60);
    }
}

void displayLoadLines(){
    char temp[20];    
    for(int i = 0; i <=17; i++){
        sprintf(temp, "line%d.txt=\"\"", i);
        sendCommand(temp);
        lcdLines[i].setText(displayLines[i]);
    }
}

void displayScrollUp(){
    char actualLine[30] = {0};

    for(int i = 0; i <=17; i++){
        sprintf(actualLine, "line%d.txt=line%d.txt", i, i+1);
        sendCommand(actualLine);
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

    if(lineNumber == 18){
        displayScrollUp();
		lineNumber = 17;
    }
}
