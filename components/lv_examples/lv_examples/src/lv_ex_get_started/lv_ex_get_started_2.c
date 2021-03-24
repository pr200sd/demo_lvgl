#include "../../lv_examples.h"


static lv_obj_t * label1;

static void btn_event_cb(lv_obj_t * btn, lv_event_t event)
{
    if(event == LV_EVENT_PRESSED) {
        /*Refresh the text*/
        lv_label_set_text_fmt(label1, "%s", "LV_EVENT_PRESSED");
    }
    if(event == LV_EVENT_PRESSING) {
		/*Refresh the text*/
		lv_label_set_text_fmt(label1, "%s", "LV_EVENT_PRESSING");
	}
    if(event ==  LV_EVENT_SHORT_CLICKED) {
    		/*Refresh the text*/
    		lv_label_set_text_fmt(label1, "%s", " LV_EVENT_SHORT_CLICKED");
    	}

}

static void event_handler(lv_obj_t * obj, lv_event_t event)
    	{
    	    if(event == LV_EVENT_VALUE_CHANGED) {
    	        //printf("State: %s\n", lv_checkbox_is_checked(obj) ? "Checked" : "Unchecked");
    	        lv_label_set_text_fmt(label1, "%s",lv_checkbox_is_checked(obj) ? "Checked" : "Unchecked");
    	    }
    	}


/**
 * Create styles from scratch for buttons.
 */
