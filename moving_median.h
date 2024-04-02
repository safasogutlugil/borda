#ifndef MOVING_MEDIAN_H
#define MOVING_MEDIAN_H

#include "circular_buffer.h"

#define MEDIAN_WINDOW_SIZE 5

float moving_median(circular_buffer *cb, float new_sample);
static int compare_floats(const void *a, const void *b);

#endif // MOVING_MEDIAN_H