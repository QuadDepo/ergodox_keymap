#include <stdbool.h>

#include QMK_KEYBOARD_H
#include "action_layer.h"

enum {
  BASE = 0,     // Default layer
  SYMB = 1,   // Arrows and Fx keys layer
  MOUSE = 2,    // Mouse movement and buttons layer

  TD_L = 0,     // Tap dance index for left shift
  TD_R = 1      // Tap dance index for right shift
};

// See the videck.png image for a visualization of the layout.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   | 1  ! | 2  @ | 3  # | 4  $ | 5  % | Lang |           | Esc  | 6  ^ | 7  & | 8  * | 9  ( | 0  ) | Bckspc |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |  L2  |           |  L2  |   Y  |   U  |   I  |   O  |   P  | \   |  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Ctrl  |   A  |   S  |  D   |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------|  L1  |           |  L1  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  | ,  < | . >  | /  ? |  - _   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  L1  | `  ~ | ' "  | \  | |  L2  |                                       |  {   |  }   | [  { | ]  } |  L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,--------------.       ,---------------.
 *                                        | Home  | End  |       | PgUp  |Insert |
 *                                 ,------|-------|------|       |-------+-------+------.
 *                                 |      |       | LGui |       | Del   |       |      |
 *                                 | Alt  | LGui  |------|       |-------| Enter |Space |
 *                                 |      |       | LGui |       | Bcsp  |       |      |
 *                                 `---------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
  // left hand
  GRAVE_ESC,     KC_1,    KC_2,     KC_3,     KC_4,   KC_5,  LGUI(KC_SPC),
  KC_TAB,     KC_Q,    KC_W,     KC_E,     KC_R,   KC_T,  MO(2),
  MO(2),    KC_A,    KC_S,     KC_D,     KC_F,   KC_G,
  OSM(MOD_LSFT),    KC_Z,    KC_X,     KC_C,     KC_V,   KC_B,  MO(1),
  MO(1),      KC_GRV,  KC_QUOT,  KC_LALT,  MO(2),

                                               KC_HOME,   KC_END,
                                                          KC_LGUI,
                                      KC_SPC, KC_LGUI,   MO(1),

  // right hand
  LALT(KC_SPC),  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,      KC_BSPC,
  KC_BSPC,   KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,      KC_BSLS,
           KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,   KC_QUOT,
  MO(1),   KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,   KC_MINS,
                     KC_LCBR,  KC_RCBR,  KC_LBRC,  KC_RBRC,   MO(1),

  KC_PGUP,  KC_INS,
  KC_DEL,
  KC_BSPC,  KC_ENT,    KC_SPC
),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   =  |    . |   0  |   -  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,

                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_EQL,KC_DOT,  KC_0,    KC_MINS,  KC_TRNS,

       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Left | Down |  Up  |Right |      |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |VolDwn|VolUp | Mute |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Play | Prev | Next |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |Brwser|Brwser|
 *                                 |      |      |------|       |------|Back  | Fwd  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MOUSE] = KEYMAP(
         RESET, KC_TRNS,        KC_TRNS,     KC_TRNS,        KC_TRNS, KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,        KC_TRNS,     KC_TRNS,        KC_TRNS, KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,        LGUI(LSFT(KC_9)),     KC_TRNS,        KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,        KC_TRNS,     KC_TRNS,        KC_TRNS, KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,        KC_TRNS,     KC_TRNS,        KC_TRNS,

                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_LGUI,  KC_TAB, LSFT(KC_TAB), KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE,  KC_TRNS, KC_TRNS,
                          KC_MPLY, KC_MPRV, KC_MNXT,  KC_TRNS, KC_TRNS,

       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS,  KC_WBAK, KC_WFWD
),
};


typedef void (*videck_tap_dance_trigger_t) (const uint16_t kc);

typedef struct
{
  uint16_t kc1;
  uint16_t kc2;
  videck_tap_dance_trigger_t trigger;
} videck_tap_dance_tuple_t;

static void videck_tap_dance_finished (qk_tap_dance_state_t *state, void *user_data) {
  videck_tap_dance_tuple_t *const tuple = (videck_tap_dance_tuple_t *)user_data;

  if (state->count == 1) {
    register_code16 (tuple->kc1);
  } else if (state->count == 2) {
    register_code16 (tuple->kc2);
  }
}

static void videck_tap_dance_reset (qk_tap_dance_state_t *state, void *user_data) {
  videck_tap_dance_tuple_t *const tuple = (videck_tap_dance_tuple_t *)user_data;

  if (state->count == 1) {
    unregister_code16 (tuple->kc1);
  } else if (state->count == 2) {
    unregister_code16 (tuple->kc2);
    tuple->trigger(tuple->kc2);
  }
}

static bool caps_lock_is_on;

// Toggles caps lock status.
static void videck_caps_trigger (const uint16_t kc) {
  caps_lock_is_on ^= true;
}

#define ACTION_TAP_DANCE_DOUBLE_TRIGGER(kc1, kc2, double_trigger) { \
    .fn = { NULL, videck_tap_dance_finished, videck_tap_dance_reset }, \
    .user_data = (void *)&((videck_tap_dance_tuple_t) { kc1, kc2, double_trigger }),  \
  }

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_L] = ACTION_TAP_DANCE_DOUBLE_TRIGGER(KC_LSFT, KC_CAPS, videck_caps_trigger),
  [TD_R] = ACTION_TAP_DANCE_DOUBLE_TRIGGER(KC_RSFT, KC_CAPS, videck_caps_trigger)
};
