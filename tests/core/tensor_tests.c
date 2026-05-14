#include "unity/unity.h"
#include "squirrel.h"

void setUp() {}
void tearDown() {}

void test_tensor_create_valid(void) {
    sqr_tensor* t = NULL;
    size_t sizes[] = {4, 5, 6};

    sqr_status status = sqr_tensor_create(sizes, 3, SQR_DTYPE_F32, SQR_DEVICE_CPU, &t);

    TEST_ASSERT_EQUAL(status, SQR_OK);
    TEST_ASSERT_NOT_NULL(t);

    sqr_tensor_destroy(t);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_tensor_create_valid);
    return UNITY_END();
}
