/* Copyright 2020 tominabox1
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details. 
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

enum layers{
  _BASE,
  _NUM_SYM,
  _NAV,
  _MOUSE
};

enum custom_keycodes {
  DEL_ALL = SAFE_RANGE,
};

//kc shorthand <<<
#define OS_C    OSM(MOD_LCTL)
#define OS_S    OSM(MOD_LSFT)
#define OS_RS   OSM(MOD_RSFT)
#define OS_GUI  OSM(MOD_LGUI)
#define OS_G    OSM(MOD_LGUI)
#define OS_MEH  OSM(MOD_MEH)
#define OS_HYPR OSM(MOD_HYPR)
#define HOME    TO(0)
#define SCSHOT  LSG(KC_S)
#define zGUI    MT(MOD_LGUI, KC_Z)
#define zCTL    CTL_T(KC_Z)
#define qGUI    GUI_T(KC_Q)
#define aGUI    GUI_T(KC_A)
#define xALT    ALT_T(KC_X)
#define xGUI    GUI_T(KC_X)
#define vSFT    SFT_T(KC_V)
#define dCTL    CTL_T(KC_D)
#define dALT    ALT_T(KC_D)
#define bspCTL  CTL_T(KC_BSPC)
#define slshCTL CTL_T(KC_SLSH)
#define dotALT  ALT_T(KC_DOT)
#define dotGUI  GUI_T(KC_DOT)
#define commSFT SFT_T(KC_COMM)
#define hALT    ALT_T(KC_H)
#define escGUI  GUI_T(KC_ESC)
#define tabGUI  GUI_T(KC_TAB)
#define pipeCTL CTL_T(KC_PIPE)
#define minsALT ALT_T(KC_MINS)
#define minsGUI GUI_T(KC_MINS)
#define plusSFT SFT_T(KC_PLUS)
#define tildALT ALT_T(KC_TILD)
#define undsALT ALT_T(KC_UNDS)// >>>

// fix for mod taps with shifted keys, like KC_PIPE <<<
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_T(KC_TILD):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_TILD); // Send KC_TILD on tap
                return false;        // Return false to ignore further processing of key
            }
        case CTL_T(KC_PIPE):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PIPE); // Send KC_PIPE on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case SFT_T(KC_PLUS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PLUS); // Send KC_PLUS on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case ALT_T(KC_UNDS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_UNDS); // Send KC_UNDS on tap
                return false;        // Return false to ignore further processing of key
            }
    }
    return true;
}// >>>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐        ┌────────┐        ┌────────┬────────┬────────┬────────┬────────┐
     KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,             KC_MPLY,          KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┤        └────────┘        ├────────┼────────┼────────┼────────┼────────┤
     KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,   
  //├────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┤
     zCTL,    xGUI,    vSFT,    dALT,    KC_C,                               KC_K,    hALT,    commSFT, dotGUI,  slshCTL,
  //└────────┴────────┴────────┼────────┼────────┤                          ├────────┼────────┼────────┴────────┴────────┘
                                bspCTL,  LT(2, KC_SPC),                      OSL(1),  OSM(MOD_LSFT)
                            // └────────┴────────┘                          └────────┴────────┘
  ),

  [_NUM_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐        ┌────────┐        ┌────────┬────────┬────────┬────────┬────────┐
     KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,          KC_MPLY,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR,
  //├────────┼────────┼────────┼────────┼────────┤        └────────┘        ├────────┼────────┼────────┼────────┼────────┤
     KC_8,    KC_7,    KC_6,    KC_5,    KC_9,                               KC_4,    KC_0,    KC_1,    KC_2,    KC_3,   
  //├────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┤
     pipeCTL, minsGUI, plusSFT, undsALT, KC_EQL,                             KC_LBRC, KC_RBRC, KC_LT,   KC_GT,   KC_BSLS,
  //└────────┴────────┴────────┼────────┼────────┤                          ├────────┼────────┼────────┴────────┴────────┘
                                vvv,     vvv,                                vvv,     vvv
                            // └────────┴────────┘                          └────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐        ┌────────┐        ┌────────┬────────┬────────┬────────┬────────┐
     qGUI,    AG_TOGG, vvv,     vvv,     RGB_TOG,          KC_MPLY,          KC_DEL,  KC_HOME, KC_PGDN, KC_PGUP, KC_END, 
  //├────────┼────────┼────────┼────────┼────────┤        └────────┘        ├────────┼────────┼────────┼────────┼────────┤
     vvv,     KC_LPRN, KC_RPRN, KC_COLN, KC_SCLN,                            KC_INS,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, 
  //├────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┤
     zCTL,    xGUI,    vSFT,    tildALT, KC_GRV,                             vvv,     vvv,     vvv,     vvv,     vvv,
  //└────────┴────────┴────────┼────────┼────────┤                          ├────────┼────────┼────────┴────────┴────────┘
                                vvv,     vvv,                                vvv,     vvv
                            // └────────┴────────┘                          └────────┴────────┘
  ),

  [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐        ┌────────┐        ┌────────┬────────┬────────┬────────┬────────┐
     vvv,     KC_WH_D, KC_MS_U, KC_WH_U, KC_F9,            KC_MPLY,          KC_F1,   KC_BTN4, KC_BTN5, KC_F4,   KC_F6,  
  //├────────┼────────┼────────┼────────┼────────┤        └────────┘        ├────────┼────────┼────────┼────────┼────────┤
     KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_R, KC_F10,                             KC_F2,   KC_BTN1, KC_BTN2, KC_ACL0, KC_F7,   
  //├────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┤
     zGUI,    xALT,    vSFT,    KC_F12,  KC_F11,                             KC_F3,   KC_ACL1, KC_ACL2, KC_F5,   KC_F8,  
  //└────────┴────────┴────────┼────────┼────────┤                          ├────────┼────────┼────────┴────────┴────────┘
                                vvv,     vvv,                                HOME,    vvv
                            // └────────┴────────┘                          └────────┴────────┘
  ),
};

// leader key shenanigans
void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_D, KC_D)) {
        // Leader, d, d => delete whole field
        SEND_STRING(SS_LCTL("a")"\b"); 
    }
    else if (leader_sequence_two_keys(KC_Y, KC_Y)) {
        // Leader, y, y => Ctrl+A, Ctrl+C
        SEND_STRING(SS_LCTL("ac"));
    }
    else if (leader_sequence_two_keys(KC_G, KC_T)) {
        tap_code16(GU_TOGG);
    }
    else if (leader_sequence_two_keys(KC_A, KC_G)) {
        tap_code16(AG_TOGG);
    }
    else if (leader_sequence_two_keys(KC_Q, KC_B)) {
        register_code16(QK_BOOT);
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}


// more complicated tap-hold settings <<<
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(3, KC_SPC):
            return true;      // tap then hold space won't continuously print spaces
        default:
            return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(3, KC_SPC):
            return true;
        case bspCTL:
            return true;
        default:
            return false;
    }
}// >>>

/*// layer indicator underglow
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
   HSV hsv_bot = {0, 255, 255}; // init. underglow hsv value
   HSV hsv_top = {0, 255, 80}; // init. top hsv value

   switch(get_highest_layer(layer_state|default_layer_state)) { // update current hsv value based on layer
      case 1:  // num_sym
         hsv_bot = (HSV){195*.71,  .40*255, 255}; // *.711 to normalize to 255 max
         hsv_top = (HSV){195*.71,  .40*255, 80}; // *.711 to normalize to 255 max
         break;
      case 2:  // nav
         hsv_bot = (HSV){ 20*.71, 1.00*255, 255};
         hsv_top = (HSV){ 20*.71, 1.00*255, 80};
         break;
       case 3:  // arrows
         hsv_bot = (HSV){345*.71, 1.00*255, 255}; // also multiplying s by a given percent instead of just inputting a straight value
         hsv_top = (HSV){345*.71, 1.00*255, 80}; // also multiplying s by a given percent instead of just inputting a straight value
         break;
      default: // layer 0
         hsv_bot = (HSV){345*.71,  .65*255, 255};
         hsv_top = (HSV){345*.71,  .65*255, 80};
         break;
      }

   RGB rgb_bot = hsv_to_rgb(hsv_bot); // convert hsv struct to rgb
   RGB rgb_top = hsv_to_rgb(hsv_top); // convert hsv struct to rgb

   for (uint8_t i = led_min; i <= 8; i++) { // using 8 for rgb max as the underglow LEDs are from 0 to 8 here
      if (g_led_config.flags[i]) {
         rgb_matrix_set_color(i, rgb_bot.r, rgb_bot.g, rgb_bot.b); // assign converted rgb values to colour 
      }
   }

   for (uint8_t i = 9; i <= led_max; i++) { // set top two leds to to rgb_top colours
      if (g_led_config.flags[i]) {
         rgb_matrix_set_color(i, rgb_top.r, rgb_top.g, rgb_top.b); // assign converted rgb values to colour 
      }
   }  
}*/

