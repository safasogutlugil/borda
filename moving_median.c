#include "moving_median.h"
#include "circular_buffer.h"
#include <stdlib.h>

static int compare_floats(const void* a, const void* b) {
    float fa = *(const float*)a;
    float fb = *(const float*)b;
    return (fa > fb) - (fa < fb);
}

float calculate_median(float* data, size_t count) {
    qsort(data, count, sizeof(float), compare_floats);
    if (count % 2 == 0) {
        return (data[count / 2 - 1] + data[count / 2]) / 2.0f;
    } else {
        return data[count / 2];
    }
}

float moving_median(circular_buffer *cb, float new_sample) {
    cb_push(cb, new_sample);
    float sorted_window[cb->size];
    for (int i = 0; i < cb->count; ++i) {
        sorted_window[i] = cb->buffer[(cb->start + i) % cb->size];
    }
    qsort(sorted_window, cb->count, sizeof(float), compare_floats);
    return calculate_median(sorted_window, cb->count);
}