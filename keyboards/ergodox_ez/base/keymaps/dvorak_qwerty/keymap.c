/* Copyright 2025 Stephen Ostermiller <https://ostermiller.org/contact.pl?regarding=qmk>
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
#include "version.h"
#include "eztd.h"

enum layer_names {
    LAY_DVORAK, // base
    LAY_QWERTY, // alternate swappable base
    LAY_NUM_FN, // number keypad, function keys, available from either base layer
    LAY_QWERTY_CONTROL, // qwerty overlay with ctrl key pressed
    LAY_QWERTY_META, // qwerty overlay with meta key pressed
    LAY_QWERTY_ALT, // qwerty overlay with alt key pressed
};

enum tap_dance_keycodes {
    LCDT_SHFT, // Space cadet left: TAP (, HOLD shift, DOUBLE TAP caps word
    LCDT_CRTL, // Space cadet left: TAP <, HOLD control (qwerty layout)
    LCDT_META, // Space cadet left: TAP [, HOLD meta (qwerty layout), DOUBLE TAP toggle auto shift on/off
    LCDT_ALT, // Space cadet left: TAP {, HOLD alt (qwerty layout), DOUBLE TAP toggle insert/overtype
    RCDT_ALT, // Space cadet right: TAP }, HOLD alt (qwerty layout), DOUBLE TAP lock screen (meta-l)
    RCDT_META, // Space cadet right: TAP ], HOLD meta (qwerty layout), DOUBLE TAP full screen (f11)
    RCDT_CRTL, // Space cadet right: TAP >, HOLD control (qwerty layout), DOUBLE TAP close window (alt-f4)
    RCDT_SHFT, // Space cadet right: TAP ), HOLD shift, DOUBLE TAP caps lock
    MUTE_MVS, // Super mute: TAP toggle mute mic (ctrl-alt-m), DOUBLE TAP toggle webcam on/off (ctrl-alt-o), TRIPLE TAP toggle mute speakers
    CALC_MAIL, // TAP calculator, DOUBLE TAP email
    HOME_TOP, // TAP home, DOUBLE TAP top (ctrl-home)
    END_BTM, // TAP end, DOUBLE TAP bottom (ctrl-end)
    SHOT_FILE, // TAP screen shot, DOUBLE TAP file manager
    NEXT_FF, // TAP media next, HELD media fast forward
    PREV_RW, // TAP media prev, HELD media rewind
    PLAY_PLYR, // TAP play/pause, DOUBLE TAP media player
    LAY_OUT, // TAP toggle base layer <-> number layer, HOLD number layer until released, DOUBLE TAP toggle base qwerty <-> dvorak, DOUBLE TAP HOLD other base layer until released
};

// used as portions of tap dances
enum custom_keycodes {
    MO_CTRL_KEY_AND_LAYOUT = SAFE_RANGE, // control key and layer while held
    MO_ALT_KEY_AND_LAYOUT, // alt key and layer while held
    MO_META_KEY_AND_LAYOUT, // meta key and layer while held
    MO_NUMFN_LAYOUT, // number/function layer while held
    TG_NUMFN_LAYOUT, // toggle number/function layer
    MO_BASE_LAYER, // swap base layer while held
    TG_BASE_LAYER, // toggle base layer qwerty <-> dvorak
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAY_DVORAK] = LAYOUT_ergodox_pretty(
/*  KEY COLUMN 1,  KEY COLUMN 2,  KEY COLUMN 3,  KEY COLUMN 4,  KEY COLUMN 5,  KEY COLUMN 6,  KEY COLUMN 7,      KEY COLUMN 8,  KEY COLUMN 9,  KEY COLUMN 10, KEY COLUMN 11, KEY COLUMN 12, KEY COLUMN 13, KEY COLUMN 14, */
    TD(MUTE_MVS),  KC_1,          KC_2,          KC_3,          KC_4,          KC_5,          TD(PLAY_PLYR),     TD(CALC_MAIL), KC_6,          KC_7,          KC_8,          KC_9,          KC_0,          KC_BSLS,
    KC_VOLU,       KC_QUOTE,      KC_COMMA,      KC_DOT,        KC_P,          KC_Y,          TD(NEXT_FF),       KC_EQUAL,      KC_F,          KC_G,          KC_C,          KC_R,          KC_L,          KC_SLASH,
    KC_VOLD,       KC_A,          KC_O,          KC_E,          KC_U,          KC_I,                                            KC_D,          KC_H,          KC_T,          KC_N,          KC_S,          KC_MINUS,
    TD(LCDT_SHFT), KC_SCLN,       KC_Q,          KC_J,          KC_K,          KC_X,          TD(PREV_RW),       KC_GRAVE,      KC_B,          KC_M,          KC_W,          KC_V,          KC_Z,          TD(RCDT_SHFT),
    KC_LEFT,       KC_RIGHT,      TD(LCDT_CRTL), TD(LCDT_META), TD(LCDT_ALT),                                                                  TD(RCDT_ALT),  TD(RCDT_META), TD(RCDT_CRTL), KC_UP,         KC_DOWN,
                                                                               KC_ESC,        TD(LAY_OUT),       TD(SHOT_FILE), KC_DELETE,
                                                                                              TD(HOME_TOP),      KC_PAGE_UP,
                                                                KC_ENTER,      KC_TAB,        TD(END_BTM),       KC_PGDN,       KC_BSPC,       KC_SPACE
  ),
  [LAY_QWERTY] = LAYOUT_ergodox_pretty(
/*  KEY COLUMN 1,  KEY COLUMN 2,  KEY COLUMN 3,  KEY COLUMN 4,  KEY COLUMN 5,  KEY COLUMN 6,  KEY COLUMN 7,      KEY COLUMN 8,  KEY COLUMN 9,  KEY COLUMN 10, KEY COLUMN 11, KEY COLUMN 12, KEY COLUMN 13, KEY COLUMN 14, */
    TD(MUTE_MVS),  KC_1,          KC_2,          KC_3,          KC_4,          KC_5,          TD(PLAY_PLYR),     TD(CALC_MAIL), KC_6,          KC_7,          KC_8,          KC_9,          KC_0,          TD(NEXT_FF),
    KC_VOLU,       KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,          KC_EQUAL,          KC_BSLS,       KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,          TD(PREV_RW),
    KC_VOLD,       KC_A,          KC_S,          KC_D,          KC_F,          KC_G,                                            KC_H,          KC_J,          KC_K,          KC_L,          KC_SCLN,       KC_QUOTE,
    TD(LCDT_SHFT), KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,          KC_MINUS,          KC_GRAVE,      KC_N,          KC_M,          KC_COMMA,      KC_DOT,        KC_SLASH,      TD(RCDT_SHFT),
    KC_LEFT,       KC_RIGHT,      TD(LCDT_CRTL), TD(LCDT_META), TD(LCDT_ALT),                                                                  TD(RCDT_ALT),  TD(RCDT_META), TD(RCDT_CRTL), KC_UP,         KC_DOWN,
                                                                               KC_ESC,        TD(LAY_OUT),       TD(SHOT_FILE), KC_DELETE,
                                                                                              TD(HOME_TOP),      KC_PAGE_UP,
                                                                KC_ENTER,      KC_TAB,        TD(END_BTM),       KC_PGDN,       KC_BSPC,       KC_SPACE
  ),
  [LAY_NUM_FN] = LAYOUT_ergodox_pretty(
/*  KEY COLUMN 1,  KEY COLUMN 2,  KEY COLUMN 3,  KEY COLUMN 4,  KEY COLUMN 5,  KEY COLUMN 6,  KEY COLUMN 7,      KEY COLUMN 8,  KEY COLUMN 9,  KEY COLUMN 10, KEY COLUMN 11, KEY COLUMN 12, KEY COLUMN 13, KEY COLUMN 14, */
    XXXXXXX,       KC_F1,         KC_F2,         KC_F3,         KC_F4,         KC_F5,         XXXXXXX,           XXXXXXX,       KC_F6,         KC_F7,         KC_F8,         KC_F9,         KC_F10,        KC_F11,
    XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,           XXXXXXX,       KC_KP_ASTERISK,KC_KP_7,       KC_KP_8,       KC_KP_9,       KC_KP_MINUS,   KC_F12,
    XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                         KC_KP_SLASH,   KC_KP_4,       KC_KP_5,       KC_KP_6,       KC_KP_PLUS,    XXXXXXX,
    XXXXXXX,       XXXXXXX,       XXXXXXX,       KC_UP,         XXXXXXX,       XXXXXXX,       XXXXXXX,           XXXXXXX,       KC_EQUAL,      KC_KP_1,       KC_KP_2,       KC_KP_3,       KC_KP_ENTER,   KC_NUM_LOCK,
    XXXXXXX,       XXXXXXX,       KC_LEFT,       KC_DOWN,       KC_RIGHT,                                                                      KC_KP_0,       KC_KP_0,       KC_KP_DOT,     KC_KP_ENTER,   XXXXXXX,
                                                                               KC_ESC,        TD(LAY_OUT),       TD(SHOT_FILE), KC_DELETE,
                                                                                              TD(HOME_TOP),      KC_PAGE_UP,
                                                                KC_ENTER,      KC_TAB,        TD(END_BTM),       KC_PGDN,       KC_BSPC,       KC_SPACE
  ),
  [LAY_QWERTY_CONTROL] = LAYOUT_ergodox_pretty(
/*  KEY COLUMN 1,  KEY COLUMN 2,  KEY COLUMN 3,  KEY COLUMN 4,  KEY COLUMN 5,  KEY COLUMN 6,  KEY COLUMN 7,      KEY COLUMN 8,  KEY COLUMN 9,  KEY COLUMN 10, KEY COLUMN 11, KEY COLUMN 12, KEY COLUMN 13, KEY COLUMN 14, */
    XXXXXXX,       C(KC_1),       C(KC_2),       C(KC_3),       C(KC_4),       C(KC_5),       XXXXXXX,           XXXXXXX,       C(KC_6),       C(KC_7),       C(KC_8),       C(KC_9),       C(KC_0),       C(KC_RBRC),
    XXXXXXX,       C(KC_Q),       C(KC_W),       C(KC_E),       C(KC_R),       C(KC_T),       C(KC_EQUAL),       C(KC_BSLS),    C(KC_Y),       C(KC_U),       C(KC_I),       C(KC_O),       C(KC_P),       C(KC_LBRC),
    XXXXXXX,       C(KC_A),       C(KC_S),       C(KC_D),       C(KC_F),       C(KC_G),                                         C(KC_H),       C(KC_J),       C(KC_K),       C(KC_L),       C(KC_SCLN),    C(KC_QUOTE),
    KC_LSFT,       C(KC_Z),       C(KC_X),       C(KC_C),       C(KC_V),       C(KC_B),       C(KC_MINUS),       C(KC_GRAVE),   C(KC_N),       C(KC_M),       C(KC_COMMA),   C(KC_DOT),     C(KC_SLASH),   KC_RSFT,
    C(KC_LEFT),    C(KC_RIGHT),   _______,       KC_LEFT_GUI,   KC_LEFT_ALT,                                                                   KC_LEFT_ALT,   KC_LEFT_GUI,   _______,       C(KC_UP),      C(KC_DOWN),
                                                                               C(KC_ESC),     XXXXXXX,           KC_F11,        C(KC_DELETE),
                                                                                              C(KC_HOME),        C(KC_PAGE_UP),
                                                                C(KC_ENTER),   C(KC_TAB),     C(KC_END),         C(KC_PGDN),    C(KC_BSPC),    C(KC_SPACE)
  ),
  [LAY_QWERTY_META] = LAYOUT_ergodox_pretty(
/*  KEY COLUMN 1,  KEY COLUMN 2,  KEY COLUMN 3,  KEY COLUMN 4,  KEY COLUMN 5,  KEY COLUMN 6,  KEY COLUMN 7,      KEY COLUMN 8,  KEY COLUMN 9,  KEY COLUMN 10, KEY COLUMN 11, KEY COLUMN 12, KEY COLUMN 13, KEY COLUMN 14, */
    XXXXXXX,       G(KC_1),       G(KC_2),       G(KC_3),       G(KC_4),       G(KC_5),       XXXXXXX,           XXXXXXX,       G(KC_6),       G(KC_7),       G(KC_8),       G(KC_9),       G(KC_0),       G(KC_RBRC),
    XXXXXXX,       G(KC_Q),       G(KC_W),       G(KC_E),       G(KC_R),       G(KC_T),       G(KC_EQUAL),       G(KC_BSLS),    G(KC_Y),       G(KC_U),       G(KC_I),       G(KC_O),       G(KC_P),       G(KC_LBRC),
    XXXXXXX,       G(KC_A),       G(KC_S),       G(KC_D),       G(KC_F),       G(KC_G),                                         G(KC_H),       G(KC_J),       G(KC_K),       G(KC_L),       G(KC_SCLN),    G(KC_QUOTE),
    KC_LSFT,       G(KC_Z),       G(KC_X),       G(KC_C),       G(KC_V),       G(KC_B),       G(KC_MINUS),       G(KC_GRAVE),   G(KC_N),       G(KC_M),       G(KC_COMMA),   G(KC_DOT),     G(KC_SLASH),   KC_RSFT,
    G(KC_LEFT),    G(KC_RIGHT),   KC_LEFT_CTRL,  _______,       KC_LEFT_ALT,                                                                   KC_LEFT_ALT,   _______,       KC_LEFT_CTRL,  G(KC_UP),      G(KC_DOWN),
                                                                               G(KC_ESC),     XXXXXXX,           XXXXXXX,       G(KC_DELETE),
                                                                                              G(KC_HOME),        G(KC_PAGE_UP),
                                                                G(KC_ENTER),   G(KC_TAB),     G(KC_END),         G(KC_PGDN),    G(KC_BSPC),    G(KC_SPACE)
  ),
  [LAY_QWERTY_ALT] = LAYOUT_ergodox_pretty(
/*  KEY COLUMN 1,  KEY COLUMN 2,  KEY COLUMN 3,  KEY COLUMN 4,  KEY COLUMN 5,  KEY COLUMN 6,  KEY COLUMN 7,      KEY COLUMN 8,  KEY COLUMN 9,  KEY COLUMN 10, KEY COLUMN 11, KEY COLUMN 12, KEY COLUMN 13, KEY COLUMN 14, */
    XXXXXXX,       A(KC_1),       A(KC_2),       A(KC_3),       A(KC_4),       A(KC_5),       XXXXXXX,           XXXXXXX,       A(KC_6),       A(KC_7),       A(KC_8),       A(KC_9),       A(KC_0),       A(KC_RBRC),
    XXXXXXX,       A(KC_Q),       A(KC_W),       A(KC_E),       A(KC_R),       A(KC_T),       A(KC_EQUAL),       A(KC_BSLS),    A(KC_Y),       A(KC_U),       A(KC_I),       A(KC_O),       A(KC_P),       A(KC_LBRC),
    XXXXXXX,       A(KC_A),       A(KC_S),       A(KC_D),       A(KC_F),       A(KC_G),                                         A(KC_H),       A(KC_J),       A(KC_K),       A(KC_L),       A(KC_SCLN),    A(KC_QUOTE),
    KC_LSFT,       A(KC_Z),       A(KC_X),       A(KC_C),       A(KC_V),       A(KC_B),       A(KC_MINUS),       A(KC_GRAVE),   A(KC_N),       A(KC_M),       A(KC_COMMA),   A(KC_DOT),     A(KC_SLASH),   KC_RSFT,
    A(KC_LEFT),    A(KC_RIGHT),   KC_LEFT_CTRL,  KC_LEFT_GUI,   _______,                                                                       _______,       KC_LEFT_GUI,   KC_LEFT_CTRL,  A(KC_UP),      A(KC_DOWN),
                                                                               A(KC_ESC),     XXXXXXX,           XXXXXXX,       A(KC_DELETE),
                                                                                              A(KC_HOME),        A(KC_PAGE_UP),
                                                                A(KC_ENTER),   A(KC_TAB),     A(KC_END),         A(KC_PGDN),    A(KC_BSPC),    A(KC_SPACE)
  ),
};

