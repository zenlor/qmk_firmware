// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _RS 1
#define _LW 2
#define _GA 3
#define _GB 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    KC_ESC, KC_TAB, KC_LGUI,  KC_LSFT, KC_BSPC,  KC_LCTL, KC_LALT, KC_SPC,  MO(_RS), KC_MINS, KC_QUOT, KC_ENT  ),

  /*
   *  !       @     up     {    }        ||     pgup    7     8     9    *
   *  #     left   down  right  $        ||     pgdn    4     5     6    +
   *  [       ]      (     )    &        ||       `     1     2     3    \
   * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
   */
  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                   KC_PGUP, KC_7,    KC_8,   KC_9, KC_ASTR ,
    KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                    KC_PGDN, KC_4,    KC_5,   KC_6, KC_PLUS ,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                   KC_GRV,  KC_1,    KC_2,   KC_3, KC_BSLS ,
    TG(_LW), KC_INS,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL  ),
  /*
   * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   *       volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    TO(_QW), KC_VOLU, KC_NO,   KC_NO,   RESET,                     KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    TO(_GA), KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  TO(_QW), KC_PSCR, KC_SLCK, KC_PAUS ),

  /*
   * Gaming Layer a.
   *
   * Specifically teilored for a specific game
   *
   * insert home   up  end   pgup       ||         9    4     5     6   7
   *  del   left  down right pgdn       ||         0    1     2     3   8
   *       volup             reset      ||         `    q     w     e   -
   *       voldn  super shift bksp ctrl || tab space   L0  prtsc scroll pause
   */
  [_GA] = LAYOUT( /* [> GAMING A <] */
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                  KC_9,   KC_4,    KC_5, KC_6, KC_7  ,
    KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                  KC_0,   KC_1,    KC_2, KC_3, KC_8  ,
    KC_NO,   KC_VOLU, KC_NO,   KC_NO,   KC_B,                     KC_GRV, KC_Q,    KC_W, KC_E, KC_MINS  ,
    TO(_QW), KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_TAB, KC_SPC, MO(_GB), KC_S, KC_V, KC_F ),

  [_GB] = LAYOUT( /* [> GAMING B <] */
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                  C(KC_R), KC_F4,   KC_F5, KC_F6, A(KC_Q) ,
    KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                  C(KC_T), KC_F1,   KC_F2, KC_F3, A(KC_W) ,
    KC_NO,   KC_VOLU, KC_NO,   KC_NO,   KC_B,                     C(KC_Y), KC_Q,    KC_W,  KC_E,  A(KC_E) ,
    TO(_QW), KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_TAB, KC_SPC,  KC_TRNS, KC_S,  KC_V,  A(KC_R) )
};