void lv_ex_get_started_2(void)
{
    static lv_style_t style_btn;
    static lv_style_t style_btn_red;

    /*Create a simple button style*/
    lv_style_init(&style_btn);
    lv_style_set_radius(&style_btn, LV_STATE_DEFAULT, 10);
    lv_style_set_bg_opa(&style_btn, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_bg_color(&style_btn, LV_STATE_DEFAULT, LV_COLOR_SILVER);
    lv_style_set_bg_grad_color(&style_btn, LV_STATE_DEFAULT, LV_COLOR_GRAY);
    lv_style_set_bg_grad_dir(&style_btn, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);

    /*Swap the colors in pressed state*/
    lv_style_set_bg_color(&style_btn, LV_STATE_PRESSED, LV_COLOR_GRAY);
    lv_style_set_bg_grad_color(&style_btn, LV_STATE_PRESSED, LV_COLOR_SILVER);

    /*Add a border*/
    lv_style_set_border_color(&style_btn, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_border_opa(&style_btn, LV_STATE_DEFAULT, LV_OPA_70);
    lv_style_set_border_width(&style_btn, LV_STATE_DEFAULT, 2);

    /*Different border color in focused state*/
    lv_style_set_border_color(&style_btn, LV_STATE_FOCUSED, LV_COLOR_BLUE);
    lv_style_set_border_color(&style_btn, LV_STATE_FOCUSED | LV_STATE_PRESSED, LV_COLOR_NAVY);

    /*Set the text style*/
    lv_style_set_text_color(&style_btn, LV_STATE_DEFAULT, LV_COLOR_GREEN);

    /*Make the button smaller when pressed*/
    lv_style_set_transform_height(&style_btn, LV_STATE_PRESSED, -5);
    lv_style_set_transform_width(&style_btn, LV_STATE_PRESSED, -10);
#if LV_USE_ANIMATION
    /*Add a transition to the size change*/
    static lv_anim_path_t path;
    lv_anim_path_init(&path);
    lv_anim_path_set_cb(&path, lv_anim_path_overshoot);

    lv_style_set_transition_prop_1(&style_btn, LV_STATE_DEFAULT, LV_STYLE_TRANSFORM_HEIGHT);
    lv_style_set_transition_prop_2(&style_btn, LV_STATE_DEFAULT, LV_STYLE_TRANSFORM_WIDTH);
    lv_style_set_transition_time(&style_btn, LV_STATE_DEFAULT, 100);
    lv_style_set_transition_path(&style_btn, LV_STATE_DEFAULT, &path);
#endif

    /*Create a red style. Change only some colors.*/
    lv_style_init(&style_btn_red);
    lv_style_set_bg_color(&style_btn_red, LV_STATE_DEFAULT, LV_COLOR_RED);
    lv_style_set_bg_grad_color(&style_btn_red, LV_STATE_DEFAULT, LV_COLOR_MAROON);
    lv_style_set_bg_color(&style_btn_red, LV_STATE_PRESSED, LV_COLOR_MAROON);
    lv_style_set_bg_grad_color(&style_btn_red, LV_STATE_PRESSED, LV_COLOR_RED);
    lv_style_set_text_color(&style_btn_red, LV_STATE_DEFAULT, LV_COLOR_WHITE);
#if LV_USE_BTN
    /*Create buttons and use the new styles*/
    lv_obj_t * btn = lv_btn_create(lv_scr_act(), NULL);     /*Add a button the current screen*/
    lv_obj_set_pos(btn, 10, 10);                            /*Set its position*/
    lv_obj_set_size(btn, 120, 50);                          /*Set its size*/
    lv_obj_reset_style_list(btn, LV_BTN_PART_MAIN);         /*Remove the styles coming from the theme*/
    lv_obj_add_style(btn, LV_BTN_PART_MAIN, &style_btn);

    lv_obj_t * label = lv_label_create(btn, NULL);          /*Add a label to the button*/
    lv_label_set_text(label, "Button");                     /*Set the labels text*/

    /*Create a new button*/
    lv_obj_t * btn2 = lv_btn_create(lv_scr_act(), btn);
    lv_obj_set_pos(btn2, 10, 80);
    lv_obj_set_size(btn2, 120, 50);                             /*Set its size*/
    lv_obj_reset_style_list(btn2, LV_BTN_PART_MAIN);         /*Remove the styles coming from the theme*/
    lv_obj_add_style(btn2, LV_BTN_PART_MAIN, &style_btn);
    lv_obj_add_style(btn2, LV_BTN_PART_MAIN, &style_btn_red);   /*Add the red style on top of the current */
    lv_obj_set_style_local_radius(btn2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_RADIUS_CIRCLE); /*Add a local style*/

    label = lv_label_create(btn2, NULL);          /*Add a label to the button*/
    lv_label_set_text(label, "Button 2");                     /*Set the labels text*/

    lv_obj_set_event_cb(btn2, btn_event_cb);         /*Assign an event function*/
    lv_obj_set_event_cb(btn,  btn_event_cb);         /*Assign an event function*/


    /* Create a label below the slider */
    	label1 = lv_label_create(lv_scr_act(), NULL);
    	lv_label_set_text(label1, "0");
    	lv_obj_set_auto_realign(btn2, true);                          /*To keep center alignment when the width of the text changes*/
    	lv_obj_align(label1, btn2, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);    /*Align below the slider*/





    	    lv_obj_t * cb = lv_checkbox_create(lv_scr_act(), NULL);
    	    lv_checkbox_set_text(cb, "I agree...");
    	    lv_obj_align(cb, label1, LV_ALIGN_OUT_BOTTOM_LEFT, -20, 10);
    	    lv_obj_set_event_cb(cb, event_handler);





#endif
}



static void event_handler_mx(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        const char * txt = lv_btnmatrix_get_active_btn_text(obj);
       // printf("%s was pressed\n", txt);
        lv_label_set_text_fmt(label1, "%s was pressed\n",txt);
    }
}


static const char * btnm_map[] = {"OUT1", "OUT2", "OUT3", "\n",
								  "OUT4", "OUT5", "OUT6","\n",
                                  "OUT7", "OUT8", "OUT9", "\n",
                                  "OUT10", "OUT11", "OUT12", ""};

void lv_ex_btnmatrix_1(void)
{
    lv_obj_t * btnm1 = lv_btnmatrix_create(lv_scr_act(), NULL);
    lv_btnmatrix_set_map(btnm1, btnm_map);
//    lv_btnmatrix_set_btn_width(btnm1, 10, 1);        /*Make "Action1" twice as wide as "Action2"*/
    lv_btnmatrix_set_btn_ctrl(btnm1, 9, LV_BTNMATRIX_CTRL_CHECKABLE);
    lv_btnmatrix_set_btn_ctrl(btnm1, 10, LV_BTNMATRIX_CTRL_CHECKABLE);
    lv_btnmatrix_set_btn_ctrl(btnm1, 11, LV_BTNMATRIX_CTRL_CHECKABLE);
 //   lv_btnmatrix_set_btn_ctrl(btnm1, 12, LV_BTNMATRIX_CTRL_CHECKABLE);
    lv_obj_align(btnm1, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_event_cb(btnm1, event_handler_mx);


    /* Create a label below the slider */
        	label1 = lv_label_create(lv_scr_act(), NULL);
        	lv_label_set_text(label1, "0");
        	lv_obj_set_auto_realign(btnm1, true);                          /*To keep center alignment when the width of the text changes*/
        	lv_obj_align(label1, btnm1, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);    /*Align below the slider*/


}
