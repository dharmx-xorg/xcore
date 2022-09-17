/* xcore.c
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

#include "xcore.h"

Display* display;

int
main(int argc, char** argv) {
    BEGIN_X_CALLS
    start_key_logger(NULL, NULL, False, BOTH_KEY_UP_DOWN);
    END_X_CALLS
    return EXIT_SUCCESS;
}

void
setup(void) {
    display = XOpenDisplay(None);
}

void
finish(void) {
    XSync(display, None);
    XFlush(display);
    XCloseDisplay(display);
}

// vim:filetype=c
