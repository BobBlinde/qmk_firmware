// Copyright 2025 Bob Blinde (@BobBlinde)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

void keyboard_pre_init_kb(void) {
    // Set GP2 as output and drive it high to power the OLED
    gpio_set_pin_output(GP2);
    gpio_write_pin_high(GP2);
    
    keyboard_pre_init_user();
}
