#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#include "keymap_swedish.h"

// Source: https://github.com/qmk/qmk_firmware/blob/4764e7712109be63df6395d70b069bceb0258e61/docs/config_options.md#behaviors-that-can-be-configured
// And from keyboards/ergodox_ez README: "You may want to enable QMK_KEYS_PER_SCAN because the Ergodox has a relatively slow scan rate."
#define QMK_KEYS_PER_SCAN 4

#define BASE 0 // Default layer
#define SYMB 1 // Symbols
#define ARROW 2 // Arrow and number keys
#define MDIA 3 // Mouse and Media keys (never used, but kept for reference)

enum custom_keycodes {
  MACRO_GRAVE_KEY = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  | DEL  |           | DEL  |   6  |   7  |   8  |   9  |   0  |Backspace|
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Å  |   Ä  |   Ö  |   P  |   Y  | MEH  |           | MEH  |   F  |   G  |   C  |   R  |   L  |, / C+M |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Ctrl  |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |    -   |
 * |--------+------+------+------+------+------| Hyper|           |Hyper |------+------+------+------+------+--------|
 * | LShift |   .  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  §   |   <  |      |  L2  |Alfred|                                       |ESC/L2|   '  |   ´  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | App  | Home |       | PgUp |  AltGr |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | End  |       |PgDown|        |      |
 *                                 | Space| LGui |------|       |------|   L1   |Enter |
 *                                 |      | (cmd)| Alt  |       | Alt  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,           KC_2,    KC_3,    KC_4,   KC_5,   KC_DEL,
        KC_TAB,         KC_LBRC,        NO_AE,   NO_OSLH, KC_P,   KC_Y,   MEH(KC_NO),
        KC_LCTL,        KC_A,           KC_O,    KC_E,    KC_U,   KC_I,
        KC_LSFT,        KC_DOT,         KC_Q,    KC_J,    KC_K,   KC_X,   ALL_T(KC_NO),
        NO_LESS,        NO_LESS_MAC,          KC_NO, MO(2),   LGUI(KC_SPC),
                                              ALT_T(KC_APP),  KC_HOME,
                                                              KC_END,
                                          KC_SPC, KC_LGUI,    KC_LALT,
        // right hand
        KC_DEL,         KC_6,   KC_7,      KC_8,   KC_9,         KC_0,           KC_BSPC,
        MEH(KC_NO),     KC_F,   KC_G,      KC_C,   KC_R,         KC_L,           MT((MOD_LCTL | MOD_LALT), KC_COMMA),
  		                  KC_D,   KC_H,      KC_T,   KC_N,         KC_S,           KC_SLSH,
        ALL_T(KC_NO),   KC_B,   KC_M,      KC_W,   KC_V,         KC_Z,           KC_RSFT,
                                LT(2,KC_ESC), NO_APOS,       NO_ACUT,      KC_NO,     KC_NO,
             KC_PGUP, KC_RALT,
             KC_PGDN,
             KC_LALT, MO(1), KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | MUTE |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   ?  |   {  |   }  |   @  |   |  |      |           |      |      |      |   =  |  >   |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   '  |   (  |   )  |   $  |   ^  |------|           |------|  /   |   <  |   -  |  >   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   `  |   [  |   ]  |   &  |   ~  |      |           |      |  \   |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_MUTE,
       KC_TRNS,LSFT(NO_PLUS), NO_LCBR_MAC, NO_RCBR_MAC, NO_AT, NO_PIPE_MAC,KC_TRNS,
       KC_TRNS,NO_APOS,   NO_LPRN, NO_RPRN,NO_DLR,NO_CIRC,
       KC_TRNS,MACRO_GRAVE_KEY,      NO_LBRC, NO_RBRC,KC_CIRC,NO_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,       KC_TRNS, KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_NO,   KC_NO,   LSFT(KC_0),    NO_GRTR_MAC,    KC_NO, KC_F12,
       LSFT(KC_7),  NO_LESS_MAC,  KC_SLSH, NO_GRTR_MAC, KC_NO,  KC_NO,
       KC_TRNS, NO_BSLS_MAC,   KC_NO,   KC_NO,    KC_NO,    KC_NO, KC_TRNS,
                         KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Arrowkeys and Numkey
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |  UP  |      |      |      |           |      |      |   7  |   8  |  9   |  *   |    +   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | LEFT | DOWN | RIGHT|      |------|           |------|  .   |   4  |   5  |  6   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Play |      | Prev | Next |      |      |           |      |  ,   |   1  |   2  |  3   |  \   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | VOL  | VOL  |------|       |------|      |      |
 *                                 | DOWN | UP   | Mute |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[ARROW] = LAYOUT_ergodox(
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,
       KC_NO, KC_MPLY, KC_NO  , KC_MRWD, KC_MFFD, KC_NO, KC_TRNS,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                    KC_VOLD,KC_VOLU,KC_MUTE,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_NO, KC_7,   KC_8,    KC_9,    LSFT(NO_APOS), NO_PLUS,
       KC_DOT,   KC_4,  KC_5,   KC_6,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_COMMA, KC_1,   KC_2,    KC_3,    NO_BSLS, KC_TRNS,
                         KC_0,   KC_NO,   KC_NO,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |  UP  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |LEFT  | DOWN | RIGHT|      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |Mouse |Mouse |
 *                                 |      |      |------|       |------|Speed0|Speed1|
 *                                 |      |      |      |       |BrwserB|     |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  , KC_BTN2, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_WBAK, KC_ACL0, KC_ACL1
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case MACRO_GRAVE_KEY:
        // send ` without needing to type something afterwords
        SEND_STRING (SS_LSFT(SS_RALT("=")));
        return false;
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
