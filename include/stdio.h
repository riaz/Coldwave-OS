#ifndef _STDIO_H
#define _STDIO_H

#define	MEM_VIDEO 0XB8000			// the beginning of video memory
#define SCREEN_LIM 0xB8FA0			// do the size of the video memory = 0xFA0
#define MEM_VIDEO_SIZE 0xFA0			// size of video memory
#define BACK_MEM_VIDEO 0xB7060			// Back video memory zone:used to store lines that are scrolled (by the function scroll), it has a size of 0xFA0 
#define LINE_SIZE (2 * LINES_COUNT)		//the size of a line

char LINES_COUNT=80;				// number of lines in the shell (window!)
char COLUMNS_COUNT=25;				
char CAR_ATTR = 0x07; 				// attribut(color of the caracter)(black & white)
char OLD_CAR_ATTR = 0x07;			//to save CAR_ATTR whan it changes
int CUR_X = 0; 					//current cursor postion (Psition for X )
int CUR_Y = 10;
char * BACK_MEM_VIDEO_PTR = BACK_MEM_VIDEO;	//a pointer on the BACK_MEM_VIDEO zone: points the last line that came from the scroll function. i.e the last saved line.

#define TAB_SPACE 0x7				//tab space


extern void gotoxy(const char x, const char y);
extern void delline(int y);
extern void gotoxy(const char x, const char y);
extern void setTextColor(char color);
extern void clrscr();

#endif