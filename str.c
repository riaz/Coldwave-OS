 /*  STR.C -- COLD-WAVE Operating System
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


#include <str.h>

char * strcat(char * destination,char * source)				
{
	register char * dp=destination;			//destination pointer, in a register to make it quicker
	register char * sp=source;

	while (*dp) dp++;
	while (*sp)					//no test on the necessary space for
							//destination:i.e overflow possible
	{						//sp may not contain an END_CHAR
		*dp = *sp;
		dp++;
		sp++;
	}
	*dp = END_CHAR;

	return destination;
}



/*!
The function searches for the first element of the string s that equals (char)c. It considers the terminating 
null character as part of the string. If successful, the function returns the address of the matching element; 
otherwise, it returns a null pointer.
*/
char * strchr(char * s,int c)
{
	register char * tempS=s;
	while ( (*tempS != c)  &&  (*tempS != END_CHAR) )//search c until the end
	{
		tempS++;
	}
	if (*tempS ==c)	return tempS;			//c was found
	else			return (char*) NULL;
}

/*!
The function compares successive elements from two strings, s1 and s2, until it finds elements that are not equal.

    * If all elements are equal, the function returns zero.
    * If the differing element from s1 is greater than the element from s2, the function returns a positive value.
    * Otherwise, the function returns a negative value. 
*/
int strcmp(char * s1,char * s2)
{
	register char * tempS1=s1, * tempS2=s2;
	
	while ( (*tempS1 != END_CHAR) && (*tempS2 != END_CHAR) && (*tempS1 == *tempS2) )
	{
		tempS1++;
		tempS2++;
	}

	return (*tempS1)-(*tempS2);
}

/* an other algorithme possible for the strcmp function, By the OsKit group kernel:
int	strcmp(const char *s1, const char *s2)
{
unsigned int a, b;
	while ( (a = *s1++), (b = *s2++), a && b) {
		if (a != b)
			return (a-b);
	}

	return a-b;
}*/

/*!
The function copies the string s2, including its terminating null character, to successive elements of the array 
of char whose first element has the address s1. It returns s1.
*/
inline char * strcopy(char  s1[], const char s2[])
{
	register int i=-1;

	do
	{
		i++;
		s1[i]=s2[i];
	} while (s2[i] != END_CHAR);						
return s1;
}


inline char * strcpy(char  s1[], const char s2[])
{						
return strcopy(s1,s2);
}


/*!
The function returns the number of characters in the string s, not including its terminating null character.
*/
/*size_t strlen(const char * s)
{
	register int i=0;

	while (s[i] != END_CHAR)
	{
		i++;
	}
	return i;
}*/



/*!
* read a line of text that ends with <ENTER>; the final '\n' is not added to 
* the result text, but NULL ('\0') caracter is added
* this function is secured, it doesn't accept more than LINE_LENGTH (for exemple :255) characters
*/
char * Sreadline()
{
char car;
int i=0;				//to walk throught "line"
char line[LINE_LENGTH];

car=getkey();
while ((car != '\n') && (i <= MAX_LINE_CHAR))
{
	line[i]=car;
	i++;
	car=getkey();
}
line[i]='\0';
return line;
}



/*!
* read a line of text that ends with <ENTER>; the final '\n' is not added to 
* the result text, but NULL ('\0') caracter is added
* this function is a non secured, it can cause an overflow
*/
char * readline()
{
char car;
int i=0;				//to walk throught "line"
char line[LINE_LENGTH];

car=getkey();
while (car != '\n') 
{
	line[i]=car;
	i++;
	car=getkey();
}
line[i]='\0';
return line;
}
