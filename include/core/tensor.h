#ifndef SQUIRREL_TENSOR_H
#define SQUIRREL_TENSOR_H

#include <stddef.h>

typedef struct sqr_tensor_t sqr_tensor;

/**
 * @brief Create a new tensor
 * 
 * User has to call 'sqr_tensor_destroy' after use to avoid memory leak
 * 
 * @param[in] sizes     shape of the tensor
 * @param[in] ndim      number of dimensions
 * @param[in] dtype     data type stored in the tensor
 * @param[out] out      output tensor
 * 
 * @return SQR_OK on success
 * @return SQR_ERR_INVALID_PARAM if one parameter is invalid
 * @return SQR_ERR_NOMEM if memory allocation fails
 * 
 * @see sqr_tensor_destroy
 */
sqr_status sqr_tensor_create(const size_t* sizes, size_t ndim, sqr_dtype dtype, sqr_device device, sqr_tensor** out);

/**
 * @brief Destroy a tensor
 * 
 * @param[in] tensor pointer of the tensor to destroy
 * @see sqr_tensor_create
 */
void sqr_tensor_destroy(sqr_tensor* tensor);

#endif // SQUIRREL_TENSOR_H
