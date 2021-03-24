#include "../../lv_examples.h"

static lv_obj_t * label;
static lv_obj_t * label1;
static lv_obj_t * label2;


static void slider_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        /*Refresh the text*/
        lv_label_set_text_fmt(label, "%d", lv_slider_get_value(slider));

    }
}

static void slider1_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        /*Refresh the text*/
        lv_label_set_text_fmt(label1, "%d", lv_slider_get_value(slider));
    }
}

static void slider2_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        /*Refresh the text*/
        lv_label_set_text_fmt(label2, "%d", lv_slider_get_value(slider));
    }
}

/**
 * Create a slider and write its value on a label.
 */
void lv_ex_get_started_3(void)
{
    /* Create a slider in the center of the display */
    lv_obj_t * slider = lv_slider_create(lv_scr_act(), NULL);
    lv_obj_set_width(slider, 200);                        /*Set the width*/
    lv_obj_align(slider, NULL, LV_ALIGN_IN_TOP_MID, 0, 20);    /*Align to the center of the parent (screen)*/
    lv_obj_set_event_cb(slider, slider_event_cb);         /*Assign an event function*/

    /* Create a label below the slider */
    label = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(label, "0");
    lv_obj_set_auto_realign(slider, true);                          /*To keep center alignment when the width of the text changes*/
    lv_obj_align(label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);    /*Align below the slider*/


/* Create a slider in the center of the display */
	lv_obj_t * slider1 = lv_slider_create(lv_scr_act(), NULL);
	lv_obj_set_width(slider1, 200);                        /*Set the width*/
	lv_obj_align(slider1, NULL, LV_ALIGN_CENTER, 0, 0);    /*Align to the center of the parent (screen)*/
	lv_obj_set_event_cb(slider1, slider1_event_cb);         /*Assign an event function*/

/* Create a label below the slider */
	label1 = lv_label_create(lv_scr_act(), NULL);
	lv_label_set_text(label1, "0");
	lv_obj_set_auto_realign(slider1, true);                          /*To keep center alignment when the width of the text changes*/
	lv_obj_align(label1, slider1, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);    /*Align below the slider*/


/* Create a slider in the center of the display */
	lv_obj_t * slider2 = lv_slider_create(lv_scr_act(), NULL);
	lv_obj_set_width(slider2, 200);                        /*Set the width*/
	lv_obj_align(slider2, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, 0);    /*Align to the center of the parent (screen)*/
	lv_obj_set_event_cb(slider2, slider2_event_cb);         /*Assign an event function*/

/* Create a label below the slider */
	label1 = lv_label_create(lv_scr_act(), NULL);
	lv_label_set_text(label2, "0");
	lv_obj_set_auto_realign(slider1, true);                          /*To keep center alignment when the width of the text changes*/
	lv_obj_align(label2, slider2, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);    /*Align below the slider*/




}


