#include <windows.h>
#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    POINT p;
    cout << "Move your mouse. Left-click to print coordinates.\nPress any key in the terminal to stop.\n" << endl;

    SHORT prevLeftButton = 0;
    int n=1;
    while (!_kbhit()) {
        if (GetCursorPos(&p)) {
            cout << "X,Y = " << p.x << "," << p.y << "     \r"; // overwrite line

            // Detect left mouse button click
            SHORT currLeftButton = GetAsyncKeyState(VK_LBUTTON);
            if ((currLeftButton & 0x8000) && !(prevLeftButton & 0x8000)) {
                cout <<"\n"<<n<< ". Mouse clicked at (X,Y) = "<<p.x <<","<< p.y<<"\n";
                n++;
            }
            prevLeftButton = currLeftButton;
        }
        Sleep(100); // update every 100ms
    }

    cout << "\nStopped.";
    return 0;
}
