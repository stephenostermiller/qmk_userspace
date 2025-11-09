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
    LAY_NUMBER_PAD, // number keypad, function keys, available from either base layer
    LAY_QWERTY_CONTROL, // qwerty overlay with ctrl key pressed
    LAY_QWERTY_META, // qwerty overlay with meta key pressed
    LAY_QWERTY_ALT, // qwerty overlay with alt key pressed
    LAY_FANCY, // Fancy unicode letters
};

// used as portions of tap dances
enum custom_keycodes {
    MO_TG_QWERTY = SAFE_RANGE, MO_TG_NUM,
};

// handle custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MO_TG_QWERTY:
            // toggle the qwerty layer while held
            layer_invert(LAY_QWERTY);
            return false;
        case MO_TG_NUM:
             // toggle the num/fn layer while held
            layer_invert(LAY_NUMBER_PAD);
            return false;
    }
    return true;
}

const char u_bullet[] PROGMEM = "•";
const char u_wbullet[] PROGMEM = "◦";
const char u_tbullet[] PROGMEM = "▸";
const char u_twbullet[] PROGMEM = "▹";
const char u_sbullet[] PROGMEM = "▪";
const char u_swbullet[] PROGMEM = "▫";
const char u_em_dash[] PROGMEM = "—";
const char u_ellipsis[] PROGMEM = "…";
const char u_degree[] PROGMEM = "°";
const char u_cent[] PROGMEM = "¢";
const char u_lsquot[] PROGMEM = "“";
const char u_rsquot[] PROGMEM = "”";
const char u_lsapos[] PROGMEM = "‘";
const char u_rsapos[] PROGMEM = "’";
const char u_brkpip[] PROGMEM = "¦";
const char u_section[] PROGMEM = "§";
const char u_pilcrow[] PROGMEM = "¶";

const char u_w_arrow[] PROGMEM = "←";
const char u_n_arrow[] PROGMEM = "↑";
const char u_e_arrow[] PROGMEM = "→";
const char u_s_arrow[] PROGMEM = "↓";
const char u_sw_arrow[] PROGMEM = "↙";
const char u_se_arrow[] PROGMEM = "↘";
const char u_nw_arrow[] PROGMEM = "↖";
const char u_ne_arrow[] PROGMEM = "↗";
const char u_ew_arrow[] PROGMEM = "↔";
const char u_ns_arrow[] PROGMEM = "↕";
const char u_nwse_arrow[] PROGMEM = "⤡";
const char u_nesw_arrow[] PROGMEM = "⤢";

const char u_b_w_arrow[] PROGMEM = "⬅";
const char u_b_n_arrow[] PROGMEM = "⬆";
const char u_b_e_arrow[] PROGMEM = "➡";
const char u_b_s_arrow[] PROGMEM = "⬇";
const char u_b_sw_arrow[] PROGMEM = "⬋";
const char u_b_se_arrow[] PROGMEM = "⬊";
const char u_b_nw_arrow[] PROGMEM = "⬉";
const char u_b_ne_arrow[] PROGMEM = "⬈";
const char u_b_ew_arrow[] PROGMEM = "⬌";
const char u_b_ns_arrow[] PROGMEM = "⬍";

const char u_w_w_arrow[] PROGMEM = "⇦";
const char u_w_n_arrow[] PROGMEM = "⇧";
const char u_w_e_arrow[] PROGMEM = "⇨";
const char u_w_s_arrow[] PROGMEM = "⇩";
const char u_w_sw_arrow[] PROGMEM = "⬃";
const char u_w_se_arrow[] PROGMEM = "⬂";
const char u_w_nw_arrow[] PROGMEM = "⬁";
const char u_w_ne_arrow[] PROGMEM = "⬀";
const char u_w_ew_arrow[] PROGMEM = "⬄";
const char u_w_ns_arrow[] PROGMEM = "⇳";

const char u_d_w_arrow[] PROGMEM = "⇐";
const char u_d_n_arrow[] PROGMEM = "⇑";
const char u_d_e_arrow[] PROGMEM = "⇒";
const char u_d_s_arrow[] PROGMEM = "⇓";
const char u_d_sw_arrow[] PROGMEM = "⇙";
const char u_d_se_arrow[] PROGMEM = "⇘";
const char u_d_nw_arrow[] PROGMEM = "⇖";
const char u_d_ne_arrow[] PROGMEM = "⇗";
const char u_d_ew_arrow[] PROGMEM = "⇔";
const char u_d_ns_arrow[] PROGMEM = "⇕";

const char u_bb3_w_arrow[] PROGMEM = "🡰";
const char u_bb3_n_arrow[] PROGMEM = "🡱";
const char u_bb3_e_arrow[] PROGMEM = "🡲";
const char u_bb3_s_arrow[] PROGMEM = "🡳";
const char u_bb3_sw_arrow[] PROGMEM = "🡷";
const char u_bb3_se_arrow[] PROGMEM = "🡶";
const char u_bb3_nw_arrow[] PROGMEM = "🡴";
const char u_bb3_ne_arrow[] PROGMEM = "🡵";

const char u_bb5_w_arrow[] PROGMEM = "🢀";
const char u_bb5_n_arrow[] PROGMEM = "🢁";
const char u_bb5_e_arrow[] PROGMEM = "🢂";
const char u_bb5_s_arrow[] PROGMEM = "🢃";
const char u_bb5_sw_arrow[] PROGMEM = "🢇";
const char u_bb5_se_arrow[] PROGMEM = "🢆";
const char u_bb5_nw_arrow[] PROGMEM = "🢄";
const char u_bb5_ne_arrow[] PROGMEM = "🢅";

const char u_box_empty[] PROGMEM = "☐";
const char u_box_checked[] PROGMEM = "☑";
const char u_box_crossed[] PROGMEM = "☒";
const char u_black_star[] PROGMEM = "★";
const char u_white_star[] PROGMEM = "☆";
const char u_cpyrght[] PROGMEM = "©";
const char u_rgstrd[] PROGMEM = "®";
const char u_trdmrk[] PROGMEM = "™";
const char u_smile0[] PROGMEM = "🙂";
const char u_smile1[] PROGMEM = "😃";
const char u_smile2[] PROGMEM = "😊";
const char u_frown[] PROGMEM = "🙁";
const char u_laugh[] PROGMEM = "😆";
const char u_snicker[] PROGMEM = "🤭";
const char u_rofl[] PROGMEM = "🤣";
const char u_mnd_blwn[] PROGMEM = "🤯";
const char u_salute[] PROGMEM = "🫡";
const char u_meltfc[] PROGMEM = "🫠";
const char u_tears[] PROGMEM = "🥹";
const char u_cry[] PROGMEM = "😭";
const char u_skull[] PROGMEM = "💀";
const char u_whtchk[] PROGMEM = "✅";
const char u_cross[] PROGMEM = "❌";
const char u_100[] PROGMEM = "💯";
const char u_fire[] PROGMEM = "🔥";
const char u_hndsair[] PROGMEM = "🙌";
const char u_party0[] PROGMEM = "🎉";
const char u_party1[] PROGMEM = "🥳";
const char u_party2[] PROGMEM = "🎊";
const char u_party3[] PROGMEM = "🪩";
const char u_party4[] PROGMEM = "🎇";
const char u_party5[] PROGMEM = "🎆";
const char u_music_2[] PROGMEM = "🎵";
const char u_music_3[] PROGMEM = "🎶";
const char u_sparkles[] PROGMEM = "✨";
const char u_eyes[] PROGMEM = "👀";
const char u_ship[] PROGMEM = "🚢";
const char u_delivery[] PROGMEM = "🚚";
const char u_bug[] PROGMEM = "🐞";
const char u_thmb_up[] PROGMEM = "👍";
const char u_thmb_dn[] PROGMEM = "👎";
const char u_link[] PROGMEM = "🔗";
const char u_palmtr[] PROGMEM = "🌴";
const char u_warning[] PROGMEM = "⚠️";
const char u_tip[] PROGMEM = "💡";
const char u_info[] PROGMEM = "ℹ️";
const char u_do_not[] PROGMEM = "🚫";
const char u_no_entry[] PROGMEM = "⛔";
const char u_klaxon[] PROGMEM = "🚨";
const char u_heart[] PROGMEM = "❤️";
const char u_heart_hands[] PROGMEM = "🫶";
const char u_heart_eyes[] PROGMEM = "😍";
const char u_heart_smile[] PROGMEM = "🥰";
const char u_ham_men[] PROGMEM = "☰";

