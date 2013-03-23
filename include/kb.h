#ifndef _KB_H
#define _KB_H



#define SPECIAL 0x00
#define ESCAPE  0x01
#define BKSPACE '\b'
#define TAB	'\t'
#define ENTER  '\n'
#define CTRL	0x00
#define LSHIFT  0x2A
#define RSHIFT  0x36
#define PRNTSCR 0x00
#define ALT     0x00
#define CAPS	0x00
#define F1	0x00
#define F2	0x00
#define F3	0x00 
#define F4	0x00
#define F5	0x00
#define F6	0x00
#define F7	0x00
#define F8	0x00
#define F9	0x00
#define F10	0x00
#define NUM     0x00
#define SCRL    0x00
#define F11	0x00
#define F12	0x00

extern char * Hexconvert(int val);
extern void KbHandler();




#endif