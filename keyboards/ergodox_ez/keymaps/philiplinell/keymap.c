#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_swedish.h"
#include "sendstring_swedish.h" // https://docs.qmk.fm/#/reference_keymap_extras?id=sendstring-support

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    ARROW,  // arrow and number keys
    MDIA,  // media keys
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
    CUSTOM_GRV, // `
    CUSTOM_TILD, // ~
    CUSTOM_CIRC, // ^
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  | DEL  |           | DEL  |   6  |   7  |   8  |   9  |   0  |Backspace|
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Å  |   Ä  |   Ö  |   P  |   Y  | MEH  |           | MEH  |   F  |   G  |   C  |   R  |   L  |    ,   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Ctrl  |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |    -   |
 * |--------+------+------+------+------+------| Hyper|           |Hyper |------+------+------+------+------+--------|
 * | LShift |   .  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  §   |   <  | LGUI |  L2  |Alfred|                                       |ESC/L2|   '  |   ´  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | App  | Home |       | PgUp |  AltGr |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | End  |       |PgDown|        |      |
 *                                 | Space| Ctrl |------|       |------|   L1   |Enter |
 *                                 |      |      | Alt  |       |  L2  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,           KC_2,    KC_3,    KC_4,   KC_5,   KC_DEL,
        KC_TAB,         SE_ARNG,        SE_ADIA,   SE_ODIA, KC_P,   KC_Y,   MEH(KC_NO),
        KC_LCTL,        KC_A,           KC_O,    KC_E,    KC_U,   KC_I,
        KC_LSFT,        KC_DOT,         KC_Q,    KC_J,    KC_K,   KC_X,   ALL_T(KC_NO),
        SE_SECT,    SE_LABK,          KC_LGUI, MO(2),   LGUI(KC_SPC),
                                              ALT_T(KC_APP),  KC_HOME,
                                                              KC_END,
                                          KC_SPC, KC_LCTL,    KC_LALT,
        // right hand
        KC_DEL,         KC_6,   KC_7,      KC_8,   KC_9,         KC_0,           KC_BSPC,
        MEH(KC_NO),     KC_F,   KC_G,      KC_C,   KC_R,         KC_L,           KC_COMMA,
  		                  KC_D,   KC_H,      KC_T,   KC_N,         KC_S,           KC_SLSH,
        ALL_T(KC_NO),   KC_B,   KC_M,      KC_W,   KC_V,         KC_Z,           KC_RSFT,
	                   LT(2,KC_ESC), SE_QUOT,       SE_ACUT,      KC_NO,     KC_NO,
             KC_PGUP, KC_RALT,
             KC_PGDN,
             MO(2), MO(1), KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | MUTE |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   ?  |   {  |   }  |   @  |   ^  |      |           |      |      |      |   =  |  >   |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   '  |   (  |   )  |   $  |   |  |------|           |------|  /   |   <  |   -  |  >   |      |        |
 * |--------+------+------+------+------+------|  +   |           |  +   |------+------+------+------+------+--------|
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
       KC_TRNS,LSFT(SE_PLUS), SE_LCBR, SE_RCBR, SE_AT, CUSTOM_CIRC, KC_TRNS,
       KC_TRNS,SE_QUOT,   SE_LPRN, SE_RPRN,SE_DLR, SE_PIPE,
       KC_TRNS,CUSTOM_GRV,      SE_LBRC, SE_RBRC,LSFT(KC_6),CUSTOM_TILD,SE_PLUS,
       KC_TRNS,KC_TRNS,       KC_TRNS, KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_NO,   KC_NO,   LSFT(KC_0),    SE_RABK,    KC_NO, KC_F12,
       LSFT(KC_7),  SE_LABK,  KC_SLSH, SE_RABK, KC_NO,  KC_NO,
       SE_PLUS, SE_BSLS,   KC_NO,   KC_NO,    KC_NO,    KC_NO, KC_TRNS,
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
 * |--------+------+------+------+------+------|  +   |           |  +   |------+------+------+------+------+--------|
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
       KC_NO, KC_MPLY, KC_NO  , KC_MRWD, KC_MFFD, KC_NO, SE_PLUS,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                    KC_VOLD,KC_VOLU,KC_MUTE,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_NO, KC_7,   KC_8,    KC_9,    SE_ASTR, SE_PLUS,
       KC_DOT,   KC_4,  KC_5,   KC_6,  KC_TRNS, KC_TRNS,
       SE_PLUS, KC_COMMA, KC_1,   KC_2,    KC_3,    SE_BSLS, KC_TRNS,
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
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
            case CUSTOM_GRV:
		SEND_STRING("`");
	        return false; // Skip all further processing of this key
            case CUSTOM_TILD:
		SEND_STRING("~");
	        return false; // Skip all further processing of this key
            case CUSTOM_CIRC:
		SEND_STRING("^");
	        return false; // Skip all further processing of this key
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
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
