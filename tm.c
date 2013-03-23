#include <system.h>

#define CMOS_READ(addr) ({ outb_p(0x80|addr,0x70); inb_p(0x71);}) 
 
#define outb_p(value,port)  __asm__ ("outb %%al,%%dx\n" "\tjmp 1f\n" "1:\tjmp 1f\n"  "1:"::"a" (value),"d" (port)) 
 
#define inb_p(port) ({ unsigned char _v; __asm__ volatile ("inb %%dx,%%al\n" "\tjmp 1f\n" "1:\tjmp 1f\n" "1:":"=a" (_v):"d" (port)); _v; }) 
 
#define outb(value,port) __asm__ ("outb %%al,%%dx"::"a" (value),"d" (port)) 

#define inb(port) ({ unsigned char _v; __asm__ volatile ("inb %%dx,%%al":"=a" (_v):"d" (port)); _v; }) 

char* day[7]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
char* month[12]={"january","february","march","april","may","june","july","august","september","october","november","december"};

 
void dayOfWeek() 
{ 
     printf("\n %s \n", day[CMOS_READ(6)-1]); 
		        
} 

void  sys_time()
{
	int second;
	int hour;
	int min;
	
	hour=(CMOS_READ(4) & 0x0F) + ((CMOS_READ(4) / 16) * 10);
	min=(CMOS_READ(2) & 0x0F) + ((CMOS_READ(2) / 16) * 10);
	second=(CMOS_READ(0) & 0x0F) + ((CMOS_READ(0) / 16) * 10);
	printf("\n %d : %d : %d\n",hour,min,second);  
        
}

void date()
{
	int year=2012;
	printf("\n %d - %s - %d\n",CMOS_READ(7),month[CMOS_READ(8)-1],year);  
    
}


