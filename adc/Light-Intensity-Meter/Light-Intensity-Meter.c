#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include <string.h>

/*#define DO 0
//reading DO pin
int main()
{
    //serial monitor
    stdio_init_all();
    printf("Recording how strong/dim light is \n");

    //DO pin on LDR
    gpio_init(DO);
    gpio_set_dir(0, false);

    while(1)
    {
        //DO PIN
        //HIGH (1) -> no light
        //LOW (0) -> light
        if(gpio_get(DO) == 1) //if D0 pin is HIGH 
        {
            printf("There is NO light present\n");
        }
        else
        {
            printf("There is light present \n"); 
        }
        sleep_ms(500);
    }
}*/


#define GPIO26 26
#define ADC0 0

//reading adc pin
int main()
{
    stdio_init_all();
    printf("Measuring Light \n");

    //init adc hardware
    adc_init();

    //init adc pin
    adc_gpio_init(GPIO26);
    adc_select_input(ADC0);

    char led_state [20] = "";

    while(1)
    {
        float conversion_factor = 3.3f/ (1 << 12);
        uint16_t led_value = adc_read();
        float analog_value = conversion_factor * led_value;
        if (analog_value < 0.8)
        {
            strcpy(led_state, "Bright");
        }
        
        else if (analog_value < 1.6)
        {
            strcpy(led_state, "Light");
        }
        
        else if (analog_value < 2.4)
        {
            strcpy(led_state, "Dim");
        }
        
        else
        {
            strcpy(led_state, "Dark");
        }
        printf("Analog value: %f , Light Level: %s\n", analog_value, led_state);
        sleep_ms(500);
    }
}