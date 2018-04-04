/*
This is the keymap for the keyboard
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2017 Art Ortenburger
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include "drashna.h"




//define layer change stuff for underglow indicator
bool skip_leds = false;



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 * 
 * 
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   = +  |  1 ! | 2 @  | 3 #  | 4 $  | 5 %  | TG(4)|           | TG(4)| 6 ^  | 7 &  |  8 * | 9 (  |  0 ) |  - _   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   TAB  |   Q  |   W  |   E  |   R  |   T  | TG(3)|           |TG(3) |   Y  |   U  |   I  |   O  |   P  |  \ |   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Bksp  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  ' "   |
 * |--------+------+------+------+------+------| TG(2)|           | TG(2)|------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  , < |  . > |  ? / | Shift  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | `/SYM|  ' " | LGUI |  [ { | ] }  |                                       | LEFT | DOWN |  UP  |RIGHT | SYMB |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,--------------.       ,--------------.
 *                                        |Alt/Ap|  Win  |       | Alt  |Ctl/Esc|
 *                                 ,------|------|-------|       |------+-------+------.
 *                                 |      |      | Home  |       | PgUp |       |      |
 *                                 | Space| Bksp |-------|       |------|  DEL  |Enter |
 *                                 |      |      | End   |       | PgDn |       |      |
 *                                 `---------------------'       `---------------------'
 */
  [_QWERTY] = LAYOUT_ergodox_wrapper(
                KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TG(_MOUS),
                KC_TAB,  _________________QWERTY_L1_________________, TG(_DIABLO),
                KC_BSPC, _________________QWERTY_L2_________________,
                KC_LSFT, _________________QWERTY_L3_________________, TG(_GAMEPAD),
       LT(_SYMB,KC_GRV), ___________ERGODOX_BOTTOM_LEFT_____________,
                
                                            ALT_T(KC_APP),   KC_LGUI,
                                                             KC_HOME,
                                           KC_SPACE,KC_BSPC, KC_END,
                                    
           TG(_MOUS),    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,   KC_MINS,
           TG(_DIABLO),  _________________QWERTY_R1_________________, KC_BSLS,
                         _________________QWERTY_R2_________________, GUI_T(KC_QUOT),
           TG(_GAMEPAD), _________________QWERTY_R3_________________, KC_RSFT,
                         ___________ERGODOX_BOTTOM_RIGHT____________, TT(_SYMB),
           KC_RGUI,      CTL_T(KC_ESCAPE),
           KC_PGUP,
           KC_PGDOWN,    KC_DELETE,  KC_ENTER
    ),
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   F  |   P  |   G  |  L1  |           |  L1  |   J  |   L  |   U  |   Y  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |O / L2|   '    |
 * |--------+------+------+------+------+------| OVER |           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_COLEMAK] = LAYOUT_ergodox_wrapper(  
        // left hand
                KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TG(_MOUS),
                KC_TAB,  _________________COLEMAK_L1________________, TG(_DIABLO),
                KC_BSPC, _________________COLEMAK_L2________________,
                KC_LSFT, _________________COLEMAK_L3________________, TG(_GAMEPAD),
       LT(_SYMB,KC_GRV), ___________ERGODOX_BOTTOM_LEFT_____________,
                                            ALT_T(KC_APP),   KC_LGUI,
                                                             KC_HOME,
                                           KC_SPACE,KC_BSPC, KC_END,
        // right hand
           TG(_MOUS),    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,   KC_MINS,
           TG(_DIABLO),  _________________COLEMAK_R1________________, KC_BSLS,
                         _________________COLEMAK_R2________________, GUI_T(KC_QUOT),
           TG(_GAMEPAD), _________________COLEMAK_R3________________, KC_RSFT,
                         ___________ERGODOX_BOTTOM_RIGHT____________, TT(_SYMB),
           KC_RGUI,      CTL_T(KC_ESCAPE),
           KC_PGUP,
           KC_PGDOWN,    KC_DELETE,  KC_ENTER
    ),
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   '  |   ,  |   .  |   P  |   Y  |  L1  |           |  L1  |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |S / L2|   -    |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |:/Ctrl|   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |Z/Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_DVORAK] = LAYOUT_ergodox_wrapper(  
        // left hand
                KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TG(_MOUS),
                KC_TAB,  _________________DVORAK_L1_________________, TG(_DIABLO),
                KC_BSPC, _________________DVORAK_L2_________________,
                KC_LSFT, _________________DVORAK_L3_________________, TG(_GAMEPAD),
       LT(_SYMB,KC_GRV), ___________ERGODOX_BOTTOM_LEFT_____________,
                                            ALT_T(KC_APP),   KC_LGUI,
                                                             KC_HOME,
                                           KC_SPACE,KC_BSPC, KC_END,
        // right hand
           TG(_MOUS),    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,   KC_BSLS,
           TG(_DIABLO),  _________________DVORAK_R1_________________, KC_SLSH,
                         _________________DVORAK_R2_________________, GUI_T(KC_MINS),
           TG(_GAMEPAD), _________________DVORAK_R3_________________, KC_RSFT,
                         ___________ERGODOX_BOTTOM_RIGHT____________, TT(_SYMB),
           KC_RGUI,      CTL_T(KC_ESCAPE),
           KC_PGUP,
           KC_PGDOWN,    KC_DELETE,  KC_ENTER
    ),
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   D  |   R  |   W  |   B  |  L1  |           |  L1  |   J  |   F  |   U  |   P  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   H  |   T  |   D  |------|           |------|   Y  |   N  |   E  |   O  |   I  |   '    |
 * |--------+------+------+------+------+------| OVER |           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   M  |   C  |   V  |      |           |      |   K  |   L  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_WORKMAN] = LAYOUT_ergodox_wrapper(  
        // left hand
                KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TG(_MOUS),
                KC_TAB,  _________________WORKMAN_L1________________, TG(_DIABLO),
                KC_BSPC, _________________WORKMAN_L2________________,
                KC_LSFT, _________________WORKMAN_L3________________, TG(_GAMEPAD),
       LT(_SYMB,KC_GRV), ___________ERGODOX_BOTTOM_LEFT_____________,
                                            ALT_T(KC_APP),   KC_LGUI,
                                                             KC_HOME,
                                           KC_SPACE,KC_BSPC, KC_END,
        // right hand
           TG(_MOUS),    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
           TG(_DIABLO),  _________________WORKMAN_R1________________, KC_BSLS,
                         _________________WORKMAN_R2________________, GUI_T(KC_QUOT),
           TG(_GAMEPAD), _________________WORKMAN_R3________________, KC_RSFT,
                         ___________ERGODOX_BOTTOM_RIGHT____________, TT(_SYMB),
           KC_RGUI,      CTL_T(KC_ESCAPE),
           KC_PGUP,
           KC_PGDOWN,    KC_DELETE,  KC_ENTER
    ),

  [_MODS] = LAYOUT_ergodox(
                KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,      KC_TRNS,      KC_TRNS,
                KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,      KC_TRNS,      KC_TRNS,
                KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,      KC_TRNS,
                OSM(MOD_LSFT),KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,      KC_TRNS,      KC_TRNS,
                KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                                                KC_TRNS,      KC_TRNS,
                                                                                              KC_TRNS,
                                                                  KC_TRNS,      KC_TRNS,      KC_TRNS,
                
                KC_TRNS,    KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
                KC_TRNS,    KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
                            KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
                KC_TRNS,    KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      OSM(MOD_RSFT),
                                          KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
                KC_TRNS,    KC_TRNS,
                KC_TRNS,
                KC_TRNS,    KC_TRNS,      KC_TRNS
            ),

    /* Keymap 3: Symbol Layer
*
* ,--------------------------------------------------.           ,--------------------------------------------------.
* |   ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |   F11  |
* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
* | VERSION|   !  |   @  |  {   |   }  |  |   |      |           |      |  +   |   7  |   8  |   9  |  *   |   F12  |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |  MAKE  |   #  |   $  |  (   |   )  |  `   |------|           |------|  -   |   4  |   5  |   6  |  /   | PrtSc  |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |  RESET |   %  |   ^  |  [   |   ]  |  ~   |      |           |      | NUM  |   1  |   2  |   3  |  =   |  PAUSE |
* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   |  LT0 |   &  |   *  |  :   |   ;  |                                       |      |   0  | NUM. | ENT  |  ENT |
*   `----------------------------------'                                       `----------------------------------'
*                                        ,-------------.       ,-------------.
*                                        | RGBM | RED  |       | OFF  | SOLID|
*                                 ,------|------|------|       |------+------+------.
*                                 |      |      | GREEN|       |      |      |      |
*                                 | RGB  | RGB  |------|       |------| NUM0 | NUME |
*                                 | DARK |BRITE | BLUE |       |      |      |      |
*                                 `--------------------'       `--------------------'
*/
  [_SYMB] = LAYOUT_ergodox(
                EPRM,           KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      TG(_MODS),
                VRSN,           KC_EXLM,    KC_AT,      KC_LCBR,    KC_RCBR,    KC_PIPE,    KC_WORKMAN,
                KC_MAKE,        KC_HASH,    KC_DLR,     KC_LPRN,    KC_RPRN,    KC_GRAVE,
                KC_RESET,       KC_PERC,    KC_CIRC,    KC_LBRACKET,KC_RBRACKET,KC_TILD,    KC_COLEMAK,
                KC_TRNS,        KC_AMPR,    KC_ASTR,    KC_COLN,    KC_SCOLON,
                                                                  RGB_SMOD, KC_RGB_T,
                                                                  RGB_HUI,
                                                                  RGB_M_R, RGB_M_SW, RGB_HUD,
                
                KC_QWERTY,   KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,         KC_F11,
                KC_DVORAK,   KC_KP_PLUS, KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_KP_ASTERISK, KC_F12,
                             KC_KP_MINUS,KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_KP_SLASH,    KC_PSCREEN,
                KC_COLEMAK,  KC_NUMLOCK, KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_EQUAL,       KC_PAUSE,
                                         KC_KP_0,    KC_KP_0,    KC_KP_DOT,  KC_KP_ENTER,    KC_TRNS,
                KC_TRNS,    KC_TRNS,
                KC_TRNS,
                KC_KP_DOT, KC_KP_0, KC_KP_ENTER
            ),

