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

enum layer_names {
    LAY_DVORAK, // base
    LAY_QWERTY, // alternate swappable base
    LAY_NUM_FN, // number keypad, function keys, available from either base layer
    LAY_QWERTY_CONTROL, // qwerty overlay with ctrl key pressed
    LAY_QWERTY_META, // qwerty overlay with meta key pressed
    LAY_QWERTY_ALT, // qwerty overlay with alt key pressed
};

// used as portions of tap dances
enum custom_keycodes {
    MO_TG_QWERTY = SAFE_RANGE,  MO_TG_NUMFN,
};

// handle custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MO_TG_QWERTY:
            // toggle the qwerty layer while held
            layer_invert(LAY_QWERTY);
            return false;
        case MO_TG_NUMFN:
             // toggle the num/fn layer while held
            layer_invert(LAY_NUM_FN);
            return false;
    }
    return true;
}

enum unicode_names {
    U_BULLET, U_EM_DASH, U_W_ARROW, U_N_ARROW, U_E_ARROW, U_S_ARROW, U_SW_ARROW, U_SE_ARROW, U_NW_ARROW, U_NE_ARROW, U_EW_ARROW, U_NS_ARROW, U_NWSE_ARROW,
    U_NESW_ARROW, U_B_W_ARROW, U_B_N_ARROW, U_B_E_ARROW, U_B_S_ARROW, U_B_SW_ARROW, U_B_SE_ARROW, U_B_NW_ARROW, U_B_NE_ARROW, U_B_EW_ARROW, U_B_NS_ARROW,
    U_W_W_ARROW, U_W_N_ARROW, U_W_E_ARROW, U_W_S_ARROW, U_W_SW_ARROW, U_W_SE_ARROW, U_W_NW_ARROW, U_W_NE_ARROW, U_W_EW_ARROW, U_W_NS_ARROW, U_BOX_EMPTY,
    U_BOX_CHECKED, U_BOX_CROSSED, U_BLACK_STAR, U_WHITE_STAR, U_CPYRGHT, U_RGSTRD, U_TRDMRK, U_SMILE, U_ROFL, U_MND_BLWN, U_SALUTE, U_MELTFC, U_TEARS,
    U_CRY, U_SKULL, U_WHTCHK, U_CROSS, U_100, U_FIRE, U_HNDSAIR, U_PARTY, U_MUSIC_2, U_MUSIC_3, U_SPARKLES, U_EYES, U_SHIP, U_DELIVERY, U_BUG, U_THMB_UP,
    U_THMB_DN, U_LINK, U_PALMTR, U_WARNING, U_HEART, U_DIV, U_H_DIV, U_PLUS_MIN, U_H_PLUS, U_MULT, U_H_MULT, U_MINUS, U_H_MINUS, U_APP_EQ, U_H_EQ, U_NE,
    U_LTE, U_GTE, U_D_W_ARROW, U_D_N_ARROW, U_D_E_ARROW, U_D_S_ARROW, U_D_SW_ARROW, U_D_SE_ARROW, U_D_NW_ARROW, U_D_NE_ARROW, U_D_EW_ARROW, U_D_NS_ARROW,
    U_BB3_W_ARROW, U_BB3_N_ARROW, U_BB3_E_ARROW, U_BB3_S_ARROW, U_BB3_SW_ARROW, U_BB3_SE_ARROW, U_BB3_NW_ARROW, U_BB3_NE_ARROW, U_BB5_W_ARROW,
    U_BB5_N_ARROW, U_BB5_E_ARROW, U_BB5_S_ARROW, U_BB5_SW_ARROW, U_BB5_SE_ARROW, U_BB5_NW_ARROW, U_BB5_NE_ARROW, U_INFINITY, U_INC_INFINITY,
    U_TIE_OVR_INFINITY, U_NEG_INFINITY,
};

