#include <tock.h>

int main(void) {

    void * input_buffer = memop(12, 1);
    void * output_buffer = memop(13, 0);

    int light_reading = 0;
    int * num_pointer = &light_reading;
    memcpy(num_pointer, input_buffer, sizeof(*num_pointer));



    printf("Based on reading: %d \n", light_reading);
    float lr_flt = light_reading;
    float target_lux = 500;
    float bchange = 0;
    if(lr_flt != 0){
        bchange = (target_lux/lr_flt)*100;
        if(bchange == 100)
        {
            printf("Brightness should stay the same\n");
        }
        else if(bchange > 100){
            printf("Brightness should be increased by %dx\n", (int)(bchange/100));
        }
        else{
            printf("Lights should be turned off\n");
        }
    }
    int final_brightness_change = (int)bchange;
    int * brightness_pointer = &final_brightness_change;
    memcpy(output_buffer, brightness_pointer, sizeof(*brightness_pointer));


    exit(0);
}

