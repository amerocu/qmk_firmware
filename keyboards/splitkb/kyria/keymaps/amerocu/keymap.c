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

#define ENABLE_COMPILE_KEYCODE

enum layers {
    _QWERTY = 0,
    _SYM,
    _NAV,
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

#define GUI_A    MT(MOD_LGUI, KC_A)
#define GUI_SCLN MT(MOD_RGUI, KC_SCLN)

// Tap Dance declarations
enum {
    TD_ADJUST = 0,
    TD_FKEYS
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ADJUST] = ACTION_TAP_DANCE_LAYER_TOGGLE(XXXXXXX, _ADJUST),
    [TD_FKEYS] = ACTION_TAP_DANCE_LAYER_TOGGLE(XXXXXXX, _FUNCTION),
};


// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |GUI/A |Alt/S |Ctlr/D|Shif/F|   G  |                              |   H  |Shif/J|Ctlr/K|Alt/L |GUI/; |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | ,  < | . >  | / ?  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | LGUI | RAlt/| Space| Canc |  | Bksp | Space| LAlt/| RGUI |      |
 *                        |      |      | Enter| Shift| Nav  |  | Sym  | Ctrl | Enter|      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
     XXXXXXX , KC_Q  ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , XXXXXXX,
     XXXXXXX ,GUI_A  , ALT_S   , CTL_D  ,  SFT_F ,   KC_G ,                                        KC_H,  SFT_J , CTL_K ,  ALT_L ,GUI_SCLN, XXXXXXX,
     XXXXXXX , KC_Z  ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, XXXXXXX,
                          TD(TD_ADJUST) , KC_LGUI,RALT_ENT, SFT_SPC,NAV_DEL,  SYM_BSP, CTL_SPC,LALT_ENT, KC_RGUI, TD(TD_FKEYS)
    ),


#define ALT_LT   MT(MOD_LALT, KC_LT)
#define ALT_GT   MT(MOD_RALT, KC_GT)

#define CTL_LBRC MT(MOD_LCTL, KC_LBRC)
#define CTL_RBRC MT(MOD_LCTL, KC_RBRC)

#define SFT_LPRN MT(MOD_LSFT, KC_LPRN)
#define SFT_RPRN MT(MOD_RSFT, KC_RPRN)

#define GUI_TILD MT(MOD_LGUI, KC_TILD)
#define GUI_GRV  MT(MOD_RGUI, KC_GRV)

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |GUI/~ |Alt/< |Ctrl/[|Shif/(|  {   |                              |   }  |Shif/)|Ctrl/]|Alt/> |GUI/` |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  \   |  ?   |  |   |  -   |  _   |      |      |  |      |      |   =  |  +   |  ,   |  .   |  /   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
     XXXXXXX ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , XXXXXXX,
     XXXXXXX ,GUI_TILD, ALT_LT ,CTL_LBRC,SFT_LPRN, KC_LCBR,                                     KC_RCBR,SFT_RPRN,CTL_RBRC, ALT_GT ,GUI_GRV , XXXXXXX,
     XXXXXXX , KC_BSLS, KC_QUES, KC_PIPE, KC_MINS, KC_UNDS, _______, _______, _______, _______, KC_EQL , KC_PLUS, KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
      XXXXXXX,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,                                      KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10, XXXXXXX,
      XXXXXXX,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                                     QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, QK_MAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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
      XXXXXXX, XXXXXXX, XXXXXXX, QWERTY , XXXXXXX, XXXXXXX,                                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD , XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_MAKE,_______, _______, _______, _______, XXXXXXX, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, XXXXXXX,
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

        oled_write_P(PSTR("\n\n\n\n\n"), false);

        uint8_t mods = get_mods();
        bool shift = mods & MOD_MASK_SHIFT;
        bool ctrl  = mods & MOD_MASK_CTRL;
        bool alt   = mods & MOD_MASK_ALT;
        bool gui   = mods & MOD_MASK_GUI;
        
        oled_write_P(PSTR("G"), gui);oled_write_P(PSTR(" "), false);
        oled_write_P(PSTR("A"), alt);oled_write_P(PSTR(" "), false);
        oled_write_P(PSTR("C"), ctrl);oled_write_P(PSTR(" "), false);
        oled_write_P(PSTR("S"), shift);oled_write_P(PSTR("\n"), false);

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(PSTR("NUMLCK"), led_usb_state.num_lock);oled_write_P(PSTR(" "), false);
        oled_write_P(PSTR("CAPLCK"), led_usb_state.caps_lock);oled_write_P(PSTR(" "), false);
        oled_write_P(PSTR("SCRLCK"), led_usb_state.scroll_lock);oled_write_P(PSTR("\n"), false);
    } else {
        oled_write_P(PSTR("Second..."), false);
    }

    return false;
}

