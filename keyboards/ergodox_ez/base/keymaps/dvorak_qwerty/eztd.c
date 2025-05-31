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
#include "eztd.h"

uint8_t eztd_step(tap_dance_state_t *state, eztd_data *data);

// send key down event. This method can be overridden to
// handle advanced key codes with special cases.
__attribute__((weak)) void eztd_reg(uint16_t keycode){
    register_code16(keycode);
}

// send key up event. This method can be overridden to
// handle advanced key codes with special cases.
__attribute__((weak)) void eztd_unreg(uint16_t keycode){
    unregister_code16(keycode);
}

uint8_t eztd_step(tap_dance_state_t *state, eztd_data *data) {
    if (data->interrupted_is_tap && state->interrupted) {
        // When interrupted and configured for flow
        // treat all taps as over taps. This causes
        // them te be handled in eztd_each, sooner
        // than the end of the dance. They will
        // then send only the single tap keycode
        switch(data->step){
            case EZTD_FIRST_OVERTAP:
            case EZTD_NTH_OVERTAP:
                // Another tap after over tap
                // has already been handled
                return EZTD_NTH_OVERTAP;
        }
        // Haven't sent over tap before,
        // mark it as the first. If interrupted
        // after the second tap, the first over
        // tap will send two keystrokes.
        return EZTD_FIRST_OVERTAP;
    }
    // Expect that single tap and single hold are always configured.
    // No check here for when they aren't.
    if (state->count == 1) {
        if (state->interrupted || state->pressed) {
            // interrupted after the first press when not configured for flow
            // or the key is actually held on the first press
            return EZTD_SINGLE_HOLD;
        }
        return EZTD_SINGLE_TAP;
    }
    // One tap cases have already been handled,
    // so extra taps when the second tap isn't
    // configured are over taps
    if (!data->double_tap) {
        if (state->count == 2) {
            return EZTD_FIRST_OVERTAP;
        }
        return EZTD_NTH_OVERTAP;
    }
    if (state->count == 2) {
        if (state->interrupted || state->pressed) {
            // interrupted after the second press when not configured for flow
            // or the key is actually held on the second press
            return EZTD_DOUBLE_HOLD;
        }
        return EZTD_DOUBLE_TAP;
    }
    // One and two tap cases have already been handled,
    // so extra taps when the third tap isn't
    // configured are over taps
    if (!data->triple_tap) {
        if (state->count == 3) {
            return EZTD_FIRST_OVERTAP;
        }
        return EZTD_NTH_OVERTAP;
    }
    if (state->count == 3) {
        if (state->interrupted || state->pressed) {
            // interrupted after the third press when not configured for flow
            // or the key is actually held on the third press
            return EZTD_TRIPLE_HOLD;
        }
        return EZTD_TRIPLE_TAP;
    }
    // One two and three tap cases have already been handled,
    // all additional taps are over taps.
    if (state->count == 4) {
        return EZTD_FIRST_OVERTAP;
    }
    return EZTD_NTH_OVERTAP;
}


void eztd_each(tap_dance_state_t *state, void *user_data) {
    eztd_data* data = (eztd_data*)user_data;
    data->step = eztd_step(state, data);
    // Send over taps as they happen rather than waiting
    // for the end of the dance.
    int taps=0;
    // First count the over taps
    switch(data->step){
        case EZTD_FIRST_OVERTAP:
            taps=state->count;
            break;
        case EZTD_NTH_OVERTAP:
            // already sent n-1 taps,
            // just need to send one more
            taps=1;
            break;
    }
    // Send all the over taps
    for (int i=0; i<taps; i++) {
        eztd_reg(data->tap);
#       if TAP_CODE_DELAY > 0
            wait_ms(TAP_CODE_DELAY);
#       endif
        eztd_unreg(data->tap);
    }
}

void eztd_finished(tap_dance_state_t *state, void *user_data) {
    eztd_data* data = (eztd_data*)user_data;
    data->step = eztd_step(state, data);
    // send key down event when tap dance is finished.
    switch (data->step) {
        case EZTD_SINGLE_TAP: eztd_reg(data->tap); break;
        case EZTD_SINGLE_HOLD: eztd_reg(data->hold); break;
        case EZTD_DOUBLE_TAP: eztd_reg(data->double_tap); break;
        case EZTD_DOUBLE_HOLD: eztd_reg(data->double_hold); break;
        case EZTD_TRIPLE_TAP: eztd_reg(data->triple_tap); break;
        case EZTD_TRIPLE_HOLD: eztd_reg(data->triple_hold); break;
        // no default case, cases for over taps handled in eztd_step
    }
}

void eztd_reset(tap_dance_state_t *state, void *user_data) {
    eztd_data* data = (eztd_data*)user_data;
#   if TAP_CODE_DELAY > 0
        wait_ms(TAP_CODE_DELAY);
#   endif
    // send key up event when tap dance is reset.
    switch (data->step) {
        case EZTD_SINGLE_TAP: eztd_unreg(data->tap); break;
        case EZTD_SINGLE_HOLD: eztd_unreg(data->hold); break;
        case EZTD_DOUBLE_TAP: eztd_unreg(data->double_tap); break;
        case EZTD_DOUBLE_HOLD: eztd_unreg(data->double_hold); break;
        case EZTD_TRIPLE_TAP: eztd_unreg(data->triple_tap); break;
        case EZTD_TRIPLE_HOLD: eztd_unreg(data->triple_hold); break;
        // no default case, cases for over taps handled in eztd_step
    }
    data->step = EZTD_UNPRESSED;
}
