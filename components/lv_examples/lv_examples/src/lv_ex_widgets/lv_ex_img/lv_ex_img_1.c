#include "../../../lv_examples.h"

#include "../../../assets/wifi.c"
#include "../../../assets/user.c"
#include "../../../assets/telegram.c"
#include "../../../assets/settings.c"
#include "../../../assets/set_temp.c"
#include "../../../assets/network.c"
#include "../../../assets/info.c"
#include "../../../assets/home.c"
#include "../../../assets/cloud.c"
#include "../../../assets/clock.c"
#include "../../../assets/config.c"
#include "../../../assets/sd_ok.c"

#include "../../../assets/widget_on.c"
#include "../../../assets/widget_off.c"
#include "../../../assets/widget_on_100.c"
#include "../../../assets/widget_off_100.c"

#include "../../../assets/new_plug_on.c"
#include "../../../assets/new_plug_off.c"
#include "../../../assets/b_off_64.c"
#include "../../../assets/b_on_64.c"
#include "../../../assets/lamp_on.c"
#include "../../../assets/lamp_off.c"
#include "../../../assets/check_on.c"
#include "../../../assets/check_off.c"



#if LV_USE_IMG

/* Find the image here: https://github.com/lvgl/lv_examples/tree/master/assets */
//LV_IMG_DECLARE(img_cogwheel_argb);
//LV_IMG_DECLARE(sd_ok);
//LV_IMG_DECLARE(M_tcp);
//LV_IMG_DECLARE(config);
//LV_IMG_DECLARE(img_cogwheel_rgb);

LV_IMG_DECLARE(wifi);
LV_IMG_DECLARE(user);
LV_IMG_DECLARE(telegram);
LV_IMG_DECLARE(settings);
LV_IMG_DECLARE(set_temp);
LV_IMG_DECLARE(network);
LV_IMG_DECLARE(info);
LV_IMG_DECLARE(home);
LV_IMG_DECLARE(cloud);
LV_IMG_DECLARE(clock);
LV_IMG_DECLARE(config);
LV_IMG_DECLARE(sd_ok);

LV_IMG_DECLARE(widget_on);
LV_IMG_DECLARE(widget_off);
LV_IMG_DECLARE(widget_on_100);
LV_IMG_DECLARE(widget_off_100);



LV_IMG_DECLARE(new_plug_on);
LV_IMG_DECLARE(new_plug_off);
LV_IMG_DECLARE(b_off_64);
LV_IMG_DECLARE(b_on_64);
LV_IMG_DECLARE(lamp_on);
LV_IMG_DECLARE(lamp_off);
LV_IMG_DECLARE(check_on);
LV_IMG_DECLARE(check_off);






static void event_handler(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
 //       printf("State: %s\n", lv_switch_get_state(obj) ? "On" : "Off");

    }
}


static void event_handler_slider_r(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        //printf("Value: %d\n", lv_slider_get_value(obj));
        lv_obj_set_style_local_bg_color(lv_scr_act(), LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex3(lv_slider_get_value(obj)));

    }
}

static void event_handler_slider_g(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        //printf("Value: %d\n", lv_slider_get_value(obj));
        lv_obj_set_style_local_bg_color(lv_scr_act(), LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x000000|(lv_slider_get_value(obj)<<8)));

    }
}

static void event_handler_slider_b(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        //printf("Value: %d\n", lv_slider_get_value(obj));
        lv_obj_set_style_local_bg_color(lv_scr_act(), LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x000000|(lv_slider_get_value(obj)<<16)));

    }
}








void lv_ex_img_1(void)
{
   	static lv_style_t style;
	lv_style_init(&style);

	// background color
	//lv_obj_set_style_local_bg_color(lv_scr_act(), LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex3(0xc1fbff));
	lv_obj_set_style_local_bg_color(lv_scr_act(), LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x999999));


	/*Darken the button when pressed*/
