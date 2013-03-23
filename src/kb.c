/*  KB.C -- COLD-WAVE Operating System
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
#include <system.h>
#include <io.h>
#include <kb.h>

int up=0;//Indicates wheter the Shift key is Down(1) or Up(0)


char charTable[]={SPECIAL,ESCAPE,'1','2','3','4','5','6','7','8','9','0','-','=',BKSPACE, 
TAB,'q','w','e','r','t','y','u','i','o','p','[',']',ENTER,CTRL,
'a','s','d','f','g','h','j','k','l',';','\'',' ',LSHIFT,
'\\','z','x','c','v','b','n','m',',','.','/',RSHIFT,PRNTSCR,ALT,
' ',CAPS,F1,F2,F3,F4,F5,F6,F7,F8,F9,F10,NUM,SCRL,F11,F12,SPECIAL,
SPECIAL,SPECIAL 
};


char ShiftcharTable[]={SPECIAL, ESCAPE,'!','@','#','$','%','^','&','*','(',')','_','+',BKSPACE, 
TAB, 'Q','W','E','R','T','Y','U','I','O','P','{','}',ENTER,CTRL,
'A','S','D','F','G','H','J','K','L','M','"',LSHIFT,'|',
'>','W','X','C','V','B','N',':','<','>','?',RSHIFT,PRNTSCR,ALT,
' ',CAPS,F1,F2,F3,F4,F5,F6,F7,F8,F9,F10,NUM,SCRL,F11,F12,SPECIAL,
SPECIAL,SPECIAL,    
};

char non_printable[22]={SPECIAL,ESCAPE,CTRL,PRNTSCR,ALT,
CAPS,F1,F2,F3,F4,F5,F6,F7,F8,F9,F10,NUM,SCRL,F11,F12};

/*!
 Converts an integer value to a Hex repesentation
 used in general for debugging purpose
*/

char * Hexconvert(int val)
{
  char tab[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
  char v[5]={0x30,0x30,0x30,0x30,0x0};
  int cpt=0;
  
  do
  {
	  v[cpt]=tab[val%16];
	  cpt--;
	  val =val /16;
  }while(val !=0 & cpt >=0);
  return v;
}


/* Handles the keyboard interrupt */
void keyboard_handler(struct regs *r)
{
    char key;
	unsigned char cmd; 
	char ascii;
	int i;  
	key =inportb(0x60);//read the pressed key

	if(key<sizeof(charTable))//If key down
	{
		//if shift
		if((key==LSHIFT)|| (key==RSHIFT)) up=1;
		else
		{
			if(up)ascii=ShiftcharTable[key];
			else ascii=charTable[key];
			//check if it's a printable character
			int i=1,j;
			for(j=0;j<sizeof(non_printable);j++)
				if(ascii==non_printable[j]){
					i=0;
					break;
				};
				
			if(i)//If printable add to the keybord buffer
			{  
				add(ascii);
			}
		}
	}
	else
	{
		i=(int)key;
		i &=0x000000FF;//Make sur that convertion is all right
		//Check if the shift key is released
		if((i==RSHIFT+0x80)||(i==LSHIFT+0x80)) up=0;
	}
	

	cmd=inportb(0x61);
	outportb(0x61,cmd | 0x80);  //Deactivate the keybord
	outportb(0x61,cmd); //Restore the previous state
	outportb(0xA0,0x20);//EOI(End Of Interupt) to the Slave
	outportb(0x20,0x20);//EOI to the master

}

/* Installs the keyboard handler into IRQ1 */
void keyboard_install()
{
    irq_install_handler(1, keyboard_handler);
}
