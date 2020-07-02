#include <stdbool.h>
#include <stdio.h>

#include <ambient_light.h>
#include <timer.h>
#include <tock.h>

static bool isl29035 = false;

//static void timer_fired(__attribute__ ((unused)) int arg0,
//                        __attribute__ ((unused)) int arg1,
//                        __attribute__ ((unused)) int arg2,
//                        __attribute__ ((unused)) void* ud) {
//  int light = 0;
//
//  /* *INDENT-OFF* */
//  if (isl29035)     ambient_light_read_intensity_sync(&light);
//
//  void * output_buffer = memop(13, 0);
//
//  int * num_pointer = &light;
//  memcpy(output_buffer, num_pointer, sizeof(*num_pointer));
//
//  if (isl29035)       printf("ISL29035:   Light Intensity: %d\n", light);
//
//  printf("\n");
//}

int main(void) {

    printf("Sensing Ambient Light.\n");

    isl29035    = driver_exists(DRIVER_NUM_AMBIENT_LIGHT);
    // Setup periodic timer to sample the sensors.
//    static tock_timer_t timer;
//    timer_every(1000, timer_fired, NULL, &timer);
  int light = 0;

  /* *INDENT-OFF* */
  if (isl29035)     ambient_light_read_intensity_sync(&light);

  void * output_buffer = memop(13, 0);

  int * num_pointer = &light;
  memcpy(output_buffer, num_pointer, sizeof(*num_pointer));

  if (isl29035)       printf("ISL29035:   Light Intensity: %d\n", light);

  printf("\n");

    exit(0);
}
