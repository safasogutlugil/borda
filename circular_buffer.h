#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

typedef struct {
    float *buffer;
    int size;
    int start;
    int count;
} circular_buffer;

void cb_init(circular_buffer *cb, int size);
void cb_push(circular_buffer *cb, float data);
void cb_free(circular_buffer *cb);

#endif // CIRCULAR_BUFFER_H