const char u_div[] PROGMEM = "÷";
const char u_h_div[] PROGMEM = "➗";
const char u_plus_min[] PROGMEM = "±";
const char u_h_plus[] PROGMEM = "➕";
const char u_mult[] PROGMEM = "×";
const char u_h_mult[] PROGMEM = "✖";
const char u_minus[] PROGMEM = "−";
const char u_h_minus[] PROGMEM = "➖";
const char u_app_eq[] PROGMEM = "≈";
const char u_h_eq[] PROGMEM = "🟰";
const char u_ne[] PROGMEM = "≠";
const char u_lte[] PROGMEM = "≤";
const char u_gte[] PROGMEM = "≥";
const char u_infinity[] PROGMEM = "∞";
const char u_inc_infinity[] PROGMEM = "⧜";
const char u_tie_ovr_infinity[] PROGMEM = "⧝";
const char u_neg_infinity[] PROGMEM = "⧞";
const char u_root_2[] PROGMEM = "√";
const char u_root_3[] PROGMEM = "∛";
const char u_root_4[] PROGMEM = "∜";
const char u_sum[] PROGMEM = "∑";
const char u_integral[] PROGMEM = "∫";
const char u_pow_2[] PROGMEM = "²";
const char u_pow_3[] PROGMEM = "³";
const char u_pow_4[] PROGMEM = "⁴";
const char u_pow_5[] PROGMEM = "⁵";
const char u_pow_6[] PROGMEM = "⁶";
const char u_pow_7[] PROGMEM = "⁷";
const char u_set_element[] PROGMEM = "∈";
const char u_set_not_element[] PROGMEM = "∉";
const char u_set_sub[] PROGMEM = "⊂";
const char u_set_sub_equal[] PROGMEM = "⊆";
const char u_set_union[] PROGMEM = "∪";
const char u_set_intersection[] PROGMEM = "∩";
const char u_pi[] PROGMEM = "π";
const char u_imaginary_i[] PROGMEM = "ⅈ";
const char u_imaginary_j[] PROGMEM = "ⅉ";
const char u_euler[] PROGMEM = "ℯ";
const char u_delta[] PROGMEM = "𝜟";
const char u_empty_set[] PROGMEM = "∅";
const char u_integral_2[] PROGMEM = "∬";
const char u_partial_diff[] PROGMEM = "∂";
const char u_prime[] PROGMEM = "′";
const char u_prime_2[] PROGMEM = "″";
const char u_frac_1_8[] PROGMEM = "⅛";
const char u_frac_1_4[] PROGMEM = "¼";
const char u_frac_1_3[] PROGMEM = "⅓";
const char u_frac_3_8[] PROGMEM = "⅜";
const char u_frac_1_2[] PROGMEM = "½";
const char u_frac_5_8[] PROGMEM = "⅝";
const char u_frac_2_3[] PROGMEM = "⅔";
const char u_frac_3_4[] PROGMEM = "¾";
const char u_frac_7_8[] PROGMEM = "⅞";
const char u_frac_1_10[] PROGMEM = "⅒";

enum unicode_names {
    U_BULLET, U_EM_DASH, U_W_ARROW, U_N_ARROW, U_E_ARROW, U_S_ARROW, U_SW_ARROW, U_SE_ARROW, U_NW_ARROW, U_NE_ARROW, U_EW_ARROW, U_NS_ARROW, U_NWSE_ARROW,
    U_NESW_ARROW, U_B_W_ARROW, U_B_N_ARROW, U_B_E_ARROW, U_B_S_ARROW, U_B_SW_ARROW, U_B_SE_ARROW, U_B_NW_ARROW, U_B_NE_ARROW, U_B_EW_ARROW, U_B_NS_ARROW,
    U_W_W_ARROW, U_W_N_ARROW, U_W_E_ARROW, U_W_S_ARROW, U_W_SW_ARROW, U_W_SE_ARROW, U_W_NW_ARROW, U_W_NE_ARROW, U_W_EW_ARROW, U_W_NS_ARROW, U_BOX_EMPTY,
    U_BOX_CHECKED, U_BOX_CROSSED, U_BLACK_STAR, U_WHITE_STAR, U_CPYRGHT, U_RGSTRD, U_TRDMRK, U_SMILE0, U_ROFL, U_MND_BLWN, U_SALUTE, U_MELTFC, U_TEARS,
    U_CRY, U_SKULL, U_WHTCHK, U_CROSS, U_100, U_FIRE, U_HNDSAIR, U_PARTY0, U_MUSIC_2, U_MUSIC_3, U_SPARKLES, U_EYES, U_SHIP, U_DELIVERY, U_BUG, U_THMB_UP,
    U_THMB_DN, U_LINK, U_PALMTR, U_WARNING, U_HEART, U_DIV, U_H_DIV, U_PLUS_MIN, U_H_PLUS, U_MULT, U_H_MULT, U_MINUS, U_H_MINUS, U_APP_EQ, U_H_EQ, U_NE,
    U_LTE, U_GTE, U_D_W_ARROW, U_D_N_ARROW, U_D_E_ARROW, U_D_S_ARROW, U_D_SW_ARROW, U_D_SE_ARROW, U_D_NW_ARROW, U_D_NE_ARROW, U_D_EW_ARROW, U_D_NS_ARROW,
    U_BB3_W_ARROW, U_BB3_N_ARROW, U_BB3_E_ARROW, U_BB3_S_ARROW, U_BB3_SW_ARROW, U_BB3_SE_ARROW, U_BB3_NW_ARROW, U_BB3_NE_ARROW, U_BB5_W_ARROW,
    U_BB5_N_ARROW, U_BB5_E_ARROW, U_BB5_S_ARROW, U_BB5_SW_ARROW, U_BB5_SE_ARROW, U_BB5_NW_ARROW, U_BB5_NE_ARROW, U_INFINITY, U_INC_INFINITY,
    U_TIE_OVR_INFINITY, U_NEG_INFINITY,U_SMILE1, U_SMILE2, U_LAUGH, U_HEART_HANDS, U_HEART_EYES, U_HEART_SMILE, U_PARTY1, U_PARTY2, U_PARTY3, U_PARTY4,
    U_PARTY5, U_SNICKER, U_ROOT_2, U_ROOT_3, U_ROOT_4, U_SUM, U_INTEGRAL, U_POW_2, U_POW_3, U_POW_4, U_POW_5, U_POW_6, U_POW_7, U_SET_ELEMENT,
    U_SET_NOT_ELEMENT, U_SET_SUB, U_SET_SUB_EQUAL, U_SET_UNION, U_SET_INTERSECTION, U_PI, U_IMAGINARY_I, U_IMAGINARY_J, U_EULER, U_DELTA, U_EMPTY_SET,
    U_INTEGRAL_2, U_PARTIAL_DIFF, U_PRIME, U_PRIME_2, U_ELLIPSIS, U_FRAC_1_8, U_FRAC_1_4, U_FRAC_1_3, U_FRAC_3_8, U_FRAC_1_2, U_FRAC_5_8, U_FRAC_2_3,
    U_FRAC_3_4, U_FRAC_7_8, U_TIP, U_INFO, U_DO_NOT, U_NO_ENTRY, U_KLAXON, U_FROWN, U_FRAC_1_10, U_HAM_MEN, U_WBULLET, U_TBULLET, U_TWBULLET, U_SBULLET,
    U_SWBULLET, U_LSQUOT, U_RSQUOT, U_LSAPOS, U_RSAPOS, U_DEGREE, U_CENT, U_BRKPIP, U_SECTION, U_PILCROW,

};

