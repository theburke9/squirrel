#include <stdio.h>

#include "squirrel.h"

int main(void) {
    sqr_tensor* t;
    size_t shape[] = {4, 6, 2, 10, 10, 11};
    sqr_tensor_create(shape, 6, SQR_DTYPE_F64, SQR_DEVICE_CPU, &t);
    sqr_tensor_destroy(t);
    return 0;
}