const char* unicode_macro_map[] = {
    [U_BULLET] = "•",
    [U_EM_DASH] = "—",

    [U_W_ARROW]= "←",
    [U_N_ARROW]= "↑",
    [U_E_ARROW]= "→",
    [U_S_ARROW]= "↓",
    [U_SW_ARROW]= "↙",
    [U_SE_ARROW]= "↘",
    [U_NW_ARROW]= "↖",
    [U_NE_ARROW]= "↗",
    [U_EW_ARROW]= "↔",
    [U_NS_ARROW]= "↕",
    [U_NWSE_ARROW]= "⤡",
    [U_NESW_ARROW]= "⤢",

    [U_B_W_ARROW]= "⬅",
    [U_B_N_ARROW]= "⬆",
    [U_B_E_ARROW]= "➡",
    [U_B_S_ARROW]= "⬇",
    [U_B_SW_ARROW]= "⬋",
    [U_B_SE_ARROW]= "⬊",
    [U_B_NW_ARROW]= "⬉",
    [U_B_NE_ARROW]= "⬈",
    [U_B_EW_ARROW]= "⬌",
    [U_B_NS_ARROW]= "⬍",

    [U_W_W_ARROW]= "⇦",
    [U_W_N_ARROW]= "⇧",
    [U_W_E_ARROW]= "⇨",
    [U_W_S_ARROW]= "⇩",
    [U_W_SW_ARROW]= "⬃",
    [U_W_SE_ARROW]= "⬂",
    [U_W_NW_ARROW]= "⬁",
    [U_W_NE_ARROW]= "⬀",
    [U_W_EW_ARROW]= "⬄",
    [U_W_NS_ARROW]= "⇳",

    [U_D_W_ARROW]= "⇐",
    [U_D_N_ARROW]= "⇑",
    [U_D_E_ARROW]= "⇒",
    [U_D_S_ARROW]= "⇓",
    [U_D_SW_ARROW]= "⇙",
    [U_D_SE_ARROW]= "⇘",
    [U_D_NW_ARROW]= "⇖",
    [U_D_NE_ARROW]= "⇗",
    [U_D_EW_ARROW]= "⇔",
    [U_D_NS_ARROW]= "⇕",

    [U_BB3_W_ARROW]= "🡰",
    [U_BB3_N_ARROW]= "🡱",
    [U_BB3_E_ARROW]= "🡲",
    [U_BB3_S_ARROW]= "🡳",
    [U_BB3_SW_ARROW]= "🡷",
    [U_BB3_SE_ARROW]= "🡶",
    [U_BB3_NW_ARROW]= "🡴",
    [U_BB3_NE_ARROW]= "🡵",

    [U_BB5_W_ARROW]= "🢀",
    [U_BB5_N_ARROW]= "🢁",
    [U_BB5_E_ARROW]= "🢂",
    [U_BB5_S_ARROW]= "🢃",
    [U_BB5_SW_ARROW]= "🢇",
    [U_BB5_SE_ARROW]= "🢆",
    [U_BB5_NW_ARROW]= "🢄",
    [U_BB5_NE_ARROW]= "🢅",

    [U_BOX_EMPTY]= "☐",
    [U_BOX_CHECKED]= "☑",
    [U_BOX_CROSSED]= "☒",
    [U_BLACK_STAR]= "★",
    [U_WHITE_STAR]= "☆",
    [U_CPYRGHT]= "©",
    [U_RGSTRD]= "®",
    [U_TRDMRK]= "™",
    [U_SMILE]= "😊",
    [U_ROFL]= "🤣",
    [U_MND_BLWN]= "🤯",
    [U_SALUTE]= "🫡",
    [U_MELTFC]= "🫠",
    [U_TEARS]= "🥹",
    [U_CRY]= "😭",
    [U_SKULL]= "💀",
    [U_WHTCHK]= "✅",
    [U_CROSS]= "❌",
    [U_100]= "💯",
    [U_FIRE]= "🔥",
    [U_HNDSAIR]= "🙌",
    [U_PARTY]= "🎉",
    [U_MUSIC_2]= "🎵",
    [U_MUSIC_3]= "🎶",
    [U_SPARKLES]= "✨",
    [U_EYES]= "👀",
    [U_SHIP]= "🚢",
    [U_DELIVERY]= "🚚",
    [U_BUG]= "🐞",
    [U_THMB_UP]= "👍",
    [U_THMB_DN]= "👎",
    [U_LINK]= "🔗",
    [U_PALMTR]= "🌴",
    [U_WARNING] = "⚠️",
    [U_HEART] = "❤️",

    [U_DIV] = "÷",
    [U_H_DIV] = "➗",
    [U_PLUS_MIN] = "±",
    [U_H_PLUS] = "➕",
    [U_MULT] = "×",
    [U_H_MULT] = "✖",
    [U_MINUS] = "−",
    [U_H_MINUS] = "➖",
    [U_APP_EQ] = "≈",
    [U_H_EQ] = "🟰",
    [U_NE] = "≠",
    [U_LTE] = "≤",
    [U_GTE] = "≥",
    [U_INFINITY] = "∞",
    [U_INC_INFINITY] = "⧜",
    [U_TIE_OVR_INFINITY] = "⧝",
    [U_NEG_INFINITY] = "⧞",
};

