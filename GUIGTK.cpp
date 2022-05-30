#include <windows.h>
#define IDB_BUT 1001

LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst, LPSTR Args, int WinMode){
     WNDCLASSEX WinClass = {0};
     WinClass.cbSize = sizeof(WNDCLASSEX);
     WinClass.hInstance = hThisInst;
     WinClass.lpszClassName = "BUTEXP";
     WinClass.lpfnWndProc = WindowFunc;
     WinClass.style = 0;
     WinClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
     WinClass.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
     WinClass.hCursor = LoadCursor(NULL, IDC_ARROW);
     WinClass.lpszMenuName = NULL;
     WinClass.cbClsExtra = 0;
     WinClass.cbWndExtra = 0;
     WinClass.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);

     if (!RegisterClassEx(&WinClass)){
          MessageBox(NULL, "Cannot register class", "Windows error", MB_OK);
          return 1;
     }

     HWND hWnd;

     if (!(hWnd = CreateWindow("BUTEXP", "Button Example", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 500, 400, NULL, NULL, hThisInst, NULL))){
          MessageBox(NULL, "Cannot create main window", "Windows error", MB_OK);
          return 2;
     }

     ShowWindow(hWnd, WinMode);
     UpdateWindow(hWnd);

     MSG Message;

     while (GetMessage(&Message, NULL, 0, 0) > 0){
          TranslateMessage(&Message);
          DispatchMessage(&Message);
     }

     return Message.wParam;
}

LRESULT CALLBACK WindowFunc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam){
     switch (Message){
     case WM_CREATE:
          CreateWindow("button", "Press Me!", WS_VISIBLE | WS_CHILD, 20, 100, 120, 30, hWnd, (HMENU)IDB_BUT, NULL, NULL);
          break;

     case WM_COMMAND:
          switch (HIWORD(wParam)){
          case BN_CLICKED:
               MessageBox(NULL, "Button pressed", "Windows", MB_OK);
               break;

          default:
               break;
          }
          break;

     case WM_PAINT:
     {
          PAINTSTRUCT ps;
          BeginPaint(hWnd, &ps);
          EndPaint(hWnd, &ps);
     }
     break;

     case WM_DESTROY:
          PostQuitMessage(0);
          break;

     default:
          return DefWindowProc(hWnd, Message, wParam, lParam);
     }
     return 0;
}