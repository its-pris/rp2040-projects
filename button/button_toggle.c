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
    gpio_set_dir(BUTTON_GPIO, false); //input
    gpio_pull_up(BUTTON_GPIO);

    bool state = false;
    int previous_state = gpio_get(BUTTON_GPIO);    //stores the previous state of gpio_get

    int dc = pico_led_init();
    hard_assert(dc == 0);
    while(true)
    {
        int current_state = gpio_get(BUTTON_GPIO);  //stores the current state of gpio_get
        if (current_state != previous_state)
        {
            if (current_state == false)  //false -> button pressed because its pulled up
            {
                state = !state; //toggles state
                pico_set_led(state); //led turns on or off
            }
            previous_state = current_state;
            sleep_ms(100);
        }

    }

}