/* Keymap 4: Customized Overwatch Layout
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |      |      |      |      |      |      |           |      |  F9  | F10  | F11  |  F12 |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   F1   |  K   |  Q   |  W   |  E   |  R   |  T   |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   TAB  |  G   |  A   |  S   |  D   |  F   |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LCTR  | LSHFT|  Z   |  X   |  C   |  V   |      |           |      |   N  |  M   |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |   J  |  U   |  I   |  Y   |  T   |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  O   |  P   |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LGUI |       |      |      |      |
 *                                 |  V   | SPACE|------        |------|      | Enter|
 *                                 |      |      |  H   |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [_GAMEPAD] = LAYOUT_ergodox(
                KC_ESCAPE,      KC_TRNS,    KC_TRNS,    KC_TRNS,    HYPR(KC_D), HYPR(KC_Q), HYPR(KC_GRV),
                KC_F1,          KC_K,       KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,
                KC_TAB,         KC_G,       KC_A,       KC_S,       KC_D,       KC_F,
                KC_LCTL,        KC_LSHIFT,  KC_Z,       KC_X,       KC_C,       KC_V,       KC_TRNS,
                KC_G,           KC_U,       KC_I,       KC_Y,       KC_T,
                                            KC_O,   KC_P,
                                                    KC_LGUI,
                                KC_V,   KC_SPACE,   KC_H,
                                    
                KC_TRNS,        KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_NO,      KC_NO,
                KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                KC_I,       KC_O,       KC_NO,      KC_NO,      KC_NO,      KC_NO,
                TG(_GAMEPAD),   KC_N,       KC_M,       KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                            KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,      KC_NO,
                KC_HYPR,         MAGIC_TOGGLE_NKRO,
                KC_NO,
                KC_PGDOWN,      KC_DELETE, KC_ENTER
            ),

/* Keymap 3:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |  V   |  D   | ALT  |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   TAB  |  S   |  I   |  F   |  M   |  T   |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    Q   |  1   |  2   |  3   |  4   |  G   |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | NUMLOCK| NUM1 | NUM2 | NUM3 | NUM4 |  Z   |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCTL | MAC1 | MAC2 | MAC3 | MAC4 |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |   L  |  J   |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  G   |       |      |      |      |
 *                                 | SPACE|  Q   |------        |------|      |      |
 *                                 | SHIFT| ALT  | 0MAC |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [_DIABLO] = LAYOUT_ergodox(
                KC_ESCAPE,  KC_V,       KC_D,       KC_LALT,    KC_NO,      KC_NO,      KC_NO,
                KC_TAB,     KC_S,       KC_I,       KC_F,       KC_M,       KC_T,       KC_TRNS,
                KC_Q,       KC_1,       KC_2,       KC_3,       KC_4,       KC_G,
                KC_LCTL,    KC_D3_1,    KC_D3_2,    KC_D3_3,    KC_D3_4, KC_Z,       KC_NO,
                KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                                KC_L,   KC_J,
                                                        KC_F,
                    SFT_T(KC_SPACE),    ALT_T(KC_Q),    KC_DIABLO_CLEAR,
                                    
                                    
                                    
                KC_TRNS,        KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_NO,      KC_NO,
                KC_TRNS,        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                KC_NO,          KC_N,       KC_M,       KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                            KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                KC_NO,          KC_NO,
                KC_NO,
                KC_PGDOWN,      KC_DELETE, KC_ENTER
            ),

/* Keymap 4: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | MsUp |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |MsLeft|MsDown|MsRght|      |      |------|           |------|      |      | Acc0 | Acc1 | Acc2 |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Acc0 | Acc1 | Acc2 |      |      |      |           |      |      | Mute |VolDn |VolUp |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Play | Stop |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | MWUp |       |      |      |      |
 *                                 | Lclk | Rclk |------|       |------| MBn4 | MBn5 |
 *                                 |      |      | MWDn |       | Mclk |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [_MOUS] = LAYOUT_ergodox(
                KC_NO,      KC_SECRET_1,KC_SECRET_2,KC_SECRET_3,KC_SECRET_4,KC_SECRET_5,KC_TRNS,
                KC_NO,      KC_NO,      KC_MS_U,    KC_NO,      KC_NO,      KC_NO,      KC_TRNS,
                KC_NO,      KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_NO,      KC_NO,
                KC_NO,      KC_ACL0,    KC_ACL1,    KC_ACL2,    KC_NO,      KC_NO,      KC_TRNS,
                KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                                                            KC_NO,      KC_NO,
                                                                                        KC_WH_U,
                                                                KC_BTN1,    KC_BTN2,    KC_WH_D,
                
                KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                            KC_NO,      KC_ACL0,    KC_ACL1,    KC_ACL2,    KC_NO,      KC_NO,
                KC_TRNS,    KC_NO,      KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_NO,      KC_NO,
                                        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                KC_NO,KC_NO,
                KC_NO,
                KC_MS_BTN3,KC_MS_BTN4,KC_MS_BTN5
            ),

};



bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}


void matrix_init_keymap(void) { // Runs boot tasks for keyboard
};


void matrix_scan_keymap(void) {  // runs frequently to update info
  uint8_t modifiders = get_mods();

  if (!skip_leds) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    // Since we're not using the LEDs here for layer indication anymore,
    // then lets use them for modifier indicators.  Shame we don't have 4...
    // Also, no "else", since we want to know each, independantly. 
    if (modifiders & MODS_SHIFT_MASK) {
      ergodox_right_led_2_on();
    }
    if (modifiders & MODS_CTRL_MASK) {
      ergodox_right_led_1_on();
    }
    if (modifiders & MODS_ALT_MASK) {
      ergodox_right_led_3_on();
    }

  }

};

