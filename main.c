 /*  MAIN.C -- COLD-WAVE Operating System
     Copyright (C) 2011-12 Munshi Riaz
	 riaz.2012@gmail.com

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
#include <system.h>
#include <types.h>
#include <time.h>

void *memcpy(void *dest, const void *src, size_t count)
{
    const char *sp = (const char *)src;
    char *dp = (char *)dest;
    for(; count != 0; count--) *dp++ = *sp++;
    return dest;
}

void *memset(void *dest, char val, size_t count)
{
    char *temp = (char *)dest;
    for( ; count != 0; count--) *temp++ = val;
    return dest;
}

unsigned short *memsetw(unsigned short *dest, unsigned short val, size_t count)
{
    unsigned short *temp = (unsigned short *)dest;
    for( ; count != 0; count--) *temp++ = val;
    return dest;
}

size_t strlen(const char *str)
{
    size_t retval;
    for(retval = 0; *str != '\0'; str++) retval++;
    return retval;
}

unsigned char inportb (unsigned short _port)
{
    unsigned char rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

void outportb (unsigned short _port, unsigned char _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

void main()
{
    gdt_install();
    idt_install();
    isrs_install();
    irq_install();
    init_video();
    timer_install();
    keyboard_install();

    __asm__ __volatile__ ("sti");

	settextcolor(LIGHT_BROWN,BLACK);
	logo();
	settextcolor(RED,BLACK);
	printf("Kernel Loaded ..........................");    
	settextcolor(GREEN,BLACK);
	printf("[OK]\n");	
		
	settextcolor(RED,BLACK);
	printf("GDT Loaded .............................");
    settextcolor(GREEN,BLACK);
	printf("[OK]\n");
	settextcolor(RED,BLACK);
	
	printf("Initializing interuptions...............");
	settextcolor(GREEN,BLACK);
	printf("[OK]\n");	
	settextcolor(RED,BLACK);

	printf("Analyzing Interrupt Requests............");
	settextcolor(GREEN,BLACK);
	printf("[OK]\n");	
	settextcolor(RED,BLACK); 

	printf("IDT Loaded .............................");  
	settextcolor(GREEN,BLACK); 
	printf("[OK]\n");
	settextcolor(RED,BLACK);

	printf("Loading Keyboard Drivers................");
	settextcolor(GREEN,BLACK);
	printf("[OK]\n");	
	settextcolor(RED,BLACK);

	printf("Initializing CPU Clock Frequency........");
 	settextcolor(GREEN,BLACK);
	printf("[OK]\n");	
	settextcolor(RED,BLACK);


	printf("Entering Protected Mode.................");
	settextcolor(GREEN,BLACK);
	printf("[OK]\n");	

	 	
    LoadConsole();			//loads the basic console




    

   // for (;;);
}
