/* Copyright 2022 Jose Pablo Ramirez <jp.ramangulo@gmail.com>
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

enum layer_names {
    DEFAULT_LYR,
    PICKER_LYR,
    SETTINGS_LYR,
    FUSION_MAIN_LYR,
    FUSION_SKTCH_LYR,
    MOUSE_LYR,
    STARBND_LYR
};

// place custom keyboard macros below
enum custom_keycodes {
    FUSION_PARAMS = SAFE_RANGE,
    FUSION_SKTCH,
    FUSION_CHMFR,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case FUSION_PARAMS:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("schange parameters\n");
        } else {
            // released
        }
        break;
      case FUSION_SKTCH:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("screate sketch\n");
        } else {
            // released
            default_layer_set(1 << FUSION_SKTCH_LYR);
        }
        break;
      case FUSION_CHMFR:
        if (record->event.pressed) {
            // pressed
            SEND_STRING("schamfer\n");
        } else {
            // released
        }
        break;
    }
      return true;
};


// https://docs.qmk.fm

// key map
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // default
  [DEFAULT_LYR] = LAYOUT(
                                                 KC_MUTE,
      DF(PICKER_LYR),        LSFT(KC_MS_BTN3),   LOPT(KC_MS_BTN1),
      KC_MS_BTN2,            KC_MS_BTN3,         KC_MS_BTN1,
      LGUI(KC_X),            LGUI(KC_C),         LGUI(KC_V),
      KC_LOPT,               KC_LCMD,            KC_LSFT
  ),
  // layout picker
  [PICKER_LYR] = LAYOUT(
                                                 QK_BOOT,
      DF(DEFAULT_LYR),     DF(SETTINGS_LYR),     DF(FUSION_MAIN_LYR),
      DF(MOUSE_LYR),       DF(STARBND_LYR),      XXXXXXX,
      XXXXXXX,             XXXXXXX,              XXXXXXX,
      XXXXXXX,             XXXXXXX,              XXXXXXX
  ),
  // Settings
  [SETTINGS_LYR] = LAYOUT(
                                                    _______,
      DF(PICKER_LYR),     QK_AUDIO_CLICKY_TOGGLE,   RGB_TOG,
      XXXXXXX,            QK_AUDIO_TOGGLE,          RGB_VAI,
      XXXXXXX,            XXXXXXX,                  RGB_VAD,
      XXXXXXX,            XXXXXXX,                  XXXXXXX
  ),
  // Fusion 360 Main
  [FUSION_MAIN_LYR] = LAYOUT(
                                             _______,
      DF(PICKER_LYR),        FUSION_PARAMS,  KC_E,
      KC_MS_BTN2,            KC_MS_BTN3,     KC_MS_BTN1,
      KC_Q,                  KC_F,           KC_I,
      XXXXXXX,               FUSION_CHMFR,   FUSION_SKTCH
  ),    
  // Fusion 360 Sketch
  [FUSION_SKTCH_LYR] = LAYOUT(
                                             _______,
      DF(PICKER_LYR),        FUSION_PARAMS,  KC_O,
      KC_MS_BTN2,            KC_MS_BTN3,     KC_MS_BTN1,
      KC_P,                  KC_C,           KC_L,
      KC_D,                  KC_R,           DF(FUSION_MAIN_LYR)
  ),
  // Virtual Mouse
  [MOUSE_LYR] = LAYOUT(
                                             _______,
      DF(PICKER_LYR),        KC_MS_BTN3,     XXXXXXX,
      KC_MS_BTN2,            KC_MS_U,        KC_MS_BTN1,
      KC_MS_L,               KC_MS_D,        KC_MS_R,
      KC_ACL0,               KC_ACL1,        KC_ACL2
  ),
  // StarBound
  [STARBND_LYR] = LAYOUT(
                                   KC_Z,
      DF(PICKER_LYR),   KC_WH_U,   KC_WH_U,
      KC_MS_BTN2,       KC_W,      KC_MS_BTN1,
      KC_A,             KC_S,      KC_D,
      KC_Q,             KC_E,      KC_SPACE
  ),
  
};


// encoder map
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [DEFAULT_LYR]      = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [PICKER_LYR]       = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [SETTINGS_LYR]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [FUSION_MAIN_LYR]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [FUSION_SKTCH_LYR] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [MOUSE_LYR] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [STARBND_LYR] = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
};
#endif

// oled text map: the display has a cpacity 8 lines of 21 mono-spaced characters
#ifdef OLED_ENABLE
char* oledtext[][8] = {

  // default
  [DEFAULT_LYR] = {
    "Layers SFT+MM OPT+LM ",
    "                     ",
    "MouseR MouseM MouseL ",
    "                     ",
    "Cut    Copy   Paste  ",
    "                     ",
    "Option Cmd    Shift  ",
    "                     "

  },

  // layout picker
  [PICKER_LYR] = {
    "Home   Setup  Fusion ",
    "                     ",
    "Mouse  StrBnd XXXXXX ",
    "                     ",
    "XXXXXX XXXXXX XXXXXX ",
    "                     ",
    "XXXXXX XXXXXX XXXXXX ",
    "                     "
  },

  // Settings
  [SETTINGS_LYR] = {
    "Layers ClkTog RGBTog ",
    "                     ",
    "XXXXXX AudTog RGBUp  ",
    "                     ",
    "XXXXXX XXXXXX RGBDwn ",
    "                     ",
    "XXXXXX XXXXXX XXXXXX ",
    "                     "
  },

  // Fusion 360 Main
  [FUSION_MAIN_LYR] = {
    "Layers Params Extrd  ",
    "                     ",
    "MouseR MouseM MouseL ",
    "                     ",
    "Psh-Pl Fillet Measre ",
    "                     ",
    "XXXXXX Chamfr Sketch ",
    "                     "
  },

  // Fusion 360 Sketch
  [FUSION_SKTCH_LYR] = {
    "Layers Params Offset ",
    "                     ",
    "MouseR MouseM MouseL ",
    "                     ",
    "Proj   Circle Line   ",
    "                     ",
    "Dim    Rect   Main   ",
    "                     "
  },
  [MOUSE_LYR] = {
    "Layers MouseM XXXXXX ",
    "                     ",
    "MouseR MsUp   MouseL ",
    "                     ",
    "MsLft  MsDw   MsRht  ",
    "                     ",
    "MsAcc0 MsAcc1 MsAcc2 ",
    "                     "
  },
  [STARBND_LYR] = {
    "Layers HotBr- HotBr+ ",
    "                     ",
    "MouseR Up     MouseL ",
    "                     ",
    "Left   Down   Right  ",
    "                     ",
    "DrpItm Intrct Jump   ",
    "                     "
  },
};

// called at the start of oled_task
bool oled_task_user(void) {
  // render a new page of keymap indicators each time the layer changes
  for(int i=0; i<8; i++){
    oled_write(oledtext[get_highest_layer(default_layer_state)][i], false);
  }
  return false;
}
#endif

void keyboard_post_init_user(void) {
    //rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    //rgb_matrix_sethsv_noeeprom(HSV_OFF);

}