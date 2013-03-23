#ifndef _IO_H
#define _IO_H


struct iobuff
{
   char Buff[8];
   int ptr;
   int in;
}kbbuff;



void add(char c)
{
	if(kbbuff.in<8)
	{
		kbbuff.Buff[(kbbuff.ptr+kbbuff.in)%8]=c;
		kbbuff.in++;
	}		
}



char getkey(void)
{
	char c;
	if(kbbuff.in>0)
	{
		c= kbbuff.Buff[kbbuff.ptr];
		kbbuff.in--;
		kbbuff.ptr=(kbbuff.ptr+1)%8;
		return c;
	}
	else
	{
		return 0x0;
	}
}



void scan(char * cmd)
{
	
	char t[2]={0,0};
	int i=0;
	
	t[0]=getkey();	
	while(t[0]!='\n')
	{
		if(t[0]!=0x0)
		{
			if(t!='\b')
			{
			 cmd[i]=t[0];
			 i++;
			}
			else i--;
			if(i<255)printf(t);
		}
		t[0]=getkey();
	}
	if(i<255)cmd[i]=0x0;
	else cmd[255]=0x0;
	printf('\n');
}

#endif