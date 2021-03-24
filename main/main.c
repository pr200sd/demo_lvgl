/* LVGL Example project
 * 
 * Basic project to test LVGL on ESP32 based projects.
 *
 * This example code is in the Public Domain (or CC0 licensed, at your option.)
 *
 * Unless required by applicable law or agreed to in writing, this
 * software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, either express or implied.
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stddef.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_freertos_hooks.h"
#include "freertos/semphr.h"
#include "esp_system.h"
#include "driver/gpio.h"


/* Littlevgl specific */
#include "lvgl/lvgl.h"
#include "lvgl_helpers.h"


#include "c1.c"
#include "c2.c"
#include "earth.c"
#include "man1.c"
#include "man2.c"
#include "man3.c"
#include "man4.c"
#include "man5.c"
#include "man6.c"
#include "man11.c"

#include "watch_bg.c"
#include "hour.c"
#include "minute.c"
#include "second.c"


static lv_style_t style;
lv_obj_t * img;
lv_obj_t * img0;

lv_obj_t * lvMinute;
lv_obj_t * lvHour;
lv_obj_t * lvSecond ;

uint8_t cur_time_h;
uint8_t cur_time_m;
uint8_t cur_time_s;


/*********************
 *      DEFINES
 *********************/
#define TAG "demo"
#define LV_TICK_PERIOD_MS 1

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void lv_tick_task(void *arg);
static void guiTask(void *pvParameter);
static void create_demo_application(void);




static void lv_periodic_task(void *arg) {
    (void) arg;



}


static void update_time(void *arg)
{
//    get_time();

	cur_time_s++;
//    lv_img_set_angle(  lvHour, cur_time_h*30*10);
//    lv_img_set_angle(  lvMinute, cur_time_m*6*10);
    lv_img_set_angle(  lvSecond, cur_time_s*6*10);
}


void demo_c1_()
{
		//фон манометры
		img0 = lv_img_create(lv_scr_act(), NULL);
//	    lv_img_set_src(img0, &c1);
	    lv_img_set_src(img0, &man5);
	    lv_obj_align(img0, NULL, LV_ALIGN_CENTER, 0, 0);
}



void watch1()
{
	lv_style_init(&style);
    img = lv_img_create(lv_scr_act(),NULL);
    lv_img_set_src(img, &watch_bg);

    lv_obj_align(img, NULL, LV_ALIGN_CENTER, 0, 0);
    lvHour = lv_img_create(img,NULL);
    lv_img_set_src( lvHour, &hour);
    lv_obj_align(  lvHour, img,LV_ALIGN_CENTER, 0, 0);
    lv_img_set_angle(lvHour, 900);

    lvMinute = lv_img_create(img,NULL);
    lv_img_set_src( lvMinute, &minute);
    lv_img_set_zoom(lvMinute, 300);
    lv_obj_align(  lvMinute, img,LV_ALIGN_CENTER, 0, 0);


    lvSecond = lv_img_create(img,NULL);
    lv_img_set_src( lvSecond, &second);
    lv_img_set_zoom(lvSecond, 350);
    lv_obj_align(  lvSecond, img,LV_ALIGN_CENTER, 0, 0);


    lv_task_create(update_time, 1000, LV_TASK_PRIO_LOW, NULL);
}





/**********************
 *   APPLICATION MAIN
 **********************/
void app_main() {
    
    /* If you want to use a task to create the graphic, you NEED to create a Pinned task
     * Otherwise there can be problem such as memory corruption and so on.
     * NOTE: When not using Wi-Fi nor Bluetooth you can pin the guiTask to core 0 */
    xTaskCreatePinnedToCore(guiTask, "gui", 4096*2, NULL, 0, NULL, 1);
}

/* Creates a semaphore to handle concurrent call to lvgl stuff
 * If you wish to call *any* lvgl function from other threads/tasks
 * you should lock on the very same semaphore! */
SemaphoreHandle_t xGuiSemaphore;

static void guiTask(void *pvParameter) {
    
    (void) pvParameter;
    xGuiSemaphore = xSemaphoreCreateMutex();

    lv_init();
    
    /* Initialize SPI or I2C bus used by the drivers */
    lvgl_driver_init();

    /* Use double buffered when not working with monochrome displays */
    static lv_color_t buf1[DISP_BUF_SIZE];
#ifndef CONFIG_LVGL_TFT_DISPLAY_MONOCHROME
    static lv_color_t buf2[DISP_BUF_SIZE];
#endif

    static lv_disp_buf_t disp_buf;
    uint32_t size_in_px = DISP_BUF_SIZE;

    /* Initialize the working buffer depending on the selected display */

#if defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_IL3820 \
    || defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_JD79653A \
    || defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_UC8151D
    /* Actual size in pixel, not bytes and use single buffer */
    size_in_px *= 8;
    lv_disp_buf_init(&disp_buf, buf1, NULL, size_in_px);
#elif defined CONFIG_LVGL_TFT_DISPLAY_MONOCHROME
    lv_disp_buf_init(&disp_buf, buf1, NULL, size_in_px);
#else
    lv_disp_buf_init(&disp_buf, buf1, buf2, size_in_px);
 //   lv_disp_buf_init(&disp_buf, buf1, NULL, size_in_px);
#endif

    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.flush_cb = disp_driver_flush;

    /* When using a monochrome display we need to register the callbacks:
     * - rounder_cb
     * - set_px_cb */
#ifdef CONFIG_LVGL_TFT_DISPLAY_MONOCHROME
    disp_drv.rounder_cb = disp_driver_rounder;
    disp_drv.set_px_cb = disp_driver_set_px;
#endif

    disp_drv.buffer = &disp_buf;
    lv_disp_drv_register(&disp_drv);

    /* Register an input device when enabled on the menuconfig */
#if CONFIG_LVGL_TOUCH_CONTROLLER != TOUCH_CONTROLLER_NONE
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.read_cb = touch_driver_read;
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    lv_indev_drv_register(&indev_drv);
#endif
    
    /* Create and start a periodic timer interrupt to call lv_tick_inc */
    const esp_timer_create_args_t periodic_timer_args = {
        .callback = &lv_tick_task,
        .name = "periodic_gui"
    };
    esp_timer_handle_t periodic_timer;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, LV_TICK_PERIOD_MS * 1000));

    /* Create the demo application */
    create_demo_application();
    
    while (1) {
        /* Delay 1 tick (assumes FreeRTOS tick is 10ms */
        vTaskDelay(pdMS_TO_TICKS(10));

        /* Try to take the semaphore, call lvgl related function on success */
        if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
            lv_task_handler();
            xSemaphoreGive(xGuiSemaphore);
       }
    }

    /* A task should NEVER return */
    vTaskDelete(NULL);
}

static void create_demo_application(void)
{

	watch1(); 	//demo манометры/индикаторы
//	demo_c1_();	//часы

}



static void lv_tick_task(void *arg) {
    (void) arg;
    lv_tick_inc(LV_TICK_PERIOD_MS);
}
