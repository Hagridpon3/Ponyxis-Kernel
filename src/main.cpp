#include <Arduino.h>
#include "keyboard.h"
#include "USBHost_t36.h"
#include "lvgl.h"
#include "SPI.h"
#include "RA8875.h"

#define LVGL_TICK_PERIOD 20

#define RA8875_CS 10
#define RA8875_RESET 9

static lv_disp_buf_t disp_buf;
static lv_color_t buf1[LV_HOR_RES_MAX * 8];
static lv_color_t buf2[LV_HOR_RES_MAX * 8];
static lv_obj_t * ta1;

USBHost myusb;
KeyboardController keyboard(myusb);
RA8875 tft = RA8875(RA8875_CS,RA8875_RESET);//Teensy

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p){
    uint16_t width = (area->x2 - area->x1 +1);
    uint16_t height = (area->y2 - area->y1+1);

    tft.writeRect(area->x1, area->y1, width, height, (uint16_t *)color_p);

    lv_disp_flush_ready(disp); /* tell lvgl that flushing is done */

}

void setup() {
	Serial.begin(9600);
	Serial1.begin(115200);
    tft.begin(RA8875_800x480);

	lv_init();

    lv_disp_buf_init(&disp_buf, buf1, buf2, LV_HOR_RES_MAX * 8);

    lv_theme_t * th = lv_theme_alien_init(210, NULL);
    lv_theme_set_current(th);

    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = 800;
    disp_drv.ver_res = 480;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.buffer = &disp_buf;
    lv_disp_drv_register(&disp_drv);

    ta1 = lv_ta_create(lv_scr_act(), NULL);
    lv_obj_set_size(ta1, 320, 240);
    lv_obj_align(ta1, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);
    lv_ta_set_cursor_type(ta1, LV_CURSOR_BLOCK);
    lv_ta_set_text(ta1, "Ponyxis kernel\n>");    /*Set an initial text*/

    keyboard.attachPress(PressKey);

    Serial1.printf("Ponyxis kernel v%s\n",VERSION);
    Serial1.printf(">");
}

void loop() {
    myusb.Task();
    lv_task_handler(); /* let the GUI do its work */
    delay(5);
}
