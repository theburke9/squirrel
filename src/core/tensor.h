#ifndef SQUIRREL_INTERNAL_TENSOR_H
#define SQUIRREL_INTERNAL_TENSOR_H

#include "squirrel_internal.h"

struct sqr_tensor_t {
    usize ndim;
    usize* sizes;
    isize* strides;
    sqr_storage* storage;
};

#endif // SQUIRREL_INTERNAL_TENSOR_H
