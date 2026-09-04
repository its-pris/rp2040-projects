#include <stdio.h>
#include "pico/stdlib.h"
#include"hardware/adc.h"


#define TEMPERATURE_PIN 4

int main()
{
    stdio_init_all();
    printf("Measuring Temperature using Internal sensor");

    adc_init();

    //since its internal, no external gpio
    adc_set_temp_sensor_enabled(true);
    adc_select_input(TEMPERATURE_PIN);

    while(1)
    {
        float conversion_factor = 3.3f / (1 << 12);
        uint16_t adc_value = adc_read();
    
        float adc_voltage = conversion_factor * adc_value;
        //conversion taken from datasheet
        float temperature = 27 - (adc_voltage - 0.706) / 0.001721;

        printf("Internal Temperature: %.1f\n", temperature);
        sleep_ms(500);
    }
}
