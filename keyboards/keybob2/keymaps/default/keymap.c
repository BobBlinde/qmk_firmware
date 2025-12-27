// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_set_cursor(0, 0);
    led_t led_state = host_keyboard_led_state();
    oled_write(led_state.caps_lock ? PSTR("Caps Lock On ") : PSTR("Caps Lock Off"), false);
    oled_set_cursor(0, 1);
    switch (get_highest_layer(layer_state|default_layer_state)){
        case 0:
            oled_write("default layer", false);
            break;
        case 1:
            oled_write("First Layer", false);
            break;
        case 2:
            oled_write("Second Layer", false);
    }
    return false;
}
#endif

const uint16_t PROGMEM default_layer_combo[] = {QK_BOOT, KC_MPLY, COMBO_END};
const uint16_t PROGMEM first_layer_combo[] = {KC_F13, KC_F14, COMBO_END};
const uint16_t PROGMEM second_layer_combo[] = {KC_F15, KC_F16, COMBO_END};
combo_t key_combos[] = {
    COMBO(default_layer_combo, DF(0)),
    COMBO(first_layer_combo, DF(1)),
    COMBO(second_layer_combo, DF(2)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *              ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
     *              │Esc│   │F1 │F2 │F3 │F4 │ │F5 │F6 │F7 │F8 │ │F9 │F10│F11│F12│ │PSc│Scr│Pse│
     *              └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
     *              ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐
     *     ┌───────┐│ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│ │Ins│Hom│PgU│
     *     │  oled │├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤
     *     └───────┘│ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │ │Del│End│PgD│
     *     ┌───┬───┐├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘
     *     │ M1│ M2││ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
     *     ├───┼───┤├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐
     *     │ M3│ M4││ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │     │ ↑ │
     *     ├───┼───┤├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐
     *     │ M5│ M6││Ctrl│GUI │Alt │                        │ Alt│ GUI│Menu│Ctrl│ │ ← │ ↓ │ → │
     *     └───┴───┘└────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘
     */
    [0] = LAYOUT_tkl_macros(
                            KC_ESC,         KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,     KC_PSCR,KC_SCRL,KC_PAUS,

                            KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,    KC_INS, KC_HOME,KC_PGUP,
                            KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,    KC_DEL, KC_END, KC_PGDN,
        QK_BOOT,KC_MPLY,    KC_CAPS,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,        KC_ENT,
        KC_F13, KC_F14,     KC_LSFT,        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,        KC_RSFT,            KC_UP,
        KC_F15, KC_F16,     KC_LCTL,KC_LGUI,KC_LALT,                        KC_SPC,                         KC_RALT, KC_RGUI,KC_APP,KC_RCTL,    KC_LEFT,KC_DOWN,KC_RGHT
    ),
    [1] = LAYOUT_tkl_macros(
                            _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,

                            _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,
                            _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,
        _______,_______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,
        _______,_______,    _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,            _______,
        _______,_______,    _______,_______,_______,                        _______,                        _______,_______,_______,_______,    _______,_______,_______
    ),
    [2] = LAYOUT_tkl_macros(
                            _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,

                            _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,
                            _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,
        _______,_______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,
        _______,_______,    _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,            _______,
        _______,_______,    _______,_______,_______,                            _______,                    _______,_______,_______,_______,    _______,_______,_______
    )
};
