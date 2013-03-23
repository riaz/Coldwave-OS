/*   CONS.C -- COLD-WAVE Operating System
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

#include <conf.h>//functions that are called by the shell command
#include <cons.h>
#include <types.h>
#include <system.h>
#include <time.h>
#include <str.h>




/*! 
* initialize the UCT (user command table), be sure that all the commands in the UCT table are sorted by alphabetic order.
*/
void initUCT()
{
struct cmd_struct cmd;				//command to insert
uint8_t cmdNum=0;					//command number in the UCT

strcopy(cmd.cmd_name,"about");
cmd.cmd_void_adress =about;
cmd.privilege= 1;
cmd.priority=0;
UCT[cmdNum]=cmd;
cmdNum++;


strcopy(cmd.cmd_name,"clear");
cmd.cmd_void_adress = cls; //cmd not yet implemented
cmd.privilege= 1;	
cmd.priority=0;
UCT[cmdNum]=cmd;
cmdNum++;

strcopy(cmd.cmd_name,"date");
cmd.cmd_void_adress = date;
cmd.privilege= 1;	
cmd.priority=0;
UCT[cmdNum]=cmd;
cmdNum++;

strcopy(cmd.cmd_name,"day");
cmd.cmd_void_adress = dayOfWeek; 
cmd.privilege= 1;	
cmd.priority=0;
UCT[cmdNum]=cmd;
cmdNum++;



strcopy(cmd.cmd_name,"echo");	
cmd.cmd_void_adress = echo;
cmd.privilege= 1;
cmd.priority=0;
UCT[cmdNum]=cmd;				//insert the first command to the UCY
cmdNum++;

strcopy(cmd.cmd_name,"exit");	
cmd.cmd_void_adress = shellExit;
cmd.privilege= 1;	
cmd.priority=0;
UCT[cmdNum]=cmd;
cmdNum++;

strcopy(cmd.cmd_name,"help");
cmd.cmd_void_adress = listUCTCmd;
cmd.privilege= 1;
cmd.priority=0;
UCT[cmdNum]=cmd;
cmdNum++;

strcopy(cmd.cmd_name,"time");
cmd.cmd_void_adress = sys_time ; 
cmd.privilege= 1;	
cmd.priority=0;
UCT[cmdNum]=cmd;
cmdNum++;


strcopy(cmd.cmd_name,"version");
cmd.cmd_void_adress =version;
cmd.privilege= 1;
cmd.priority=0;
UCT[cmdNum]=cmd;
cmdNum++;



}



/*!
* execUctCmd : search for the command in the UCT and then executes it by calling the function
* that performs the command action; for exemple with the command help we call the function 
* listCmd() witch will list all the commands
*/
void execUCTCmd(char * cmd, char * parameters)
{
//quick search  (recherche dichotomique)
int infBorn=0, supBorn=UCT_CMD_NUMBER, midle=0;

while (infBorn <= supBorn)
{
	midle = (infBorn+supBorn)/2;
	if( strcmp(cmd , UCT[midle].cmd_name) < 0)    supBorn=midle-1;
	else if(strcmp(cmd , UCT[midle].cmd_name) > 0)  infBorn=midle+1;
	     else
	     { 	
	     	// call the function that executes the command
		( *(UCT[midle].cmd_void_adress) )    (parameters);	    
	     	break;
	     }	
}
if((infBorn > supBorn) || (supBorn < 0))  //cmd not found
		CmdNotImplemented(); 
}



/*!
* jump all spaces befor the word and returns the beginning of the string  line
*/
 int nextWord(char * line, int frrom)
{
int nN;

nN=frrom;
while (line[nN]==' ')  nN++;
return nN;
}



/*!
* return the first word from the line with ends with '\n' <enter>,
* for exemple : returns    "word1"  from the line "word1 is extracted by getFirstWord()"
* words are delimited by   SPACE
* line : the full line from where you want to extract the firstWord and the otherWords
* firstWord : the first word to extract from the line
* otherWords : the rest of the words
*/
char * getFirstWord(char * line, char * firstWord,char * otherWords)
{
int i=0;				//used to read  line
int j=0;				//used to write in firstWord
char * tempOtherWords;

i=nextWord(line,i);			//go forword until the first word begins
while (line[i] != '\0'  &&  line[i] != ' ')			//extract the first word witch ends with SPACE
{	
	firstWord[j]=line[i];
	i++;
	j++;
}
firstWord[j]='\0';			//add the final caracter to the firstWord
//exeption : if the first word has exactly 255 caracters so the final caracter '\0' will not
//have a place in the firstWord
tempOtherWords=line + i;
strcopy(otherWords,tempOtherWords);//extract the rest of the line

return firstWord;
}



/*!
 the main console, it needs more security
 */
int LoadConsole()
{
char  parameters[LINE_LENGTH];
char  cmd[LINE_LENGTH];
char  line[LINE_LENGTH];

initUCT();				//initialize the UCT	
listUCTCmd();			

do {
	settextcolor(LIGHT_GREY,BLACK);  
	printf("\nwave>"); 
	settextcolor(MAGENTA,BLACK);
	scan(line);		
	getFirstWord(line,cmd,parameters);	
	execUCTCmd(cmd,parameters);
   }while (1);	
return 0;
}
