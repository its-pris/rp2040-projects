#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"


#define BUTTON_GPIO 15
#define LED_GPIO 25


int pico_led_init(void)
{
    gpio_init(LED_GPIO);
    gpio_set_dir(LED_GPIO, true);
    return 0;
}

void pico_set_led(bool state)
{
    gpio_put(LED_GPIO, state);
}

int main()
{
    gpio_init(BUTTON_GPIO);
    gpio_set_dir(BUTTON_GPIO, false);  //false -> input
    gpio_pull_up(BUTTON_GPIO);         //gently pulls pin to 3.3v (1)

    int dc = pico_led_init();    //initialize led
    hard_assert(dc == 0);       //crashes program if error
    while(true)
    {
        //when button is pressed
        if (!gpio_get(BUTTON_GPIO))    //!GPIO_GET inverts it;   gpio_get -> current button state
       
        {
            pico_set_led(true);
            sleep_ms(100);
            
        }
        else
        {
            pico_set_led(false);
            sleep_ms(100);
        }
        

    }
}