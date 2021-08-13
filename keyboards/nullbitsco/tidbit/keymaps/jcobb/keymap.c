/* Copyright 2020 Jay Greco
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

#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "remote_kb.h"
#include "bitc_led.h"

#define _NUMPAD     0
#define _FUNC     1

enum custom_keycodes {
  PROG = SAFE_RANGE,
};

enum td_keycodes {
    TD_ENTER_LAYER
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for KP_ENTER, twice for _FUNC layer
    [TD_ENTER_LAYER] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_KP_ENTER, 1),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Base layer (numpad)
  [_NUMPAD] = LAYOUT(
           KC_NO,    KC_KP_ASTERISK, KC_KP_MINUS, \
  KC_KP_7, KC_KP_8,  KC_KP_9,        KC_KP_PLUS, \
  KC_KP_4, KC_KP_5,  KC_KP_6,        KC_NO, \
  KC_KP_1, KC_KP_2,  KC_KP_3,        TD(TD_ENTER_LAYER), \
  KC_NO,   KC_KP_0,  KC_KP_DOT,      KC_NO \
  ),
  // Function layer (numpad)
  [_FUNC] = LAYOUT(
           KC_NO, RGB_TOG, KC_NO,
    KC_NO, KC_NO, RGB_MOD, KC_NO,
    KC_NO, KC_NO, RGB_HUI, KC_NO,
    KC_NO, KC_NO, RGB_SAI, KC_NO,
    PROG,  KC_NO, RGB_VAI, TO(_NUMPAD)
  ),
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { 
  // return OLED_ROTATION_180; 
  return OLED_ROTATION_270;
}

// static void render_logo(void) {
//   static const char PROGMEM tidbit_oled[] = {
//     0x00, 0x0e, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
//     0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0e, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 
//     0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0x1f, 0x1f, 0x1f, 
//     0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x3e, 0x3e, 0x7e, 0xfc, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x00, 0x00, 
//     0x00, 0x00, 0x00, 0x00, 0xf8, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 
//     0x1f, 0x1f, 0x3f, 0x7e, 0xfe, 0xfe, 0xfc, 0xf8, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//     0xfe, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x0e, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 
//     0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1e, 0x00, 
//     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
//     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 
//     0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
//     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xc0, 
//     0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 
//     0xe0, 0xf0, 0xf0, 0xf8, 0xff, 0xff, 0xbf, 0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//     0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//     0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
//     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 
//     0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
//     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x03, 
//     0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
//     0x03, 0x03, 0x03, 0x07, 0x07, 0xbf, 0xff, 0xff, 0xff, 0xfe, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 
//     0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//     0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x7f, 0xff, 0xff, 0x7f, 0x3f, 
//     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 
//     0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xf8, 0xf8, 0xf8, 
//     0xf8, 0xf8, 0xf8, 0x7c, 0x7c, 0x7c, 0x7e, 0x3e, 0x3f, 0x3f, 0x1f, 0x0f, 0x07, 0x01, 0x00, 0x00, 
//     0x00, 0x00, 0x00, 0x00, 0x1f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 
//     0xf8, 0x7c, 0x7c, 0x7c, 0x7e, 0x3f, 0x3f, 0x1f, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
//     0x7f, 0xff, 0xff, 0x7f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//     0x00, 0x3f, 0x7f, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
// };
//     // Host Keyboard Layer Status
//     oled_write_raw_P(tidbit_oled, sizeof(tidbit_oled));
// }

static void print_status_narrow(void) {
    // Print current mode
    oled_set_cursor(0,0);
    oled_write("TIDBT",false);
    oled_set_cursor(0,1);
    oled_write("Cobb_",false);
    
    // Print current layer
    oled_set_cursor(0,5);
    oled_write("Layer", false);
    oled_set_cursor(0,6);

    switch (get_highest_layer(layer_state)) {
        case _NUMPAD:
            oled_write("NUMPD", false);
            break;
        case _FUNC:
            oled_write("FUNC ", false);
            break;
        default:
            oled_write("Undef", false);
    }
}

void oled_task_user(void) {
    // render_logo();
    print_status_narrow();
}
#endif

void matrix_init_user(void) {
  matrix_init_remote_kb();
  register_code(KC_NLCK);
}

void matrix_scan_user(void) {
  matrix_scan_remote_kb();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  process_record_remote_kb(keycode, record);

  switch(keycode) {
    case PROG:
      if (record->event.pressed) {
        set_bitc_LED(LED_DIM);
        rgblight_disable_noeeprom();
        bootloader_jump(); //jump to bootloader
      }
    break;

    default:
    break;
  }
  return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
    tap_code(KC_VOLU);
  } else {
    tap_code(KC_VOLD);
  } 
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _FUNC:
        unregister_code(KC_NLCK);
        break;
    default: //  for any other layers, or the default layer
        register_code(KC_NLCK);
        break;
    }
  return state;
}

void led_set_kb(uint8_t usb_led) {
  if (usb_led & (1<<USB_LED_NUM_LOCK))
    set_bitc_LED(LED_DIM);
  else
    set_bitc_LED(LED_OFF);
}