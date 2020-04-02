#include "keyboard.h"
#include "display.h"

NexButton btn1   = NexButton(1, 3, "b0");
NexButton btn2   = NexButton(1, 4, "b1");
NexButton btn3   = NexButton(1, 5, "b2");
NexButton btn4   = NexButton(1, 6, "b3");
NexButton btn5   = NexButton(1, 7, "b4");
NexButton btn6   = NexButton(1, 8, "b5");
NexButton btn7   = NexButton(1, 9, "b6");
NexButton btn8   = NexButton(1, 10, "b7");
NexButton btn9   = NexButton(1, 11, "b8");
NexButton btn0   = NexButton(1, 12, "b9");
NexButton btnQ   = NexButton(1, 13, "b10");
NexButton btnW   = NexButton(1, 14, "b11");
NexButton btnE   = NexButton(1, 15, "b12");
NexButton btnR   = NexButton(1, 16, "b13");
NexButton btnT   = NexButton(1, 17, "b14");
NexButton btnY   = NexButton(1, 18, "b15");
NexButton btnU   = NexButton(1, 19, "b16");
NexButton btnI   = NexButton(1, 20, "b17");
NexButton btnO   = NexButton(1, 21, "b18");
NexButton btnP   = NexButton(1, 22, "b19");
NexButton btnA   = NexButton(1, 23, "b20");
NexButton btnS   = NexButton(1, 24, "b21");
NexButton btnD   = NexButton(1, 25, "b22");
NexButton btnF   = NexButton(1, 26, "b23");
NexButton btnG   = NexButton(1, 27, "b24");
NexButton btnH   = NexButton(1, 28, "b25");
NexButton btnJ   = NexButton(1, 29, "b26");
NexButton btnK   = NexButton(1, 30, "b27");
NexButton btnL   = NexButton(1, 31, "b28");
NexButton btnEnter   = NexButton(1, 32, "b29");
NexButton btnCapsShift   = NexButton(1, 33, "b30");
NexButton btnZ   = NexButton(1, 34, "b31");
NexButton btnX   = NexButton(1, 35, "b32");
NexButton btnC   = NexButton(1, 36, "b33");
NexButton btnV   = NexButton(1, 37, "b34");
NexButton btnB   = NexButton(1, 38, "b35");
NexButton btnN   = NexButton(1, 39, "b36");
NexButton btnM   = NexButton(1, 40, "b37");
NexButton btnSymbolShift   = NexButton(1, 41, "b38");
NexButton btnSpace   = NexButton(1, 42, "b39");

NexButton btnKeyboard   = NexButton(0, 19, "b0");

NexText keyboardLine = NexText(1, 2, "t0");

bool capsShift = false;
bool symbolShift = false;

char lineBuffer[60];
uint8_t position = 0;

char keyboardNormal[40] = {
	'1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
	'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
	'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '\n',
	' ', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ' ', ' ',
};
char keyboardBig[40] = {
	'1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
	'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
	'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', '\n',
	' ', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', ' ', ' ',
};

NexTouch *nexListenList[] = 
{
    &btn1,
	&btn2,
	&btn3,
	&btn4,
	&btn5,
	&btn6,
	&btn7,
	&btn8,
	&btn9,
	&btn0,
	&btnQ,
	&btnW,
	&btnE,
	&btnR,
	&btnT,
	&btnY,
	&btnU,
	&btnI,
	&btnO,
	&btnP,
	&btnA,
	&btnS,
	&btnD,
	&btnF,
	&btnG,
	&btnH,
	&btnJ,
	&btnK,
	&btnL,
	&btnEnter,
	&btnCapsShift,
	&btnZ,
	&btnX,
	&btnC,
	&btnV,
	&btnB,
	&btnN,
	&btnM,
	&btnSymbolShift,
	&btnSpace,
	&btnKeyboard,
    NULL
};

void registrButtons(){
	btn1.attachPop(btn1PopCallback);
	btn2.attachPop(btn2PopCallback);
	btn3.attachPop(btn3PopCallback);
	btn4.attachPop(btn4PopCallback);
	btn5.attachPop(btn5PopCallback);
	btn6.attachPop(btn6PopCallback);
	btn7.attachPop(btn7PopCallback);
	btn8.attachPop(btn8PopCallback);
	btn9.attachPop(btn9PopCallback);
	btn0.attachPop(btn0PopCallback);
	btnQ.attachPop(btnqPopCallback);
	btnW.attachPop(btnwPopCallback);
	btnE.attachPop(btnePopCallback);
	btnR.attachPop(btnrPopCallback);
	btnT.attachPop(btntPopCallback);
	btnY.attachPop(btnyPopCallback);
	btnU.attachPop(btnuPopCallback);
	btnI.attachPop(btniPopCallback);
	btnO.attachPop(btnoPopCallback);
	btnP.attachPop(btnpPopCallback);
	btnA.attachPop(btnaPopCallback);
	btnS.attachPop(btnsPopCallback);
	btnD.attachPop(btndPopCallback);
	btnF.attachPop(btnfPopCallback);
	btnG.attachPop(btngPopCallback);
	btnH.attachPop(btnhPopCallback);
	btnJ.attachPop(btnjPopCallback);
	btnK.attachPop(btnkPopCallback);
	btnL.attachPop(btnlPopCallback);
	btnEnter.attachPop(btnEnterPopCallback);
	btnCapsShift.attachPop(btnCapsShiftPopCallback);
	btnZ.attachPop(btnzPopCallback);
	btnX.attachPop(btnxPopCallback);
	btnC.attachPop(btncPopCallback);
	btnV.attachPop(btnvPopCallback);
	btnB.attachPop(btnbPopCallback);
	btnN.attachPop(btnnPopCallback);
	btnM.attachPop(btnmPopCallback);
	btnSymbolShift.attachPop(btnSymbolShiftPopCallback);
	btnSpace.attachPop(btnSpacePopCallback);
	btnKeyboard.attachPop(btnKeyboardPopCallback);
}

