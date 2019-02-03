#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

enum {
    TD_SPC_ENT = 0,
    TD_BSPC_DEL,
    TD_J_CTL_ESC,
    TD_SFT_TAB_CAP,
};

// Tap Dance Definitions
//qk_tap_dance_action_t tap_dance_actions[] = {
    //Tap once for space, twice for enter
    /*[TD_SPC_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),*/
    //Tap once for backspace, twice for delete
    /*[TD_BSPC_DEL] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_DEL),*/
    //Tap once for J, hold for right control, tap twice for Esc
    /*[TD_J_CTL_ESC] = ACTION_TAP_DANCE_DOUBLE(MOD_RCTL(KC_J), KC_ESC),*/
    //Tap once for tab, hold for left shift, tap twice for capslock
    /*[TD_SFT_TAB_CAP] = ACTION_TAP_DANCE_DOUBLE(MOD_LSFT(KC_TAB), KC_CAPS),*/
//};

/*typedef struct { bool is_press_action; int state; } tap;*/
/*int cur_dance(qk_tap_dance_state_t *state) {*/
    /*if (state->count == 1) {*/
        /*if (state->interrupted || state->pressed == 0)*/
            /*return SINGLE_TAP;*/
        /*else*/
            /*return SINGLE_HOLD; }*/
    /*else if (state->count == 2) {*/
        /*if (state->interrupted)*/
            /*return DOUBLE_SINGLE_TAP;*/
        /*else if (state->pressed)*/
            /*return DOUBLE_HOLD;*/
        /*else*/
            /*return DOUBLE_TAP;*/
    /*}*/
    /*if (state->count == 3) {*/
        /*if (state->interrupted || !state->pressed)*/
            /*return TRIPLE_TAP;*/
        /*else*/
            /*return TRIPLE_HOLD;*/
    /*}*/
/*}*/
/*else*/
/*return 8;*/

// Tap for space, hold for shift, double tap for enter.
/*static tap CUSTOM_state = { .is_press_action = true, .state = 0 };*/
/*void CUSTOM_finished(qk_tap_dance_state_t *state, void *user_data) { CUSTOM_state.state = cur_dance(state); switch (CUSTOM_state.state) { case SINGLE_TAP: register_code(KC_SPC); break; case SINGLE_HOLD: register_code(KC_LSFT); break; case DOUBLE_TAP: register_code(KC_ENT); break; } }*/
/*void CUSTOM_reset(qk_tap_dance_state_t *state, void *user_data) { switch (CUSTOM_state.state) { case SINGLE_TAP: unregister_code(KC_SPC); break; case SINGLE_HOLD: unregister_code(KC_LSFT); break; case DOUBLE_TAP: unregister_code(KC_ENT); break; } LSCP_state.state = 0; }*/
/*[CUSTOM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CUSTOM_finished, CUSTOM_reset) */

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |alt/D |ctrl/F|   G  |           |   H  |ctrl/J|alt/K |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | Shift| LOWER|      |    |      | RAISE| BSPC |
 *                  `-------------|shf/tb|    |Space |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_QWERTY] = LAYOUT( \
  KC_Q,    KC_W,              KC_E,              KC_R,                 KC_T,            KC_Y,              KC_U,              KC_I,    KC_O,    KC_P,    \
  KC_A,    KC_S,      LALT_T(KC_D), LCTL_T(KC_F),                KC_G,            KC_H, RCTL_T(KC_J), RALT_T(KC_K),    KC_L,    KC_SCLN, \
  KC_Z,    KC_X,              KC_C,              KC_V,                 KC_B,            KC_N,              KC_M,           KC_COMM,  KC_DOT,  KC_SLSH, \
                     OSM(MOD_LSFT),             LOWER, MT(MOD_LSFT, KC_TAB),  KC_SPC,             RAISE,    KC_BSPC                \
),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Tab |      |      |      |      |           |      |   -  |   =  |   [  |   ]  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Ctrl|   `  |  GUI |  Alt |      |           |      |      |   \  |   #  |   '  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_RAISE] = LAYOUT( \
  KC_1,      KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
  KC_TAB, _______, _______, _______, _______,      _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, \
  KC_LCTL, KC_GRV, KC_LGUI, KC_LALT, _______,      _______, _______, KC_NUBS, KC_NUHS,  KC_QUOT, \
                   _______, _______, _______,      _______, _______, _______                    \
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Esc |      |      |      |      |           |      |   _  |   +  |   {  |   }  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Caps|   ¬  |      |      |      |           |      |      |   |  |   ~  |   @  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|  Del |
 *                  `-------------|      |    | Enter|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_LOWER] = LAYOUT( \
  KC_EXLM,  LSFT(KC_2), KC_HASH,  KC_DLR, KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
  KC_ESC,  _______, _______, _______, _______,      _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, \
  KC_CAPS, KC_TILD, _______, _______, _______,      _______, _______, LSFT(KC_NUBS), LSFT(KC_NUHS), LSFT(KC_QUOT), \
                    _______, _______, _______,      KC_ENT,  _______, KC_DEL                    \
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   F6 |  F7  |  Up  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |      |RGBSAI|RGBSAD|           |      | Left | Down |Right |caltde|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Reset|RGBTOG|RGBMOD|RGBHUI|RGBHUD|           |RGBVAI|RGBVAD|  F8  |Taskmg|      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10, \
  KC_F11,  KC_F12,  _______, RGB_SAI, RGB_SAD,      KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,  CALTDEL, \
  RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD,      RGB_VAI, RGB_VAD, _______, TSKMGR,  _______, \
                    _______, _______, _______,      _______, _______, _______                    \
)
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