// use callback when layer is switched to set lights based on layer
uint8_t layer_state_set_user(uint8_t state) {

    // Red light is NUM/FN
    if (layer_state_cmp(state, LAY_NUM_FN)){
        ergodox_right_led_1_on();
    } else {
        ergodox_right_led_1_off();
    }

    // Green light is QWERTY
    if(layer_state_cmp(state, LAY_QWERTY) || layer_state_cmp(state, LAY_QWERTY_CONTROL) || layer_state_cmp(state, LAY_QWERTY_META) || layer_state_cmp(state, LAY_QWERTY_ALT)){
        ergodox_right_led_2_on();
    } else {
        ergodox_right_led_2_off();
    }

    return state;
}

// use call back when scanning for keypresses to set caps lock light
void matrix_scan_user(void) {

    if(IS_LAYER_ON(LAY_NUM_FN)){
        // Blue light is ARROWLOCK
        if(host_keyboard_led_state().num_lock) {
            ergodox_right_led_3_off();
        } else {
            ergodox_right_led_3_on();
        }
    } else {
        // Blue light is CAPSLOCK
        if(host_keyboard_led_state().caps_lock || is_caps_word_on()) {
            ergodox_right_led_3_on();
        } else {
            ergodox_right_led_3_off();
        }
    }
}