const char* const unicode_macro_map[] PROGMEM = {
    [U_BULLET] = u_bullet,
    [U_WBULLET] = u_wbullet,
    [U_TBULLET] = u_tbullet,
    [U_TWBULLET] = u_twbullet,
    [U_SBULLET] = u_sbullet,
    [U_SWBULLET] = u_swbullet,

    [U_EM_DASH] = u_em_dash,
    [U_ELLIPSIS] = u_ellipsis,
    [U_DEGREE] = u_degree,
    [U_CENT] = u_cent,
    [U_LSQUOT] = u_lsquot,
    [U_RSQUOT] = u_rsquot,
    [U_LSAPOS] = u_lsapos,
    [U_RSAPOS] = u_rsapos,
    [U_BRKPIP] = u_brkpip,
    [U_SECTION] = u_section,
    [U_PILCROW] = u_pilcrow,

    [U_W_ARROW] = u_w_arrow,
    [U_N_ARROW] = u_n_arrow,
    [U_E_ARROW] = u_e_arrow,
    [U_S_ARROW] = u_s_arrow,
    [U_SW_ARROW] = u_sw_arrow,
    [U_SE_ARROW] = u_se_arrow,
    [U_NW_ARROW] = u_nw_arrow,
    [U_NE_ARROW] = u_ne_arrow,
    [U_EW_ARROW] = u_ew_arrow,
    [U_NS_ARROW] = u_ns_arrow,
    [U_NWSE_ARROW] = u_nwse_arrow,
    [U_NESW_ARROW] = u_nesw_arrow,

    [U_B_W_ARROW] = u_b_w_arrow,
    [U_B_N_ARROW] = u_b_n_arrow,
    [U_B_E_ARROW] = u_b_e_arrow,
    [U_B_S_ARROW] = u_b_s_arrow,
    [U_B_SW_ARROW] = u_b_sw_arrow,
    [U_B_SE_ARROW] = u_b_se_arrow,
    [U_B_NW_ARROW] = u_b_nw_arrow,
    [U_B_NE_ARROW] = u_b_ne_arrow,
    [U_B_EW_ARROW] = u_b_ew_arrow,
    [U_B_NS_ARROW] = u_b_ns_arrow,

    [U_W_W_ARROW] = u_w_w_arrow,
    [U_W_N_ARROW] = u_w_n_arrow,
    [U_W_E_ARROW] = u_w_e_arrow,
    [U_W_S_ARROW] = u_w_s_arrow,
    [U_W_SW_ARROW] = u_w_sw_arrow,
    [U_W_SE_ARROW] = u_w_se_arrow,
    [U_W_NW_ARROW] = u_w_nw_arrow,
    [U_W_NE_ARROW] = u_w_ne_arrow,
    [U_W_EW_ARROW] = u_w_ew_arrow,
    [U_W_NS_ARROW] = u_w_ns_arrow,

    [U_D_W_ARROW] = u_d_w_arrow,
    [U_D_N_ARROW] = u_d_n_arrow,
    [U_D_E_ARROW] = u_d_e_arrow,
    [U_D_S_ARROW] = u_d_s_arrow,
    [U_D_SW_ARROW] = u_d_sw_arrow,
    [U_D_SE_ARROW] = u_d_se_arrow,
    [U_D_NW_ARROW] = u_d_nw_arrow,
    [U_D_NE_ARROW] = u_d_ne_arrow,
    [U_D_EW_ARROW] = u_d_ew_arrow,
    [U_D_NS_ARROW] = u_d_ns_arrow,

    [U_BB3_W_ARROW] = u_bb3_w_arrow,
    [U_BB3_N_ARROW] = u_bb3_n_arrow,
    [U_BB3_E_ARROW] = u_bb3_e_arrow,
    [U_BB3_S_ARROW] = u_bb3_s_arrow,
    [U_BB3_SW_ARROW] = u_bb3_sw_arrow,
    [U_BB3_SE_ARROW] = u_bb3_se_arrow,
    [U_BB3_NW_ARROW] = u_bb3_nw_arrow,
    [U_BB3_NE_ARROW] = u_bb3_ne_arrow,

    [U_BB5_W_ARROW] = u_bb5_w_arrow,
    [U_BB5_N_ARROW] = u_bb5_n_arrow,
    [U_BB5_E_ARROW] = u_bb5_e_arrow,
    [U_BB5_S_ARROW] = u_bb5_s_arrow,
    [U_BB5_SW_ARROW] = u_bb5_sw_arrow,
    [U_BB5_SE_ARROW] = u_bb5_se_arrow,
    [U_BB5_NW_ARROW] = u_bb5_nw_arrow,
    [U_BB5_NE_ARROW] = u_bb5_ne_arrow,

    [U_BOX_EMPTY] = u_box_empty,
    [U_BOX_CHECKED] = u_box_checked,
    [U_BOX_CROSSED] = u_box_crossed,
    [U_BLACK_STAR] = u_black_star,
    [U_WHITE_STAR] = u_white_star,
    [U_CPYRGHT] = u_cpyrght,
    [U_RGSTRD] = u_rgstrd,
    [U_TRDMRK] = u_trdmrk,
    [U_SMILE0] = u_smile0,
    [U_SMILE1] = u_smile1,
    [U_SMILE2] = u_smile2,
    [U_FROWN] = u_frown,
    [U_LAUGH] = u_laugh,
    [U_SNICKER] = u_snicker,
    [U_ROFL] = u_rofl,
    [U_MND_BLWN] = u_mnd_blwn,
    [U_SALUTE] = u_salute,
    [U_MELTFC] = u_meltfc,
    [U_TEARS] = u_tears,
    [U_CRY] = u_cry,
    [U_SKULL] = u_skull,
    [U_WHTCHK] = u_whtchk,
    [U_CROSS] = u_cross,
    [U_100] = u_100,
    [U_FIRE] = u_fire,
    [U_HNDSAIR] = u_hndsair,
    [U_PARTY0] = u_party0,
    [U_PARTY1] = u_party1,
    [U_PARTY2] = u_party2,
    [U_PARTY3] = u_party3,
    [U_PARTY4] = u_party4,
    [U_PARTY5] = u_party5,
    [U_MUSIC_2] = u_music_2,
    [U_MUSIC_3] = u_music_3,
    [U_SPARKLES] = u_sparkles,
    [U_EYES] = u_eyes,
    [U_SHIP] = u_ship,
    [U_DELIVERY] = u_delivery,
    [U_BUG] = u_bug,
    [U_THMB_UP] = u_thmb_up,
    [U_THMB_DN] = u_thmb_dn,
    [U_LINK] = u_link,
    [U_PALMTR] = u_palmtr,
    [U_WARNING] = u_warning,
    [U_TIP] = u_tip,
    [U_INFO] = u_info,
    [U_DO_NOT] = u_do_not,
    [U_NO_ENTRY] = u_no_entry,
    [U_KLAXON] = u_klaxon,
    [U_HEART] = u_heart,
    [U_HEART_HANDS] = u_heart_hands,
    [U_HEART_EYES] = u_heart_eyes,
    [U_HEART_SMILE] = u_heart_smile,

    [U_DIV] = u_div,
    [U_H_DIV] = u_h_div,
    [U_PLUS_MIN] = u_plus_min,
    [U_H_PLUS] = u_h_plus,
    [U_MULT] = u_mult,
    [U_H_MULT] = u_h_mult,
    [U_MINUS] = u_minus,
    [U_H_MINUS] = u_h_minus,
    [U_APP_EQ] = u_app_eq,
    [U_H_EQ] = u_h_eq,
    [U_NE] = u_ne,
    [U_LTE] = u_lte,
    [U_GTE] = u_gte,
    [U_INFINITY] = u_infinity,
    [U_INC_INFINITY] = u_inc_infinity,
    [U_TIE_OVR_INFINITY] = u_tie_ovr_infinity,
    [U_NEG_INFINITY] = u_neg_infinity,
    [U_ROOT_2] = u_root_2,
    [U_ROOT_3] = u_root_3,
    [U_ROOT_4] = u_root_4,
    [U_SUM] = u_sum,
    [U_INTEGRAL] = u_integral,
    [U_POW_2] = u_pow_2,
    [U_POW_3] = u_pow_3,
    [U_POW_4] = u_pow_4,
    [U_POW_5] = u_pow_5,
    [U_POW_6] = u_pow_6,
    [U_POW_7] = u_pow_7,
    [U_SET_ELEMENT] = u_set_element,
    [U_SET_NOT_ELEMENT] = u_set_not_element,
    [U_SET_SUB] = u_set_sub,
    [U_SET_SUB_EQUAL] = u_set_sub_equal,
    [U_SET_UNION] = u_set_union,
    [U_SET_INTERSECTION] = u_set_intersection,
    [U_PI] = u_pi,
    [U_IMAGINARY_I] = u_imaginary_i,
    [U_IMAGINARY_J] = u_imaginary_j,
    [U_EULER] = u_euler,
    [U_DELTA] = u_delta,
    [U_EMPTY_SET] = u_empty_set,
    [U_INTEGRAL_2] = u_integral_2,
    [U_PARTIAL_DIFF] = u_partial_diff,
    [U_PRIME] = u_prime,
    [U_PRIME_2] = u_prime_2,
    [U_FRAC_1_8] = u_frac_1_8,
    [U_FRAC_1_4] = u_frac_1_4,
    [U_FRAC_1_3] = u_frac_1_3,
    [U_FRAC_3_8] = u_frac_3_8,
    [U_FRAC_1_2] = u_frac_1_2,
    [U_FRAC_5_8] = u_frac_5_8,
    [U_FRAC_2_3] = u_frac_2_3,
    [U_FRAC_3_4] = u_frac_3_4,
    [U_FRAC_7_8] = u_frac_7_8,
    [U_FRAC_1_10] = u_frac_1_10,
    [U_HAM_MEN] = u_ham_men,
};