/*	lv_style_set_image_recolor_opa(&style, LV_STATE_PRESSED, LV_OPA_30);
	lv_style_set_image_recolor(&style, LV_STATE_PRESSED, LV_COLOR_BLACK);
	lv_style_set_text_color(&style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
	lv_style_set_bg_color(&style, LV_STATE_PRESSED, LV_COLOR_BLACK);
*/

	/*Create an Image button*/
/*	lv_obj_t * imgbtn1 = lv_imgbtn_create(lv_scr_act(), NULL);
    lv_imgbtn_set_src(imgbtn1, LV_BTN_STATE_RELEASED, &clock);
	lv_imgbtn_set_src(imgbtn1, LV_BTN_STATE_PRESSED, &clock);
	lv_imgbtn_set_src(imgbtn1, LV_BTN_STATE_CHECKED_RELEASED, &info);
	lv_imgbtn_set_src(imgbtn1, LV_BTN_STATE_CHECKED_PRESSED, &info);
	lv_obj_set_event_cb(imgbtn1, event_handler);

	lv_imgbtn_set_checkable(imgbtn1, true);*/
//	lv_obj_add_style(imgbtn1, LV_IMGBTN_PART_MAIN, &style);


	/*Create an Image button*/
/*    lv_obj_t * imgbtn2 = lv_imgbtn_create(lv_scr_act(), NULL);
    lv_imgbtn_set_src(imgbtn2, LV_BTN_STATE_RELEASED, &wifi);
	lv_imgbtn_set_src(imgbtn2, LV_BTN_STATE_PRESSED, &wifi);
	lv_imgbtn_set_src(imgbtn2, LV_BTN_STATE_CHECKED_RELEASED, &info);
	lv_imgbtn_set_src(imgbtn2, LV_BTN_STATE_CHECKED_PRESSED, &info);
	lv_imgbtn_set_checkable(imgbtn2, true);*/
//	lv_obj_add_style(imgbtn2, LV_IMGBTN_PART_MAIN, &style);


/*    lv_obj_t * img3 = lv_imgbtn_create(lv_scr_act(), NULL);
    lv_imgbtn_set_src(img3, LV_BTN_STATE_RELEASED, &telegram);
    lv_imgbtn_set_src(img3, LV_BTN_STATE_PRESSED, &info);
    lv_imgbtn_set_src(img3, LV_BTN_STATE_CHECKED_RELEASED, &info);
    lv_imgbtn_set_src(img3, LV_BTN_STATE_CHECKED_PRESSED, &info);
    lv_imgbtn_set_checkable(img3, false);*/
//    lv_obj_add_style(img3, LV_IMGBTN_PART_MAIN, &style);



 //   lv_obj_add_style(img4, LV_IMGBTN_PART_MAIN, &style);
    lv_obj_t * img4 = lv_imgbtn_create(lv_scr_act(), NULL);
	lv_imgbtn_set_src(img4, LV_BTN_STATE_RELEASED, &widget_off_100);
	lv_imgbtn_set_src(img4, LV_BTN_STATE_PRESSED, &widget_off_100);
	lv_imgbtn_set_src(img4, LV_BTN_STATE_CHECKED_RELEASED, &widget_on_100);
	lv_imgbtn_set_src(img4, LV_BTN_STATE_CHECKED_PRESSED, &widget_on_100);
	lv_imgbtn_set_checkable(img4, true);


    lv_obj_t * img5 = lv_imgbtn_create(lv_scr_act(), NULL);
    lv_imgbtn_set_src(img5, LV_BTN_STATE_RELEASED, &widget_off_100);
    lv_imgbtn_set_src(img5, LV_BTN_STATE_PRESSED, &widget_off_100);
    lv_imgbtn_set_src(img5, LV_BTN_STATE_CHECKED_RELEASED, &widget_on_100);
    lv_imgbtn_set_src(img5, LV_BTN_STATE_CHECKED_PRESSED, &widget_on_100);
    lv_imgbtn_set_checkable(img5, true);


    /*Create a slider*/
	lv_obj_t * slider_r = lv_slider_create(lv_scr_act(), NULL);
	lv_obj_align(slider_r, NULL, LV_ALIGN_CENTER, 0, 60);
	lv_slider_set_range(slider_r, 0, 4095);

	lv_obj_set_event_cb(slider_r, event_handler_slider_r);
