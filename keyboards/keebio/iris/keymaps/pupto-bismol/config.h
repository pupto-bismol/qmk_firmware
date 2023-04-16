/*
Copyright 2021 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


// custom defines
#define ONESHOT_TIMEOUT 250
#define TAPPING_TERM 190
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD_PER_KEY

//#define COMBO_SHOULD_TRIGGER
#define COMBO_STRICT_TIMER
#define COMBO_TERM 40
#define COMBO_ONLY_FROM_LAYER 0


// mouse defines
#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL

#define MK_C_OFFSET_UNMOD	 8	//Cursor offset per movement (unmodified)
#define MK_C_INTERVAL_UNMOD	 8	//Time between cursor movements (unmodified)
#define MK_C_OFFSET_0	     4	//Cursor offset per movement (0)
#define MK_C_INTERVAL_0	     8	//Time between cursor movements (0)
#define MK_C_OFFSET_1	    16	//Cursor offset per movement (1)
#define MK_C_INTERVAL_1	     8	//Time between cursor movements (1)
#define MK_C_OFFSET_2	     2	//Cursor offset per movement (2)
#define MK_C_INTERVAL_2	     8	//Time between cursor movements (2)

#define MK_W_OFFSET_UNMOD	 1	//Scroll steps per scroll action (unmodified)
#define MK_W_INTERVAL_UNMOD	40	//Time between scroll steps (unmodified)
#define MK_W_OFFSET_0	     1	//Scroll steps per scroll action (0)
#define MK_W_INTERVAL_0	   360	//Time between scroll steps (0)
#define MK_W_OFFSET_1	     1	//Scroll steps per scroll action (1)
#define MK_W_INTERVAL_1	   120	//Time between scroll steps (1)
#define MK_W_OFFSET_2	     1	//Scroll steps per scroll action (2)
#define MK_W_INTERVAL_2	    20	//Time between scroll steps (2)


/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_ROW_PINS { B1, F0, F5, B4, D7 }
#define MATRIX_COL_PINS { F1, F4, B5, C7, D4, D6 }
#define MATRIX_ROW_PINS_RIGHT { B1, F0, F5, B4, B5 }
#define MATRIX_COL_PINS_RIGHT { D4, D6, D7, C7, F1, F4 }
#define SPLIT_HAND_PIN D5

//#define ENCODERS_PAD_A { B3 }   // not currently using this encoder
//#define ENCODERS_PAD_B { B2 }
#define ENCODERS_PAD_A_RIGHT { B3 }
#define ENCODERS_PAD_B_RIGHT { B2 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN D0

/* ws2812 RGB LED */
#define RGB_DI_PIN E6
#ifdef RGB_DI_PIN
#    define RGBLED_NUM 68
#    define RGBLED_SPLIT { 34, 34 }
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    define RGBLIGHT_LIMIT_VAL 145 /* The maximum brightness level */
#    define RGBLIGHT_SLEEP         /* If defined, the RGB lighting will be switched off when the host goes to sleep */
/*== enabled animations ==*/
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_DEFAULT_VAL 120
#    define RGBLIGHT_DEFAULT_MODE (RGBLIGHT_MODE_PLAIN)
// RGB Matrix
#    ifdef RGB_MATRIX_ENABLE
#        define ENABLE_RGB_MATRIX_ALPHAS_MODS
#        define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #        define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
// #        define ENABLE_RGB_MATRIX_BREATHING
// #        define ENABLE_RGB_MATRIX_BAND_SAT
// #        define ENABLE_RGB_MATRIX_BAND_VAL
// #        define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
// #        define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #        define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
// #        define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
// #        define ENABLE_RGB_MATRIX_CYCLE_ALL
// #        define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #        define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
// #        define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #        define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
// #        define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #        define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #        define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
// #        define ENABLE_RGB_MATRIX_DUAL_BEACON
// #        define ENABLE_RGB_MATRIX_RAINBOW_BEACON
// #        define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
#        define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#        define ENABLE_RGB_MATRIX_DIGITAL_RAIN
// enabled only if RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
#        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #        define ENABLE_RGB_MATRIX_SOLID_REACTIVE
// #        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
// #        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
// #        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
// #        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
// #        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
// #        define ENABLE_RGB_MATRIX_SPLASH
// #        define ENABLE_RGB_MATRIX_MULTISPLASH
// #        define ENABLE_RGB_MATRIX_SOLID_SPLASH
// #        define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#        define RGB_MATRIX_MAXIMUM_BRIGHTNESS 145
#		 define RGBLIGHT_LAYERS
#        define RGB_MATRIX_STARTUP_VAL 150
#        define DRIVER_LED_TOTAL RGBLED_NUM
#        define RGB_MATRIX_SPLIT { 34, 34 }
#        define RGB_DISABLE_WHEN_USB_SUSPENDED
#        define RGB_MATRIX_KEYPRESSES
#		 define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#		 define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_ALPHAS_MODS
#        define SPLIT_LAYER_STATE_ENABLE
//#		 define RGB_MATRIX_LED_FLUSH_LIMIT 16
#    endif
#endif

//custom rgb defines


//space saving defines
#undef LOCKING_SUPPORT_ENABLE  // locking keys
#undef LOCKING_RESYNC_ENABLE   // ...
//#define NO_ACTION_TAPPING    // mod tap/tap dance/OSM
#define NO_MUSIC_MODE          // playing music mode
#define LAYER_STATE_8BIT       // set to 16 bit for >8 layers

