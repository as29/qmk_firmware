/*
 * @as29 custom keymap for sofle v2
 */

#include QMK_KEYBOARD_H
//#include "oled.c"
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
    KC_PRVWD,
    KC_NXTWD,
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
 * |LShift| Undo | Cut  | Copy | Paste|      |-------|    |-------| Acc2 |      |      |      |      |Ent/RS|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LGUI | LALT |LOWER | / BkSpc /       \Space \  |RAISE | Home | End  | PgDn |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_NAVI] = LAYOUT(
    KC_ESC,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,                 		KC_NO,    	KC_NO,    	KC_NO,    	KC_NO,    	KC_NO,    	KC_DEL,
    KC_TAB,		KC_NO,      KC_BTN1,	KC_MS_U,    KC_BTN2,    KC_WH_U,                    KC_ACL0,    KC_PRVWD,	KC_UP,      KC_NXTWD,	KC_NO,      KC_NO,
    KC_CAPS, 	KC_NO,      KC_MS_L,	KC_MS_D,    KC_MS_R,    KC_WH_D,                    KC_ACL1,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_NO,      KC_NO,
    KC_LSFT,	LCTL(KC_Z),	LCTL(KC_X),	LCTL(KC_C),	LCTL(KC_V),	KC_NO,  KC_MUTE,    KC_PSCR,KC_ACL1,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      RSFT_T(KC_ENT),
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
							_______, _______, _______, _______, _______,					_______,  _______, KC_0, _______, KC_PGUP
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
 * |LShift| Undo | Cut  | Copy | Paste|      |-------|    |-------| Acc2 |      | PgUp |      |      |Ent/RS|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LGUI | LALT |LOWER | / BkSpc /       \Space \  |RAISE | Home | End  | PgDn |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_RAISE] = LAYOUT(
    _______,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,                 		KC_NO,    	KC_NO,    	KC_NO,    	KC_NO,    	KC_NO,    	_______,
    _______,	KC_NO,      KC_BTN1,	KC_MS_U,    KC_BTN2,    KC_WH_U,                    KC_ACL0,    KC_PRVWD,	KC_UP,      KC_NXTWD,	KC_NO,      KC_NO,
    KC_ENT,		KC_NO,      KC_MS_L,	KC_MS_D,    KC_MS_R,    KC_WH_D,                    KC_ACL1,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_NO,      KC_NO,
    _______,	LCTL(KC_Z),	LCTL(KC_X),	LCTL(KC_C),	LCTL(KC_V),	KC_NO,  KC_MUTE,    KC_PSCR,KC_ACL1,    KC_NO,      KC_PGUP,	KC_NO,      KC_NO,      _______,
                                _______,	_______, _______, _______, _______,      _______,  _______, _______, _______, _______
    
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


#ifdef OLED_ENABLE
/* 32 * 20 logo 'Initials', 32x20px */
static void render_logo(void) {
    static const char PROGMEM ANS_logo[] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 
		0xe0, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0x00, 0x00, 0xc0, 0xe0, 0x20, 0x20, 0x60, 0x00, 0x00, 
		0x00, 0x00, 0x34, 0x3c, 0x0e, 0x07, 0x05, 0x04, 0x1f, 0x3f, 0x20, 0x00, 0x00, 0x3c, 0x3f, 0x03, 
		0x03, 0x0f, 0x1c, 0x30, 0x30, 0x1f, 0x01, 0x00, 0x70, 0x61, 0x43, 0x46, 0x7c, 0x38, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};
		/* ANS logo uninverted */
/* 		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x1f, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 
		0x1f, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x1f, 0xff, 0xff, 0x3f, 0x1f, 0xdf, 0xdf, 0x9f, 0xff, 0xff, 
		0xff, 0xff, 0xcb, 0xc3, 0xf1, 0xf8, 0xfa, 0xfb, 0xe0, 0xc0, 0xdf, 0xff, 0xff, 0xc3, 0xc0, 0xfc, 
		0xfc, 0xf0, 0xe3, 0xcf, 0xcf, 0xe0, 0xfe, 0xff, 0x8f, 0x9e, 0xbc, 0xb9, 0x83, 0xc7, 0xff, 0xff, 
		0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
		0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f
		}; */
	
		// 'Rose', 32x24px	
	static const char PROGMEM rose_logo[] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf8, 0x18, 0x04, 0x02, 0xf2, 0x02, 0xc4, 
		0xc4, 0x04, 0x04, 0x04, 0x04, 0x04, 0xc4, 0xc4, 0x02, 0xf2, 0x02, 0x04, 0x18, 0xf8, 0xe0, 0x00, 
		0x00, 0xcc, 0x7a, 0x32, 0x01, 0x7d, 0x83, 0x00, 0x00, 0x80, 0x81, 0x41, 0x33, 0x34, 0x1c, 0x18, 
		0x18, 0x19, 0x35, 0x37, 0x35, 0x09, 0x18, 0xf8, 0xf8, 0x04, 0x03, 0x01, 0x01, 0x01, 0x00, 0x00, 
		0x00, 0x00, 0x07, 0x0f, 0x11, 0x10, 0x10, 0x11, 0x3e, 0x3e, 0x31, 0x58, 0x58, 0x58, 0x7f, 0x27, 
		0x38, 0x3c, 0x40, 0x59, 0x5e, 0x36, 0x62, 0x4f, 0x5f, 0x50, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00
	};


    oled_write_raw_P(ANS_logo, sizeof(ANS_logo));
	oled_set_cursor(0, 5);
	oled_write_raw_P(rose_logo, sizeof(rose_logo));
		
}