#define KC_FULL_SCREEN KC_F11

enum tap_dance_keycodes {
    LCDT_SHFT, LCDT_CRTL, LCDT_META, LCDT_ALT, RCDT_ALT, RCDT_META, RCDT_CRTL, RCDT_SHFT, LAY_OUT, FANC_ALPH, TD_PERC, HOME_TOP, END_BTM, W_ARROW,
    N_ARROW, E_ARROW, S_ARROW, SW_ARROW, SE_ARROW, NW_ARROW, NE_ARROW, EW_ARROW, NS_ARROW, DIAG_ARROW, DIVIDES, MULTIPLIES, SUBTRACTS, ADDS, EQUALS,
    TD_INF, EM_SMILE, EM_LOL, EM_LOVE, EM_PARTY, MTH_ROOT, MTH_PWR, MTH_CLCLS, MTH_SET, MTH_PAREN, MTH_CONST, EM_LIKE, EM_CAUTN, EM_LGL_IP, EM_BALLOT, EM_SAD,
    F1_FRAC, F2_FRAC, F3_FRAC, F4_FRAC, F5_FRAC, F6_FRAC, F7_FRAC, F8_FRAC, F9_FRAC, F10_FRAC, MSC_FACE, MSC_ICN, EM_CD_RVW, MINU_DASH, DOT_GTE, TD_AMP, TD_7,
    TD_8, TD_BSLS, TD_SLASH, TD_APOS, TD_DQT, TD_DOL, TD_ASRK, TD_PLUS, TD_PIPE, TD_SCLN
};

