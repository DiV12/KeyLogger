Malware Implementation - Project Keylogger. 
The keylogger is implemented using the hooking mechanism through Win32 API Microsoft Windows SDK on the RLES virtual environment. The keylogger records all the keyboard events and stores them in a textfile. This textfile is saved at a location which is unknown to the user. 

The source code named 'main.cpp' is present in the 'keylogger_project' folder.

Language used : C++ 

Installation : 
You will need the following tools set-up: 
1) Microsoft Windows SDK - Win32 API for Windows 7 
2) .Net framework 4 
3) Qt SDK
4) Qt C++ editor
5) RLES virtual environment 

6) Hstart

 

For the instructor to execute the code: 
1) Once the required tools are installed, it is very simple to execute this piece of code. 
2) Build the project.
3) Hit the Run button on the editor. 

Malware execution setup in the RLES VMware: 

1) An exe file is generated for the malware code.

2) The exe file runs once the system boots
.
3) The console window of the key logger is made hidden using Hstart.
4) The keylogger executes in the background of any application and the user is not aware of its existence. 


