// Copyright 2025 Bob Blinde (@BobBlinde)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

void keyboard_pre_init_kb(void) {
    // Set GP2 as output and drive it high to power the OLED
    gpio_set_pin_output(GP2);
    gpio_write_pin_high(GP2);

    // Row 3 is scanned on GP21, but GP9 is still wired to the same trace.
    // Left unconfigured, GP9 keeps the RP2040's default pull-down and fights
    // the row's pull-up, causing phantom key presses. Make it high-Z.
    gpio_set_pin_input(GP9);

    keyboard_pre_init_user();
}
