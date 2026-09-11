#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include <string.h>

#define DO 0

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
}
