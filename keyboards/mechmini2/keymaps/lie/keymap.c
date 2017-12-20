/*
 *
 */
#include "kb.h"

// Layers
#define _QWERTY  0
#define _COLEMAK 1
#define _RAISE   2
#define _LOWER   3
#define _NAV     4

// Empty keys
#define ______ KC_TRNS
#define __xx__ KC_TRNS
#define XXXXXX KC_NO


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
#define COLEMAK TO(_COLEMAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |      |      |   Y  |   U  |   I  |   O  |   P  |
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
 * |   Q  |   W  |   F  |   P  |   G  | CANC | BKSP |   J  |   L  |   U  |   Y  |  L   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   D  | TAB  | ENTER|   H  |   N  |   E  |   I  |  S   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |LSHIFT|RSHIFT|   K  |   M  |   ,  |   .  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCTL | LGUI | LALT |  FN3 |  SYM |   SPC/NAV   | KEYP |  FN4 | RALT | RGUI | RCTL |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = KEYMAP_2U_SPACE_ORTHO(
    KC_Q,    KC_W,    KC_F,    KC_P,   KC_G,  KC_GESC, KC_BSPC, KC_J,  KC_L,  KC_U,    KC_Y,    KC_SCLN ,
    KC_A,    KC_S,    KC_D,    KC_F,   KC_G,  KC_TAB,  C_ENT,   KC_H,  KC_J,  KC_K,    KC_L,    KC_O    ,
    KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,  KC_LSPO, KC_RSPC, KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH ,
    KC_LCTL, KC_LGUI, KC_LALT, KC_ESC, LOWER,      SPCNAV,      RAISE, C_ENT, KC_RALT, KC_RGUI, KC_RCTL  ),

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
    ______,  ______,  KC_EQL,  KC_PLUS, KC_MINS, KC_LSPO, KC_RSPC, KC_MINS, KC_PLUS, KC_EQL,  ______,  ______  ,
    ______,  ______,  ______,  ______,  ______,        ______,     __xx__,  ______,  ______,  ______,  ______  ),

/* ,-----------------------------------------------------------------------------------.
 * |  F9  |  F10 |  F11 |  F12 |      |VOL_UP|VOL_DW|  {   |  7   |  8   |  9   |  }   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F5  |  F6  |  F7  |  F8  |      | PREV | NEXT |  [   |  4   |  5   |  6   |  ]   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |      | STOP | PLAY |  (   |  1   |  2   |  3   |  )   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | #### |             |      |  0   |  .   |ENTER |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP_2U_SPACE_ORTHO(
    KC_F9,  KC_F10, KC_F11, KC_F12, ______, KC_VOLU, KC_VOLD, KC_LCBR, KC_7, KC_8,   KC_9,   KC_RCBR ,
    KC_F5,  KC_F6,  KC_F7,  KC_F8,  ______, KC_MPRV, KC_MNXT, KC_LBRC, KC_4, KC_5,   KC_6,   KC_RBRC ,
    KC_F1,  KC_F2,  KC_F3,  KC_F4,  ______, KC_MSTP, KC_MPLY, KC_LSPO, KC_1, KC_2,   KC_3,   KC_RSPC ,
    ______, ______, ______, ______, __xx__,      ______,      ______,  KC_0, KC_DOT, KC_ENT, ______  ),

/* ,-----------------------------------------------------------------------------------.
 * |Accel0|MW_UP |M_BTN3|MW_DWN|      |      |      |      | HOME |  END |      | PASTE|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Accel1|M_BTN1| M_UP |M_BTN2|      |      |      | LEFT |  UP  | DOWN |RIGHT | COPY |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Accel2|M_LEFT|M_DOWN|M_RIGH|      |      |      |      | PG_UP|PG_DOW|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |QUERTY|COLEMK|      |      |      |     ###     |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = KEYMAP_2U_SPACE_ORTHO(
    KC_ACL0, KC_WH_U, KC_BTN3, KC_WH_D, ______, RGB_TOG, RGB_MOD, ______,  KC_HOME, KC_END,  ______,   KC_PASTE ,
    KC_ACL1, KC_BTN1, KC_MS_U, KC_BTN2, ______, RGB_VAD, RGB_VAI, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_COPY  ,
    KC_ACL2, KC_MS_L, KC_MS_D, KC_MS_R, ______, BL_TOGG, BL_INC,  ______,  KC_PGUP, KC_PGDN, ______,   ______   ,
    QWERTY,  COLEMAK, ______,  ______,  ______,      __xx__,      ______,  ______,  ______,  ______,   ______   ),
};
