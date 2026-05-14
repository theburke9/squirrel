#ifndef SQUIRREL_TYPES_H
#define SQUIRREL_TYPES_H

typedef enum sqr_dtype_t sqr_dtype;
typedef enum sqr_status_t sqr_status;
typedef enum sqr_device_t sqr_device;

enum sqr_dtype_t {
    SQR_DTYPE_F32,
    SQR_DTYPE_F64
};

enum sqr_status_t {
    SQR_OK,
    SQR_ERR_INVALID_PARAM,
    SQR_ERR_NOMEM,
    SQR_ERR_INVALID_PHY_SIZE
};

enum sqr_device_t {
    SQR_DEVICE_CPU
};

#endif // SQUIRREL_TYPES_H
