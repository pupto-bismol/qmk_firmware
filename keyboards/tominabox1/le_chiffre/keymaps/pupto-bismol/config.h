/* Copyright 2020 tominabox1
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
#pragma once


// custom defines
#define ONESHOT_TIMEOUT 220
#define ONESHOT_TAP_TOGGLE 3
#define LEADER_TIMEOUT 600
#define TAPPING_TERM 190
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD_PER_KEY

//#define COMBO_SHOULD_TRIGGER
#define COMBO_STRICT_TIMER
#define COMBO_TERM 35
//#define COMBO_ONLY_FROM_LAYER 0

// mouse defines
#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL

#define MK_C_OFFSET_UNMOD    8  //Cursor offset per movement (unmodified)
#define MK_C_INTERVAL_UNMOD  8  //Time between cursor movements (unmodified)
#define MK_C_OFFSET_0        4  //Cursor offset per movement (0)
#define MK_C_INTERVAL_0      8  //Time between cursor movements (0)
#define MK_C_OFFSET_1       16  //Cursor offset per movement (1)
#define MK_C_INTERVAL_1      8  //Time between cursor movements (1)
#define MK_C_OFFSET_2        2  //Cursor offset per movement (2)
#define MK_C_INTERVAL_2      8  //Time between cursor movements (2)

#define MK_W_OFFSET_UNMOD    1  //Scroll steps per scroll action (unmodified)
#define MK_W_INTERVAL_UNMOD 40  //Time between scroll steps (unmodified)
#define MK_W_OFFSET_0        1  //Scroll steps per scroll action (0)
#define MK_W_INTERVAL_0    360  //Time between scroll steps (0)
#define MK_W_OFFSET_1        1  //Scroll steps per scroll action (1)
#define MK_W_INTERVAL_1    120  //Time between scroll steps (1)
#define MK_W_OFFSET_2        1  //Scroll steps per scroll action (2)
#define MK_W_INTERVAL_2     20  //Time between scroll steps (2)

//space saving defines
#undef LOCKING_SUPPORT_ENABLE  // locking keys
#undef LOCKING_RESYNC_ENABLE   // ...
#define NO_MUSIC_MODE          // playing music mode
#define LAYER_STATE_8BIT       // set to 16 bit for >8 layers
