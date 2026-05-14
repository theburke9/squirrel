#ifndef SQUIRREL_INTERNAL_STORAGE_H
#define SQUIRREL_INTERNAL_STORAGE_H

#include "squirrel_internal.h"

typedef struct sqr_storage_t sqr_storage;

struct sqr_storage_t {
    u8* data;
    usize phy_size;
    sqr_dtype dtype;
    sqr_device device;
};

sqr_status sqr_storage_create(usize phy_size, sqr_dtype dtype, sqr_device device, sqr_storage** out);
void sqr_storage_destroy(sqr_storage* storage);

#endif // SQUIRREL_INTERNAL_STORAGE_H
