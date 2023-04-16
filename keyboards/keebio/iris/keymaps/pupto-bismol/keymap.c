#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
#include "print.h"
//#include "Windows.h"

//layers
#define _COLE 0
#define _ONESHOT 1
#define _LEAGUE 2
#define _ARROWKEYS 3
#define _GAMES 4
#define _QWERTY 5
#define _MOUSEKEYS 6

//kc shorthand
#define OS_C    OSM(MOD_LCTL)
#define OS_S    OSM(MOD_LSFT)
#define OS_RS   OSM(MOD_RSFT)
#define OS_GUI  OSM(MOD_LGUI)
#define OS_G    OSM(MOD_LGUI)
#define OS_MEH  OSM(MOD_MEH)
#define OS_HYPR OSM(MOD_HYPR)
#define ARROWS  MO(3)
#define HOME    TO(0)
#define CA      LCA(KC_NO)
#define SA      LSA(KC_NO)
#define SCSHOT  LSG(KC_S)
#define zGUI    MT(MOD_LGUI, KC_Z)
#define zCTL    CTL_T(KC_Z)
#define qGUI    GUI_T(KC_Q)
#define aGUI    GUI_T(KC_A)
#define xALT    ALT_T(KC_X)
#define vSFT    SFT_T(KC_V)
#define dCTL    CTL_T(KC_D)
#define bspCTL  CTL_T(KC_BSPC)
#define slshCTL CTL_T(KC_SLSH)
#define dotALT  ALT_T(KC_DOT)
#define commSFT SFT_T(KC_COMM)
#define escGUI  GUI_T(KC_ESC)
#define tabGUI  GUI_T(KC_TAB)
#define pipeCTL CTL_T(KC_PIPE)
#define minsALT ALT_T(KC_MINS)
#define plusSFT SFT_T(KC_PLUS)

// fix for mod taps with shifted keys, like KC_PIPE
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_T(KC_PIPE):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PIPE); // Send KC_DQUO on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case SFT_T(KC_PLUS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PLUS); // Send KC_DQUO on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
    }
    return true;
}

