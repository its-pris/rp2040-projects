#include <stdio.h>
#include "pico/stdlib.h"

#define BUTTON_GPIO 15
#define LED_GPIO 25

int pico_led_init(void)  //initalize led
{
    gpio_init(LED_GPIO);
    gpio_set_dir(LED_GPIO, true);
    return 0;
}

void pico_set_led(bool state)  //state of led
{
    gpio_put(LED_GPIO, state);      //switches between 1 and 0 
}

int main()
{
    stdio_init_all();

    sleep_ms(2000);
    
    gpio_init(BUTTON_GPIO);
    gpio_set_dir(BUTTON_GPIO, false);   //input
    gpio_pull_up(BUTTON_GPIO);   

    bool state = false;
    int previous_state = gpio_get(BUTTON_GPIO);

    int dc = pico_led_init();
    hard_assert(dc == 0);

    int count = 0;

    while(true)
    {
    
        int current_state = gpio_get(BUTTON_GPIO);

        if (current_state != previous_state)
        {
            if (current_state == false)    //false -> button pressed
            {
                state = !state;  //toggles state
                pico_set_led(state);
                count++;
                printf("count: %d\n ", count);
            }
            previous_state = current_state;
            sleep_ms(100);
            
        }
    }
}
