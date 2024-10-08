/* Copyright 2023 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
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

#define PLOOPY_DRAGSCROLL_DIVISOR_V 1.5
#define PLOOPY_DRAGSCROLL_DIVISOR_H 1.5
#define PLOOPY_DRAGSCROLL_INVERT

#define PLOOPY_DPI_OPTIONS { 1200, 1900, 2400 }
#define PLOOPY_DPI_DEFAULT 1

#include QMK_KEYBOARD_H

enum LAYER_NAMES {
    DEFAULT_LYR,
    NAV_SET_LYR,

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    [_LYR] = LAYOUT( 
        _______, _______, _______, _______,
        _______,                   _______ 
    ),
    */
    [DEFAULT_LYR] = LAYOUT( 
        MO(NAV_SET_LYR), KC_BTN5, KC_BTN3, KC_BTN2, 
        KC_BTN1,                           DRAG_SCROLL
    ),
    [NAV_SET_LYR] = LAYOUT( 
        _______, C(KC_LEFT), C(KC_RIGHT), C(KC_UP),
        _______,                          DPI_CONFIG  
    ),
};
