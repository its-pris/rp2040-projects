#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"

//using potentiometer to control led

//first define what pins to use
#define GPIO_PIN_26 26
#define ADC_MODULE_0 0
#define GPIO_PIN_15 15

int main()
{
    //serial monitor
    stdio_init_all();
    printf("Measure Potentiometer value\n");

    //initalize main adc hardware
    adc_init();

    //initalize and select adc gpio & input
    adc_gpio_init(GPIO_PIN_26);
    adc_select_input(ADC_MODULE_0);

    //PWM
    //gpio function set to pwm
    gpio_set_function (GPIO_PIN_15, GPIO_FUNC_PWM);

    //getting the slice for gpio 15
    uint slice_num = pwm_gpio_to_slice_num(15);

    //set wrap
    pwm_set_wrap(slice_num, 255);

    //setting channel and level
    pwm_set_chan_level(slice_num, PWM_CHAN_B, 0);

    //set pwm enabled
    pwm_set_enabled(slice_num, true);

    //pwm_value start at 0
    uint pwm_value = 0;

    while(1)
    {
        uint16_t result = adc_read(); //adc_read() can be upto 4095 since its 12 bit
        //scaling 12 bit adc with 16 bit pwm 
        pwm_value = (result * ((1 << 8) - 1)) / ((1 << 12) - 1);
        pwm_set_chan_level(slice_num, PWM_CHAN_B, pwm_value);
        printf("pwm value : %u \n", pwm_value);
        sleep_ms(500);
    }
}