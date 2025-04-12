#include <windows.h>
#include <stdio.h>


/*
 * Add a shortcut key to run this program(.exe file) easily:

 * Right click on the executable file, drag and release at desktop.
 * Choose option to create a desktop shortcut.
 * Then right click on the shortcut and select properties.
 * In the shortcut tab, you can set a shortcut key combination.
 * For example, Ctrl + Alt + K.
 * This will allow you to run the program using the shortcut key
 * 
 * Note:
 * ---- Ensure that the shortcut does not conflict with
 *      existing system  or application shortcuts.
 * ---- On Windows, you may use APIs like `RegisterHotKey` 
 *      to register global shortcuts.
*/

void ClickAt(int x, int y) {
    // Move cursor
    SetCursorPos(x, y);
    Sleep(400);  // Ensure pointer arrives

    // Create INPUT structure for mouse down
    INPUT input = {0};
    input.type = INPUT_MOUSE;
    input.mi.dx = (LONG)(x * (65536.0 / GetSystemMetrics(SM_CXSCREEN)));
    input.mi.dy = (LONG)(y * (65536.0 / GetSystemMetrics(SM_CYSCREEN)));
    input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
    SendInput(1, &input, sizeof(INPUT));

    Sleep(400); // Small delay to ensure the mouse has "arrived"

    // Simulate left-click
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));

    Sleep(500); // Ensure click registers
}

int main() {
    Sleep(100);

    // Click keyboard icon
    //Adjust the coordinates based on your screen resolution and layout
    ClickAt(1197, 753);
    Sleep(500); // Wait for keyboard to open
    
    // Click mic icon
    //Adjust the coordinates based on your screen resolution and layout
    ClickAt(1130, 19);

    printf("Clicked keyboard and mic.\n");
    return 0;
}
