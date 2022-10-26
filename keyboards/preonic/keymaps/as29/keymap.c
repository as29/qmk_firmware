/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _ARROWS,
  _NUMPAD,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MODRGB
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  ARROWS,
  NUMPAD,
  LOWER,
  RAISE,
  MODRGB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  [   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CAPS |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | BL   | GUI  | Alt  |Lower | Bksp |Space |Raise | Home | PgUp | PgDn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_5x12(
  KC_ESC,	KC_1, 		KC_2, 		KC_3, 		KC_4, 		KC_5, 		KC_6, 		KC_7, 	KC_8,		KC_9,		KC_0,		KC_DEL, 
  KC_TAB, 	KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,		KC_Y,		KC_U,	KC_I,		KC_O,		KC_P,		KC_LBRC,
  KC_CAPS,	KC_A, 		KC_S,		KC_D,		KC_F,		KC_G,		KC_H,		KC_J,	KC_K,		KC_L,		KC_SCLN,	KC_QUOT,
  KC_LSFT,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_N,		KC_M,	KC_COMM,	KC_DOT,		KC_SLSH,	RSFT_T(KC_ENT),
  KC_LCTL,	MODRGB,		KC_LGUI,	KC_LALT,	LOWER,		KC_BSPC,	KC_SPC, 	RAISE,	KC_HOME,	KC_PGUP,	KC_PGDN,	RCTL_T(KC_END)
),

/* ARROWS
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |      | Btn1 | Ms U | Btn2 | Scr U|      | PgUp |  UP  | PgDn |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CAPS |      | Ms L | Ms D | Ms R | Src D|      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      | Acc0 | Acc1 | Acc2 |      |      |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | RGB  | GUI  | Alt  |Lower | Bksp |Space |Raise | Home | PgUp | PgDn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_ARROWS] = LAYOUT_ortho_5x12(
  KC_ESC,	KC_EXLM,	KC_AT,		KC_HASH,	KC_DLR,		KC_PERC,	KC_CIRC,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RPRN,	KC_DEL,
  KC_TAB,	KC_NO,		KC_BTN1,	KC_MS_U,	KC_BTN2,	KC_WH_U,	KC_NO,		KC_PGUP,	KC_UP,		KC_PGDN,	KC_NO,		KC_NO,
  KC_CAPS,	KC_NO,		KC_MS_L,	KC_MS_D,	KC_MS_R,	KC_WH_D,	KC_NO,		KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_NO,		KC_NO,
  KC_LSFT,	KC_NO,		KC_ACL0,	KC_ACL1,	KC_ACL2,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		RSFT_T(KC_ENT),
  KC_LCTL,	MODRGB,		KC_LGUI,	KC_LALT,	LOWER,		KC_BSPC,	KC_SPC, 	RAISE,		KC_HOME,	KC_PGUP,	KC_PGDN,	RCTL_T(KC_END)
),

/* NUMPAD
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |      |      |      |      |      |      |   *  |   /  |  -   |   -  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      |   7  |  8   |   9  |  +   |   {  |   }  |
 * |------+------+------+------+------+-------------+------+------+------+------|------|
 * | CAPS |      |      |      |      |   .  |   4  |  5   |   6  |   ,  |   (  |   )  |
 * |------+------+------+------+------+------|------+------+------+------+------|------|
 * | Shift|      |      |      |      |   0  |   1  |  2   |   3  |   =  |   \  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | RGB  | GUI  | Alt  |Lower | Bksp |Space |Raise | Home | PgUp | PgDn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_ortho_5x12(
  KC_ESC,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_PAST,	KC_PSLS,	KC_PMNS,	KC_NO,		KC_DEL,
  KC_TAB,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_P7,		KC_P8,		KC_P9,		KC_PPLS,	KC_LCBR,	KC_RCBR,
  KC_CAPS,	KC_NO, 		KC_NO,		KC_NO,		KC_NO,		KC_PDOT,	KC_P4,		KC_P5,		KC_P6,		KC_PCMM,	KC_LPRN,	KC_RPRN,
  KC_LSFT,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_P0,		KC_P1,		KC_P2,		KC_P3,		KC_PEQL,	KC_BSLS,	RSFT_T(KC_ENT),
  KC_LCTL,	MODRGB,		KC_LGUI,	KC_LALT,	LOWER,		KC_BSPC,	KC_SPC,		RAISE,		KC_HOME,	KC_PGUP,	KC_PGDN,	RCTL_T(KC_END)
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |      |      |      |      |      |      |   *  |   /  |  -   |      | PrScr|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |      |      |   =  |      |   ~  |   7  |  8   |   9  |  +   |   {  |   }  |
 * |------+------+------+------+------+-------------+------+------+------+------|------|
 * | CAPS |      |      |   _  |   -  |   `  |   4  |  5   |   6  |   ,  |   (  |   )  |
 * |------+------+------+------+------+------|------+------+------+------+------|------|
 * | Shift|      |      |      |      |   0  |   1  |  2   |   3  |   =  |   \  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | RGB  | GUI  | Alt  |Lower | Bksp |Space |Raise | Home | PgUp | PgDn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_5x12(

  _______,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_PSLS,	KC_PAST,	KC_PMNS,	KC_NO,		KC_PSCR,
  _______,	KC_NO,		KC_NO,		KC_EQL,		KC_NO,		KC_TILD,	KC_P7,		KC_P8,		KC_P9,		KC_PPLS,	KC_LCBR,	KC_RCBR,
  _______,	KC_NO,		KC_NO,		KC_UNDS,	KC_PMNS,	KC_GRV,		KC_P4,		KC_P5,		KC_P6,		KC_PCMM,	KC_LPRN,	KC_RPRN,
  _______,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_P0,		KC_P1,		KC_P2,		KC_P3,		KC_PEQL,	KC_BSLS,	_______,
  _______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_PDOT,	_______,	_______,	_______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |      | Btn1 | Ms U | Btn2 | Scr U|      |      |  UP  |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CAPS |      | Ms L | Ms D | Ms R | Src D|      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      | Acc0 | Acc1 | Acc2 |      |      | Mute |  Trk-| Trk+ | Play |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | RGB  | GUI  | Alt  |Lower | Bksp |Space |Raise | Prev | Vol+ | Vol- | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_5x12(
  KC_F12,	KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_F11,
  _______,	KC_NO,		KC_BTN1,	KC_MS_U,	KC_BTN2,	KC_WH_U,	KC_NO,		KC_NO,		KC_UP,		KC_NO,		KC_NO,		KC_NO,
  _______,	KC_NO,		KC_MS_L,	KC_MS_D,	KC_MS_R,	KC_WH_D,	KC_NO,		KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_NO,		KC_NO,
  _______,	KC_NO,		KC_ACL0,	KC_ACL1,	KC_ACL2,	KC_NO,		KC_NO,		KC_MUTE,	KC_MRWD,	KC_MFFD,	KC_MPLY,	_______,
  _______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_MPRV,	KC_VOLU,	KC_VOLD,	KC_MNXT
),

/* Adjust (Lower + Raise)
 * 
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|ARROWS|Qwerty|NUMPAD|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_5x12(

  KC_NO,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
  _______,	QK_BOOT,	DEBUG,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		_______,	_______,	KC_NO,
  _______,	_______,	MU_MOD,		AU_ON,		AU_OFF,		AG_NORM,	AG_SWAP,	ARROWS,		QWERTY,		NUMPAD,		_______,	_______,
  _______,	MUV_DE,		MUV_IN,		MU_ON, 		MU_OFF,		MI_ON,		MI_OFF,		_______,	_______,	_______,	_______,	_______,
  _______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_NO,		KC_NO,		KC_NO,		KC_NO
  
  
/*   RGB_TOG,	RGB_M_P,	RGB_M_B,	RGB_M_R,	RGB_M_SW,	RGB_M_SN,	RGB_M_K,	RGB_M_X,	RGB_M_G,	RGB_M_T,	KC_NO,		KC_NO,
  _______,	QK_BOOT,	DEBUG,		RGB_HUI,	RGB_HUD,	RGB_SAI,	RGB_SAD,	RGB_VAI,	RGB_VAD,	_______,	_______,	KC_NO,
  _______,	_______,	MU_MOD,		AU_ON,		AU_OFF,		AG_NORM,	AG_SWAP,	ARROWS,		QWERTY,		NUMPAD,		_______,	_______,
  _______,	MUV_DE,		MUV_IN,		MU_ON, 		MU_OFF,		MI_ON,		MI_OFF,		_______,	_______,	_______,	_______,	_______,
  _______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	RGB_RMOD,	RGB_SPD,	RGB_SPI,	RGB_MOD */

),

