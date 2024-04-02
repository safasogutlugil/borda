#ifndef BLE_SIMULATION_H
#define BLE_SIMULATION_H

void send_ble_statistics(const char* sensor_type, float min, float max, float median, float std_dev);

#endif // BLE_SIMULATION_H