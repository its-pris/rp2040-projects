#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

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