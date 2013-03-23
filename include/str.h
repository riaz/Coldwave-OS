
#ifndef _STRING_H
#define	_STRING_H

#include <types.h>		//Types definition

#define END_CHAR  '\0'		//char indicates the end of string
#define LINE_LENGTH 255		//length of a line in the console
#define MAX_LINE_CHAR	254	//used as LINE_LENGTH-1, but it's calculated for performence

extern char * strcat(char * destination,char * source);
extern char * strchr(char * s,int c);
extern int strcmp(char * s1,char * s2);
extern inline char * strcpy(char  s1[], const char s2[]);
extern inline char * strcopy(char  s1[], const char s2[]);
//extern size_t strlen(const char * s);
extern char * Sreadline();
extern char * readline();

#endif
