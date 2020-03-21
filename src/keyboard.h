#pragma once

#include "Nextion.h"

NexText line_kb = NexText(1, 2, "t0");

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
	line_kb.setText("q");
}

void btnwPopCallback(void *ptr){
	line_kb.setText("w");
}

void btnePopCallback(void *ptr){
	line_kb.setText("e");
}

void btnrPopCallback(void *ptr){
	line_kb.setText("r");
}

void btntPopCallback(void *ptr){
	line_kb.setText("t");
}

void btnyPopCallback(void *ptr){
	line_kb.setText("y");
}

void btnuPopCallback(void *ptr){
	line_kb.setText("u");
}

void btniPopCallback(void *ptr){
	line_kb.setText("i");
}

void btnoPopCallback(void *ptr){
	line_kb.setText("o");
}

void btnpPopCallback(void *ptr){
	line_kb.setText("p");
}

void btnaPopCallback(void *ptr){
	line_kb.setText("a");
}

void btnsPopCallback(void *ptr){
	line_kb.setText("s");
}

void btndPopCallback(void *ptr){
	line_kb.setText("d");
}

void btnfPopCallback(void *ptr){
	line_kb.setText("f");
}

void btngPopCallback(void *ptr){
	line_kb.setText("g");
}

void btnhPopCallback(void *ptr){
	line_kb.setText("h");
}

void btnjPopCallback(void *ptr){
	line_kb.setText("j");
}

void btnkPopCallback(void *ptr){
	line_kb.setText("k");
}

void btnlPopCallback(void *ptr){
	line_kb.setText("l");
}

void btnenterPopCallback(void *ptr){
	//line_kb.setText("1");
    sendCommand("page 0");
}

void btnCapsShiftPopCallback(void *ptr){
	//line_kb.setText("1");
}

void btnzPopCallback(void *ptr){
	line_kb.setText("z");
}

void btnxPopCallback(void *ptr){
	line_kb.setText("x");
}

void btncPopCallback(void *ptr){
	line_kb.setText("c");
}

void btnvPopCallback(void *ptr){
	line_kb.setText("v");
}

void btnbPopCallback(void *ptr){
	line_kb.setText("b");
}

void btnnPopCallback(void *ptr){
	line_kb.setText("n");
}

void btnmPopCallback(void *ptr){
	line_kb.setText("m");
}

void btnSymbolShiftPopCallback(void *ptr){
	//line_kb.setText("9");
}

void btnSpacePopCallback(void *ptr){
	line_kb.setText(" ");
}