#define KC_FULL_SCREEN KC_F11

enum tap_dance_keycodes {
    LCDT_SHFT, LCDT_CRTL, LCDT_META, LCDT_ALT, RCDT_ALT, RCDT_META, RCDT_CRTL, RCDT_SHFT, LAY_OUT, MUTE_MVS, CALC_MAIL, HOME_TOP, END_BTM, SHOT_FILE, NEXT_FF, PREV_RW,
    PLAY_PLYR, W_ARROW, N_ARROW, E_ARROW, S_ARROW, SW_ARROW, SE_ARROW, NW_ARROW, NE_ARROW, EW_ARROW, NS_ARROW, DIAG_ARROW, DIVIDES, MULTIPLIES, SUBTRACTS, ADDS, EQUALS,
    COPYRIGHT, TD_INF,
};

tap_dance_action_t tap_dance_actions[] = {
    // Space cadet left: TAP (, HOLD shift, DOUBLE TAP caps word
    [LCDT_SHFT] = EZTD_TAP_HOLD_DTAP(KC_LEFT_PAREN, KC_LEFT_SHIFT, QK_CAPS_WORD_TOGGLE),
    // Space cadet left: TAP <, HOLD control (qwerty layout)
    [LCDT_CRTL] = EZTD_TAP_HOLD(KC_LEFT_ANGLE_BRACKET,  LM(LAY_QWERTY_CONTROL, MOD_MASK_CTRL)),
    // Space cadet left: TAP [, HOLD meta (qwerty layout), DOUBLE TAP toggle auto shift on/off
    [LCDT_META] = EZTD_TAP_HOLD_DTAP(KC_LEFT_BRACKET, LM(LAY_QWERTY_META, MOD_MASK_GUI), QK_AUTO_SHIFT_TOGGLE),
    // Space cadet left: TAP {, HOLD alt (qwerty layout), DOUBLE TAP toggle insert/overtype
    [LCDT_ALT] = EZTD_TAP_HOLD_DTAP(KC_LEFT_CURLY_BRACE, LM(LAY_QWERTY_ALT, MOD_MASK_ALT), KC_INS),
    // Space cadet right: TAP }, HOLD alt (qwerty layout), DOUBLE TAP lock screen (meta-l)
    [RCDT_ALT] = EZTD_TAP_HOLD_DTAP(KC_RIGHT_CURLY_BRACE, LM(LAY_QWERTY_ALT, MOD_MASK_ALT), G(KC_L)),
    // Space cadet right: TAP ], HOLD meta (qwerty layout), DOUBLE TAP full screen (f11)
    [RCDT_META] = EZTD_TAP_HOLD_DTAP(KC_RIGHT_BRACKET, LM(LAY_QWERTY_META, MOD_MASK_GUI), KC_FULL_SCREEN),
    // Space cadet right: TAP >, HOLD control (qwerty layout), DOUBLE TAP close window (alt-f4)
    [RCDT_CRTL] = EZTD_TAP_HOLD_DTAP(KC_RIGHT_ANGLE_BRACKET, LM(LAY_QWERTY_CONTROL, MOD_MASK_CTRL), A(KC_F4)),
    // Space cadet right: TAP ), HOLD shift, DOUBLE TAP caps lock
    [RCDT_SHFT] = EZTD_TAP_HOLD_DTAP(KC_RIGHT_PAREN, KC_RIGHT_SHIFT, KC_CAPS),
    // TAP toggle base layer <-> number layer, HOLD number layer until released, DOUBLE TAP toggle base qwerty <-> dvorak, DOUBLE TAP HOLD other base layer until released
    [LAY_OUT] = EZTD_TAP_HOLD_DTAP_DHOLD(TG(LAY_NUM_FN), MO_TG_NUMFN, TG(LAY_QWERTY), MO_TG_QWERTY),
    // Super mute: TAP toggle mute mic (ctrl-alt-m), DOUBLE TAP toggle webcam on/off (ctrl-alt-o), TRIPLE TAP toggle mute speakers
    [MUTE_MVS] = EZTD_TAP_DTAP_TTAP(C(S(KC_M)), C(S(KC_O)), KC_AUDIO_MUTE),
    // TAP calculator, DOUBLE TAP email
    [CALC_MAIL] = EZTD_TAP_DTAP(KC_CALCULATOR, KC_MAIL),
    // TAP home, DOUBLE TAP t<op (ctrl-home)
    [HOME_TOP] =  EZTD_TAP_DTAP(KC_HOME, C(KC_HOME)),
    // TAP end, DOUBLE TAP bottom (ctrl-end)
    [END_BTM] = EZTD_TAP_DTAP(KC_END, C(KC_END)),
    // TAP screen shot, DOUBLE TAP file manager
    [SHOT_FILE] = EZTD_TAP_DTAP(KC_PSCR, KC_MY_COMPUTER),
    // TAP media next, HELD media fast forward
    [NEXT_FF] = EZTD_TAP_HOLD(KC_MEDIA_NEXT_TRACK, KC_MEDIA_FAST_FORWARD),
    // TAP media prev, HELD media rewind
    [PREV_RW] = EZTD_TAP_HOLD(KC_MEDIA_PREV_TRACK, KC_MEDIA_REWIND),
    // TAP play/pause, DOUBLE TAP media player
    [PLAY_PLYR] = EZTD_TAP_DTAP(KC_MEDIA_PLAY_PAUSE, KC_MEDIA_SELECT),
    [W_ARROW] =  EZTD_TAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_W_ARROW) , UM(U_B_W_ARROW) , UM(U_W_W_ARROW) , UM(U_D_W_ARROW) , UM(U_BB3_W_ARROW) , UM(U_BB5_W_ARROW) ),
    [N_ARROW] =  EZTD_TAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_N_ARROW) , UM(U_B_N_ARROW) , UM(U_W_N_ARROW) , UM(U_D_N_ARROW) , UM(U_BB3_N_ARROW) , UM(U_BB5_N_ARROW) ),
    [E_ARROW] =  EZTD_TAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_E_ARROW) , UM(U_B_E_ARROW) , UM(U_W_E_ARROW) , UM(U_D_E_ARROW) , UM(U_BB3_E_ARROW) , UM(U_BB5_E_ARROW) ),
    [S_ARROW] =  EZTD_TAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_S_ARROW) , UM(U_B_S_ARROW) , UM(U_W_S_ARROW) , UM(U_D_S_ARROW) , UM(U_BB3_S_ARROW) , UM(U_BB5_S_ARROW) ),
    [SW_ARROW] = EZTD_TAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_SW_ARROW), UM(U_B_SW_ARROW), UM(U_W_SW_ARROW), UM(U_D_SW_ARROW), UM(U_BB3_SW_ARROW), UM(U_BB5_SW_ARROW)),
    [SE_ARROW] = EZTD_TAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_SE_ARROW), UM(U_B_SE_ARROW), UM(U_W_SE_ARROW), UM(U_D_SE_ARROW), UM(U_BB3_SE_ARROW), UM(U_BB5_SE_ARROW)),
    [NW_ARROW] = EZTD_TAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_NW_ARROW), UM(U_B_NW_ARROW), UM(U_W_NW_ARROW), UM(U_D_NW_ARROW), UM(U_BB3_NW_ARROW), UM(U_BB5_NW_ARROW)),
    [NE_ARROW] = EZTD_TAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_NE_ARROW), UM(U_B_NE_ARROW), UM(U_W_NE_ARROW), UM(U_D_NE_ARROW), UM(U_BB3_NE_ARROW), UM(U_BB5_NE_ARROW)),
    [EW_ARROW] = EZTD_TAP_HOLD_DTAP_DHOLD(UM(U_EW_ARROW), UM(U_B_EW_ARROW), UM(U_W_EW_ARROW), UM(U_D_EW_ARROW)),
    [NS_ARROW] = EZTD_TAP_HOLD_DTAP_DHOLD(UM(U_NS_ARROW), UM(U_B_NS_ARROW), UM(U_W_NS_ARROW), UM(U_D_NS_ARROW)),
    [DIAG_ARROW] = EZTD_TAP_HOLD(UM(U_NESW_ARROW), UM(U_NWSE_ARROW)),
    [DIVIDES] = EZTD_TAP_HOLD_DTAP(KC_KP_SLASH, UM(U_DIV), UM(U_H_DIV)),
    [MULTIPLIES] = EZTD_TAP_HOLD_DTAP(KC_KP_ASTERISK, UM(U_MULT), UM(U_H_MULT)),
    [SUBTRACTS] = EZTD_TAP_HOLD_DTAP(KC_KP_MINUS, UM(U_MINUS), UM(U_H_MINUS)),
    [ADDS] = EZTD_TAP_HOLD_DTAP(KC_KP_PLUS, UM(U_PLUS_MIN), UM(U_H_PLUS)),
    [EQUALS] = EZTD_TAP_HOLD_DTAP_DHOLD(KC_KP_EQUAL, UM(U_NE), UM(U_H_EQ), UM(U_APP_EQ)),
};

