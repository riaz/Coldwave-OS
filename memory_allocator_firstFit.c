 /*  memory_allocator_firstFit.C -- COLD-WAVE Operating System
     Copyright (C) 2011-12 Munshi Riaz
	 riaz.2012@gamil.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.*/
#include <mem_alloc.h>



/*!
 * this is a list of free memory chunks (pieces), the size of each chunk is specified before it's address 
 *that means, for example if chunk1 is the address the first chunk of free memory, so it's size is in the address :
                        chunk1 - sizeof(unsigned  long int)
 *use the function mem_firstFit_get_chunk_size() to get the size  
 */
typedef struct chunk 
{
     unsigned  long int  chunk_size;
      void * mem_chunk;      
      struct chunk * nextFree;
}     __attribute__ ((packed)); 




/*!
	allocate function: looks into the free chunks list and chooses the first
	free chunk that has a space more than the requested, it allocates it, 
	and memories the size of the new allocated chunk, so that when memory is 
	freed, free space can be recognised.
*/
void * mem_firstFit_alloc(unsigned  long int size)
{
      struct chunk * memory_chunks_list;
      void * allocated_space;
      unsigned  long int oldSize;

     memory_chunks_list =memory;
      while   ((memory_chunks_list != NULL)   &&  ((memory_chunks_list->chunk_size)<size))
      { 
            memory_chunks_list = memory_chunks_list->nextFree;
      }
     if (memory_chunks_list  == NULL)   //request not satisfied
     {            
            //printf("Memory Full, Refragmenting memory... please try to allocate again.\n ");
            mem_firstFit_fragment(); //not yet implemented
            return NULL;
     }
     else
     {
            oldSize=memory_chunks_list->chunk_size; 
            free_mem_size_bytes -= size;
            allocated_space = memory_chunks_list->mem_chunk;                 
            allocated_space=mem_firstFit_set_chunk_size(allocated_space, size);
            memory_chunks_list->chunk_size =  oldSize - size;
            memory_chunks_list->mem_chunk =allocated_space + size;
          
            return allocated_space;
     }      
}


/*!
	get the size of the allocated space p, the size of an allocated memory
	chunk is stored in the 4 bytes just before the address of that chunk,
	in this way we can get the size of the allocated space, and add it to
	the free chunks list
	
	*********************************************************
	* size of allocated	*	the allocated space	* 
	* space (4 bytes)	*				*
	*********************************************************
*/
unsigned  long int mem_firstFit_get_chunk_size (void * p)
{
 unsigned  long int *  thatPlace=    p - sizeof(unsigned  long int);
 return *thatPlace;
}

/*!
	specify the size of the allocated space
*/
void * mem_firstFit_set_chunk_size (void * p,unsigned  long int size)
{
      uli * pp= p;
      (*pp) = size;
      p += sizeof (uli);
      return p;
}

/*!
 * 	free and adjascesnt chunks are not grouped, so fragmentation is high,
   	until the function fragment is run;
 */
int mem_firstFit_free(void * p)
{
      struct chunk *  new_free_chunk;
      new_free_chunk=mem_firstFit_alloc(sizeof(struct chunk)); //this should not fail!
      if(new_free_chunk==NULL)
      {     
            //Memory  is very low! trying to free memory by refragmenting
            mem_firstFit_fragment();
            new_free_chunk=mem_firstFit_alloc(sizeof(struct chunk)); //this should NEVER fail, else the system kernel crash
            if(new_free_chunk==NULL)
            {
                        //printf(" Could not get more space by reframenting memory! No memory !\n");
                        return 0;
                        // what could we do here, we can shou info about memory
            }
            else
            {
                  //printf(" More space was freed \n");
            }                  
     }      
      free_mem_size_bytes  += mem_firstFit_get_chunk_size(p) ;
      new_free_chunk->chunk_size=mem_firstFit_get_chunk_size(p) ;
      new_free_chunk->mem_chunk=p;
      new_free_chunk->nextFree = memory;     
      memory=new_free_chunk;
}


void mem_firstFit_fragment()
{
      //fragment memory, merge adjascent chunks into one: not yet implemented
}

/*! initialize the allocator*/
int mem_firstFit_init(void * pool, unsigned  long int __mem_size)
{
      /* if many memory managers are used with the same kernel, we should spesify a pool for this allocator to be 
       used when allocating, this is not yes supported*/
      
      //we leave the first 2MB of memory, we start allocating from the address 2000000
      memory=pool;   
      memory ->mem_chunk = pool+sizeof(struct chunk);      
      memory->nextFree=NULL;    
       free_mem_size_bytes =  __mem_size - sizeof(struct chunk);
        memory->chunk_size= free_mem_size_bytes;
}


int mem_firstFit_finish()
{
      
}
 
/*! Return free memory in bytes*/
unsigned long int mem_firstFit_free_size()
{     
      return  free_mem_size_bytes;
}