const eztd_data_t eztd_data[] PROGMEM = {
    [LCDT_SHFT] = EZTD_TAP_HOLD_DTAP(KC_LEFT_PAREN, KC_LEFT_SHIFT, QK_CAPS_WORD_TOGGLE),
    [LCDT_CRTL] = EZTD_TAP_HOLD_DTAP_DHOLD_TTAP_THOLD(KC_LEFT_ANGLE_BRACKET,  LM(LAY_QWERTY_CONTROL, MOD_MASK_CTRL), KC_CALCULATOR, KC_CALCULATOR, KC_MY_COMPUTER, KC_MY_COMPUTER),
    [LCDT_META] = EZTD_TAP_HOLD_DTAP_DHOLD_TTAP_THOLD(KC_LEFT_BRACKET, LM(LAY_QWERTY_META, MOD_MASK_GUI), KC_PRINT_SCREEN, KC_PRINT_SCREEN, KC_MAIL, KC_MAIL),
    [LCDT_ALT] = EZTD_TAP_HOLD_DTAP_DHOLD_TTAP_THOLD(KC_LEFT_CURLY_BRACE, LM(LAY_QWERTY_ALT, MOD_MASK_ALT), KC_INS, KC_INS, QK_AUTO_SHIFT_TOGGLE, QK_AUTO_SHIFT_TOGGLE),
    [RCDT_ALT] = EZTD_TAP_HOLD_DTAP(KC_RIGHT_CURLY_BRACE, LM(LAY_QWERTY_ALT, MOD_MASK_ALT), G(KC_L)),
    [RCDT_META] = EZTD_TAP_HOLD_DTAP(KC_RIGHT_BRACKET, LM(LAY_QWERTY_META, MOD_MASK_GUI), KC_FULL_SCREEN),
    [RCDT_CRTL] = EZTD_TAP_HOLD_DTAP(KC_RIGHT_ANGLE_BRACKET, LM(LAY_QWERTY_CONTROL, MOD_MASK_CTRL), A(KC_F4)),
    [RCDT_SHFT] = EZTD_TAP_HOLD_DTAP(KC_RIGHT_PAREN, KC_RIGHT_SHIFT, KC_CAPS),
    [LAY_OUT] = EZTD_TAP_HOLD_DTAP_DHOLD_TTAP(KC_COLON, MO_TG_NUM, TG(LAY_NUMBER_PAD), MO_TG_QWERTY, TG(LAY_QWERTY)),
    [FANC_ALPH] = EZTD_TAP_HOLD_DTAP(KC_QUESTION, KC_UNICODE_FANCY_ALPHABET_MOMENTARY, KC_UNICODE_FANCY_ALPHABET_CYCLE),
    [TD_PERC] = EZTD_ALLTAP_HOLD(KC_PERCENT, C(S(KC_O))),
    [TD_AMP] = EZTD_ALLTAP_HOLD_DHOLD(KC_AMPERSAND, C(S(KC_M)), KC_AUDIO_MUTE),
    [TD_PIPE] = EZTD_FLOWTAP_HOLD(KC_PIPE, UM(U_BRKPIP)),
    [TD_SCLN] = EZTD_FLOWTAP_HOLD_DTAP(KC_SCLN, UM(U_SECTION), UM(U_PILCROW)),
    [HOME_TOP] =  EZTD_FLOWTAP_DTAP(KC_HOME, C(KC_HOME)),
    [END_BTM] = EZTD_FLOWTAP_DTAP(KC_END, C(KC_END)),
    [MINU_DASH] = EZTD_ALLTAP_HOLD_DHOLD(KC_MINUS, KC_UNDERSCORE, UM(U_EM_DASH)),
    [TD_APOS] = EZTD_FLOWTAP_HOLD_DHOLD(KC_QUOTE, UM(U_LSAPOS), UM(U_RSAPOS)),
    [TD_DQT] = EZTD_FLOWTAP_HOLD_DHOLD(KC_DQT, UM(U_LSQUOT), UM(U_RSQUOT)),
    [DOT_GTE] = EZTD_FLOWTAP_HOLD_TTAP(KC_DOT, UM(U_GTE), UM(U_ELLIPSIS)),
    [TD_7] =  EZTD_FLOWTAP_HOLD_DHOLD_THOLD(KC_7, UM(U_WBULLET), UM(U_TWBULLET), UM(U_SWBULLET)),
    [TD_8] =  EZTD_FLOWTAP_HOLD_DHOLD_THOLD(KC_8, UM(U_BULLET), UM(U_TBULLET), UM(U_SBULLET)),
    [W_ARROW] =  EZTD_FLOWTAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_W_ARROW), UM(U_B_W_ARROW), UM(U_W_W_ARROW), UM(U_D_W_ARROW), UM(U_BB3_W_ARROW), UM(U_BB5_W_ARROW)),
    [N_ARROW] =  EZTD_FLOWTAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_N_ARROW), UM(U_B_N_ARROW), UM(U_W_N_ARROW), UM(U_D_N_ARROW), UM(U_BB3_N_ARROW), UM(U_BB5_N_ARROW)),
    [E_ARROW] =  EZTD_FLOWTAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_E_ARROW), UM(U_B_E_ARROW), UM(U_W_E_ARROW), UM(U_D_E_ARROW), UM(U_BB3_E_ARROW), UM(U_BB5_E_ARROW)),
    [S_ARROW] =  EZTD_FLOWTAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_S_ARROW), UM(U_B_S_ARROW), UM(U_W_S_ARROW), UM(U_D_S_ARROW), UM(U_BB3_S_ARROW), UM(U_BB5_S_ARROW)),
    [SW_ARROW] = EZTD_FLOWTAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_SW_ARROW), UM(U_B_SW_ARROW), UM(U_W_SW_ARROW), UM(U_D_SW_ARROW), UM(U_BB3_SW_ARROW), UM(U_BB5_SW_ARROW)),
    [SE_ARROW] = EZTD_FLOWTAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_SE_ARROW), UM(U_B_SE_ARROW), UM(U_W_SE_ARROW), UM(U_D_SE_ARROW), UM(U_BB3_SE_ARROW), UM(U_BB5_SE_ARROW)),
    [NW_ARROW] = EZTD_FLOWTAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_NW_ARROW), UM(U_B_NW_ARROW), UM(U_W_NW_ARROW), UM(U_D_NW_ARROW), UM(U_BB3_NW_ARROW), UM(U_BB5_NW_ARROW)),
    [NE_ARROW] = EZTD_FLOWTAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_NE_ARROW), UM(U_B_NE_ARROW), UM(U_W_NE_ARROW), UM(U_D_NE_ARROW), UM(U_BB3_NE_ARROW), UM(U_BB5_NE_ARROW)),
    [EW_ARROW] = EZTD_FLOWTAP_HOLD_DTAP_DHOLD(UM(U_EW_ARROW), UM(U_B_EW_ARROW), UM(U_W_EW_ARROW), UM(U_D_EW_ARROW)),
    [NS_ARROW] = EZTD_FLOWTAP_HOLD_DTAP_DHOLD(UM(U_NS_ARROW), UM(U_B_NS_ARROW), UM(U_W_NS_ARROW), UM(U_D_NS_ARROW)),
    [DIAG_ARROW] = EZTD_FLOWTAP_HOLD(UM(U_NESW_ARROW), UM(U_NWSE_ARROW)),
    [DIVIDES] = EZTD_FLOWTAP_HOLD_DTAP(KC_KP_SLASH, UM(U_DIV), UM(U_H_DIV)),
    [MULTIPLIES] = EZTD_FLOWTAP_HOLD_DTAP(KC_KP_ASTERISK, UM(U_MULT), UM(U_H_MULT)),
    [SUBTRACTS] = EZTD_FLOWTAP_HOLD_DTAP(KC_KP_MINUS, UM(U_MINUS), UM(U_H_MINUS)),
    [ADDS] = EZTD_FLOWTAP_HOLD_DTAP(KC_KP_PLUS, UM(U_PLUS_MIN), UM(U_H_PLUS)),
    [EQUALS] = EZTD_FLOWTAP_HOLD_DTAP_DHOLD(KC_KP_EQUAL, UM(U_NE), UM(U_H_EQ), UM(U_APP_EQ)),
    [TD_INF] = EZTD_FLOWTAP_HOLD_DTAP_DHOLD(UM(U_INFINITY), UM(U_INC_INFINITY), UM(U_TIE_OVR_INFINITY), UM(U_NEG_INFINITY)),
    [EM_SMILE] = EZTD_FLOWTAP_HOLD_DTAP(UM(U_SMILE0), UM(U_SMILE1), UM(U_SMILE2)),
    [EM_LOL] = EZTD_FLOWTAP_HOLD_DTAP(UM(U_LAUGH), UM(U_SNICKER), UM(U_ROFL)),
    [EM_LOVE] = EZTD_FLOWTAP_HOLD_DTAP_DHOLD(UM(U_HEART), UM(U_HEART_HANDS), UM(U_HEART_EYES), UM(U_HEART_SMILE)),
    [EM_LIKE] = EZTD_FLOWTAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_THMB_UP), UM(U_100), UM(U_HNDSAIR), UM(U_MUSIC_2), UM(U_MUSIC_3), UM(U_FIRE)),
    [EM_CAUTN] = EZTD_FLOWTAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_INFO), UM(U_TIP), UM(U_WARNING), UM(U_DO_NOT), UM(U_NO_ENTRY), UM(U_KLAXON)),
    [EM_PARTY] =  EZTD_FLOWTAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_PARTY0), UM(U_PARTY1), UM(U_PARTY2), UM(U_PARTY3), UM(U_PARTY4), UM(U_PARTY5)),
    [EM_LGL_IP] = EZTD_FLOWTAP_HOLD_DTAP(UM(U_CPYRGHT), UM(U_RGSTRD), UM(U_TRDMRK)),
    [EM_BALLOT] = EZTD_FLOWTAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_WHTCHK), UM(U_CROSS), UM(U_BOX_CHECKED), UM(U_BOX_CROSSED), UM(U_BOX_EMPTY), UM(U_BOX_EMPTY)),
    [EM_SAD] =  EZTD_FLOWTAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_THMB_DN), UM(U_MELTFC), UM(U_FROWN), UM(U_SKULL), UM(U_CRY), UM(U_CRY)),
    [EM_CD_RVW] =  EZTD_FLOWTAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_EYES), UM(U_BUG), UM(U_WHTCHK), UM(U_WHTCHK), UM(U_SHIP), UM(U_DELIVERY)),
    [MSC_FACE] = EZTD_FLOWTAP_HOLD_DTAP(UM(U_MND_BLWN), UM(U_SALUTE), UM(U_TEARS)),
    [MSC_ICN] = EZTD_FLOWTAP_HOLD_DTAP_DHOLD(UM(U_LINK), UM(U_PALMTR), UM(U_HAM_MEN), UM(U_SPARKLES)),
    [MTH_ROOT] = EZTD_FLOWTAP_HOLD_DTAP(UM(U_ROOT_2), UM(U_ROOT_3), UM(U_ROOT_4)),
    [MTH_PWR] = EZTD_FLOWTAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_POW_2), UM(U_POW_3), UM(U_POW_4), UM(U_POW_5), UM(U_POW_6), UM(U_POW_7)),
    [MTH_CLCLS] = EZTD_FLOWTAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_DELTA), UM(U_INTEGRAL), UM(U_SUM), UM(U_INTEGRAL_2), UM(U_PARTIAL_DIFF), UM(U_PRIME)),
    [MTH_SET] = EZTD_FLOWTAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_SET_ELEMENT), UM(U_SET_NOT_ELEMENT), UM(U_SET_SUB), UM(U_SET_SUB_EQUAL), UM(U_SET_UNION), UM(U_SET_INTERSECTION)),
    [MTH_PAREN] = EZTD_FLOWTAP_HOLD(KC_LEFT_PAREN, KC_RIGHT_PAREN),
    [MTH_CONST] = EZTD_FLOWTAP_HOLD_DTAP_DHOLD_TTAP_THOLD(UM(U_PI), UM(U_IMAGINARY_I), UM(U_EULER), UM(U_IMAGINARY_J), UM(U_EMPTY_SET), UM(U_PRIME_2)),
    [F1_FRAC] = EZTD_FLOWTAP_HOLD_DTAP(KC_F1, UM(U_FRAC_1_10), UM(U_FRAC_1_10)),
    [F2_FRAC] = EZTD_FLOWTAP_HOLD_DTAP(KC_F2, UM(U_FRAC_1_2), UM(U_FRAC_1_2)),
    [F3_FRAC] = EZTD_FLOWTAP_HOLD_DTAP(KC_F3, UM(U_FRAC_1_3), UM(U_FRAC_1_3)),
    [F4_FRAC] = EZTD_FLOWTAP_HOLD_DTAP(KC_F4, UM(U_FRAC_1_4), UM(U_FRAC_1_4)),
    [F5_FRAC] = EZTD_FLOWTAP_HOLD_DTAP(KC_F5, UM(U_FRAC_2_3), UM(U_FRAC_2_3)),
    [F6_FRAC] = EZTD_FLOWTAP_HOLD_DTAP(KC_F6, UM(U_FRAC_3_4), UM(U_FRAC_3_4)),
    [F7_FRAC] = EZTD_FLOWTAP_HOLD_DTAP(KC_F7, UM(U_FRAC_1_8), UM(U_FRAC_1_8)),
    [F8_FRAC] = EZTD_FLOWTAP_HOLD_DTAP(KC_F8, UM(U_FRAC_3_8), UM(U_FRAC_3_8)),
    [F9_FRAC] = EZTD_FLOWTAP_HOLD_DTAP(KC_F9, UM(U_FRAC_5_8), UM(U_FRAC_5_8)),
    [F10_FRAC] = EZTD_FLOWTAP_HOLD_DTAP(KC_F10, UM(U_FRAC_7_8), UM(U_FRAC_7_8)),
    [TD_BSLS] = EZTD_FLOWTAP_HOLD_DHOLD_THOLD(KC_BSLS, KC_VOLU, KC_MEDIA_NEXT_TRACK, KC_MEDIA_FAST_FORWARD),
    [TD_SLASH] = EZTD_FLOWTAP_HOLD_DHOLD_THOLD(KC_SLASH, KC_VOLD, KC_MEDIA_PREV_TRACK, KC_MEDIA_REWIND),
    [TD_DOL] = EZTD_FLOWTAP_HOLD(KC_DOLLAR, UM(U_CENT)),
    [TD_ASRK] = EZTD_FLOWTAP_HOLD(KC_ASTERISK, UM(U_DEGREE)),
    [TD_PLUS] = EZTD_FLOWTAP_HOLD(KC_PLUS, UM(U_PLUS_MIN)),
};

