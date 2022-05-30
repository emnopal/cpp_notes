#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow){
        MessageBox(NULL, "Hi!", "Welcome to C++", MB_RETRYCANCEL);
        return 0;
    }