// handle key down for tap dances
void eztd_reg(uint16_t keycode){
    switch (keycode) {
        case QK_CAPS_WORD_TOGGLE:
            caps_word_toggle();
            break;
        case KC_RIGHT_SHIFT:
        case KC_LEFT_SHIFT:
            register_mods(MOD_MASK_SHIFT);
            break;
        case MO_CTRL_KEY_AND_LAYOUT:
            register_mods(MOD_MASK_CTRL);
            layer_on(LAY_QWERTY_CONTROL);
            break;
        case MO_ALT_KEY_AND_LAYOUT:
            register_mods(MOD_MASK_ALT);
            layer_on(LAY_QWERTY_ALT);
            break;
        case MO_META_KEY_AND_LAYOUT:
            register_mods(MOD_MASK_GUI);
            layer_on(LAY_QWERTY_META);
            break;
        case MO_NUMFN_LAYOUT:
        case TG_NUMFN_LAYOUT:
            layer_invert(LAY_NUM_FN);
            break;
        case MO_BASE_LAYER:
        case TG_BASE_LAYER:
            layer_invert(LAY_DVORAK);
            layer_invert(LAY_QWERTY);
            break;
        case QK_AUTO_SHIFT_TOGGLE:
            autoshift_toggle();
            break;
        default:
            register_code16(keycode);
    }
}

