/* xcore-logger.h
 *
 * Copyright 2022 dharmx
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#include "xcore-util.h"

#include <X11/XKBlib.h>
#include <X11/extensions/XInput2.h>

typedef struct {
    int major_opcode_return;
    int first_event_return;
    int first_error_return;
    Bool query_result;

    int opcode_rtrn;
    int event_rtrn;
    int error_rtrn;
    int major_in_out;
    int minor_in_out;
    int xkb_query_result;

    Status xi_query_result;
} dump_t;

typedef enum {
    ONLY_KEY_UP,
    ONLY_KEY_DOWN,
    BOTH_KEY_UP_DOWN,
} RawKeyPressMode;

void init_xinput(dump_t*, int[2]);
Bool display_key(XIRawEvent*, char*, Bool);
void start_key_logger(char*, char*, Bool, RawKeyPressMode);

// vim:filetype=c