const tap_dance_action_t tap_dance_actions[] PROGMEM = {
    [LCDT_SHFT] = EZTD_ACTION(eztd_data[LCDT_SHFT]),
    [LCDT_CRTL] = EZTD_ACTION(eztd_data[LCDT_CRTL]),
    [LCDT_META] = EZTD_ACTION(eztd_data[LCDT_META]),
    [LCDT_ALT] = EZTD_ACTION(eztd_data[LCDT_ALT]),
    [RCDT_ALT] = EZTD_ACTION(eztd_data[RCDT_ALT]),
    [RCDT_META] = EZTD_ACTION(eztd_data[RCDT_META]),
    [RCDT_CRTL] = EZTD_ACTION(eztd_data[RCDT_CRTL]),
    [RCDT_SHFT] = EZTD_ACTION(eztd_data[RCDT_SHFT]),
    [LAY_OUT] = EZTD_ACTION(eztd_data[LAY_OUT]),
    [FANC_ALPH] = EZTD_ACTION(eztd_data[FANC_ALPH]),
    [TD_PERC] = EZTD_ACTION(eztd_data[TD_PERC]),
    [TD_AMP] = EZTD_ACTION(eztd_data[TD_AMP]),
    [HOME_TOP] = EZTD_ACTION(eztd_data[HOME_TOP]),
    [END_BTM] = EZTD_ACTION(eztd_data[END_BTM]),
    [TD_7] = EZTD_ACTION(eztd_data[TD_7]),
    [TD_8] = EZTD_ACTION(eztd_data[TD_8]),
    [W_ARROW] = EZTD_ACTION(eztd_data[W_ARROW]),
    [N_ARROW] = EZTD_ACTION(eztd_data[N_ARROW]),
    [E_ARROW] = EZTD_ACTION(eztd_data[E_ARROW]),
    [S_ARROW] = EZTD_ACTION(eztd_data[S_ARROW]),
    [SW_ARROW] = EZTD_ACTION(eztd_data[SW_ARROW]),
    [SE_ARROW] = EZTD_ACTION(eztd_data[SE_ARROW]),
    [NW_ARROW] = EZTD_ACTION(eztd_data[NW_ARROW]),
    [NE_ARROW] = EZTD_ACTION(eztd_data[NE_ARROW]),
    [EW_ARROW] = EZTD_ACTION(eztd_data[EW_ARROW]),
    [NS_ARROW] = EZTD_ACTION(eztd_data[NS_ARROW]),
    [DIAG_ARROW] = EZTD_ACTION(eztd_data[DIAG_ARROW]),
    [DIVIDES] = EZTD_ACTION(eztd_data[DIVIDES]),
    [MULTIPLIES] = EZTD_ACTION(eztd_data[MULTIPLIES]),
    [SUBTRACTS] = EZTD_ACTION(eztd_data[SUBTRACTS]),
    [ADDS] = EZTD_ACTION(eztd_data[ADDS]),
    [EQUALS] = EZTD_ACTION(eztd_data[EQUALS]),
    [TD_INF] = EZTD_ACTION(eztd_data[TD_INF]),
    [EM_SMILE] = EZTD_ACTION(eztd_data[EM_SMILE]),
    [EM_LOL] = EZTD_ACTION(eztd_data[EM_LOL]),
    [EM_LOVE] = EZTD_ACTION(eztd_data[EM_LOVE]),
    [EM_LIKE] = EZTD_ACTION(eztd_data[EM_LIKE]),
    [EM_CAUTN] = EZTD_ACTION(eztd_data[EM_CAUTN]),
    [EM_PARTY] = EZTD_ACTION(eztd_data[EM_PARTY]),
    [EM_LGL_IP] = EZTD_ACTION(eztd_data[EM_LGL_IP]),
    [EM_BALLOT] = EZTD_ACTION(eztd_data[EM_BALLOT]),
    [EM_SAD] = EZTD_ACTION(eztd_data[EM_SAD]),
    [EM_CD_RVW] = EZTD_ACTION(eztd_data[EM_CD_RVW]),
    [MSC_FACE] = EZTD_ACTION(eztd_data[MSC_FACE]),
    [MSC_ICN] = EZTD_ACTION(eztd_data[MSC_ICN]),
    [MTH_ROOT] = EZTD_ACTION(eztd_data[MTH_ROOT]),
    [MTH_PWR] = EZTD_ACTION(eztd_data[MTH_PWR]),
    [MTH_CLCLS] = EZTD_ACTION(eztd_data[MTH_CLCLS]),
    [MTH_SET] = EZTD_ACTION(eztd_data[MTH_SET]),
    [MTH_PAREN] = EZTD_ACTION(eztd_data[MTH_PAREN]),
    [MTH_CONST] = EZTD_ACTION(eztd_data[MTH_CONST]),
    [F1_FRAC] = EZTD_ACTION(eztd_data[F1_FRAC]),
    [F2_FRAC] = EZTD_ACTION(eztd_data[F2_FRAC]),
    [F3_FRAC] = EZTD_ACTION(eztd_data[F3_FRAC]),
    [F4_FRAC] = EZTD_ACTION(eztd_data[F4_FRAC]),
    [F5_FRAC] = EZTD_ACTION(eztd_data[F5_FRAC]),
    [F6_FRAC] = EZTD_ACTION(eztd_data[F6_FRAC]),
    [F7_FRAC] = EZTD_ACTION(eztd_data[F7_FRAC]),
    [F8_FRAC] = EZTD_ACTION(eztd_data[F8_FRAC]),
    [F9_FRAC] = EZTD_ACTION(eztd_data[F9_FRAC]),
    [F10_FRAC] = EZTD_ACTION(eztd_data[F10_FRAC]),
    [MINU_DASH] = EZTD_ACTION(eztd_data[MINU_DASH]),
    [TD_APOS] = EZTD_ACTION(eztd_data[TD_APOS]),
    [TD_DQT] = EZTD_ACTION(eztd_data[TD_DQT]),
    [DOT_GTE] = EZTD_ACTION(eztd_data[DOT_GTE]),
    [TD_BSLS] = EZTD_ACTION(eztd_data[TD_BSLS]),
    [TD_SLASH] = EZTD_ACTION(eztd_data[TD_SLASH]),
    [TD_DOL] = EZTD_ACTION(eztd_data[TD_DOL]),
    [TD_ASRK] = EZTD_ACTION(eztd_data[TD_ASRK]),
    [TD_PLUS] = EZTD_ACTION(eztd_data[TD_PLUS]),
    [TD_PIPE] = EZTD_ACTION(eztd_data[TD_PIPE]),
    [TD_SCLN] = EZTD_ACTION(eztd_data[TD_SCLN]),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAY_DVORAK] = LAYOUT_ergodox_pretty(
/*  KEY COLUMN 1,  KEY COLUMN 2,  KEY COLUMN 3,  KEY COLUMN 4,  KEY COLUMN 5,  KEY COLUMN 6,  KEY COLUMN 7,      KEY COLUMN 8,  KEY COLUMN 9,  KEY COLUMN 10, KEY COLUMN 11, KEY COLUMN 12, KEY COLUMN 13, KEY COLUMN 14, */
    KC_GRAVE,      KC_1,          KC_2,          KC_3,          KC_4,          KC_5,          TD(TD_DOL),        TD(TD_ASRK),   KC_6,          TD(TD_7),      TD(TD_8),      KC_9,          KC_0,          TD(TD_BSLS),
    TD(TD_DQT),    TD(TD_APOS),   KC_COMMA,      TD(DOT_GTE),   KC_P,          KC_Y,          TD(TD_PERC),       TD(TD_PLUS),   KC_F,          KC_G,          KC_C,          KC_R,          KC_L,          TD(TD_SLASH),
    TD(TD_PIPE),   KC_A,          KC_O,          KC_E,          KC_U,          KC_I,                                            KC_D,          KC_H,          KC_T,          KC_N,          KC_S,          TD(MINU_DASH),
    TD(LCDT_SHFT), TD(TD_SCLN),   KC_Q,          KC_J,          KC_K,          KC_X,          TD(TD_AMP),        KC_EQUAL,      KC_B,          KC_M,          KC_W,          KC_V,          KC_Z,          TD(RCDT_SHFT),
    TD(FANC_ALPH), TD(LAY_OUT),   TD(LCDT_CRTL), TD(LCDT_META), TD(LCDT_ALT),                                                                  TD(RCDT_ALT),  TD(RCDT_META), TD(RCDT_CRTL), KC_PAGE_UP,    KC_PGDN,
                                                                               TD(HOME_TOP),  TD(END_BTM),       KC_ESC,        KC_DELETE,
                                                                                              KC_RIGHT,          KC_UP,
                                                                KC_ENTER,      KC_TAB,        KC_LEFT,           KC_DOWN,       KC_BSPC,       KC_SPACE
  ),
  [LAY_NUMBER_PAD] = LAYOUT_ergodox_pretty(
/*  KEY COLUMN 1,  KEY COLUMN 2,  KEY COLUMN 3,  KEY COLUMN 4,  KEY COLUMN 5,  KEY COLUMN 6,  KEY COLUMN 7,      KEY COLUMN 8,  KEY COLUMN 9,  KEY COLUMN 10, KEY COLUMN 11, KEY COLUMN 12, KEY COLUMN 13, KEY COLUMN 14, */
    TD(EM_SMILE),  TD(F1_FRAC),   TD(F2_FRAC),   TD(F3_FRAC),   TD(F4_FRAC),   TD(F5_FRAC),   TD(EM_LGL_IP),     TD(MTH_CLCLS), TD(F6_FRAC),   TD(F7_FRAC),   TD(F8_FRAC),   TD(F9_FRAC),   TD(F10_FRAC),  KC_F11,
    TD(EM_LIKE),   TD(EM_SAD),    TD(NS_ARROW),  TD(NW_ARROW),  TD(N_ARROW),   TD(NE_ARROW),  TD(EM_BALLOT),     TD(DIVIDES),   KC_KP_7,       KC_KP_8,       KC_KP_9,       TD(SUBTRACTS), TD(TD_INF),    KC_F12,
    TD(EM_LOVE),   TD(MSC_ICN),   TD(EW_ARROW),  TD(W_ARROW),   TD(EM_CD_RVW), TD(E_ARROW),                                     KC_KP_4,       KC_KP_5,       KC_KP_6,       TD(ADDS),      TD(MTH_PWR),   TD(MTH_SET),
    TD(EM_LOL),    TD(MSC_FACE),  TD(DIAG_ARROW),TD(SW_ARROW),  TD(S_ARROW),   TD(SE_ARROW),  TD(EM_CAUTN),      TD(MULTIPLIES),KC_KP_1,       KC_KP_2,       KC_KP_3,       TD(EQUALS),    TD(MTH_ROOT),  KC_NUM_LOCK,
    TD(EM_PARTY),  TD(LAY_OUT),   KC_LEFT_CTRL,  KC_LEFT_GUI,   KC_LEFT_ALT,                                                                   KC_KP_0,       KC_KP_DOT,     KC_KP_ENTER,   TD(MTH_PAREN), TD(MTH_CONST),
                                                                               TD(HOME_TOP),  TD(END_BTM),       KC_ESC,        KC_DELETE,
                                                                                              KC_RIGHT,          KC_UP,
                                                                KC_ENTER,      KC_TAB,        KC_LEFT,           KC_DOWN,       KC_BSPC,       KC_SPACE
  ),
  [LAY_QWERTY] = LAYOUT_ergodox_pretty(
/*  KEY COLUMN 1,  KEY COLUMN 2,  KEY COLUMN 3,  KEY COLUMN 4,  KEY COLUMN 5,  KEY COLUMN 6,  KEY COLUMN 7,      KEY COLUMN 8,  KEY COLUMN 9,  KEY COLUMN 10, KEY COLUMN 11, KEY COLUMN 12, KEY COLUMN 13, KEY COLUMN 14, */
    KC_GRAVE,      KC_1,          KC_2,          KC_3,          KC_4,          KC_5,          TD(TD_PLUS),       TD(TD_ASRK),   KC_6,          TD(TD_7),      TD(TD_8),      KC_9,          KC_0,          TD(TD_AMP),
    TD(TD_DOL),    KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,          KC_EQUAL,          TD(TD_BSLS),   KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,          TD(TD_DQT),
    TD(TD_PIPE),   KC_A,          KC_S,          KC_D,          KC_F,          KC_G,                                            KC_H,          KC_J,          KC_K,          KC_L,          TD(TD_SCLN),   TD(TD_APOS),
    TD(LCDT_SHFT), KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,          TD(MINU_DASH),     TD(TD_PERC),   KC_N,          KC_M,          KC_COMMA,      TD(DOT_GTE),   TD(TD_SLASH),  TD(RCDT_SHFT),
    TD(FANC_ALPH), TD(LAY_OUT),   TD(LCDT_CRTL), TD(LCDT_META), TD(LCDT_ALT),                                                                  TD(RCDT_ALT),  TD(RCDT_META), TD(RCDT_CRTL), KC_PAGE_UP,    KC_PGDN,
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
  [LAY_FANCY] = LAYOUT_ergodox_pretty(
/*  KEY COLUMN 1,  KEY COLUMN 2,  KEY COLUMN 3,  KEY COLUMN 4,  KEY COLUMN 5,  KEY COLUMN 6,  KEY COLUMN 7,      KEY COLUMN 8,  KEY COLUMN 9,  KEY COLUMN 10, KEY COLUMN 11, KEY COLUMN 12, KEY COLUMN 13, KEY COLUMN 14, */
    UFA_DS,        _______,       _______,       _______,       _______,       _______,       UFA_FRK,            UFA_MON,      _______,       _______,       _______,       _______,       _______,       UFA_CUR,
    UFA_CIR,       _______,       _______,       _______,       _______,       _______,       UFA_FB,             UFA_ITC,      _______,       _______,       _______,       _______,       _______,       XXXXXXX,
    UFA_NC,        _______,       _______,       _______,       _______,       _______,                                         _______,       _______,       _______,       _______,       _______,       XXXXXXX,
    _______,       _______,       _______,       _______,       _______,       _______,       UFA_REG,            UFA_BI,       _______,       _______,       _______,       _______,       _______,       _______,
    _______,       UFA_SQ,        UFA_NSQ,       UFA_SCR,       UFA_SB,                                                                        UFA_BLD,       UFA_WDE,       UFA_RSM,       _______,       _______,
                                                                               _______,       _______,           _______,       _______,
                                                                                              _______,           _______,
                                                                _______,       _______,       _______,           _______,       _______,       _______
  ),
};

