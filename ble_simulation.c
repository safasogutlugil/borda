#include "ble_simulation.h"
#include <stdio.h>

void send_ble_statistics(const char* sensor_type, float min, float max, float median, float std_dev) {
    printf("BLE Packet with Statistics for %s:\n", sensor_type);
    printf("Min: %.2f, Max: %.2f, Median: %.2f, Std Dev: %.2f\n\n", min, max, median, std_dev);
}