// handle key up for tap dances
void eztd_unreg(uint16_t keycode){
    switch (keycode) {
        case QK_CAPS_WORD_TOGGLE:
            break;
        case KC_RIGHT_SHIFT:
        case KC_LEFT_SHIFT:
            unregister_mods(MOD_MASK_SHIFT);
            break;
        case MO_CTRL_KEY_AND_LAYOUT:
            unregister_mods(MOD_MASK_CTRL);
            layer_off(LAY_QWERTY_CONTROL);
            break;
        case MO_ALT_KEY_AND_LAYOUT:
            unregister_mods(MOD_MASK_ALT);
            layer_off(LAY_QWERTY_ALT);
            break;
        case MO_META_KEY_AND_LAYOUT:
            unregister_mods(MOD_MASK_GUI);
            layer_off(LAY_QWERTY_META);
            break;
        case MO_NUMFN_LAYOUT:
            layer_invert(LAY_NUM_FN);
            break;
        case TG_NUMFN_LAYOUT:
            break;
        case MO_BASE_LAYER:
            layer_invert(LAY_DVORAK);
            layer_invert(LAY_QWERTY);
            break;
        case TG_BASE_LAYER:
            break;
        case QK_AUTO_SHIFT_TOGGLE:
            break;
        default:
            unregister_code16(keycode);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [LCDT_SHFT] = EZTD_TAP_HOLD_DTAP(KC_LEFT_PAREN, S(XXXXXXX), QK_CAPS_WORD_TOGGLE),
    [LCDT_CRTL] = EZTD_TAP_HOLD(KC_LEFT_ANGLE_BRACKET, MO_CTRL_KEY_AND_LAYOUT),
    [LCDT_META] = EZTD_TAP_HOLD_DTAP(KC_LEFT_BRACKET, MO_META_KEY_AND_LAYOUT, QK_AUTO_SHIFT_TOGGLE),
    [LCDT_ALT] = EZTD_TAP_HOLD_DTAP(KC_LEFT_CURLY_BRACE, MO_ALT_KEY_AND_LAYOUT, KC_INS),
    [RCDT_ALT] = EZTD_TAP_HOLD_DTAP(KC_RIGHT_CURLY_BRACE, MO_ALT_KEY_AND_LAYOUT, G(KC_L)),
    [RCDT_META] = EZTD_TAP_HOLD_DTAP(KC_RIGHT_BRACKET, MO_META_KEY_AND_LAYOUT, KC_F11),
    [RCDT_CRTL] = EZTD_TAP_HOLD_DTAP(KC_RIGHT_ANGLE_BRACKET, MO_CTRL_KEY_AND_LAYOUT, A(KC_F4)),
    [RCDT_SHFT] = EZTD_TAP_HOLD_DTAP(KC_RIGHT_PAREN, S(XXXXXXX), KC_CAPS),
    [LAY_OUT] = EZTD_TAP_HOLD_DTAP_DHOLD(TG_NUMFN_LAYOUT, MO_NUMFN_LAYOUT, TG_BASE_LAYER, MO_BASE_LAYER),
    [MUTE_MVS] = EZTD_TAP_DTAP_TTAP(C(S(KC_M)), C(S(KC_O)), KC_AUDIO_MUTE),
    [CALC_MAIL] = EZTD_TAP_DTAP(KC_CALCULATOR, KC_MAIL),
    [HOME_TOP] =  EZTD_TAP_DTAP(KC_HOME, C(KC_HOME)),
    [END_BTM] = EZTD_TAP_DTAP(KC_END, C(KC_END)),
    [SHOT_FILE] = EZTD_TAP_DTAP(KC_PSCR, KC_MY_COMPUTER),
    [NEXT_FF] = EZTD_TAP_HOLD(KC_MEDIA_NEXT_TRACK, KC_MEDIA_FAST_FORWARD),
    [PREV_RW] = EZTD_TAP_HOLD(KC_MEDIA_PREV_TRACK, KC_MEDIA_REWIND),
    [PLAY_PLYR] = EZTD_TAP_DTAP(KC_MEDIA_PLAY_PAUSE, KC_MEDIA_SELECT),
};
