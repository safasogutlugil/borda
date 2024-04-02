#include "sensors.h"
#include <stdlib.h>

float read_sensor(sensor_type type) {
    switch (type) {
        case TEMPERATURE:
            return (rand() % 4000) / 100.0; // Simulating temperatures between 0.0 and 40.0
        case HUMIDITY:
            return (rand() % 10000) / 100.0; // Simulating humidity between 0.0 and 100.0
        case CO2:
            return (rand() % 2000) + 400.0; // Simulating CO2 levels between 400.0 and 2400.0 ppm
        default:
            return 0.0;
    }
}