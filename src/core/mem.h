#ifndef SQUIRREL_INTERNAL_MEM
#define SQUIRREL_INTERNAL_MEM

#include <stddef.h>

/**
 * @brief Allocate memory of the given size
 * 
 * @note Allocate memory is ALWAYS zero-initialized
 * 
 * @param[in] size Number of bytes
 * @return pointer to the allocated memory, or NULL if allocation fails
 */
void* sqr_mem_alloc(size_t size);
void sqr_mem_free(void* ptr);

#endif // SQUIRREL_INTERNAL_MEM
