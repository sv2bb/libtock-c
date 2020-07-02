#include <stdbool.h>
#include <stdio.h>
#include <tock.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <ble_advdata.h>
#include <nordic_common.h>
#include <nrf_error.h>

#include <simple_adv.h>
#include <simple_ble.h>

#include <gpio.h>
#include <ninedof.h>
#include <nrf51_serialization.h>
#include <timer.h>


// Manufacturer specific data setup
#define SEMI_COMPANY_IDENTIFIER 0x02E0
uint8_t mdata[2] = {0x01, 0x03};

// Intervals for BLE advertising and connections
simple_ble_config_t ble_config = {
  .platform_id       = 0x13,                // used as 4th octect in device BLE address
  .device_id         = DEVICE_ID_DEFAULT,
  .adv_name          = (char*)"imixboi",
  .adv_interval      = MSEC_TO_UNITS(1000, UNIT_0_625_MS),
  .min_conn_interval = MSEC_TO_UNITS(1000, UNIT_1_25_MS),
  .max_conn_interval = MSEC_TO_UNITS(1250, UNIT_1_25_MS),
};

// Empty handler for setting BLE addresses
void ble_address_set (void) {
  // nop
}

static void timer_fired(__attribute__ ((unused)) int arg0,
                        __attribute__ ((unused)) int arg1,
                        __attribute__ ((unused)) int arg2,
                        __attribute__ ((unused)) void* ud) {

                        printf("hello :)");
                        printf("\n");
                        exit(0);

//    exit(0);
}

int main(void) {
    printf("[imix] BLE app!\n");

    // get input buffer
    void * input_buffer = memop(12, 2);

    int brightness_change = 0;
    int * num_pointer = &brightness_change;
    memcpy(num_pointer, input_buffer, sizeof(*num_pointer));

    printf("Received brightness change %d", brightness_change);
    simple_ble_init(&ble_config);

    uint32_t      err_code;
    ble_advdata_service_data_t service_data;
//    service_data.service_uuid   = 0xBEAF;
    service_data.data.p_data    = &brightness_change;
    service_data.data.size      = 4;

    ble_advdata_t advdata;
    ble_advdata_t srdata;
    memset(&advdata, 0, sizeof(advdata));
    memset(&srdata, 0, sizeof(srdata));
    advdata.include_appearance      = false;
    advdata.flags                   = BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE;
    advdata.p_service_data_array = &service_data;
    advdata.service_data_count      = 1;
    srdata.name_type            = BLE_ADVDATA_FULL_NAME;
    err_code = ble_advdata_set(&advdata, &srdata);
    APP_ERROR_CHECK(err_code);

    // Start the advertisement
    advertising_start();
    static tock_timer_t timer;
    timer_every(1000, timer_fired, NULL, &timer);
    return(0);
}
