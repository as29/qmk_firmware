/*
 * @as29 custom keymap for sofle v2
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

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
		// use left encoder to scroll in the RAISE layer
		if (get_highest_layer(layer_state) == 4 /*_RAISE*/) {
			if (clockwise) {
				tap_code(KC_WH_D);
			} else {
				tap_code(KC_WH_U);
			}
		} else {			
			if (clockwise) {
				tap_code(KC_VOLU);
			} else {
				tap_code(KC_VOLD);
			}
		}
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
