#include <stdlib.h>
#include "core/mem.h"

void* sqr_mem_alloc(size_t size) {
    return calloc(1, size);
}

void sqr_mem_free(void* ptr) {
    free(ptr);
}
