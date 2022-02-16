 /* Copyright 2021 Studio Kestra
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

// Forked from studiokestra/galatea/keymaps/default by f-eq-ma

// Combined with https://github.com/f-eq-ma/xd87
// Layer0
//   pause -> F16 (AHK controlled - iTunes Mute)
//   scroll lock -> F17 (AHK controlled - iTunes minimize player)
//   print screen -> F19 (AHK controlled - iTunes Next)
// Layer1
//   pause -> KC_VOLD
//   scroll lock -> KC_VOLU
//   print screen -> F14 (AHK controlled - iTunes Back)
//
// Tap Dance:
// F9 -> f9 | (CWXTITVAL-)
// F10 -> f10 | {noformat}
//

  
#include QMK_KEYBOARD_H

enum {
  TD_F10_NOFORMAT,
  TD_F9_CWXTITVAL
};

void td_f10_noformat_func(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 1) {
		register_code16(KC_F10);
		unregister_code16(KC_F10);
	} else {
		SEND_STRING("{noformat}");
		reset_tap_dance(state);
	}
}

void td_f9_cwxtitval_func(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 1) {
		register_code16(KC_F9);
		unregister_code16(KC_F9);
	} else {
		SEND_STRING(" (CWXTITVAL-)");
		reset_tap_dance(state);
	}
}

//Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_F9_CWXTITVAL] = ACTION_TAP_DANCE_FN(td_f9_cwxtitval_func),
	[TD_F10_NOFORMAT] = ACTION_TAP_DANCE_FN(td_f10_noformat_func)
}; // comment



// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { 

    [_BASE] = LAYOUT_all(
    KC_ESC,  KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   TD(TD_F9_CWXTITVAL), TD(TD_F10_NOFORMAT),   KC_F11,   KC_F12,      KC_F16, KC_F17, KC_F19,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_BSPC,                 KC_INS,  KC_HOME, KC_PGUP,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,                           KC_DEL,  KC_END,  KC_PGDN,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_ENT,     
    KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,    MO(1),                                      KC_UP,          
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,           KC_RALT,          MO(1),  KC_APP,   KC_RCTRL,                                       KC_LEFT, KC_DOWN, KC_RIGHT ),

    [_FN] = LAYOUT_all(
    RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_VOLD, KC_VOLU, KC_F14, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                       
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                        KC_TRNS,            
    KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS ),
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