/*
	lv_obj_t * slider_g = lv_slider_create(lv_scr_act(), NULL);
	lv_obj_align(slider_g, slider_r, LV_ALIGN_CENTER, 0, 30);
	lv_obj_set_event_cb(slider_g, event_handler_slider_g);

	lv_obj_t * slider_b = lv_slider_create(lv_scr_act(), NULL);
	lv_obj_align(slider_b, slider_g, LV_ALIGN_CENTER, 0, 30);
	lv_obj_set_event_cb(slider_b, event_handler_slider_b);
*/

/*
    lv_obj_t * img5 = lv_imgbtn_create(lv_scr_act(), NULL);
    lv_imgbtn_set_src(img5, LV_BTN_STATE_RELEASED, &clock);
    lv_imgbtn_set_src(img5, LV_BTN_STATE_PRESSED, &set_temp);
    lv_imgbtn_set_checkable(img5, true);

    lv_obj_t * img6 = lv_imgbtn_create(lv_scr_act(), NULL);
    lv_img_set_src(img6, &network);


    lv_obj_t * img7 = lv_imgbtn_create(lv_scr_act(), NULL);
    lv_img_set_src(img7, &info);


    lv_obj_t * img8 = lv_imgbtn_create(lv_scr_act(), NULL);
    lv_img_set_src(img8, &home);


    lv_obj_t * img9 = lv_imgbtn_create(lv_scr_act(), NULL);
    lv_img_set_src(img9, &cloud);


    lv_obj_t * img10 = lv_imgbtn_create(lv_scr_act(), NULL);
    lv_img_set_src(img10, &clock);


    lv_obj_t * img11 = lv_imgbtn_create(lv_scr_act(), NULL);
    lv_img_set_src(img11, &config);


    lv_obj_t * img12 = lv_imgbtn_create(lv_scr_act(), NULL);
    lv_img_set_src(img12, &sd_ok);

*/

 //   lv_img_set_src(img1, &img_cogwheel_argb);
//    lv_img_set_src(img2, LV_SYMBOL_OK "Accept");

    /*
    lv_obj_align(imgbtn1, NULL, LV_ALIGN_IN_TOP_LEFT, 25, 25);
    lv_obj_align(imgbtn2, imgbtn1, LV_ALIGN_IN_TOP_LEFT, 50+23, 0);
    lv_obj_align(img3, imgbtn2, LV_ALIGN_IN_TOP_LEFT, 50+23, 0);
 //   lv_obj_align(img4, img3, LV_ALIGN_IN_TOP_LEFT, 50+23, 0);
*/


    lv_obj_align(img4, NULL, LV_ALIGN_IN_TOP_LEFT, 40, 40);
    lv_obj_align(img5, NULL, LV_ALIGN_IN_TOP_LEFT, 180, 40);



/*
    lv_obj_align(img5, NULL, LV_ALIGN_IN_TOP_LEFT, 25, 20+50+20);
    lv_obj_align(img6, img5, LV_ALIGN_IN_TOP_LEFT, 50+23, 0);
    lv_obj_align(img7, img6, LV_ALIGN_IN_TOP_LEFT, 50+23, 0);
    lv_obj_align(img8, img7, LV_ALIGN_IN_TOP_LEFT, 50+23, 0);

    lv_obj_align(img9, NULL, LV_ALIGN_IN_TOP_LEFT, 25, 20+50+20+50+20);
    lv_obj_align(img10, img9, LV_ALIGN_IN_TOP_LEFT, 50+23, 0);
   lv_obj_align(img11, img10, LV_ALIGN_IN_TOP_LEFT, 50+23, 0);
   lv_obj_align(img12, img11, LV_ALIGN_IN_TOP_LEFT, 50+23, 0);
*/


}

#endif
