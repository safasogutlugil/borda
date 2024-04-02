#ifndef STATISTICS_H
#define STATISTICS_H

#include <stddef.h>

void calculate_statistics(const float* data, size_t count, float* min, float* max, float* median, float* std_dev);

#endif // STATISTICS_H