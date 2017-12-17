/*
 *
 */
#include "kb.h"

enum layer_names {
  _QWERTY = 0,
  _RAISE,
  _LOWER,
  _NAV,
};

#define ______ KC_TRNS
#define __xx__ KC_TRNS
#define XXXXXX KC_NO

#define C_LCTL MT(MOD_LCTL, KC_LEFT_CURLY_BRACE) // Curly braces
#define C_RCTL MT(MOD_RCTL, KC_RIGHT_CURLY_BRACE)

#define C_LGUI MT(MOD_LGUI, KC_LBRACKET) // Brackets
#define C_RGUI MT(MOD_RGUI, KC_RBRACKET)

#define C_LALT MT(MOD_LGUI, KC_LEFT_PAREN) // Paren
#define C_RALT MT(MOD_RGUI, KC_RIGHT_PAREN)

#define C_ESC MT(MOD_LCTL, KC_ESC) // Esc, LCtrl
#define C_ENT MT(MOD_RCTL, KC_ENT) // Enter, RCtl

#define SPCNAV LT(_NAV, KC_SPC) // Space, layer NAV

#define C_SSCLN SFT_T(KC_SCOLON) //
#define C_SSLSH SFT_T(KC_SLASH)
#define C_SZED  SFT_T(KC_Z)
#define C_AENT  ALT_T(KC_ENT)
#define C_ESCTL CTL_T(KC_ESC)
#define TABALT  ALT_T(KC_TAB)

#define RAISE  MO(_RAISE)
#define LOWER  MO(_LOWER)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  | CANC | BKSP |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  | TAB  |  '   |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |LSHIFT|RSHIFT|   N  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCTL | META | LALT |  ESC |LOWER |   SPC/NAV   | RAISE| ENTER| RALT | META | RCTL |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP_2U_SPACE_ORTHO(
    KC_Q,   KC_W,   KC_E,   KC_R,    KC_T,  KC_DEL,  KC_BSPC, KC_Y,  KC_U,  KC_I,    KC_O,   KC_P    ,
    KC_A,   KC_S,   KC_D,   KC_F,    KC_G,  KC_TAB,  C_ENT,   KC_H,  KC_J,  KC_K,    KC_L,   KC_SCLN ,
    KC_Z,   KC_X,   KC_C,   KC_V,    KC_B,  KC_LSPO, KC_RSPC, KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH ,
    C_LCTL, C_LGUI, C_LALT, KC_GESC, LOWER,      SPCNAV,      RAISE, C_ENT, C_RALT,  C_RGUI, C_RCTL  ),

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
 * |  F9  |  F10 |  F11 |  F12 |      |      |      |      |  7   |  8   |  9   |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F5  |  F6  |  F7  |  F8  |      |      |      |      |  4   |  5   |  6   |  *   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |      |      |      |      |  1   |  2   |  3   |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | #### |             |      |  0   |  .   |ENTER |  +   |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP_2U_SPACE_ORTHO(
    KC_F9,  KC_F10, KC_F11, KC_F12, ______, KC_VOLU, KC_VOLD, ______, KC_P7, KC_P8,   KC_P9,   KC_PSLS ,
    KC_F5,  KC_F6,  KC_F7,  KC_F8,  ______, KC_MPRV, KC_MNXT, ______, KC_P4, KC_P5,   KC_P6,   KC_PAST ,
    KC_F1,  KC_F2,  KC_F3,  KC_F4,  ______, KC_MSTP, KC_MPLY, ______, KC_P1, KC_P2,   KC_P3,   KC_PMNS ,
    ______, ______, ______, ______, __xx__,      ______,      ______, KC_P0, KC_PDOT, KC_PENT, KC_PPLS ),

/* ,-----------------------------------------------------------------------------------.
 * |Accel0|MW_UP |M_BTN3|MW_DWN|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Accel1|M_BTN1| M_UP |M_BTN2|      |      |      | LEFT |  UP  | DOWN |RIGHT |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Accel2|M_LEFT|M_DOWN|M_RIGH|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |     ###     |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = KEYMAP_2U_SPACE_ORTHO(
    KC_ACL0, KC_WH_U, KC_BTN3, KC_WH_D, ______, RGB_TOG, RGB_MOD, ______,  KC_HOME, KC_END,  ______,   KC_PASTE ,
    KC_ACL1, KC_BTN1, KC_MS_U, KC_BTN2, ______, RGB_VAD, RGB_VAI, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_COPY  ,
    KC_ACL2, KC_MS_L, KC_MS_D, KC_MS_R, ______, BL_TOGG, BL_INC,  ______,  KC_PGUP, KC_PGDN, ______,   ______   ,
    ______,  ______,  ______,  ______,  ______,      __xx__,      ______,  ______,  ______,  ______,   ______   ),
};


/*
 * Sample COLEMAK layer
 *
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   F  |   P  |   G  | CANC | BKSP |   J  |   L  |   U  |   Y  |   L  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   D  | TAB  | ENTER|   H  |   N  |   E  |   I  |   S  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |SFT/ Z|   X  |   C  |   V  |   B  |LSHIFT|RSHIFT|   K  |   M  |   ,  |   .  |SFT/ /|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCTL | LGUI |LALT [|  FN3 |  SYM |   SPC/NAV   | KEYP |  FN4 |] RALT| RGUI | RCTL |
 * `-----------------------------------------------------------------------------------'
 */
/*
[_COLEMAK] = KEYMAP_2U_SPACE_ORTHO(
    KC_Q,   KC_W,   KC_F,   KC_P,  KC_G,  KC_GESC, KC_BSPC, KC_J,  KC_L,  KC_U,    KC_Y,   KC_SCLN ,
    KC_A,   KC_S,   KC_D,   KC_F,  KC_G,  KC_TAB,  C_ENT,   KC_H,  KC_J,  KC_K,    KC_L,   KC_O    ,
    KC_Z,   KC_X,   KC_C,   KC_V,  KC_B,  KC_LSPO, KC_RSPC, KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH ,
    C_LCTL, C_LGUI, C_LALT, MO(3), MO(1),      C_SPC,       MO(2), MO(4), C_RALT,  C_RGUI, C_RCTL  ),
*/
