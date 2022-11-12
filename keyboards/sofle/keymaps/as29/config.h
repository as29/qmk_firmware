#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
// Disabling these to save flash space
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// Syncing WPM between two sides
#define SPLIT_WPM_ENABLE

//Enabling RGB light to sleep when host sleeps
#define RGBLIGHT_SLEEP

//Total 24 RGB underlight, 12 on each side
#define RGB_DI_PIN D3
#define RGBLED_NUM 24
#define RGBLED_SPLIT \
        {12, 12}

//OLED Config
#define OLED_TIMEOUT 30000		//setting time out to 30s
#define OLED_BRIGHTNESS 175		//no need for bright oleds, help oleds last longer
