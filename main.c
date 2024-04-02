#include "sensors.h"
#include "moving_median.h"
#include "circular_buffer.h"
#include "ble_simulation.h"
#include "statistics.h"
#include <stdio.h>

#define SENSOR_READINGS_COUNT 100
#define MEDIAN_WINDOW_SIZE 5

int main() {
    circular_buffer cb_temp, cb_humidity, cb_co2;
    cb_init(&cb_temp, MEDIAN_WINDOW_SIZE);
    cb_init(&cb_humidity, MEDIAN_WINDOW_SIZE);
    cb_init(&cb_co2, MEDIAN_WINDOW_SIZE);

    float sensor_values_temp[SENSOR_READINGS_COUNT];
    float sensor_values_humidity[SENSOR_READINGS_COUNT];
    float sensor_values_co2[SENSOR_READINGS_COUNT];
    float median_filtered_values_temp[SENSOR_READINGS_COUNT];
    float median_filtered_values_humidity[SENSOR_READINGS_COUNT];
    float median_filtered_values_co2[SENSOR_READINGS_COUNT];

    // Simulate sensor data collection and processing for each sensor type
    for(int i = 0; i < SENSOR_READINGS_COUNT; ++i) {
        sensor_values_temp[i] = read_sensor(TEMPERATURE);
        median_filtered_values_temp[i] = moving_median(&cb_temp, sensor_values_temp[i]);

        sensor_values_humidity[i] = read_sensor(HUMIDITY);
        median_filtered_values_humidity[i] = moving_median(&cb_humidity, sensor_values_humidity[i]);

        sensor_values_co2[i] = read_sensor(CO2);
        median_filtered_values_co2[i] = moving_median(&cb_co2, sensor_values_co2[i]);
    }

    // Calculate and send statistics for each sensor type
    float min, max, median, std_dev;
    calculate_statistics(median_filtered_values_temp, SENSOR_READINGS_COUNT, &min, &max, &median, &std_dev);
    send_ble_statistics("Temperature (°C)", min, max, median, std_dev);

    calculate_statistics(median_filtered_values_humidity, SENSOR_READINGS_COUNT, &min, &max, &median, &std_dev);
    send_ble_statistics("Humidity (%)", min, max, median, std_dev);

    calculate_statistics(median_filtered_values_co2, SENSOR_READINGS_COUNT, &min, &max, &median, &std_dev);
    send_ble_statistics("CO2 (ppm)", min, max, median, std_dev);

    return 0;
}