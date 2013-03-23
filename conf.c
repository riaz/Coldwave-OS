/*   CONF.C -- COLD-WAVE Operating System
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
#include <cons.h>
#include <system.h>
//#include <time.h>
#include <conf.h>

void shellExit(short EXIT_STATUS)
{
	printf("\nyou cannot exit");
}



/*! 
* this function is called when a command is not found
*/
void CmdNotImplemented()
{
	printf("\nBad Command or File Name.");
	listUCTCmd();
}



void listUCTCmd()
{
int i=0;

printf("\nCommands are :");
for (i=0; i<UCT_CMD_NUMBER; i++)
{
	if(i%5 == 0) 	  printf("\n");    	//a new line for each 5 commands
	printf(UCT[i].cmd_name);		//print the command
	printf("\t");
}
printf("\nFor more information read the Documentation");
}


/*!
 print a string on the screen
*/
void echo(char * str)
{
	printf("\n");
	printf(str);
}

void version()
{
	printf("\nCOLD-WAVE v0.1 Beta \n");
}

void about()
{
	printf("\nCOLD-WAVE Operating System\n");
	printf("An Open-Sourced Operating System\n");
	printf("---------------------------------\n");
	printf("Reality-Soft Corporation 2011-12\n");
}



