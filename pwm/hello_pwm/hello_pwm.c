/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Output PWM signals on pins 0 and 1

#include "pico/stdlib.h"
#include "hardware/pwm.h"

/*int main() {
    

    // Tell GPIO 0 and 1 they are allocated to the PWM
    gpio_set_function(0, GPIO_FUNC_PWM);
    gpio_set_function(1, GPIO_FUNC_PWM);

    // Find out which PWM slice is connected to GPIO 0 (it's slice 0)
    uint slice_num = pwm_gpio_to_slice_num(0);

    // Set period of 4 cycles (0 to 3 inclusive)
    pwm_set_wrap(slice_num, 3);
    // Set channel A output high for one cycle before dropping
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 1);
    // Set initial B output high for three cycles before dropping
    pwm_set_chan_level(slice_num, PWM_CHAN_B, 3);
    // Set the PWM running
    pwm_set_enabled(slice_num, true);
    
} */


#define RED_LED_GPIO 15

int main()
{
    //setting gpio pins to PWM
    gpio_set_function(RED_LED_GPIO, GPIO_FUNC_PWM);

    //determining slice of GPIO
    uint slice_num = pwm_gpio_to_slice_num(15);

    //wrap (count till a certain number before restarting)
    pwm_set_wrap(slice_num, 255);

    //setting the channel and level of GPIO 15 (channel B)
    pwm_set_chan_level(slice_num, PWM_CHAN_B, 0);
    //setting the level at 0, the LED starts as OFF as its 0% duty cycle

    //set pwm running
    pwm_set_enabled(slice_num, true);

    while(1)
    {
        //increase the brightness every increment till 100
        for(int i = 0; i <= 255; i ++)
        {
            pwm_set_chan_level(slice_num, PWM_CHAN_B, i);
            //pwm level = i which changes at every increment
            sleep_ms(100); //delay for 100ms
        }

        //decrease the brightness every increment till it reaches 0
        for(int i = 255; i >= 0; i--)
        {
            pwm_set_chan_level(slice_num, PWM_CHAN_B, i);
            sleep_ms(100);
        }
    }

}