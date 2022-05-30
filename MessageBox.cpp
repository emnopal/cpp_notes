#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
    MessageBox(NULL, "Test MessageBox", "Test", MB_ICONASTERISK);
    return 0;
}