enum custom_keycodes {
  DEL_ALL = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // layer 0
  [_COLE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               _______, _______, KC_Y,    KC_Y,    KC_Y,    KC_EQL, 
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, qGUI,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, zCTL,    xALT,    vSFT,    KC_D,    KC_C,    _______,          KC_MUTE, KC_K,    KC_H,    commSFT, dotALT,  slshCTL, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, bspCTL,  LT(3, KC_SPC),             OSL(1),  OS_S,    _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // layer 1
  [_ONESHOT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     vvv,     vvv,     vvv,     vvv,     vvv,     vvv,                                vvv,     KC_LPRN, vvv,     vvv,     KC_LPRN, vvv,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     vvv,     KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, vvv,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     vvv,     KC_8,    KC_7,    KC_6,    KC_5,    KC_9,                               KC_4,    KC_0,    KC_1,    KC_2,    KC_3,    vvv,  
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     SCSHOT,  pipeCTL, minsALT, plusSFT, KC_UNDS, KC_EQL,  _______,          TO(5),   KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_BSLS, vvv,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    vvv,     vvv,     vvv,                       vvv,     HOME,    _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // layer 2
  [_LEAGUE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_Y,    KC_Y,    KC_Y,    KC_EQL, 
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSPC, KC_Z,    KC_X,    KC_V,    KC_D,    KC_C,    _______,          KC_MUTE, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, OS_MEH,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LCTL, KC_SPC,                    OSL(1),  KC_LSFT, HOME
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // layer 3
  [_ARROWKEYS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     vvv,     vvv,     vvv,     vvv,     vvv,     vvv,                                vvv,     vvv,     vvv,     vvv,     KC_PGUP, vvv,
  //├────────┼────────┼────────┼────────┼────────┼────────┤ vvv use for wspaces      ├────────┼────────┼────────┼────────┼────────┼────────┤
     vvv,     escGUI,  vvv,     vvv,     vvv,     vvv,                                KC_HOME, KC_PGDN, KC_UP,   KC_PGUP, KC_GRV,  vvv,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     vvv,     KC_TAB,  vvv,     vvv,     vvv,     vvv,                                KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, KC_SCLN, vvv,
  //├────────┼────────┼────────┼────────┼────────┼────────┼─^^^^^──┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     vvv,     zCTL,    xALT,    vSFT,    vvv,     vvv,     vvv,              _______, KC_INS,  KC_DEL,  commSFT, dotALT,  slshCTL, vvv,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, bspCTL,  LT(3, KC_SPC),             vvv,     vvv,     _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // layer 4
  [_GAMES] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_5,    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_F1,   KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_T,    KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_F2,   KC_F3,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_G,    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_NO,            KC_NO,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_F4,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LCTL, KC_SPC,                    vvv,     HOME,    _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // layer 5
  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,            KC_NO,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LCTL, KC_SPC,                    KC_NO,   KC_LSFT, HOME
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // layer 6
  [_MOUSEKEYS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, KC_F4,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, qGUI,    KC_WH_D, KC_MS_U, KC_WH_U, KC_F9,                              KC_F1,   KC_BTN4, KC_BTN5, KC_F4,   KC_F6,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_R, KC_F10,                             KC_F2,   KC_BTN1, KC_BTN2, KC_ACL0, KC_F7,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, zCTL,    xALT,    vSFT,    KC_F12,  KC_F11,  _______,          _______, KC_F3,   KC_ACL1, KC_ACL2, KC_F5,   KC_F8,   _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, bspCTL,  LT(3, KC_SPC),             vvv,     HOME,    _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
};


// COMBOS

// void process_combo_event(uint16_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case clrline:
//       if (pressed) {
//          tap_code16(C(KC_A));
//          tap_code(KC_BSPC);
//       }
//       break;
//   }
// }

// enum combos {
//   ESC_C_M_EQL_BOOT,
//   ESC_5_EQL_ENT_RST,
//   ESC_LSFT_EQL_ENT_SLEP,
//   BSPC_ENT_ABSPC,
//   OSL1_SPC_LGUI,
//   OSL1_E_OSL2,
//   OSL1_I_OSL6,
//   OSL1_O_OSL4,
//   COMM_DOT_ENT,

//   COMBO_LENGTH         // auto-sets COMBO_LEN with next line
// };
// uint16_t COMBO_LEN = COMBO_LENGTH;

// const uint16_t PROGMEM boot_combo[] = {KC_ESC, KC_C, KC_M, KC_EQL, COMBO_END};
// const uint16_t PROGMEM eeprst_combo[] = {KC_ESC, KC_3, KC_4, KC_5, COMBO_END};
// const uint16_t PROGMEM cleartext_combo[] = {KC_BSPC, OSL(1), COMBO_END};
// const uint16_t PROGMEM windows_combo[] = {OSL(1), KC_SPC, COMBO_END};
// const uint16_t PROGMEM easy_enter[] = {KC_DOT, KC_COMM, COMBO_END};
// const uint16_t PROGMEM sleep_combo[] = {KC_ESC, KC_LSFT, KC_EQL, KC_ENT, COMBO_END};

// const uint16_t PROGMEM layer2_combo[] = {OSL(1), KC_E, COMBO_END};
// const uint16_t PROGMEM layer6_combo[] = {OSL(1), KC_I, COMBO_END};
// const uint16_t PROGMEM layer4_combo[] = {OSL(1), KC_O, COMBO_END};

// combo_t key_combos[] = {
//   [ESC_C_M_EQL_BOOT] = COMBO(boot_combo, QK_BOOT),
//   [ESC_5_EQL_ENT_RST] = COMBO(eeprst_combo, EEP_RST),
//   [BSPC_ENT_ABSPC] = COMBO(cleartext_combo, DEL_ALL),
//   [OSL1_SPC_LGUI] = COMBO(windows_combo, KC_LGUI),
//   [COMM_DOT_ENT] = COMBO(easy_enter, KC_ENT),
//   [ESC_LSFT_EQL_ENT_SLEP] = COMBO(sleep_combo, KC_SLEP),

//   [OSL1_E_OSL2] = COMBO(layer2_combo, TO(2)),
//   [OSL1_I_OSL6] = COMBO(layer6_combo, TO(6)),
//   [OSL1_O_OSL4] = COMBO(layer4_combo, TO(4))
// };


// bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
//     /* Enable combo `SOME_COMBO` on layer `_LAYER_A` */
//     /*              `ESC_C_M_EQL_BOOT`    `_COLE`    */     
//     switch (combo_index) {
//         case ESC_C_M_EQL_BOOT:
//             if (layer_state_is(_COLE)) {
//                 return true;
//             }
//     }

//     return false;
// }

// rgb bullshit
// layer indicator underglow
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    HSV hsv = {0, 255, 255}; // init. current hsv value

    switch(get_highest_layer(layer_state|default_layer_state)) { // update current hsv value based on layer
        case 1: // raise
            hsv = (HSV){195*.71,  .40*255, 255}; // *.711 to normalize to 255 max
            break;
        case 2: // league
            hsv = (HSV){ 20*.71, 1.00*255, 255};
        case 3: // arrows
            hsv = (HSV){345*.71, 1.00*255, 255}; // also multiplying s by a given percent instead of just inputting a straight value
            break;
        case 6: // mousekeys
            hsv = (HSV){125*.71,  .60*255, 255};
            break;
        default:
            hsv = (HSV){345*.71,  .65*255, 255};
            break;
    }

    RGB rgb = hsv_to_rgb(hsv); // convert hsv struct to rgb

    for (uint8_t i = led_min; i <= led_max; i++) {
        if (g_led_config.flags[i] & LED_FLAG_UNDERGLOW) { // check for underglow flag
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b); // assign converted rgb values to colour 
        }
    }
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_COLE]      = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  },
    [_ONESHOT]   = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  },
    [_LEAGUE]    = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  },
    [_ARROWKEYS] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_MPRV, KC_MNXT),  },
    [_GAMES]     = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  },
    [_QWERTY]    = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  },
    [_MOUSEKEYS] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  },
};
#endif

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(3, KC_SPC):
            return true;
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
}


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case zGUI:
            return TAPPING_TERM + 150;
        case qGUI:
            return TAPPING_TERM + 150;
        case xALT:
            return TAPPING_TERM + 125;
        case vSFT:
            return TAPPING_TERM + 50;
        case dCTL:
            return TAPPING_TERM + 0;
        default:
            return TAPPING_TERM;
    }
}




// keycodes i might need later:
// CMB_ON (turns combo on, also CMB_OFF or CMB_TOG)
