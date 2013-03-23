#ifndef _MEM_ALLOC_H
#define _MEM_ALLOC_H


 typedef unsigned long int 	uli;
 unsigned  long int  		free_mem_size_bytes;
 struct chunk * 			memory;  //the list of free memory chunks

extern int 	mem_firstFit_init(void * pool, unsigned  long int __mem_size);
extern int 	mem_firstFit_free(void * p);
extern void 	mem_firstFit_fragment();
extern void * 	mem_firstFit_alloc(unsigned  long int size);
extern void * 	mem_firstFit_set_chunk_size (void * p,unsigned  long int size);
extern unsigned long  int mem_firstFit_get_chunk_size (void * p);

#endif