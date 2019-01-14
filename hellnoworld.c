//#pragma comment(linker, "/subsystem:windows")
//Pre-processor directives
#include <stdbool.h>
#include <windows.h>
//Windows Procedure Event Handler
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    PAINTSTRUCT paintStruct;
    //Device context
    HDC hDC;
    //Text for display
    char string[] = "Hell no, world!";
    char string2[] = "Second String, display random stuff but in text";
    //Switch message, condition that is met will execute
    switch (message) {
        //Window is being created
        case WM_CREATE:
            return 0;
            break;
        //Window is closing
        case WM_CLOSE:
            PostQuitMessage(0);
            return(0);
            break;
        //Window needs update
        case WM_PAINT:
            hDC = BeginPaint(hwnd, &paintStruct);
            //Set text color to blue
            SetTextColor(hDC, RGB(0, 0, 255));
            TextOut(hDC, 150, 150, string, sizeof(string) - 1);
            //Display text in middle of window
            TextOut(hDC, 10, 10, string2, sizeof(string2) - 1);
            EndPaint(hDC, &paintStruct);
            return(0);
            break;
        default:
            break;
    }
    return (DefWindowProc(hwnd, message, wParam, lParam));
}


//Main function
int APIENTRY WinMain(HINSTANCE  hInstance,
                    HINSTANCE   hPrevInstance,
                    LPSTR       lpCmdLine,
                    int         nCmdShow) {
    WNDCLASSEX windowClass; //window class
    HWND hwnd; //window handle
    MSG msg; //message
    bool done; //flag saying when app is complete
    //Fill out the window class structure
    windowClass.cbSize = sizeof(WNDCLASSEX);
    windowClass.style = CS_HREDRAW | CS_VREDRAW;
    windowClass.lpfnWndProc = WndProc;
    windowClass.cbClsExtra = 0;
    windowClass.cbWndExtra = 0;
    windowClass.hInstance = hInstance;
    windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    windowClass.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
    windowClass.lpszMenuName = NULL;
    windowClass.lpszClassName = "MyClass";
    windowClass.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
    //Register window class
    if(!RegisterClassEx(&windowClass)) return 0;
    //Class registered, so now create window
    hwnd = CreateWindowEx(NULL, //extended style
                    "MyClass", //class name
                    "A Real Windows application", //app name
                    WS_OVERLAPPEDWINDOW | //window style
                    WS_VISIBLE |
                    WS_SYSMENU,
                    100, 100, //x/y coords
                    400, 400, //width, height
                    NULL, //handle to parent
                    NULL, //handle to menu
                    hInstance, //application instance
                    NULL); //no extra params
    //Check if window creation failed
    if(!hwnd) return 0;
    //Initialize loop condition variable
    done = false;
    //Main message loop
    while(!done) {
        PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE);
        if(msg.message == WM_QUIT) done = true; //if message is to quit - then quit app
        else {
            //Translate and dispatch to event queue
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return msg.wParam;
}