void clearLineBuffer(){
	for(uint8_t i = 0; i <= 59; i++){
		lineBuffer[i] = '\0';
	}
	position = 0;
}

void keyboardShowLetter(uint8_t keyCode){
	char array[20];
	sprintf(array, "%c", capsShift ? keyboardBig[keyCode] : keyboardNormal[keyCode]);
	keyboardLine.setText(array);
	lineBuffer[position] = array[0];
	position++;
}

void btn1PopCallback(void *ptr){
	keyboardShowLetter(0);
}

void btn2PopCallback(void *ptr){
	keyboardShowLetter(1);
}

void btn3PopCallback(void *ptr){
	keyboardShowLetter(2);
}

void btn4PopCallback(void *ptr){
	keyboardShowLetter(3);
}

void btn5PopCallback(void *ptr){
	keyboardShowLetter(4);
}

void btn6PopCallback(void *ptr){
	keyboardShowLetter(5);
}

void btn7PopCallback(void *ptr){
	keyboardShowLetter(6);
}

void btn8PopCallback(void *ptr){
	keyboardShowLetter(7);
}

void btn9PopCallback(void *ptr){
	keyboardShowLetter(8);
}

void btn0PopCallback(void *ptr){
	keyboardShowLetter(9);
}

void btnqPopCallback(void *ptr){
	keyboardShowLetter(10);
}

void btnwPopCallback(void *ptr){
	keyboardShowLetter(11);
}

void btnePopCallback(void *ptr){
	keyboardShowLetter(12);
}

void btnrPopCallback(void *ptr){
	keyboardShowLetter(13);
}

void btntPopCallback(void *ptr){
	keyboardShowLetter(14);
}

void btnyPopCallback(void *ptr){
	keyboardShowLetter(15);
}

void btnuPopCallback(void *ptr){
	keyboardShowLetter(16);
}

void btniPopCallback(void *ptr){
	keyboardShowLetter(17);
}

void btnoPopCallback(void *ptr){
	keyboardShowLetter(18);
}

void btnpPopCallback(void *ptr){
	keyboardShowLetter(19);
}

void btnaPopCallback(void *ptr){
	keyboardShowLetter(20);
}

void btnsPopCallback(void *ptr){
	keyboardShowLetter(21);
}

void btndPopCallback(void *ptr){
	keyboardShowLetter(22);
}

void btnfPopCallback(void *ptr){
	keyboardShowLetter(23);
}

void btngPopCallback(void *ptr){
	keyboardShowLetter(24);
}

void btnhPopCallback(void *ptr){
	keyboardShowLetter(25);
}

void btnjPopCallback(void *ptr){
	keyboardShowLetter(26);
}

void btnkPopCallback(void *ptr){
	keyboardShowLetter(27);
}

void btnlPopCallback(void *ptr){
	keyboardShowLetter(28);
}

void btnEnterPopCallback(void *ptr){
	sendCommand("page 0");
	keyboardShowLetter(29);
	displayLoadLines();
	displayPrintf(lineBuffer);
	displayPrintf(">");
	clearLineBuffer();
}

void btnCapsShiftPopCallback(void *ptr){
	capsShift = !capsShift;
}

void btnzPopCallback(void *ptr){
	keyboardShowLetter(31);
}

void btnxPopCallback(void *ptr){
	keyboardShowLetter(32);
}

void btncPopCallback(void *ptr){
	keyboardShowLetter(33);
}

void btnvPopCallback(void *ptr){
	keyboardShowLetter(34);
}

void btnbPopCallback(void *ptr){
	keyboardShowLetter(35);
}

void btnnPopCallback(void *ptr){
	keyboardShowLetter(36);
}

void btnmPopCallback(void *ptr){
	keyboardShowLetter(37);
}

void btnSymbolShiftPopCallback(void *ptr){
}

void btnSpacePopCallback(void *ptr){
	keyboardShowLetter(39);
}

void btnKeyboardPopCallback(void *ptr){
	displaySaveLines();
	sendCommand("page 1");
}

