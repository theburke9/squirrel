#include "squirrel_internal.h"

static usize sqr_storage_get_phy_size(usize size, sqr_dtype dtype) {
    switch (dtype) {
        case SQR_DTYPE_F32:
            return sizeof(f32) * size;
        case SQR_DTYPE_F64:
            return sizeof(f64) * size;
        default:
            return 0;
    }
}

sqr_status sqr_storage_create(usize size, sqr_dtype dtype, sqr_device device, sqr_storage** out) {
    if (out == NULL)
        return SQR_ERR_INVALID_PARAM;

    if (size == 0)
        return SQR_ERR_INVALID_PARAM;

    sqr_status status = SQR_OK;

    u8* data = NULL;
    usize phy_size = 0;
    sqr_storage* storage = NULL;

    phy_size = sqr_storage_get_phy_size(size, dtype);
    if (phy_size == 0) {
        status = SQR_ERR_INVALID_PHY_SIZE;
        goto cleanup;
    }

    storage = sqr_mem_alloc(sizeof(sqr_storage));
    if (storage == NULL) {
        status = SQR_ERR_NOMEM;
        goto cleanup;
    }

    data = sqr_mem_alloc(phy_size);
    if (data == NULL) {
        status = SQR_ERR_NOMEM;
        goto cleanup;
    }

    storage->data = data;
    storage->phy_size = phy_size;
    storage->dtype = dtype;
    storage->device = device;

    *out = storage;
    
    return SQR_OK;

cleanup:
    sqr_storage_destroy(storage);
    return status;
}

void sqr_storage_destroy(sqr_storage* storage) {
    if (storage) {
        if (storage->data) {
            sqr_mem_free(storage->data);
            storage->data = NULL;
        }

        sqr_mem_free(storage);
    }
}