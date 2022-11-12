/*
 * @as29 custom keymap for sofle v2
 */

#include QMK_KEYBOARD_H
#include "oled.c"
#include "encoder.c"

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
	_QWERTY,
    _NAVI,
    _NUMPAD,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_NAVI,
    KC_NUMPAD,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,	//navigate to start of word
    KC_NXTWD,	//navigate to end of word
	KC_BWORD,	//backspace to start of word
	KC_DWORD	//delete to end of word
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  [   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Caps |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    | PrtSc |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |Ent/RS|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LGUI | LALT |LOWER | / BkSpc /       \Space \  |RAISE | Home | End  | PgDn |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
	KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     	KC_6,	KC_7,	KC_8,		KC_9,	KC_0,		KC_DEL,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     	KC_Y,	KC_U,	KC_I,		KC_O,	KC_P,		KC_LBRC,
    KC_CAPS,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     	KC_H,	KC_J,	KC_K,		KC_L,	KC_SCLN,	KC_QUOT,
    KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     KC_PSCR,KC_N,	KC_M, 	KC_COMM,	KC_DOT,	KC_SLSH,	RSFT_T(KC_ENT),
				KC_LCTRL, KC_LGUI, KC_LALT, KC_LOWER, KC_BSPC,      KC_SPC,  KC_RAISE, KC_HOME, KC_END, RCTL_T(KC_PGDN)
),
/*
 * NAVI
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |      |      |      |      |      |                    |      |      |      |      |      |  DEL |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  TAB |      | Btn 1| Ms U |Btn 2 | Scr U|                    | Acc0 | PrvWd|  Up | NxtWd |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Caps |      | Ms L | Md D | MS R | Scr D|-------.    ,-------| Acc1 | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|  MUTE |    | PrtSc |------+------+------+------+------+------|
 * |LShift| Undo | Cut  | Copy | Paste|      |-------|    |-------| Acc2 | BWord|      | Dword|      |Ent/RS|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LGUI | LALT |LOWER | / BkSpc /       \Space \  |RAISE | Home | End  | PgDn |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_NAVI] = LAYOUT(
    KC_ESC,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,                 		KC_NO,    	KC_NO,    	KC_NO,    	KC_NO,    	KC_NO,    	KC_DEL,
    KC_TAB,		KC_NO,      KC_BTN1,	KC_MS_U,    KC_BTN2,    KC_WH_U,                    KC_ACL0,    KC_PRVWD,	KC_UP,      KC_NXTWD,	KC_NO,      KC_NO,
    KC_CAPS, 	KC_NO,      KC_MS_L,	KC_MS_D,    KC_MS_R,    KC_WH_D,                    KC_ACL1,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_NO,      KC_NO,
    KC_LSFT,	LCTL(KC_Z),	LCTL(KC_X),	LCTL(KC_C),	LCTL(KC_V),	KC_NO,  KC_MUTE,    KC_PSCR,KC_ACL1,    KC_BWORD,	KC_NO,      KC_DWORD,	KC_NO,      RSFT_T(KC_ENT),
								KC_LCTRL,	KC_LGUI, KC_LALT, KC_LOWER, KC_BSPC,      KC_SPC,  KC_RAISE, KC_HOME, KC_END, RCTL_T(KC_PGDN)
),
/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |      |      |      |      |      |                    |      |   /  |   *  |   -  |      | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  TAB |      |      |      |      |      |                    |   7  |   8  |   9  |   +  |   {  |   }  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |      |      |      |      |   .  |-------.    ,-------|   4  |   5  |   6  |   ,  |   (  |   )  |
 * |------+------+------+------+------+------|  MUTE |    | PrtSc |------+------+------+------+------+------|
 * |LShift|      |      |      |      |   0  |-------|    |-------|   1  |   2  |   3  |   =  |   \  |Ent/RS|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LGUI | LALT |LOWER | / BkSpc /       \Space \  |RAISE | Home | End  | PgDn |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NUMPAD] = LAYOUT(
    KC_ESC,		KC_NO,	KC_NO,	KC_NO,	KC_NO,  KC_NO,							KC_NO,	KC_PSLS,	KC_PAST,	KC_PMNS,	KC_NO,		KC_DEL,
    KC_TAB,     KC_NO,  KC_NO,	KC_NO,	KC_NO,  KC_NO,							KC_P7,	KC_P8,		KC_P9,		KC_PPLS,	KC_LCBR,	KC_RCBR,
    KC_CAPS, 	KC_NO,  KC_NO,	KC_NO,	KC_NO,  KC_NO,							KC_P4,	KC_P5,		KC_P6,		KC_PCMM,	KC_LPRN,	KC_RPRN,
    KC_LSFT,	KC_NO,  KC_NO,	KC_NO,	KC_NO,  KC_P0, KC_MUTE,       KC_PSCR,	KC_P1,	KC_P2,		KC_P3,		KC_EQL,		KC_BSLS,	RSFT_T(KC_ENT),
                    KC_LCTRL, KC_LGUI, KC_LALT, KC_LOWER, KC_BSPC,      KC_SPC,  KC_RAISE, KC_HOME, KC_END, RCTL_T(KC_PGDN)
),
    
    
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  Del |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Space|  {   |  }   |  =   |  [   |  ~   |                    |   ]  |   7  |  8   |   9  |  +   | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Enter|SelAll| Save |  _   |  -   |  `   |-------.    ,-------|   ^  |   4  |  5   |   6  |   (  |  )   |
 * |------+------+------+------+------+------|  MUTE |    | PrtSc |------+------+------+------+------+------|
 * |LShift| Undo |  Cut | Copy | Paste| Bold |-------|    |-------|  New |   1  |  2   |   3  |   \  |Ent/RS|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LGUI | LALT |LOWER | / BkSpc /       \Space \  |RAISE |  0   | End  | PgUp |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
	KC_DEL,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,								KC_F6,		KC_F7,	KC_F8,	KC_F9,	KC_F10,		KC_F11,
	KC_SPC,		KC_LCBR,	KC_RCBR,	KC_EQL,		KC_LBRC,	KC_TILD,							KC_RBRC,	KC_7,	KC_8,	KC_9,	KC_PLUS,	KC_F12,
	KC_ENT,		LCTL(KC_A),	LCTL(KC_S),	KC_UNDS,	KC_PMNS,	KC_GRV,								KC_CIRC,	KC_4,	KC_5,	KC_6,	KC_LPRN,	KC_RPRN,
	_______,	LCTL(KC_Z),	LCTL(KC_X),	LCTL(KC_C),	LCTL(KC_V),	LCTL(KC_B), _______,		_______,LCTL(KC_N),	KC_1,	KC_2,	KC_3,	KC_BSLS,	_______,
										_______, _______, _______, _______, _______,		_______,  _______, KC_0, _______, KC_PGUP
),

/*
 * RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |      |      |      |      |      |                    |      |      |      |      |      |  DEL |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  TAB |      | Btn 1| Ms U |Btn 2 | Scr U|                    | Acc0 | PrvWd|  Up | NxtWd |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Enter|      | Ms L | Md D | MS R | Scr D|-------.    ,-------| Acc1 | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|  MUTE |    | PrtSc |------+------+------+------+------+------|
 * |LShift| Undo | Cut  | Copy | Paste|      |-------|    |-------| Acc2 | BWord|      | Dword|      |Ent/RS|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LGUI | LALT |LOWER | / BkSpc /       \Space \  |RAISE | Home | End  | PgUp |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_RAISE] = LAYOUT(
    _______,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,                 		KC_NO,    	KC_NO,    	KC_NO,    	KC_NO,    	KC_NO,    	_______,
    _______,	KC_NO,      KC_BTN1,	KC_MS_U,    KC_BTN2,    KC_WH_U,                    KC_ACL0,    KC_PRVWD,	KC_UP,      KC_NXTWD,	KC_NO,      KC_NO,
    KC_ENT,		KC_NO,      KC_MS_L,	KC_MS_D,    KC_MS_R,    KC_WH_D,                    KC_ACL1,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_NO,      KC_NO,
    _______,	LCTL(KC_Z),	LCTL(KC_X),	LCTL(KC_C),	LCTL(KC_V),	KC_NO,  KC_MUTE,    KC_PSCR,KC_ACL1,    KC_BWORD,	KC_NO,		KC_DWORD,	KC_NO,      _______,
                                _______,	_______, _______, _______, _______,      _______,  _______, _______, _______, KC_PGUP
    
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |RGBtog|      |      |      |      |      |                    |      |      |      |      |      |		|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |	  |QK_BT |      | Hue+ | Sat+ | Bri+ |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN| Hue- | Sat- | Bri- |-------.    ,-------|      | NAVI |Qwerty|NUMPAD|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LGUI | LALT |LOWER | / BkSpc /       \Space \  |RAISE | Home | End  | PgDn |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_ADJUST] = LAYOUT(
	RGB_TOG,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,						XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
	XXXXXXX,	QK_BOOT,	XXXXXXX,	RGB_HUI,	RGB_SAI,	RGB_VAI,						XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
	XXXXXXX,	XXXXXXX,	CG_TOGG,	RGB_HUD,	RGB_SAD,	RGB_VAD,						XXXXXXX,	KC_NAVI,	KC_QWERTY,	KC_NUMPAD,	XXXXXXX,	XXXXXXX,
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,		XXXXXXX,	XXXXXXX, 	XXXXXXX,	XXXXXXX,	XXXXXXX,
									_______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
			break;
        case KC_NAVI:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_NAVI);
            }
            return false;
			break;
		case KC_NUMPAD:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_NUMPAD);
            }
            return false;
			break;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
			break;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
			break;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
			break;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
			return false;
			break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
			return false;
            break;
        case KC_BWORD:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
			return false;
			break;
		case KC_DWORD:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_DEL);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_DEL);
            }
			return false;
			break;
			
			/* KEYBOARD PET STATUS START */
        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
				isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;
            /* KEYBOARD PET STATUS END */
    }
    return true;
}