[1]  GREETING
------------------------------------------------------------------------------------------
Thanks, for reading COLD-WAVE v0.1 readme.

Please read this document carefully prior to using any file  in this operating system Bundle.
COLD-Wave is protected under the GNU GPLv3 License, and is an open-source OS  for students 
currently enrolled in academic programs, to gain practical exposure to OS Development or 
for Researchers/Scientists who ar involving in testing features of specific hardware or software.


[2]  WARNING
-----------------------------------------------------------------------------------------
This Operaring System doesn't take any responsibility for the damage caused for using
this operating system.However, you are free to  test and run the operating system but 
at your own risk (read Documentation for possible risks).



[3]  TESTING
--------------------------------------------------------------------------------------------
This sections,give the instruction to test this OS in your local system.Please note, that the 
operating system is tested Ok,to run on 32-bit Intel x86 set of CPUs,and must work well on
any PC with the same,but this doesn't guarantee any possible risks in the program.

You can test the OS either in the local machine by  installing in a seperate primary partition,
or one may make use of a virtual-machine, to simulate the desired platform.

The virtual-machine alternative,suits better since it minimizes the risk of damaging a real-system.
The possible sets of virtual-machines that one may use are-

1)Bochs  --recommended
2)Microsoft Virtual PC
3)Oracle VirtualBox
4)VM Ware
5)Qemu etc.

1)Testing in local-system
-------------------------------
1.Burn the cold-wave.iso/cold-wave.img file, into a  disk/floppy and   restart the system.
2.Please set the boot order as -boot from CD , to boot from the CD that contains COLD-WAVE.
3.You can see a grub loader screen, showing the menu, select  COLD WAVE OS , and press enter key.
4.Finally, you have the OS  loaded, and have fun with the command-line that the OS provides.

2)Testing using Virtual Machine  [Bochs]
----------------------------------------
1.Install the Bochs virtual-machine emulator from the dev_tools folder in the bundle.
2.Run the file cold_wave.bxrc in the bundle,to test the OS in bochs.


[4] DEVELOPMENT
-------------------------------------------------------------------------------------
Please read the developers documentation, to start development using this OS.