/* 32 * 14 os logos */
static const char PROGMEM windows_logo[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0xbc, 0xbe, 0xbe, 0x00,
	0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0f, 0x0f, 0x00,
	0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};

static const char PROGMEM mac_logo[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8, 0xf8,
	0xf0, 0xf6, 0xfb, 0xfb, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x1f, 0x1f,
	0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};

/* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED      10
#    define MIN_RUN_SPEED       70

/* advanced settings */
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int   current_wpm = 0;
int	  max_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

/* logic */
static void render_rose(int ROSE_X, int ROSE_Y) {
	
    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
													   0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
													   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
													   0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
													   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
													   0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'sit2', 32x22px */
                                                   {
													   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
													   0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
													   0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
													   0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
													   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
													   0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
													   }
												  };

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'walk1', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80,
														0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00,
														0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
														0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00,
														0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03,
														0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'walk2', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
														0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
														0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
														0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00,
														0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e,
														0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }
												   };

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 32x22px */
                                                   {
														0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
														0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00,
														0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
														0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00,
														0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01,
														0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'run2', 32x22px */
                                                   {
														0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
														0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
														0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
														0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00,
														0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37,
														0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
													}
												   };

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'bark1', 32x22px */
                                                    {
                                                        0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40,
														0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
														0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
														0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
														0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02,
														0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'bark2', 32x22px */
                                                    {
                                                        0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40,
														0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
														0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
														0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10,
														0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02,
														0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }
												   };

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
                                                     {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
														0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
														0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04,
														0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00,
														0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06,
														0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
                                                     },

                                                     /* 'sneak2', 32x22px */
                                                     {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
														0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
														0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04,
														0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00,
														0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04,
														0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                     }
													};

    /* animation */
    void animate_rose(void) {
        /* jump */
        if (isJumping || !showedJump) {
            /* clear */
            oled_set_cursor(ROSE_X, ROSE_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(ROSE_X, ROSE_Y - 1);

            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(ROSE_X, ROSE_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(ROSE_X, ROSE_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (led_usb_state.caps_lock) {
            oled_write_raw_P(bark[abs(1 - current_frame)], ANIM_SIZE);

        } else if (isSneaking) {
            oled_write_raw_P(sneak[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[abs(1 - current_frame)], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[abs(1 - current_frame)], ANIM_SIZE);
        }
    }
	
	/* this fixes the screen on and off bug */
	if(get_current_wpm() != 000) {
        oled_on(); // not essential but turns on animation OLED with any alpha keypress
        if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animate_rose();
        }
        anim_sleep = timer_read32();
    } else {
        if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        } else {
            if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animate_rose();
            }
        }
    }
}

/* KEYBOARD PET END */

static void print_logo_narrow(void) {
    render_logo();
	
	/* setting the max wpm */
	current_wpm = get_current_wpm();
	max_wpm = max_wpm >= current_wpm?max_wpm:current_wpm;
	
	/* reset stats if oled is off */
	if(!is_oled_on()) {
		max_wpm = 0;
	} else {	
		/* wpm counter */
		oled_set_cursor(0, 11);
		oled_write(get_u8_str(current_wpm, '0'), false);	

		oled_set_cursor(0, 12);
		oled_write("wpm", false);

		
		/* max WPM */
		oled_set_cursor(2, 14);
		oled_write(get_u8_str(max_wpm, '0'), false);

		oled_set_cursor(2, 15);
		oled_write("max", false);
	}
}

static void print_status_narrow(void) {
    /* Print current mode */
    oled_set_cursor(0, 0);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_raw_P(mac_logo, sizeof(mac_logo));
    } else {
        oled_write_raw_P(windows_logo, sizeof(windows_logo));
    }

    oled_set_cursor(0, 3);
	
	switch (get_highest_layer(default_layer_state)) {
        case 0:  	//_QWERTY
            oled_write("QWRTY", false);
            break;
        case 1:		//_NAVI
            oled_write("NAVI ", false);
            break;
		case 2:		//_NUMPAD
            oled_write("NUMS ", false);
            break;
        default:
            oled_write("Undef", false);
    }

    oled_set_cursor(0, 5);

    /* Print current layer */
    oled_write("LAYER", false);

    oled_set_cursor(0, 6);
	
	switch (get_highest_layer(layer_state)) {
        case 0:		//_QWERTY
            oled_write("Base ", false);
            break;
		case 1:		//_NAVI
            oled_write("Navi ", false);
            break;
		case 2:		//_NUMPAD
            oled_write("Nums ", false);
            break;
        case 3:		//_LOWER
            oled_write("Lower", false);
            break;
        case 4:		//_RAISE
            oled_write("Raise", false);
            break;
        case 5:		//_ADJUST
            oled_write("Adj  ", false);
            break;
        default:
            oled_write("Undef", false);
    }

    /* caps lock */
    oled_set_cursor(0, 8);
    oled_write("CAPS", led_usb_state.caps_lock);

    /* KEYBOARD PET RENDER START */

    render_rose(0, 13);

    /* KEYBOARD PET RENDER END */
}

bool oled_task_user(void) {
    /* KEYBOARD PET VARIABLES START */

    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */

    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_logo_narrow();
    }
    return false;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        return OLED_ROTATION_270;
}

#endif


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