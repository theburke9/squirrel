#ifndef SQUIRREL_INTERNAL_MEM
#define SQUIRREL_INTERNAL_MEM

#include <stddef.h>

void* sqr_mem_alloc(size_t);
void sqr_mem_free(void*);

#endif // SQUIRREL_INTERNAL_MEM