tap_dance_action_t tap_dance_xtras[] = {
    [COPYRIGHT] = EZTD_TAP_HOLD_DTAP(UM(U_CPYRGHT), UM(U_RGSTRD), UM(U_TRDMRK)),
    [TD_INF] = EZTD_TAP_HOLD_DTAP_DHOLD(UM(U_INFINITY), UM(U_INC_INFINITY), UM(U_TIE_OVR_INFINITY), UM(U_NEG_INFINITY)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAY_DVORAK] = LAYOUT_ergodox_pretty(
/*  KEY COLUMN 1,  KEY COLUMN 2,  KEY COLUMN 3,  KEY COLUMN 4,  KEY COLUMN 5,  KEY COLUMN 6,  KEY COLUMN 7,      KEY COLUMN 8,  KEY COLUMN 9,  KEY COLUMN 10, KEY COLUMN 11, KEY COLUMN 12, KEY COLUMN 13, KEY COLUMN 14, */
    TD(MUTE_MVS),  KC_1,          KC_2,          KC_3,          KC_4,          KC_5,          TD(PLAY_PLYR),     TD(CALC_MAIL), KC_6,          KC_7,          KC_8,          KC_9,          KC_0,          KC_BSLS,
    KC_VOLU,       KC_QUOTE,      KC_COMMA,      KC_DOT,        KC_P,          KC_Y,          TD(NEXT_FF),       KC_EQUAL,      KC_F,          KC_G,          KC_C,          KC_R,          KC_L,          KC_SLASH,
    KC_VOLD,       KC_A,          KC_O,          KC_E,          KC_U,          KC_I,                                            KC_D,          KC_H,          KC_T,          KC_N,          KC_S,          KC_MINUS,
    TD(LCDT_SHFT), KC_SCLN,       KC_Q,          KC_J,          KC_K,          KC_X,          TD(PREV_RW),       KC_GRAVE,      KC_B,          KC_M,          KC_W,          KC_V,          KC_Z,          TD(RCDT_SHFT),
    TD(SHOT_FILE), TD(LAY_OUT),   TD(LCDT_CRTL), TD(LCDT_META), TD(LCDT_ALT),                                                                  TD(RCDT_ALT),  TD(RCDT_META), TD(RCDT_CRTL), KC_PAGE_UP,    KC_PGDN,
                                                                               TD(HOME_TOP),  TD(END_BTM),       KC_ESC,        KC_DELETE,
                                                                                              KC_RIGHT,          KC_UP,
                                                                KC_ENTER,      KC_TAB,        KC_LEFT,           KC_DOWN,       KC_BSPC,       KC_SPACE
  ),
  [LAY_NUM_FN] = LAYOUT_ergodox_pretty(
/*  KEY COLUMN 1,  KEY COLUMN 2,  KEY COLUMN 3,  KEY COLUMN 4,  KEY COLUMN 5,  KEY COLUMN 6,  KEY COLUMN 7,      KEY COLUMN 8,  KEY COLUMN 9,  KEY COLUMN 10, KEY COLUMN 11, KEY COLUMN 12, KEY COLUMN 13, KEY COLUMN 14, */
    UM(U_SMILE),   KC_F1,         KC_F2,         KC_F3,         KC_F4,         KC_F5,         UM(U_WHTCHK),      XXXXXXX/*TD(COPYRIGHT)*/, KC_F6,         KC_F7,         KC_F8,         KC_F9,         KC_F10,        KC_F11,
    UM(U_ROFL),    UM(U_BUG),     TD(NS_ARROW),  TD(NW_ARROW),  TD(N_ARROW),   TD(NE_ARROW),  UM(U_CROSS),       TD(DIVIDES),   KC_KP_7,       KC_KP_8,       KC_KP_9,       TD(SUBTRACTS), XXXXXXX/*TD(TD_INF)*/,    KC_F12,
    UM(U_MND_BLWN),UM(U_EYES),    TD(EW_ARROW),  TD(W_ARROW),   UM(U_HEART),   TD(E_ARROW),                                     KC_KP_4,       KC_KP_5,       KC_KP_6,       TD(ADDS),      XXXXXXX,       UM(U_PALMTR),
    UM(U_SALUTE),  UM(U_MUSIC_3), TD(DIAG_ARROW),TD(SW_ARROW),  TD(S_ARROW),   TD(SE_ARROW),  UM(U_WARNING),     TD(MULTIPLIES),KC_KP_1,       KC_KP_2,       KC_KP_3,       TD(EQUALS),    XXXXXXX,       KC_NUM_LOCK,
    UM(U_MELTFC),  TD(LAY_OUT),   KC_LEFT_CTRL,  KC_LEFT_GUI,   KC_LEFT_ALT,                                                                   KC_KP_0,       KC_KP_DOT,     KC_KP_ENTER,   XXXXXXX,       UM(U_LINK),
                                                                               TD(HOME_TOP),  TD(END_BTM),       KC_ESC,        KC_DELETE,
                                                                                              KC_RIGHT,          KC_UP,
                                                                KC_ENTER,      KC_TAB,        KC_LEFT,           KC_DOWN,       KC_BSPC,       KC_SPACE
  ),
  [LAY_QWERTY] = LAYOUT_ergodox_pretty(
/*  KEY COLUMN 1,  KEY COLUMN 2,  KEY COLUMN 3,  KEY COLUMN 4,  KEY COLUMN 5,  KEY COLUMN 6,  KEY COLUMN 7,      KEY COLUMN 8,  KEY COLUMN 9,  KEY COLUMN 10, KEY COLUMN 11, KEY COLUMN 12, KEY COLUMN 13, KEY COLUMN 14, */
    TD(MUTE_MVS),  KC_1,          KC_2,          KC_3,          KC_4,          KC_5,          TD(PLAY_PLYR),     TD(CALC_MAIL), KC_6,          KC_7,          KC_8,          KC_9,          KC_0,          TD(NEXT_FF),
    KC_VOLU,       KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,          KC_EQUAL,          KC_BSLS,       KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,          TD(PREV_RW),
    KC_VOLD,       KC_A,          KC_S,          KC_D,          KC_F,          KC_G,                                            KC_H,          KC_J,          KC_K,          KC_L,          KC_SCLN,       KC_QUOTE,
    TD(LCDT_SHFT), KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,          KC_MINUS,          KC_GRAVE,      KC_N,          KC_M,          KC_COMMA,      KC_DOT,        KC_SLASH,      TD(RCDT_SHFT),
    TD(SHOT_FILE), TD(LAY_OUT),   TD(LCDT_CRTL), TD(LCDT_META), TD(LCDT_ALT),                                                                  TD(RCDT_ALT),  TD(RCDT_META), TD(RCDT_CRTL), KC_PAGE_UP,    KC_PGDN,
                                                                               TD(HOME_TOP),  TD(END_BTM),       KC_ESC,        KC_DELETE,
                                                                                              KC_RIGHT,          KC_UP,
                                                                KC_ENTER,      KC_TAB,        KC_LEFT,           KC_DOWN,       KC_BSPC,       KC_SPACE
  ),
  [LAY_QWERTY_CONTROL] = LAYOUT_ergodox_pretty(
/*  KEY COLUMN 1,  KEY COLUMN 2,  KEY COLUMN 3,  KEY COLUMN 4,  KEY COLUMN 5,  KEY COLUMN 6,  KEY COLUMN 7,      KEY COLUMN 8,  KEY COLUMN 9,  KEY COLUMN 10, KEY COLUMN 11, KEY COLUMN 12, KEY COLUMN 13, KEY COLUMN 14, */
    XXXXXXX,       C(KC_1),       C(KC_2),       C(KC_3),       C(KC_4),       C(KC_5),       XXXXXXX,           XXXXXXX,       C(KC_6),       C(KC_7),       C(KC_8),       C(KC_9),       C(KC_0),       C(KC_RBRC),
    XXXXXXX,       C(KC_Q),       C(KC_W),       C(KC_E),       C(KC_R),       C(KC_T),       C(KC_EQUAL),       C(KC_BSLS),    C(KC_Y),       C(KC_U),       C(KC_I),       C(KC_O),       C(KC_P),       C(KC_LBRC),
    XXXXXXX,       C(KC_A),       C(KC_S),       C(KC_D),       C(KC_F),       C(KC_G),                                         C(KC_H),       C(KC_J),       C(KC_K),       C(KC_L),       C(KC_SCLN),    C(KC_QUOTE),
    KC_LSFT,       C(KC_Z),       C(KC_X),       C(KC_C),       C(KC_V),       C(KC_B),       C(KC_MINUS),       C(KC_GRAVE),   C(KC_N),       C(KC_M),       C(KC_COMMA),   C(KC_DOT),     C(KC_SLASH),   KC_RSFT,
    XXXXXXX,       XXXXXXX,       KC_LEFT_CTRL,  KC_LEFT_GUI,   KC_LEFT_ALT,                                                                   KC_LEFT_ALT,   KC_LEFT_GUI,   KC_LEFT_CTRL,  C(KC_PAGE_UP), C(KC_PGDN),
                                                                               C(KC_HOME),    C(KC_END),         C(KC_ESC),     C(KC_DELETE),
                                                                                              C(KC_RIGHT),       C(KC_UP),
                                                                C(KC_ENTER),   C(KC_TAB),     C(KC_LEFT),        C(KC_DOWN),    C(KC_BSPC),    C(KC_SPACE)
  ),
  [LAY_QWERTY_META] = LAYOUT_ergodox_pretty(
/*  KEY COLUMN 1,  KEY COLUMN 2,  KEY COLUMN 3,  KEY COLUMN 4,  KEY COLUMN 5,  KEY COLUMN 6,  KEY COLUMN 7,      KEY COLUMN 8,  KEY COLUMN 9,  KEY COLUMN 10, KEY COLUMN 11, KEY COLUMN 12, KEY COLUMN 13, KEY COLUMN 14, */
    XXXXXXX,       G(KC_1),       G(KC_2),       G(KC_3),       G(KC_4),       G(KC_5),       XXXXXXX,           XXXXXXX,       G(KC_6),       G(KC_7),       G(KC_8),       G(KC_9),       G(KC_0),       G(KC_RBRC),
    XXXXXXX,       G(KC_Q),       G(KC_W),       G(KC_E),       G(KC_R),       G(KC_T),       G(KC_EQUAL),       G(KC_BSLS),    G(KC_Y),       G(KC_U),       G(KC_I),       G(KC_O),       G(KC_P),       G(KC_LBRC),
    XXXXXXX,       G(KC_A),       G(KC_S),       G(KC_D),       G(KC_F),       G(KC_G),                                         G(KC_H),       G(KC_J),       G(KC_K),       G(KC_L),       G(KC_SCLN),    G(KC_QUOTE),
    KC_LSFT,       G(KC_Z),       G(KC_X),       G(KC_C),       G(KC_V),       G(KC_B),       G(KC_MINUS),       G(KC_GRAVE),   G(KC_N),       G(KC_M),       G(KC_COMMA),   G(KC_DOT),     G(KC_SLASH),   KC_RSFT,
    XXXXXXX,       XXXXXXX,       KC_LEFT_CTRL,  KC_LEFT_GUI,   KC_LEFT_ALT,                                                                   KC_LEFT_ALT,   KC_LEFT_GUI,   KC_LEFT_CTRL,  G(KC_PAGE_UP), G(KC_PGDN),
                                                                               G(KC_HOME),    G(KC_END),         G(KC_ESC),     G(KC_DELETE),
                                                                                              G(KC_RIGHT),       G(KC_UP),
                                                                G(KC_ENTER),   G(KC_TAB),     G(KC_LEFT),        G(KC_DOWN),    G(KC_BSPC),    G(KC_SPACE)
  ),
  [LAY_QWERTY_ALT] = LAYOUT_ergodox_pretty(
/*  KEY COLUMN 1,  KEY COLUMN 2,  KEY COLUMN 3,  KEY COLUMN 4,  KEY COLUMN 5,  KEY COLUMN 6,  KEY COLUMN 7,      KEY COLUMN 8,  KEY COLUMN 9,  KEY COLUMN 10, KEY COLUMN 11, KEY COLUMN 12, KEY COLUMN 13, KEY COLUMN 14, */
    XXXXXXX,       A(KC_1),       A(KC_2),       A(KC_3),       A(KC_4),       A(KC_5),       XXXXXXX,           XXXXXXX,       A(KC_6),       A(KC_7),       A(KC_8),       A(KC_9),       A(KC_0),       A(KC_RBRC),
    XXXXXXX,       A(KC_Q),       A(KC_W),       A(KC_E),       A(KC_R),       A(KC_T),       A(KC_EQUAL),       A(KC_BSLS),    A(KC_Y),       A(KC_U),       A(KC_I),       A(KC_O),       A(KC_P),       A(KC_LBRC),
    XXXXXXX,       A(KC_A),       A(KC_S),       A(KC_D),       A(KC_F),       A(KC_G),                                         A(KC_H),       A(KC_J),       A(KC_K),       A(KC_L),       A(KC_SCLN),    A(KC_QUOTE),
    KC_LSFT,       A(KC_Z),       A(KC_X),       A(KC_C),       A(KC_V),       A(KC_B),       A(KC_MINUS),       A(KC_GRAVE),   A(KC_N),       A(KC_M),       A(KC_COMMA),   A(KC_DOT),     A(KC_SLASH),   KC_RSFT,
    XXXXXXX,       XXXXXXX,       KC_LEFT_CTRL,  KC_LEFT_GUI,   KC_LEFT_ALT,                                                                   KC_LEFT_ALT,   KC_LEFT_GUI,   KC_LEFT_CTRL,  A(KC_PAGE_UP), A(KC_PGDN),
                                                                               A(KC_HOME),    A(KC_END),         A(KC_ESC),     A(KC_DELETE),
                                                                                              A(KC_RIGHT),       A(KC_UP),
                                                                A(KC_ENTER),   A(KC_TAB),     A(KC_LEFT),        A(KC_DOWN),    A(KC_BSPC),    A(KC_SPACE)
  ),
};

const key_override_t *key_overrides[] = {
    &ezovrd_make_basic(MOD_MASK_SHIFT, KC_COMMA, UM(U_LTE)),
    &ezovrd_make_basic(MOD_MASK_SHIFT, KC_DOT, UM(U_GTE)),
    &ezovrd_make_basic(MOD_MASK_SHIFT, TD(NEXT_FF), UM(U_N_ARROW)),
    &ezovrd_make_basic(MOD_MASK_SHIFT, TD(PREV_RW), UM(U_S_ARROW)),
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

// Use the callback for OS detection to flash different
// lights for different OS.
bool process_detected_host_os_user(os_variant_t detected_os) {

    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            // Flash the red light
            ergodox_right_led_1_on();
            ergodox_right_led_2_off();
            break;
        case OS_WINDOWS:
            // Flash the red and green lights
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case OS_LINUX:
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
