#ifndef SENSORS_H
#define SENSORS_H

typedef enum {
    TEMPERATURE,
    HUMIDITY,
    CO2
} sensor_type;

float read_sensor(sensor_type type);

#endif // SENSORS_H