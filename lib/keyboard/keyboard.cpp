#include "keyboard.h"

#include "Nextion.h"

NexText line_kb = NexText(1, 2, "t0");
bool caps_shift = false;
bool symbol_shift = false;

void btn1PopCallback(void *ptr){
	line_kb.setText("1");
}

void btn2PopCallback(void *ptr){
	line_kb.setText("2");
}

void btn3PopCallback(void *ptr){
	line_kb.setText("3");
}

void btn4PopCallback(void *ptr){
	line_kb.setText("4");
}

void btn5PopCallback(void *ptr){
	line_kb.setText("5");
}

void btn6PopCallback(void *ptr){
	line_kb.setText("6");
}

void btn7PopCallback(void *ptr){
	line_kb.setText("7");
}

void btn8PopCallback(void *ptr){
	line_kb.setText("8");
}

void btn9PopCallback(void *ptr){
	line_kb.setText("9");
}

void btn0PopCallback(void *ptr){
	line_kb.setText("0");
}

void btnqPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("Q");
		caps_shift = false;
	}else{
		line_kb.setText("q");
	}
}

void btnwPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("W");
		caps_shift = false;
	}else{
		line_kb.setText("w");
	}
}

void btnePopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("E");
		caps_shift = false;
	}else{
		line_kb.setText("e");
	}
}

void btnrPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("R");
		caps_shift = false;
	}else{
		line_kb.setText("r");
	}
}

void btntPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("T");
		caps_shift = false;
	}else{
		line_kb.setText("t");
	}
}

void btnyPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("Y");
		caps_shift = false;
	}else{
		line_kb.setText("y");
	}
}

void btnuPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("U");
		caps_shift = false;
	}else{
		line_kb.setText("u");
	}
}

void btniPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("I");
		caps_shift = false;
	}else{
		line_kb.setText("i");
	}
}

void btnoPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("O");
		caps_shift = false;
	}else{
		line_kb.setText("o");
	}
}

void btnpPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("P");
		caps_shift = false;
	}else{
		line_kb.setText("p");
	}
}

void btnaPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("A");
		caps_shift = false;
	}else{
		line_kb.setText("a");
	}
}

void btnsPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("S");
		caps_shift = false;
	}else{
		line_kb.setText("s");
	}
}

void btndPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("D");
		caps_shift = false;
	}else{
		line_kb.setText("d");
	}
}

void btnfPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("F");
		caps_shift = false;
	}else{
		line_kb.setText("f");
	}
}

void btngPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("G");
		caps_shift = false;
	}else{
		line_kb.setText("g");
	}
}

void btnhPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("H");
		caps_shift = false;
	}else{
		line_kb.setText("h");
	}
}

void btnjPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("J");
		caps_shift = false;
	}else{
		line_kb.setText("j");
	}
}

void btnkPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("K");
		caps_shift = false;
	}else{
		line_kb.setText("k");
	}
}

void btnlPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("L");
		caps_shift = false;
	}else{
		line_kb.setText("l");
	}
}

void btnenterPopCallback(void *ptr){
	//line_kb.setText("1");
    sendCommand("page 0");
}

void btnCapsShiftPopCallback(void *ptr){
	//line_kb.setText("1");
	caps_shift = true;
}

void btnzPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("Z");
		caps_shift = false;
	}else{
		line_kb.setText("z");
	}
}

void btnxPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("X");
		caps_shift = false;
	}else{
		line_kb.setText("x");
	}
}

void btncPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("C");
		caps_shift = false;
	}else{
		line_kb.setText("c");
	}
}

void btnvPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("V");
		caps_shift = false;
	}else{
		line_kb.setText("v");
	}
}

void btnbPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("B");
		caps_shift = false;
	}else{
		line_kb.setText("b");
	}
}

void btnnPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("N");
		caps_shift = false;
	}else{
		line_kb.setText("n");
	}
}

void btnmPopCallback(void *ptr){
	if (caps_shift == true){
		line_kb.setText("M");
		caps_shift = false;
	}else{
		line_kb.setText("m");
	}
}

void btnSymbolShiftPopCallback(void *ptr){
	//line_kb.setText("9");
	symbol_shift = true;
}

void btnSpacePopCallback(void *ptr){
	line_kb.setText(" ");
}
