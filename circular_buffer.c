#include "circular_buffer.h"
#include <stdlib.h>
#include <string.h>

void cb_init(circular_buffer *cb, int size) {
    cb->buffer = (float*)malloc(sizeof(float) * size);
    cb->size = size;
    cb->start = 0;
    cb->count = 0;
}

void cb_push(circular_buffer *cb, float data) {
    int end = (cb->start + cb->count) % cb->size;
    cb->buffer[end] = data;
    if (cb->count == cb->size) {
        cb->start = (cb->start + 1) % cb->size; // Overwrite oldest data
    } else {
        ++cb->count;
    }
}

void cb_free(circular_buffer *cb) {
    free(cb->buffer);
    cb->buffer = NULL;
    cb->size = 0;
    cb->start = 0;
    cb->count = 0;
}