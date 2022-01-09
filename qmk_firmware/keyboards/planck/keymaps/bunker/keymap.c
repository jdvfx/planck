/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


/* Removed Colemak, Dvorak, Plover - also removed any keymap to switch between them and Qwerty
 * home,end,pageUp,pageDown are on the arrows with either raise/lower keys
 * (){}[] are on the same layer (lower+opl;./)
 * raise+jkl maps to -=+ for easy increment/decrement += -=
 * \ is on the same key as / (with raise)
 * _ is in the same key as - (lower+j raise+j)
 */

#include QMK_KEYBOARD_H

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
};


enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * | Del  | Ctrl | GUI  | Alt  |Lower |    Space    |Raise | Left | Down | Up   |Right |
 */
[_BASE] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_DEL,  KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
/* Lower
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * | Bksp |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |   [  |   ]  |      |
 * |Leader|      |      |      |      |             |      | Home |Pg Dn |Pg Up | End  |
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    KC_BSPC, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,    _______,    KC_LBRC, KC_RBRC, _______,
    KC_LEAD, _______, _______, _______, _______, _______, _______, _______,    KC_HOME,    KC_PGDN, KC_PGUP, KC_END
),
/* Raise
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |      |      |      |      |      |      |      |   -  |   +  |   =  |      |   "  |
 * |      |      |      |      |      |      |      |      |      |      |  \   |      |
 * |Pr_Scn|      |      |      |      |             |      | Home |Pg Dn |Pg Up | End  |
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_PLUS, KC_EQL,  _______, KC_DQUO,
    _______, _______, _______, _______, _______, KC_MS_U, KC_MS_D, KC_WH_D, KC_WH_U, _______, KC_BSLS, _______,
    KC_PSCR, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),
/* Adjust (Lower + Raise)
 * |      | Reset|Debug | RGB  |RGBMOD|      |      |      |      |HUE+  |HUE-  |      |
 * |      |      |      |      |      |      |      |      |      |SAT + |SAT-  |      |
 * |      |      |      |      |      |      |TermOn|TermOf|BRGTH+|BRGTH-|      |      |
 * |      |      |      |      |      |      |      |      |     |       |      |      |
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, _______, _______, _______, _______,  RGB_HUI, RGB_HUD, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  RGB_SAI, RGB_SAD, _______,
    _______, _______, _______, _______, _______, _______, _______,  TERM_ON, TERM_OFF, RGB_VAI, RGB_VAD, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};


// >> turn on layer _ADJUST if _LOWER and _RAISE are both pressed
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


/*
// >> LEADER KEY STUFF
//
LEADER_EXTERNS();

void matrix_scan_user(void) {

 LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_Q) {
      // Anything you can do in a macro.
      SEND_STRING("QMK is awesome.");
    }
    SEQ_TWO_KEYS(KC_D, KC_D) {
      SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    }
    SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
      SEND_STRING("https://start.duckduckgo.com\n");
    }
  }
}
*/

// >> COMBOS
//
enum combo_events {
  BSPC_P_CLEAR,
  SCLN_QUOT_CLEARWORD,
  LOWER_ALT_CLEARWORD,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM clear_line_combo[] = {KC_BSPC, KC_P, COMBO_END};
const uint16_t PROGMEM clear_word_combo[] = {KC_SCLN, KC_QUOT, COMBO_END};
const uint16_t PROGMEM clear_word_combo2[] = {LOWER, KC_LALT, COMBO_END};


combo_t key_combos[] = {
  [BSPC_P_CLEAR] = COMBO_ACTION(clear_line_combo),
  [SCLN_QUOT_CLEARWORD] = COMBO_ACTION(clear_word_combo),
  [LOWER_ALT_CLEARWORD] = COMBO_ACTION(clear_word_combo2),
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case BSPC_P_CLEAR:
      if (pressed) {
        tap_code16(KC_END);
        tap_code16(S(KC_HOME));
        tap_code16(KC_BSPC);
      }
      break;
    case SCLN_QUOT_CLEARWORD:
      if (pressed) {
        tap_code16(LCTL(KC_LEFT));
        tap_code16(LCTL(KC_DEL));
      }
      break;
    case LOWER_ALT_CLEARWORD:
      if (pressed) {
        tap_code16(LCTL(KC_LEFT));
        tap_code16(LCTL(KC_DEL));
      }
      break;
  }
}


