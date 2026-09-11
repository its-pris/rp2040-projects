/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdbool.h>
#include "pico/stdlib.h"


// Pico W devices use a GPIO on the WIFI chip for the LED,
// so when building for Pico W, CYW43_WL_GPIO_LED_PIN will be defined
#ifdef CYW43_WL_GPIO_LED_PIN
#include "pico/cyw43_arch.h"
#endif

#ifndef LED_DELAY_MS     
#endif

//initialization
int pico_led_init(void)
{
    gpio_init(10);
    gpio_set_dir(10, true);
    return 0;
}

//turn led on/off
void pico_set_led(bool state)
{
    gpio_put(10, state);
}

int main()
{
    int dc = pico_led_init();
    int short_delay = 200;
    int long_delay = 900;
    hard_assert(dc == 0);
    while (true)
    {
        for(int i = 0; i < 4; i++)
        {
            pico_set_led(true);
            sleep_ms(short_delay);
            pico_set_led(false);
            sleep_ms(long_delay);
        }
        pico_set_led(true);
        sleep_ms(short_delay);
    }
} 