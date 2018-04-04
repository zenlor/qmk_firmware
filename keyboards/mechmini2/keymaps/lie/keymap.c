/*
 *
 */
#include "kb.h"

// Layers
#define _QWERTY  0
#define _WORKMAN 1
#define _RAISE   2
#define _LOWER   3
#define _NAV     4

// Empty keys
#define ______ KC_TRNS
#define __xx__ KC_TRNS
#define XXXXXX KC_NO

// Shifted keys
#define S_INS S(KC_INS)


// Tap Macros
#define C_ESC  LCTL_T(KC_ESC) // Esc, LCtrl
#define C_ENT  LCTL_T(KC_ENT) // Enter, RCtl

#define CS_Z    MT(MOD_LSFT, KC_Z)
#define CS_SLSH MT(MOD_RSFT, KC_SLSH)

// Layer Macros
#define SPCNAV LT(_NAV, KC_SPC) // Space, layer NAV
#define RAIS_Q LT(_RAISE, KC_Q) // Q, layer RAISE
#define RAIS_P LT(_RAISE, KC_P) // P, layer RAISE

#define RAISE  MO(_RAISE)
#define LOWER  MO(_LOWER)
#define ADJUST MO(_ADJUST)

#define QWERTY  TO(_QWERTY)
#define WORKMAN TO(_WORKMAN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  | CANC | BKSP |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  | TAB  |  '   |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |LSHFT(|RSHFT)|   N  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ESC | META | LALT | BSPC |LOWER |   SPC/NAV   | RAISE| ENTER| RALT | META | RCTL |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP_2U_SPACE_ORTHO(
    RAIS_Q, KC_W,    KC_E,    KC_R,    KC_T,  KC_DEL,  KC_BSPC, KC_Y,  KC_U,   KC_I,    KC_O,    RAIS_P  ,
    KC_A,   KC_S,    KC_D,    KC_F,    KC_G,  KC_TAB,  KC_QUOT, KC_H,  KC_J,   KC_K,    KC_L,    KC_SCLN ,
    CS_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_LSPO, KC_RSPC, KC_N,  KC_M,   KC_COMM, KC_DOT,  CS_SLSH ,
    C_ESC,  KC_LGUI, KC_LALT, KC_BSPC, LOWER,      SPCNAV,      RAISE, KC_DEL, KC_RALT, KC_RGUI, C_ENT   ),

/*
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   D  |   R  |   W  |   B  | CANC | BKSP |   J  |   F  |   U  |   P  |  ;   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   S  |   H  |   T  |   G  | TAB  | ENTER|   Y  |   N  |   E  |   O  |  I   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   M  |   C  |   V  |LSHIFT|RSHIFT|   K  |   L  |   ,  |   .  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCTL | LGUI | LALT |  FN3 |  SYM |   SPC/NAV   | KEYP |  FN4 | RALT | RGUI | RCTL |
 * `-----------------------------------------------------------------------------------'
 */
[_WORKMAN] = KEYMAP_2U_SPACE_ORTHO(
    KC_Q,   KC_D,    KC_R,    KC_W,    KC_B,  KC_GESC, KC_BSPC, KC_J,  KC_F,   KC_U,    KC_P,    KC_SCLN ,
    KC_A,   KC_S,    KC_H,    KC_T,    KC_G,  KC_TAB,  C_ENT,   KC_Y,  KC_N,   KC_E,    KC_O,    KC_I    ,
    KC_Z,   KC_X,    KC_M,    KC_C,    KC_V,  KC_LSPO, KC_RSPC, KC_K,  KC_L,   KC_COMM, KC_DOT,  KC_SLSH ,
    C_ESC,  KC_LGUI, KC_LALT, KC_BSPC, LOWER,      SPCNAV,      RAISE, KC_DEL, KC_RALT, KC_RGUI, C_ENT   ),

/* ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |  {   |  }   |   $  |   #  |   @  |   !  |   ~  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   %  |   ^  |   &  |   *  |  [   |  ]   |   *  |   &  |   ^  |   %  |   `  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   =  |   +  |   -  |  (   |  )   |   -  |   +  |   =  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             | #### |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP_2U_SPACE_ORTHO(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_LCBR, KC_RCBR, KC_DLR,  KC_HASH, KC_AT,   KC_EXLM, KC_TILD ,
    KC_GRV,  KC_PERC, KC_AMPR, KC_ASTR, KC_UNDS, KC_LBRC, KC_RBRC, KC_UNDS, KC_ASTR, KC_AMPR, KC_PERC, KC_GRV  ,
    KC_BSLS, KC_CIRC, KC_EQL,  KC_PLUS, KC_MINS, KC_LSPO, KC_RSPC, KC_MINS, KC_PLUS, KC_EQL,  KC_CIRC, KC_BSLS ,
    ______,  ______,  ______,  ______,  ______,        ______,     __xx__,  ______,  ______,  ______,  ______  ),

/* ,-----------------------------------------------------------------------------------.
 * |  F9  |  F10 |  F11 |  F12 |      |VOL_UP|VOL_DW|      |  7   |  8   |  9   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F5  |  F6  |  F7  |  F8  |      | PREV | NEXT |      |  4   |  5   |  6   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |      | STOP | PLAY |      |  1   |  2   |  3   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | #### |             |      |  0   |  .   |ENTER |      |
 * `-----------------------------------------------------------------------------------'
 *
 *
 */
[_LOWER] = KEYMAP_2U_SPACE_ORTHO(
    KC_F9,  KC_F10, KC_F11, KC_F12, XXXXXX, KC_VOLU, KC_VOLD, XXXXXX, KC_7, KC_8,   KC_9,   XXXXXX,
    KC_F5,  KC_F6,  KC_F7,  KC_F8,  XXXXXX, KC_MPRV, KC_MNXT, XXXXXX, KC_4, KC_5,   KC_6,   XXXXXX,
    KC_F1,  KC_F2,  KC_F3,  KC_F4,  XXXXXX, KC_MSTP, KC_MPLY, XXXXXX, KC_1, KC_2,   KC_3,   XXXXXX,
    ______, ______, ______, ______, __xx__,      ______,      ______, KC_0, KC_DOT, KC_ENT, ______),

/* ,-----------------------------------------------------------------------------------.
 * |Accel0|MW_UP |M_BTN3|MW_DWN|      |      |      |      | HOME |  END |      | PASTE|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Accel1|M_BTN1| M_UP |M_BTN2|      |      |      | LEFT |  UP  | DOWN |RIGHT | COPY |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Accel2|M_LEFT|M_DOWN|M_RIGH|      |      |      |      | PG_UP|PG_DOW|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |QUERTY|      |      |      |      |     ###     |S+INS |      |      |      |WORKMA|
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = KEYMAP_2U_SPACE_ORTHO(
    KC_ACL0, KC_WH_U, KC_BTN3, KC_WH_D, XXXXXX, RGB_TOG, RGB_MOD, XXXXXX,  KC_HOME, KC_END,  XXXXXX,   KC_PASTE ,
    KC_ACL1, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXX, RGB_VAD, RGB_VAI, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_COPY  ,
    KC_ACL2, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXX, BL_TOGG, BL_INC,  XXXXXX,  KC_PGUP, KC_PGDN, XXXXXX,   XXXXXX   ,
    QWERTY,  ______,  ______,  ______,  ______,      __xx__,      S_INS,   ______,  ______,  ______,   WORKMAN  ),
};

/*
  template
  ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
  │    │    │    │    │    │    │    │    │    │    │    │    │
  ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
  │    │    │    │    │    │    │    │    │    │    │    │    │
  ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
  │    │    │    │    │    │    │    │    │    │    │    │    │
  ├────┼────┼────┼────┼────┼────┴────┼────┼────┼────┼────┼────┤
  │    │    │    │    │    │         │    │    │    │    │    │
  └────┴────┴────┴────┴────┴─────────┴────┴────┴────┴────┴────┘
 */
