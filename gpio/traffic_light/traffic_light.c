#include <stdio.h>
#include "pico/stdlib.h"


#define RED_LED_GPIO 16
#define YELLOW_LED_GPIO 17
#define GREEN_LED_GPIO 18

int pico_led_init(void)
{
    //initalize red led
    gpio_init(RED_LED_GPIO);
    gpio_set_dir(RED_LED_GPIO, true);

    //initalize yellow led
    gpio_init(YELLOW_LED_GPIO);
    gpio_set_dir(YELLOW_LED_GPIO, true);

    //initalize green led
    gpio_init(GREEN_LED_GPIO);
    gpio_set_dir(GREEN_LED_GPIO, true);

    return 0;

}


int main()
{
    int dc = pico_led_init();

    //set output of red led
    gpio_put(RED_LED_GPIO, false);

    //set output of yellow led
    gpio_put(YELLOW_LED_GPIO, false);

    //set output of green led
    gpio_put(GREEN_LED_GPIO, false);

    hard_assert (dc == 0);

    while(true)
    {
        //red light
        gpio_put(RED_LED_GPIO, true);
        sleep_ms(1000);
        
        //yellow light
        gpio_put(YELLOW_LED_GPIO, true);
        sleep_ms(1000);

        //green light
        gpio_put(RED_LED_GPIO, false);
        gpio_put(YELLOW_LED_GPIO, false);
        gpio_put(GREEN_LED_GPIO, true);
        sleep_ms(1000);

        //switch off green pin
        gpio_put(GREEN_LED_GPIO, false);
        sleep_ms(500);
    }
}