const key_override_t *key_overrides[] = {
    &ezovrd_make_basic(MOD_MASK_SHIFT, KC_COMMA, UM(U_LTE)),
    &ezovrd_make_basic(MOD_MASK_SHIFT, TD(DOT_GTE), UM(U_GTE)),
    &ezovrd_make_basic(MOD_MASK_SHIFT, TD(TD_7), UM(U_WBULLET)),
    &ezovrd_make_basic(MOD_MASK_SHIFT, TD(TD_8), UM(U_BULLET)),
    &ezovrd_make_basic(MOD_MASK_SHIFT, KC_EQUAL, UM(U_NE)),
    &ezovrd_make_basic(MOD_MASK_SHIFT, TD(TD_DOL), UM(U_CENT)),
    &ezovrd_make_basic(MOD_MASK_SHIFT, TD(TD_ASRK), UM(U_DEGREE)),
    &ezovrd_make_basic(MOD_MASK_SHIFT, TD(TD_PLUS), UM(U_PLUS_MIN)),
    &ezovrd_make_basic(MOD_MASK_SHIFT, TD(TD_PERC), C(S(KC_O))),
    &ezovrd_make_basic(MOD_MASK_SHIFT, TD(TD_AMP), C(S(KC_M))),
    &ezovrd_make_basic(MOD_MASK_SHIFT, KC_4, UM(U_BLACK_STAR)),
    &ezovrd_make_basic(MOD_MASK_SHIFT, KC_5, UM(U_WHITE_STAR)),
    &ezovrd_make_basic(MOD_MASK_SHIFT, KC_9, KC_MEDIA_SELECT),
    &ezovrd_make_basic(MOD_MASK_SHIFT, KC_0, KC_MEDIA_PLAY_PAUSE),
    &ezovrd_make_basic(MOD_MASK_SHIFT, TD(MINU_DASH), KC_UNDERSCORE),
    &ezovrd_make_basic(MOD_MASK_SHIFT, TD(TD_APOS), UM(U_LSAPOS)),
    &ezovrd_make_basic(MOD_MASK_SHIFT, TD(TD_DQT), UM(U_LSQUOT)),
    &ezovrd_make_basic(MOD_MASK_SHIFT, TD(TD_BSLS), KC_VOLU),
    &ezovrd_make_basic(MOD_MASK_SHIFT, TD(TD_SLASH), KC_VOLD),
    &ezovrd_make_basic(MOD_MASK_SHIFT, TD(TD_PIPE), UM(U_BRKPIP)),
    &ezovrd_make_basic(MOD_MASK_SHIFT, TD(TD_SCLN), UM(U_SECTION)),
};


