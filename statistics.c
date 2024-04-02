#include "statistics.h"
#include <math.h>
#include <stdlib.h>

static int compare_floats(const void* a, const void* b) {
    float fa = *(const float*)a;
    float fb = *(const float*)b;
    return (fa > fb) - (fa < fb);
}

void calculate_statistics(const float* data, size_t count, float* min, float* max, float* median, float* std_dev) {
    float sum = 0, mean, variance = 0;
    *min = *max = data[0];
    float* sorted_data = (float*)malloc(count * sizeof(float));
    for (size_t i = 0; i < count; ++i) {
        sorted_data[i] = data[i];
        sum += data[i];
        if (data[i] < *min) *min = data[i];
        if (data[i] > *max) *max = data[i];
    }

    mean = sum / count;
    qsort(sorted_data, count, sizeof(float), compare_floats);
    *median = (count % 2 == 0) ? 
              (sorted_data[count / 2 - 1] + sorted_data[count / 2]) / 2.0f :
              sorted_data[count / 2];

    for (size_t i = 0; i < count; ++i) {
        variance += pow(data[i] - mean, 2);
    }
    *std_dev = sqrt(variance / count);

    free(sorted_data);
}