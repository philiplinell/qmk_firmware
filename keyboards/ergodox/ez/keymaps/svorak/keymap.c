#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

// Include keymap swedish from github.lindhe's branch
#include "keymap_swedish.h"

#define BASE 0 // Default layer
#define SYMB 1 // Symbols
#define ARROW 2 // Arrow and number keys
#define MDIA 3 // Mouse and Media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |   1  |   2  |   3  |   4  |   5  | DEL  |           | DEL  |   6  |   7  |   8  |   9  |   0  |   ?    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab/C+M|   Å  |   Ä  |   Ö  |   P  |   Y  | MEH  |           |Hyper |   F  |   G  |   C  |   R  |   L  |, / C+M |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl   |A / L2|   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |S / L2|    -   |
 * |--------+------+------+------+------+------| Hyper|           |  L1  |------+------+------+------+------+--------|
 * | LShift |   .  |   Q  |   J  |   K  |   X  |      |           |      |   B  | M/L3 |   W  |   V  |Z/Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  §   |   <  |   >  |      |Insert|                                       |   '  |   ´  |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | App  | Home |       | PgUp |  AltGr |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |Back  | End  |       |PgDown|        |      |
 *                                 | LGui/|space |------|       |------|   L1   |Enter |
 *                                 | Space|/Alt  |Hyper |       |Alt/ES|        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,           KC_2,    KC_3,   KC_4,   KC_5,   KC_DEL,
        MT((MOD_LCTL | MOD_LALT), KC_TAB),         KC_LBRC,        KC_QUOT, KC_SCLN, KC_P,   KC_Y,   MEH(KC_NO),
        KC_LCTL,        LT(2, KC_A),    KC_O,    KC_E,   KC_U,   KC_I,
        KC_LSFT,        KC_DOT,         KC_Q,   KC_J,    KC_K,   KC_X,   ALL_T(KC_NO),
        KC_GRV,         NO_LESS, LSFT(NO_LESS), KC_NO,   KC_INS,
                                              ALT_T(KC_APP),  KC_HOME,
                                                              KC_END,
        GUI_T(KC_SPC), ALT_T(KC_BSPC),    ALL_T(KC_NO),
        // right hand
             KC_DEL,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,              LSFT(NO_PLUS),
        ALL_T(KC_NO),     KC_F,   KC_G,   KC_C,   KC_R,   KC_L,             MT((MOD_LCTL | MOD_LALT), KC_COMMA),
				                  KC_D,   KC_H,   KC_T,   KC_N,   LT(2, KC_S),    KC_SLSH,
           MO(1), KC_B,   LT(3,KC_M),   KC_W,   KC_V,   CTL_T(KC_Z),      KC_RSFT,
                          NO_APOS,  NO_ACUT, NO_LBRC,NO_RBRC,          KC_FN1,
             KC_PGUP,        KC_RALT,
             KC_PGDN,
             ALT_T(KC_ESC), MO(1), KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | MUTE |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   ?  |   {  |   }  |   @  |   |  |      |           |      |      |      |      |      |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    =   |   >  |   (  |   )  |   $  |   ^  |------|           |------|  /   |   <  |   >  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   \  |   [  |   ]  |   &  |   ~  |      |           |      |  \   |      |      |      |      |        |
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
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_MUTE,
       KC_TRNS,LSFT(NO_PLUS), NO_LCBR, NO_RCBR, NO_AT, NO_PIPE,KC_TRNS,
       LSFT(KC_0),NO_GRTR,       NO_LPRN, NO_RPRN,NO_DLR,NO_CIRC,
       KC_TRNS,NO_BSLS,       NO_LBRC, NO_RBRC,KC_CIRC,NO_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,       KC_TRNS, KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO, KC_F12,
                LSFT(KC_7),  NO_LESS,   LSFT(NO_LESS),    KC_NO,    KC_NO,   KC_NO,
       KC_TRNS, NO_BSLS,   KC_NO,   KC_NO,    KC_NO,    KC_NO, KC_TRNS,
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
 * |        |      |      |      |      |      |      |           |      |  ,   |   1  |   2  |  3   |  \   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | VOL  | VOL  |------|       |------|      |      |
 *                                 | DOWN | UP   |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
KEYMAP(
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                    KC_VOLD,KC_VOLU,KC_TRNS,
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
 * |        |      |      | MsUp |      |      |      |           |      |      |      |  UP  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |LEFT  | DOWN | RIGHT|      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |Mouse |Mouse |
 *                                 | Lclk | Rclk |------|       |------|Speed0|Speed1|
 *                                 |      |      |      |       |BrwserB|     |      |
 *                                 `--------------------'       `--------------------'
 */
KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN1, KC_BTN2, KC_TRNS,
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

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