enum light_state_enum {
    LIGHT_OFF,
    LIGHT_BLINKING_SLOW,
    LIGHT_BLINKING_INVERSE_SLOW,
    LIGHT_BLINKING_MED,
    LIGHT_BLINKING_INVERSE_MED,
    LIGHT_BLINKING_FAST,
    LIGHT_BLINKING_INVERSE_FAST,
    LIGHT_ON,
};

enum light_enum {
    RED_LIGHT,
    GREEN_LIGHT,
    BLUE_LIGHT,
};

uint8_t light_state[] = {
    [RED_LIGHT] = LIGHT_OFF,
    [GREEN_LIGHT] = LIGHT_OFF,
    [BLUE_LIGHT] = LIGHT_OFF,
};

uint16_t light_count = 0;

bool is_light_on(uint8_t light_index){
    if (light_state[light_index] == LIGHT_ON){
        return true;
    }
    if (light_state[light_index] == LIGHT_BLINKING_SLOW && !(light_count&0x400)){
        return true;
    }
    if (light_state[light_index] == LIGHT_BLINKING_INVERSE_SLOW && (light_count&0x400)){
        return true;
    }
    if (light_state[light_index] == LIGHT_BLINKING_MED && !(light_count&0x200)){
        return true;
    }
    if (light_state[light_index] == LIGHT_BLINKING_INVERSE_MED && (light_count&0x200)){
        return true;
    }
    if (light_state[light_index] == LIGHT_BLINKING_FAST && !(light_count&0x100)){
        return true;
    }
    if (light_state[light_index] == LIGHT_BLINKING_INVERSE_FAST && (light_count&0x100)){
        return true;
    }
    return false;
}

bool any_light_blinking(void){
    if (light_state[RED_LIGHT] != LIGHT_ON && light_state[RED_LIGHT] != LIGHT_OFF){
        return true;
    }
    if (light_state[GREEN_LIGHT] != LIGHT_ON && light_state[GREEN_LIGHT] != LIGHT_OFF){
        return true;
    }
    if (light_state[BLUE_LIGHT] != LIGHT_ON && light_state[BLUE_LIGHT] != LIGHT_OFF){
        return true;
    }
    return false;
}

// use call back when scanning for keypresses to set lights
void matrix_scan_user(void) {

    if(IS_LAYER_ON(LAY_NUMBER_PAD)){
        // Blue light is ARROWLOCK
        light_state[BLUE_LIGHT] = host_keyboard_led_state().num_lock ? LIGHT_OFF : LIGHT_ON;
    } else {
        // Blue light is CAPSLOCK
        light_state[BLUE_LIGHT] = host_keyboard_led_state().caps_lock ? LIGHT_BLINKING_MED : (is_caps_word_on() ? LIGHT_BLINKING_FAST : LIGHT_OFF);
    }

    if (unicode_fancy_alphabet_get() != UNICODE_FANCY_ALPHABET_NONE) {
        // Red and green lights is fancy alphabet,
        // regardless of other layers.
        light_state[RED_LIGHT] = LIGHT_BLINKING_MED;
        light_state[GREEN_LIGHT] = LIGHT_BLINKING_INVERSE_MED;
    } else {
        // Red light is NUM/FN
        light_state[RED_LIGHT] = layer_state_cmp(layer_state, LAY_NUMBER_PAD) ? LIGHT_ON : LIGHT_OFF;

        // Green light is QWERTY
        light_state[GREEN_LIGHT] = (layer_state_cmp(layer_state, LAY_QWERTY) || layer_state_cmp(layer_state, LAY_QWERTY_CONTROL) || layer_state_cmp(layer_state, LAY_QWERTY_META) || layer_state_cmp(layer_state, LAY_QWERTY_ALT)) ? LIGHT_ON : LIGHT_OFF;
    }

    if (is_light_on(RED_LIGHT)){
        ergodox_right_led_1_on();
    } else {
        ergodox_right_led_1_off();
    }
    if (is_light_on(GREEN_LIGHT)){
        ergodox_right_led_2_on();
    } else {
        ergodox_right_led_2_off();
    }
    if (is_light_on(BLUE_LIGHT)){
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_3_off();
    }
    light_count++;
    if (!any_light_blinking()){
        light_count = 0;
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

void unicode_fancy_alphabet_set_user(uint8_t alphabet) {
    if (alphabet == UNICODE_FANCY_ALPHABET_NONE){
        layer_off(LAY_FANCY);
    } else {
        layer_on(LAY_FANCY);
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
        case TD(MINU_DASH):
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
