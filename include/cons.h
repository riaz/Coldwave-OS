#ifndef CONSOLE_H
#define CONSOLE_H

#define UCT_CMD_NUMBER 9			//the number of UCT commands
						//UCT= (user commands table)
#define SCT_CMD_NUMBER 10			//SCT = system commands table
						//(root commands)
#define PARAMETER_LENGTH 25			//length of command parameters
#define CMD_LENGTH 10				//length of the command itself


 
/*!
 standard command structure : the command name, the function called by the command , the privilidge of this command (0:root, 1:user), priority : defines how much the command is important (this will be used by the memory manager)
*/
struct cmd_struct
{
	char  cmd_name[10];				//reserve 10 characters for the name
	void (* cmd_void_adress)();			//function to call
	unsigned  privilege :1;				// who can use this cmd, 0:root, 1:user
	unsigned  priority  :3;				//the priority is a defined int
	/*to specify how the cmd will be stored (memory,compressed in memory,writen to disk)
	0: for hight priority,i.e it's used frequently ,so it will be stored in memory	
	1: the cmd isn't frequantly used, so it'll be compressed and stored in memory
	2: cmd rarly used will be stored in disk */
};

struct cmd_struct UCT[UCT_CMD_NUMBER];		//user commands table
struct cmd_struct SCT[SCT_CMD_NUMBER];		//system commands table



// functions list   (functions prototypes)
extern void initUCT();
extern void execUCTCmd(char * cmd, char * parameters);
extern void listUCTCmd();
extern void CmdNotImplemented();
extern char * readline();
extern int LoadConsole();

#endif
