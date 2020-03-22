#include <Arduino.h>
#include <SerialFlash.h>
#include "Nextion.h"
#include "keyboard.h"
#include "display.h"

char line[60];
char _ch;
uint8_t _pos;

SerialFlashFile file;

NexButton btn_1   = NexButton(1, 3, "b0");
NexButton btn_2   = NexButton(1, 4, "b1");
NexButton btn_3   = NexButton(1, 5, "b2");
NexButton btn_4   = NexButton(1, 6, "b3");
NexButton btn_5   = NexButton(1, 7, "b4");
NexButton btn_6   = NexButton(1, 8, "b5");
NexButton btn_7   = NexButton(1, 9, "b6");
NexButton btn_8   = NexButton(1, 10, "b7");
NexButton btn_9   = NexButton(1, 11, "b8");
NexButton btn_0   = NexButton(1, 12, "b9");
NexButton btn_q   = NexButton(1, 13, "b10");
NexButton btn_w   = NexButton(1, 14, "b11");
NexButton btn_e   = NexButton(1, 15, "b12");
NexButton btn_r   = NexButton(1, 16, "b13");
NexButton btn_t   = NexButton(1, 17, "b14");
NexButton btn_y   = NexButton(1, 18, "b15");
NexButton btn_u   = NexButton(1, 19, "b16");
NexButton btn_i   = NexButton(1, 20, "b17");
NexButton btn_o   = NexButton(1, 21, "b18");
NexButton btn_p   = NexButton(1, 22, "b19");
NexButton btn_a   = NexButton(1, 23, "b20");
NexButton btn_s   = NexButton(1, 24, "b21");
NexButton btn_d   = NexButton(1, 25, "b22");
NexButton btn_f   = NexButton(1, 26, "b23");
NexButton btn_g   = NexButton(1, 27, "b24");
NexButton btn_h   = NexButton(1, 28, "b25");
NexButton btn_j   = NexButton(1, 29, "b26");
NexButton btn_k   = NexButton(1, 30, "b27");
NexButton btn_l   = NexButton(1, 31, "b28");
NexButton btn_enter   = NexButton(1, 32, "b29");
NexButton btn_caps_shift   = NexButton(1, 33, "b30");
NexButton btn_z   = NexButton(1, 34, "b31");
NexButton btn_x   = NexButton(1, 35, "b32");
NexButton btn_c   = NexButton(1, 36, "b33");
NexButton btn_v   = NexButton(1, 37, "b34");
NexButton btn_b   = NexButton(1, 38, "b35");
NexButton btn_n   = NexButton(1, 39, "b36");
NexButton btn_m   = NexButton(1, 40, "b37");
NexButton btn_symbol_shift   = NexButton(1, 41, "b38");
NexButton btn_space   = NexButton(1, 42, "b39");


NexTouch *nex_listen_list[] = 
{
    &btn_1,
	&btn_2,
	&btn_3,
	&btn_4,
	&btn_5,
	&btn_6,
	&btn_7,
	&btn_8,
	&btn_9,
	&btn_0,
	&btn_q,
	&btn_w,
	&btn_e,
	&btn_r,
	&btn_t,
	&btn_y,
	&btn_u,
	&btn_i,
	&btn_o,
	&btn_p,
	&btn_a,
	&btn_s,
	&btn_d,
	&btn_f,
	&btn_g,
	&btn_h,
	&btn_j,
	&btn_k,
	&btn_l,
	&btn_enter,
	&btn_caps_shift,
	&btn_z,
	&btn_x,
	&btn_c,
	&btn_v,
	&btn_b,
	&btn_n,
	&btn_m,
	&btn_symbol_shift,
	&btn_space,
    NULL
};
char buff[60];
void setup() {
	nexInit();
	SerialFlash.begin(6);
	btn_1.attachPop(btn1PopCallback);
	btn_2.attachPop(btn2PopCallback);
	btn_3.attachPop(btn3PopCallback);
	btn_4.attachPop(btn4PopCallback);
	btn_5.attachPop(btn5PopCallback);
	btn_6.attachPop(btn6PopCallback);
	btn_7.attachPop(btn7PopCallback);
	btn_8.attachPop(btn8PopCallback);
	btn_9.attachPop(btn9PopCallback);
	btn_0.attachPop(btn0PopCallback);
	btn_q.attachPop(btnqPopCallback);
	btn_w.attachPop(btnwPopCallback);
	btn_e.attachPop(btnePopCallback);
	btn_r.attachPop(btnrPopCallback);
	btn_t.attachPop(btntPopCallback);
	btn_y.attachPop(btnyPopCallback);
	btn_u.attachPop(btnuPopCallback);
	btn_i.attachPop(btniPopCallback);
	btn_o.attachPop(btnoPopCallback);
	btn_p.attachPop(btnpPopCallback);
	btn_a.attachPop(btnaPopCallback);
	btn_s.attachPop(btnsPopCallback);
	btn_d.attachPop(btndPopCallback);
	btn_f.attachPop(btnfPopCallback);
	btn_g.attachPop(btngPopCallback);
	btn_h.attachPop(btnhPopCallback);
	btn_j.attachPop(btnjPopCallback);
	btn_k.attachPop(btnkPopCallback);
	btn_l.attachPop(btnlPopCallback);
	btn_enter.attachPop(btnenterPopCallback);
	btn_caps_shift.attachPop(btnCapsShiftPopCallback);
	btn_z.attachPop(btnzPopCallback);
	btn_x.attachPop(btnxPopCallback);
	btn_c.attachPop(btncPopCallback);
	btn_v.attachPop(btnvPopCallback);
	btn_b.attachPop(btnbPopCallback);
	btn_n.attachPop(btnnPopCallback);
	btn_m.attachPop(btnmPopCallback);
	btn_symbol_shift.attachPop(btnSymbolShiftPopCallback);
	btn_space.attachPop(btnSpacePopCallback);

	displayPrintf(0, "Ponyxis kernel v0.2.0.0");
	displayPrintf(1, ">");

}

void loop() {
	nexLoop(nex_listen_list);
}
