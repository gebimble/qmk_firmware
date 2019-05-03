#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Level 0: Default Layer
     * ,---------------------------------------------------------------------------------------.
     * |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |  BSP  |
     * |---------------------------------------------------------------------------------------|
     * |LT(2|A)|   S   | ALT/D | CTL/F |   G   |   H   | CTL/J | ALT/K |   L   |SPC/SHF|LT(1|;)|
     * |---------------------------------------------------------------------------------------|
     * |LT(3|Z)|   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   |  ENT  |
     * |---------------------------------------------------------------------------------------|
     */
  [0] = LAYOUT_ortho_3x11(
    KC_Q,        KC_W, KC_E,       KC_R,       KC_T, KC_Y, KC_U,       KC_I,       KC_O,    KC_P,          KC_BSPC,
    LT(2, KC_A), KC_S, LALT(KC_D), LCTL(KC_F), KC_G, KC_H, RCTL(KC_J), RALT(KC_K), KC_L,    SFT_T(KC_SPC), LT(1, KC_SCLN),
    LT(3, KC_Z), KC_X, KC_C,       KC_V,       KC_B, KC_N, KC_M,       KC_COMM,    KC_DOT,  KC_SLSH,       KC_ENT)
  ),
  /* Level 1: Numbers Layer
     * ,---------------------------------------------------------------------------------------.
     * |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |  DEL  |
     * |---------------------------------------------------------------------------------------|
     * |  TAB  |   {   |   }   |   [   |   ]   |  TRNS |   -   |   =   |  TRNS |  TRNS |  TRNS |
     * |---------------------------------------------------------------------------------------|
     * |   \   |   `   |  GUI  |  TRNS |  TRNS |  TRNS |  TRNS |  TRNS |  TRNS |   #   |   /   |
     * |---------------------------------------------------------------------------------------|
     */
  [1] = LAYOUT_ortho_3x11(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_DEL,
    KC_TAB,  KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______, KC_MINS, KC_EQL,  _______, _______, _______,
    KC_NUBS, KC_GRV,  KC_LGUI, _______, _______, _______, _______, _______, _______, KC_NUHS, KC_SLSH
  ),
  /* Level 2: Symbols Layer
     * ,---------------------------------------------------------------------------------------.
     * |   !   |   "   |   £   |   $   |   %   |   ^   |   &   |   *   |   -   |   +   |   =   |
     * |---------------------------------------------------------------------------------------|
     * |   {   |   }   |   [   |   ]   |  TRNS |  TRNS |   \   |   #   |   _   |   `   |   ?   |
     * |---------------------------------------------------------------------------------------|
     * |  LSFT |  LCTL |   L   |   T   |       |  TAB  |   N   |  TRNS |  TRNS |  RCTL |  TRNS |
     * |---------------------------------------------------------------------------------------|
     */
  [2] = LAYOUT_ortho_3x11(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS, KC_EQL,
    KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______, _______, KC_NUBS, KC_NUHS, KC_UNDS, KC_GRV,  KC_QUOT,
    KC_LSFT, KC_LCTL, KC_L,    KC_T,    _______, KC_TAB,  KC_N,    _______, _______, KC_RCTL, _______
  ),
  /* Level 3: RGB Layer
     * ,---------------------------------------------------------------------------------------.
     * | RESET |  TRNS |  TRNS |  TRNS |  TRNS |   F1  |   F2  |   F3  |   F4  |   F5  |   F6  |
     * |---------------------------------------------------------------------------------------|
     * |RGB_TOG|RGB_MOD|RGB_HUI|RGB_HUD|   NO  |RGB_SAI|RGB_SAD|RGB_VAI|RGB_VAD|  TRNS |  TRNS |
     * |---------------------------------------------------------------------------------------|
     * |  CAPS |  TRNS |  TRNS |  TRNS |       |   F7  |   F8  |   F9  |  F10  |  F11  |  F12  |
     * |---------------------------------------------------------------------------------------|
     */
  [3] = LAYOUT_ortho_3x11(
    RESET,   _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, KC_NO,   RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______,
    KC_CAPS, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12
  )
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

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

  if (usb_led & (1 << USB_LED_NUM_LOCK)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_COMPOSE)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_KANA)) {

  } else {

  }

}
