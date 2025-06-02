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
#include "ezovrd.h"
#include "keycode_handler.h"

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
    MO_TG_QWERTY = SAFE_RANGE, // toggle the qwerty layer while held
    MO_TG_NUMFN, // toggle the num/fn layer while held
};

enum unicode_names {
    U_EM_DASH, U_LEFT_ARROW, U_UP_ARROW, U_RIGHT_ARROW, U_DOWN_ARROW, U_BOX_EMPTY, U_BOX_CHECKED, U_BOX_CROSSED, U_BLACK_STAR, U_WHITE_STAR, U_CPYRGHT,
    U_RGSTRD, U_TRDMRK, U_SMILE, U_ROFL, U_MND_BLWN, U_SALUTE, U_MELTFC, U_TEARS, U_CRY, U_SKULL, U_WHTCHK, U_CROSS, U_WARNING, U_100, U_PNKHRT, U_FIRE,
    U_HNDSAIR, U_PARTY, U_MUSIC_2, U_MUSIC_3, U_SPARKLES, U_EYES, U_SHIP, U_DELIVERY, U_BUG, U_THMB_UP, U_THMB_DN, U_LINK, U_PALMTR,
};

const uint32_t PROGMEM unicode_map[] = {
    [U_EM_DASH] = 0x2014,  // —
    [U_LEFT_ARROW] = 0x2190,  // ←
    [U_UP_ARROW] = 0x2191,  // ↑
    [U_RIGHT_ARROW] = 0x2192,  // →
    [U_DOWN_ARROW] = 0x2193,  // ↓
    [U_BOX_EMPTY] = 0x2610,  // ☐
    [U_BOX_CHECKED] = 0x2611,  // ☑
    [U_BOX_CROSSED] = 0x2612,  // ☒
    [U_BLACK_STAR] = 0x2605,  // ★
    [U_WHITE_STAR] = 0x2606,  // ☆
    [U_CPYRGHT] = 0x00A9, // ©
    [U_RGSTRD] = 0x00AE, // ®
    [U_TRDMRK] = 0x2122, // ™
    [U_SMILE] = 0x1F60A, // 😊
    [U_ROFL] = 0x1F923, // 🤣
    [U_MND_BLWN] = 0x1F92F, // 🤯
    [U_SALUTE] = 0x1FAE1, // 🫡
    [U_MELTFC] = 0x1FAE0, // 🫠
    [U_TEARS] = 0x1F979, // 🥹
    [U_CRY] = 0x1F62C, // 😭
    [U_SKULL] = 0x1F480, // 💀
    [U_WHTCHK] = 0x2705, // ✅
    [U_CROSS] = 0x274C, // ❌
    [U_WARNING] = 0x26A0, // ⚠
    [U_100] = 0x1F4AF, // 💯
    [U_PNKHRT] = 0x1FA77, // 🩷
    [U_FIRE] = 0x1F525, // 🔥
    [U_HNDSAIR] = 0x1F64C, // 🙌
    [U_PARTY] = 0x1F389, // 🎉
    [U_MUSIC_2] = 0x1F3B5, // 🎵
    [U_MUSIC_3] = 0x1F3B6, // 🎶
    [U_SPARKLES] = 0x2728, // ✨
    [U_EYES] = 0x1F440, // 👀
    [U_SHIP] = 0x1F6A2, // 🚢
    [U_DELIVERY] = 0x1F69A, // 🚚
    [U_BUG] = 0x1F41E, // 🐞
    [U_THMB_UP] = 0x1F44D, // 👍
    [U_THMB_DN] = 0x1F44E, // 👎
    [U_LINK] = 0x1F517, // 🔗
    [U_PALMTR] = 0x1F334, // 🌴
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
    UM(U_SMILE),   KC_F1,         KC_F2,         KC_F3,         KC_F4,         KC_F5,         UM(U_WHTCHK),      UM(U_CPYRGHT), KC_F6,         KC_F7,         KC_F8,         KC_F9,         KC_F10,        KC_F11,
    UM(U_ROFL),    UM(U_TEARS),   UM(U_100),     UM(U_HNDSAIR), UM(U_SHIP),    UM(U_BUG),     UM(U_CROSS),       UM(U_RGSTRD),  KC_KP_ASTERISK,KC_KP_7,       KC_KP_8,       KC_KP_9,       KC_KP_MINUS,   KC_F12,
    UM(U_MND_BLWN),UM(U_CRY),     UM(U_PNKHRT),  UM(U_PARTY),   UM(U_DELIVERY),UM(U_EYES),                                      KC_KP_SLASH,   KC_KP_4,       KC_KP_5,       KC_KP_6,       KC_KP_PLUS,    UM(U_PALMTR),
    UM(U_SALUTE),  UM(U_SKULL),   UM(U_FIRE),    KC_UP,         UM(U_MUSIC_2), UM(U_MUSIC_3), UM(U_WARNING),     UM(U_TRDMRK),  KC_EQUAL,      KC_KP_1,       KC_KP_2,       KC_KP_3,       KC_KP_ENTER,   KC_NUM_LOCK,
    UM(U_MELTFC),  UM(U_SPARKLES),KC_LEFT,       KC_DOWN,       KC_RIGHT,                                                                      KC_KP_0,       KC_KP_0,       KC_KP_DOT,     KC_KP_ENTER,   UM(U_LINK),
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

tap_dance_action_t tap_dance_actions[] = {
    [LCDT_SHFT] = EZTD_TAP_HOLD_DTAP(KC_LEFT_PAREN, KC_LEFT_SHIFT, QK_CAPS_WORD_TOGGLE),
    [LCDT_CRTL] = EZTD_TAP_HOLD(KC_LEFT_ANGLE_BRACKET,  LM(LAY_QWERTY_CONTROL, MOD_MASK_CTRL)),
    [LCDT_META] = EZTD_TAP_HOLD_DTAP(KC_LEFT_BRACKET, LM(LAY_QWERTY_META, MOD_MASK_GUI), QK_AUTO_SHIFT_TOGGLE),
    [LCDT_ALT] = EZTD_TAP_HOLD_DTAP(KC_LEFT_CURLY_BRACE, LM(LAY_QWERTY_ALT, MOD_MASK_ALT), KC_INS),
    [RCDT_ALT] = EZTD_TAP_HOLD_DTAP(KC_RIGHT_CURLY_BRACE, LM(LAY_QWERTY_ALT, MOD_MASK_ALT), G(KC_L)),
    [RCDT_META] = EZTD_TAP_HOLD_DTAP(KC_RIGHT_BRACKET, LM(LAY_QWERTY_META, MOD_MASK_GUI), KC_F11),
    [RCDT_CRTL] = EZTD_TAP_HOLD_DTAP(KC_RIGHT_ANGLE_BRACKET, LM(LAY_QWERTY_CONTROL, MOD_MASK_CTRL), A(KC_F4)),
    [RCDT_SHFT] = EZTD_TAP_HOLD_DTAP(KC_RIGHT_PAREN, KC_RIGHT_SHIFT, KC_CAPS),
    [LAY_OUT] = EZTD_TAP_HOLD_DTAP_DHOLD(TG(LAY_NUM_FN), MO_TG_NUMFN, TG(LAY_QWERTY), MO_TG_QWERTY),
    [MUTE_MVS] = EZTD_TAP_DTAP_TTAP(C(S(KC_M)), C(S(KC_O)), KC_AUDIO_MUTE),
    [CALC_MAIL] = EZTD_TAP_DTAP(KC_CALCULATOR, KC_MAIL),
    [HOME_TOP] =  EZTD_TAP_DTAP(KC_HOME, C(KC_HOME)),
    [END_BTM] = EZTD_TAP_DTAP(KC_END, C(KC_END)),
    [SHOT_FILE] = EZTD_TAP_DTAP(KC_PSCR, KC_MY_COMPUTER),
    [NEXT_FF] = EZTD_TAP_HOLD(KC_MEDIA_NEXT_TRACK, KC_MEDIA_FAST_FORWARD),
    [PREV_RW] = EZTD_TAP_HOLD(KC_MEDIA_PREV_TRACK, KC_MEDIA_REWIND),
    [PLAY_PLYR] = EZTD_TAP_DTAP(KC_MEDIA_PLAY_PAUSE, KC_MEDIA_SELECT),
};

const key_override_t *key_overrides[] = {
	&ezovrd_make_basic(MOD_MASK_SHIFT, KC_COMMA, UM(U_LEFT_ARROW)),
	&ezovrd_make_basic(MOD_MASK_SHIFT, KC_DOT, UM(U_RIGHT_ARROW)),
	&ezovrd_make_basic(MOD_MASK_SHIFT, TD(NEXT_FF), UM(U_UP_ARROW)),
	&ezovrd_make_basic(MOD_MASK_SHIFT, TD(PREV_RW), UM(U_DOWN_ARROW)),
	&ezovrd_make_basic(MOD_MASK_SHIFT, TD(PLAY_PLYR), UM(U_EM_DASH)),
	&ezovrd_make_basic(MOD_MASK_SHIFT, TD(MUTE_MVS), UM(U_BOX_EMPTY)),
	&ezovrd_make_basic(MOD_MASK_SHIFT, KC_VOLU, UM(U_BOX_CHECKED)),
	&ezovrd_make_basic(MOD_MASK_SHIFT, KC_VOLD, UM(U_BOX_CROSSED)),
	&ezovrd_make_basic(MOD_MASK_SHIFT, KC_9, UM(U_BLACK_STAR)),
	&ezovrd_make_basic(MOD_MASK_SHIFT, KC_0, UM(U_WHITE_STAR)),
	&ezovrd_make_basic(MOD_MASK_SHIFT, TD(LAY_OUT), UM(U_THMB_DN)),
	&ezovrd_make_basic(MOD_MASK_SHIFT, TD(SHOT_FILE), UM(U_THMB_UP)),
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

// handle custom actions in tap dances
bool eztd_key_event_user(uint16_t keycode, bool pressed){
    switch (keycode) {
        case MO_TG_QWERTY:
            layer_invert(LAY_QWERTY);
            return true;
        case MO_TG_NUMFN:
            layer_invert(LAY_NUM_FN);
            return true;
    }
    return false;
}

// Walk though the key overrides to see if the shift key has
// been overridden for this key.  If so, return the override.
uint16_t get_shift_replacement(uint16_t keycode) {
    for(int i=0; i<sizeof(key_overrides)/sizeof(key_overrides[0]); i++){
        if(key_overrides[i]->trigger == keycode && key_overrides[i]->suppressed_mods == MOD_MASK_SHIFT) {
            return key_overrides[i]->replacement;
        }
    }
    return 0;
}

// handle auto shift presses
void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    if (shifted) {
        uint16_t replacement = get_shift_replacement(keycode);
        if (replacement){
            // found a key override, use the replacement for auto shift
            process_keycode_full(replacement, true);
            return;
        }
        // for regular keys, shift modifier needs to be active to get shifted behavior
        add_weak_mods(MOD_BIT(KC_LSFT));
    }
    // no override found or shift not held, use normal key code
    register_code16(keycode);
}

// handle auto shift releases
void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    if (shifted) {
        uint16_t replacement = get_shift_replacement(keycode);
        if (replacement){
            // found a key override, use the replacement for auto shift
            process_keycode_full(replacement, false);
            return;
        }
    }
    // no override found or shift not held, use normal key code
    unregister_code16(keycode);
}

// Use the callback for OS detection to set the unicode mode
bool process_detected_host_os_user(os_variant_t detected_os) {

    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            set_unicode_input_mode(UNICODE_MODE_MACOS);
            // Flash the red light
            ergodox_right_led_1_on();
            ergodox_right_led_2_off();
            break;
        case OS_WINDOWS:
            set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);
            // Flash the red and green lights
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case OS_LINUX:
            set_unicode_input_mode(UNICODE_MODE_LINUX);
            // Flash the green light
            ergodox_right_led_1_off();
            ergodox_right_led_2_on();
            break;
        default:
            break;
    }

    // wait and unflash the lights
    wait_ms(500);
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();

    return true;
}
