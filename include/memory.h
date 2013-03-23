#ifndef _MEMORY_H
#define _MEMORY_H
#include <types.h>

#define ALLOCATOR_BASE 0x100000	
extern void * NextFreeByte=ALLOCATOR_BASE;

extern void memcopy(void *str1, void *str2, int n);

extern void memset(void *dest,int size,char car);

extern int writeMemToFile();

extern void * malloc(uint32_t size);

extern void free(void * address);

extern void memory_allocator_init();

extern unsigned long int mem_get_free_space();

#endif