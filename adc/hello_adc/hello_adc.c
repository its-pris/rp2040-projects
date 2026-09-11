/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

#define GPIO26 26
#define ADC0 0


int main()
{
    stdio_init_all(); //serial monitor
    printf("Measuring GPIO26 \n");

    adc_init(); //initalizing adc hardware

    adc_gpio_init(GPIO26);  //initalizes pin 26
    adc_select_input(ADC0); //selects the adc module linked to gpio26 which is adc 0

    while (1)
    {
        float conversion_factor = 3.3f / 4096; 
        uint16_t res = adc_read();
        /*printf("%u\n", res);
        sleep_ms(200);*/           //to check the values res outputs
        float output = res * conversion_factor;
        printf("Raw value: 0x%03x , voltage: %f V \n", res, output);
        sleep_ms(500);
    }
}