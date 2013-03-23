/*   MEMORY.C -- COLD-WAVE Operating System
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

#include "include/types.h"	//for size_t
#include "memory_allocator_firstFit.c"

#define ALLOCATOR_BASE 0x100000		//we start allocating memory from this address
void * NextFreeByte=ALLOCATOR_BASE;	//indicates the next free byte in memory

/*!
 * Copies n characters from str2 to str1
 */


/*!
 * copy memory to file, used to write MEM_VIDEO to a file, or used to write to the paging file
*/
int writeMemToFile()
{
	//not yet writen
}


/*!
 * malloc : a simple malloc that allocates the next bytes of memory and return to you their address
*/
void * malloc(uint32_t size)
{
	return mem_firstFit_alloc(size);
}

void free(void * address)
{
	mem_firstFit_free(address);
}

void memory_allocator_init()
{
	// start at address 2MB
	// memory size = 16MB, this should be set to the size of real memory
	mem_firstFit_init(2000000, 16*1024*1024); 
}

unsigned long int mem_get_free_space()
{
	return mem_firstFit_free_size();
}

