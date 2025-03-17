/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _QWERTY = 0,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST,
};


// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    TG(_FUNCTION)
#define ADJUST   TG(_ADJUST)

#define SYM_BSP  LT(_SYM, KC_BSPC)
#define NAV_DEL  LT(_NAV, KC_DEL)

#define LALT_ENT MT(MOD_LALT, KC_ENT)
#define RALT_ENT MT(MOD_RALT, KC_ENT)
#define ALT_S    MT(MOD_LALT, KC_S)
#define ALT_L    MT(MOD_RALT, KC_L)

#define CTL_D    MT(MOD_LCTL, KC_D)
#define CTL_K    MT(MOD_LCTL, KC_K)
#define CTL_SPC  MT(MOD_LCTL, KC_SPC)

#define SFT_F    MT(MOD_LSFT, KC_F)
#define SFT_J    MT(MOD_RSFT, KC_J)
#define SFT_SPC  MT(MOD_RSFT, KC_SPC)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | ADJ    |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  | F-keys |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | CapsLk |   A  |Alt/S |Ctlr/D|Shif/F|   G  |                              |   H  |Shif/J|Ctlr/K|Alt/L | ; :  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | ,  < | . >  | / ?  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | LGUI | RAlt/| Space| Canc |  | Bksp | Space| LAlt/| RGUI |      |
 *                        |      |      | Enter| Shift| Nav  |  | Sym  | Ctrl | Enter|      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
     XXXXXXX , KC_Q  ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , XXXXXXX,
     KC_CAPS , KC_A  , ALT_S   , CTL_D  ,  SFT_F ,   KC_G ,                                        KC_H,  SFT_J , CTL_K ,  ALT_L ,KC_SCLN, XXXXXXX,
     XXXXXXX , KC_Z  ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , _______, _______,    _______, _______, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, XXXXXXX,
                                 ADJUST , KC_LGUI,RALT_ENT, SFT_SPC,NAV_DEL,  SYM_BSP, CTL_SPC,LALT_ENT, KC_RGUI, FKEYS
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | Home | PgUp | PgDn | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              |  ←   |  ↓   |   ↑  |   →  |VolMut| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |M Prev|M Play| Pause|M Next| VolDn| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     KC_HOME, KC_PGDN, KC_PGUP , KC_END , KC_VOLU, KC_DEL,
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                                     KC_LEFT, KC_DOWN, KC_UP   , KC_RGHT, KC_MUTE, KC_INS,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_PAUSE, KC_MNXT, KC_VOLD, KC_PSCR,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______ , _______
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  ~   |  <   |  [   |  (   |  {   |                              |   }  |  )   |  ]   |  >   |  `   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  \   |  ?   |  |   |  -   |  _   |      |      |  |      |      |   =  |  +   |  ,   |  .   |  /   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
     XXXXXXX ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , XXXXXXX,
     XXXXXXX , KC_TILD, KC_LT  , KC_LBRC, KC_LPRN, KC_LCBR,                                     KC_RCBR, KC_RPRN, KC_RBRC,  KC_GT , KC_GRV , XXXXXXX,
     XXXXXXX , KC_BSLS, KC_QUES, KC_PIPE, KC_MINS, KC_UNDS, _______, _______, _______, _______, KC_EQL , KC_PLUS, KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*];
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | BOOT   |  F1  |  F2  |  F3  |  F4  |  F5  |                              |  F6  |  F7  |  F8  |  F9  | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F11 |  F12 |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      QK_BOOT,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,                                      KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10, XXXXXXX,
      XXXXXXX,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |QWERTY|      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      QK_BOOT, XXXXXXX, XXXXXXX, QWERTY , XXXXXXX, XXXXXXX,                                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD , XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______, _______, _______, _______, XXXXXXX, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, XXXXXXX,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

const uint16_t PROGMEM combo_df[] = {CTL_D, SFT_F, COMBO_END};
const uint16_t PROGMEM combo_sd[] = {ALT_S, CTL_D, COMBO_END};
const uint16_t PROGMEM combo_jk[] = {SFT_J, CTL_K, COMBO_END};
const uint16_t PROGMEM combo_kl[] = {CTL_K, ALT_L, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_sd, KC_TAB),
    COMBO(combo_df, KC_ESC),
    COMBO(combo_jk, KC_DOUBLE_QUOTE),
    COMBO(combo_kl, KC_QUOTE),
};

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // clang-format off
        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        oled_write_P(PSTR("Second."), false);
        // clang-format on
    }
    return false;
}

