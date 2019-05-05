#include QMK_KEYBOARD_H

enum miuni32_layers {
  _QWERTY,
  _WORKMAN,
  _NUMBERS,
  _SYMBOLS,
  _ADJUST
};

enum miuni32_keycodes {
  QWERTY = SAFE_RANGE,
  WORKMAN
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
     * ,---------------------------------------------------------------------------------------.
     * |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |  BSP  |
     * |---------------------------------------------------------------------------------------|
     * |   A   |   S   | ALT/D | CTL/F |   G   |   H   | CTL/J | ALT/K |   L   |SHF/SPC|   ;   |
     * |---------------------------------------------------------------------------------------|
     * | SHF/Z |   X   |   C   |   V   |LT(@|B)|LT(#|N)|   M   |   ,   |   .   |   /   |LT(A|↵)|
     * |---------------------------------------------------------------------------------------|
     */
  [_QWERTY] = LAYOUT_ortho_3x11(
    KC_Q,         KC_W, KC_E,         KC_R,         KC_T,               KC_Y,               KC_U,         KC_I,         KC_O,   KC_P,          KC_BSPC,
    KC_A,         KC_S, LALT_T(KC_D), LCTL_T(KC_F), KC_G,               KC_H,               RCTL_T(KC_J), RALT_T(KC_K), KC_L,   SFT_T(KC_SPC), KC_SCLN,
    SFT_T(KC_Z),  KC_X, KC_C,         KC_V,         LT(_SYMBOLS, KC_B), LT(_NUMBERS, KC_N), KC_M,        KC_COMM,      KC_DOT, KC_SLSH,       LT(_ADJUST, KC_ENT)
  ),
    /* Workman
     * ,---------------------------------------------------------------------------------------.
     * |   Q   |   D   |   R   |   W   |   B   |   J   |   F   |   U   |   P   |   ;   |  BSP  |
     * |---------------------------------------------------------------------------------------|
     * |   A   |   S   | ALT/H | CTL/T |   G   |   Y   | CTL/N | ALT/E |   O   |SHF/SPC|   I   |
     * |---------------------------------------------------------------------------------------|
     * | SHF/Z |   X   |   M   |   C   |LT(@|V)|LT(#|K)|   L   |   ,   |   .   |   /   |LT(A|↵)|
     * |---------------------------------------------------------------------------------------|
     */
  [_WORKMAN] = LAYOUT_ortho_3x11(
    KC_Q,        KC_D, KC_R,         KC_W,         KC_B, KC_J,                               KC_F,         KC_U,         KC_P,   KC_SCLN,       KC_BSPC,
    KC_A,        KC_S, LALT_T(KC_H), LCTL_T(KC_T), KC_G, KC_Y,                               RCTL_T(KC_N), RALT_T(KC_E), KC_O,   SFT_T(KC_SPC), KC_I,
    SFT_T(KC_Z), KC_X, KC_M,         KC_C,         LT(_SYMBOLS, KC_V),  LT(_NUMBERS,  KC_K), KC_L,         KC_COMM,      KC_DOT, KC_SLSH,       LT(_ADJUST, KC_ENT)
  ),
  /* Numbers Layer
     * ,---------------------------------------------------------------------------------------.
     * |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |  TRNS |
     * |---------------------------------------------------------------------------------------|
     * |  TAB  |   [   |   ]   |  ESC  |  TRNS |  TRNS |   -   |   =   |  TRNS |  TRNS |  TRNS |
     * |---------------------------------------------------------------------------------------|
     * |   \   |   `   |  GUI  |   #   |   /   |  TRNS |  TRNS |  TRNS |  TRNS |  TRNS |  TRNS |
     * |---------------------------------------------------------------------------------------|
     */
  [_NUMBERS] = LAYOUT_ortho_3x11(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_TAB,  KC_LBRC, KC_RBRC, KC_ESC,  _______, _______, KC_MINS, KC_EQL,  _______, _______, _______,
    KC_NUBS, KC_GRV,  KC_LGUI, KC_NUHS, KC_SLSH, _______, _______, _______, _______, _______, _______
  ),
  /* Symbols Layer
     * ,---------------------------------------------------------------------------------------.
     * |   !   |   "   |   £   |   $   |   %   |   ^   |   &   |   *   |   (   |   )   |  DEL  |
     * |---------------------------------------------------------------------------------------|
     * |  TRNS |  TRNS |  TRNS |  TRNS |  TRNS |  TRNS |   _   |   +   |   {   |   }   |   '   |
     * |---------------------------------------------------------------------------------------|
     * |  TRNS |  TRNS |  TRNS |  TRNS |  TRNS |  TRNS |  TRNS |   |   |   ¬   |   ~   |   @   |
     * |---------------------------------------------------------------------------------------|
     */
  [_SYMBOLS] = LAYOUT_ortho_3x11(
    KC_EXLM, LSFT(KC_2), LSFT(KC_3), KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,       KC_LPRN,      KC_RPRN,       KC_DEL,
    _______, _______,    _______,    _______, _______, _______, KC_UNDS, KC_PLUS,       KC_LCBR,      KC_RCBR,       KC_QUOT,
    _______, _______,    _______,    _______, _______, _______, _______, LSFT(KC_NUBS), LSFT(KC_GRV), LSFT(KC_TILD), LSFT(KC_QUOT)
  ),
  /* Level 3: RGB Layer
     * ,---------------------------------------------------------------------------------------.
     * | RESET |RGB_MOD|RGB_HUI|RGB_HUD|   NO  |   F1  |   F2  |   F3  |   F4  |   F5  |   F6  |
     * |---------------------------------------------------------------------------------------|
     * |RGB_TOG|  HOME |  PGUP |  PGDN |  END  |  LEFT |  DOWN |   UP  | RIGHT |WORKMAN| QWERTY|
     * |---------------------------------------------------------------------------------------|
     * |  CAPS |RGB_SAI|RGB_SAD|RGB_VAI|RGB_VAD|   F7  |   F8  |   F9  |  F10  |  F11  |  F12  |
     * |---------------------------------------------------------------------------------------|
     */
  [_ADJUST] = LAYOUT_ortho_3x11(
    RESET,   RGB_MOD, RGB_HUI, RGB_HUD, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,
    RGB_TOG, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, WORKMAN, QWERTY,
    KC_CAPS, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12
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
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case WORKMAN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WORKMAN);
      }
      return false;
      break;
  }
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
