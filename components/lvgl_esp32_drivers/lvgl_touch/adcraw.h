/**
* @file ADCRAW.h
*/

#ifndef ADCRAW_H
#define ADCRAW_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "driver/gpio.h"
#include "driver/adc.h"
#include "lvgl/lvgl.h"

#include "include/soc/adc_channel.h"


/*
#define TOUCHSCREEN_RESISTIVE_PIN_YU CONFIG_LVGL_TOUCHSCREEN_RESSITIVE_PIN_YU // Y+ any gpio
#define TOUCHSCREEN_RESISTIVE_PIN_YD CONFIG_LVGL_TOUCHSCREEN_RESISTIVE_PIN_YD // Y- also ADC
#define TOUCHSCREEN_RESISTIVE_PIN_XL CONFIG_LVGL_TOUCHSCREEN_RESISTIVE_PIN_XL // X- any gpio
#define TOUCHSCREEN_RESISTIVE_PIN_XR CONFIG_LVGL_TOUCHSCREEN_RESISTIVE_PIN_XR // X+ also ADC
*/

#define TOUCHSCREEN_RESISTIVE_PIN_YU 5 // Y+ any gpio
#define TOUCHSCREEN_RESISTIVE_PIN_YD 32 // Y- also ADC
#define TOUCHSCREEN_RESISTIVE_PIN_XL 18 // X- any gpio
#define TOUCHSCREEN_RESISTIVE_PIN_XR 33 // X+ also ADC


// Default calibration points
#define TOUCHCAL_ULX 38  // Upper Left X
#define TOUCHCAL_ULY 925  // Upper Left Y
#define TOUCHCAL_URX 855 // Upper Right X
#define TOUCHCAL_URY 903  // Upper Right Y
#define TOUCHCAL_LLX 38  // Lower Left X
#define TOUCHCAL_LLY 121 // Lower Left Y
#define TOUCHCAL_LRX 860 // Lower Right X
#define TOUCHCAL_LRY 107 // Lower Right Y

#define TOUCHSCREEN_RESISTIVE_PRESS_THRESHOLD 2000
//#define TOUCHSCREEN_RESISTIVE_PRESS_THRESHOLD 4000

	
/*GetMaxX Macro*/
#if CONFIG_LVGL_DISPLAY_ORIENTATION_LANDSCAPE
#define GetMaxX()   (CONFIG_LVGL_DISPLAY_WIDTH - 1)
#else
#define GetMaxX()   (CONFIG_LVGL_DISPLAY_HEIGHT - 1)
#endif

/*GetMaxY Macro*/
#if CONFIG_LVGL_DISPLAY_ORIENTATION_LANDSCAPE
#define GetMaxY()   (CONFIG_LVGL_DISPLAY_HEIGHT - 1)
#else
#define GetMaxY()   (CONFIG_LVGL_DISPLAY_WIDTH - 1)
#endif

#ifndef CONCAT3
#define _CONCAT3(a,b,c) a ## b ## c
#define CONCAT3(a,b,c) _CONCAT3(a,b,c)
#endif

#define GPIO_TO_ADC_ELEMENT(x) [x] = CONCAT3(ADC1_GPIO, x, _CHANNEL)

typedef enum {
    IDLE,
    SET_X,
    SET_Y,
    SET_Z1,
    SET_Z2,
	READ_X,
	READ_Y,
	READ_Z1,
	READ_Z2
} TOUCH_STATES; 

void adcraw_init(void);
bool adcraw_read(lv_indev_drv_t * drv, lv_indev_data_t * data);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ADCRAW_H */