/* MODRGB - RGB Controls
 * 
 * ,-----------------------------------------------------------------------------------.
 * |Toggle|Plain |Breath| Rnbow |Swirl|Snake |Kn.Rdr| XMas | Grad | Test |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Hue+ | Sat+ | Bri+ |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Hue- | Sat- | Bri- |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |Mode- | Spd+ | Spd- |Mode+ |
 * `-----------------------------------------------------------------------------------'
 */
[_MODRGB] = LAYOUT_ortho_5x12(
  RGB_TOG, 	RGB_M_P, 	RGB_M_B, 	RGB_M_R, 	RGB_M_SW, 	RGB_M_SN, 	RGB_M_K, 	RGB_M_X, 	RGB_M_G, 	RGB_M_T, 	KC_NO, 		KC_NO,
  KC_NO,	KC_NO,  	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		RGB_HUI, 	RGB_SAI, 	RGB_VAI, 	KC_NO,
  KC_NO, 	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		RGB_HUD, 	RGB_SAD, 	RGB_VAD, 	KC_NO,
  KC_NO, 	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO,
  KC_NO,	_______, 	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		RGB_RMOD, 	RGB_SPI, 	RGB_SPD, 	RGB_MOD
)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case ARROWS:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_ARROWS);
          }
          return false;
          break;
        case NUMPAD:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_NUMPAD);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
		case MODRGB:
          if (record->event.pressed) {
            layer_on(_MODRGB);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_MODRGB);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        /* case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();				REMOVING SINCE USING RGB 
            #endif
            #ifdef RGBLIGHT_ENABLE
              rgblight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break; */
      }
    return true;
};


// CAN DISABLE FEATURES NOT USED: ENCODER, MUSIC MODE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
