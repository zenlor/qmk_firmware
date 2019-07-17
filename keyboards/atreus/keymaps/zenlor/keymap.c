// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _GM 2
#define _L1 3
#define _L2 4
#define _L3 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QW] = LAYOUT( /* Qwerty */
            KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,                      KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,
            KC_A,   KC_S,   KC_D,    KC_F,    KC_G,                      KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN,
            KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,                      KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
            KC_ESC, KC_TAB, KC_LGUI, KC_LSFT, KC_BSPC, KC_RCTL, KC_LALT, KC_SPC, MO(_L1), KC_MINS, KC_QUOT, KC_ENT
            ),

    [_GM] = LAYOUT( /* Gaming */
            KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                  KC_9,   KC_4,    KC_5, KC_6, KC_7  ,
            KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                  KC_0,   KC_1,    KC_2, KC_3, KC_8  ,
            KC_NO,   KC_VOLU, KC_NO,   KC_NO,   KC_B,                     KC_GRV, KC_Q,    KC_W, KC_E, KC_MINS  ,
            MO(_L2), KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_TAB, KC_SPC, MO(_L3), KC_S, KC_V, KC_F
            ),

    [_L1] = LAYOUT( /* LAYER 1 */
            KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_VOLU, KC_7,    KC_8,   KC_9, KC_LBRC,
            KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_VOLD, KC_4,    KC_5,   KC_6, KC_RBRC,
            KC_GRV,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MINS,                   KC_MUTE, KC_1,    KC_2,   KC_3, KC_BSLS,
            TG(_L2), KC_APP,  KC_LGUI, KC_LSFT, KC_DEL,  KC_RCTL, KC_LALT, KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL
            ),
    [_L2] = LAYOUT( /* LAYER 2 */
            KC_TRNS, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,                   DF(_QW), KC_F7,   KC_F8,   KC_F9,   KC_F10,
            KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                   DF(_GM), KC_F6,   KC_F5,   KC_F6,   KC_F11,
            KC_BTN4, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4,                   KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12,
            KC_TRNS, KC_TRNS, KC_LGUI, KC_LSFT, KC_BSPC, KC_RCTL, KC_LALT, KC_SPC,  KC_TRNS, KC_TRNS, KC_TRNS, RESET
            ),

    [_L3] = LAYOUT( /* LAYER 3 Gaming */
            KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                  C(KC_R), KC_F4,   KC_F5, KC_F6, A(KC_Q) ,
            KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                  C(KC_T), KC_F1,   KC_F2, KC_F3, A(KC_W) ,
            KC_NO,   KC_VOLU, KC_NO,   KC_NO,   KC_B,                     C(KC_Y), KC_Q,    KC_W,  KC_E,  A(KC_E) ,
            KC_NO,   KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_TAB, KC_SPC,  KC_TRNS, KC_S,  KC_V,  A(KC_R)
            ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
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
