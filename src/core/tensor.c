#include <stdio.h>
#include "squirrel_internal.h"

static sqr_status sqr_tensor_create_sizes(const usize* sizes, usize ndim, usize** out) {
    if ((sizes == NULL) || (out == NULL))
        return SQR_ERR_INVALID_PARAM;

    // scalar tensor (ndim == 0) has no sizes
    if (ndim == 0)
        return SQR_ERR_INVALID_PARAM;

    usize* outSizes = NULL;

    outSizes = sqr_mem_alloc(sizeof(usize) * ndim);
    if (outSizes == NULL)
        return SQR_ERR_NOMEM;

    for (usize i = 0; i < ndim; ++i)
        outSizes[i] = sizes[i];

    *out = outSizes;

    return SQR_OK;
}

static sqr_status sqr_tensor_create_strides(const usize* sizes, usize ndim, isize** out) {
    if ((sizes == NULL) || (out == NULL))
        return SQR_ERR_INVALID_PARAM;

    // scalar tensor (ndim == 0) has no strides
    if (ndim == 0)
        return SQR_ERR_INVALID_PARAM;

    isize* outStrides = NULL;

    outStrides = sqr_mem_alloc(sizeof(isize) * ndim);
    if (outStrides == NULL)
        return SQR_ERR_NOMEM;

    outStrides[ndim - 1] = 1;
    for (usize i = ndim - 1; i > 0; --i)
        outStrides[i - 1] = outStrides[i] * sizes[i];

    *out = outStrides;

    return SQR_OK;
}

sqr_status sqr_tensor_create(const usize* sizes, usize ndim, sqr_dtype dtype, sqr_device device, sqr_tensor** out) {
    if (out == NULL)
        return SQR_ERR_INVALID_PARAM;

    sqr_status status = SQR_OK;
    
    usize phy_size = 1;
    usize* outSizes = NULL;
    isize* outStrides = NULL;
    sqr_tensor* tensor = NULL;
    sqr_storage* storage = NULL;

    // allocate memory for the output tensor
    tensor = sqr_mem_alloc(sizeof(sqr_tensor));
    if (tensor == NULL) {
        status = SQR_ERR_NOMEM;
        goto cleanup;
    }

    if (ndim > 0) {
        // allocate memory for the sizes of the tensor
        status = sqr_tensor_create_sizes(sizes, ndim, &outSizes);
        if (status != SQR_OK)
            goto cleanup;

        // allocate memory for the strides of the tensor
        status = sqr_tensor_create_strides(sizes, ndim, &outStrides);
        if (status != SQR_OK)
            goto cleanup;
    }

    for (usize i = 0; i < ndim; ++i) {
        phy_size *= sizes[i];
    }

    status = sqr_storage_create(phy_size, dtype, device, &storage);
    if (status != SQR_OK)
        goto cleanup;

    tensor->ndim = ndim;
    tensor->sizes = outSizes;
    tensor->strides = outStrides;
    tensor->storage = storage;

    *out = tensor;

    return SQR_OK;

cleanup:
    sqr_tensor_destroy(tensor);
    return status;
}

void sqr_tensor_destroy(sqr_tensor* tensor) {
    if (tensor) {
        if (tensor->sizes) {
            sqr_mem_free(tensor->sizes);
            tensor->sizes = NULL;
        }

        if (tensor->strides) {
            sqr_mem_free(tensor->strides);
            tensor->strides = NULL;
        }

        if (tensor->storage) {
            sqr_storage_destroy(tensor->storage);
            tensor->storage = NULL;
        }

        sqr_mem_free(tensor);
    }
}
