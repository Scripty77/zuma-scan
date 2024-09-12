#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    while(true) {
        LPCWSTR windows_title = L"Zuma Deluxe 1.0";
        HWND hWND = FindWindowW(NULL, windows_title);

        while (hWND == NULL) {
            hWND = FindWindowW(NULL, windows_title);
            if (hWND == NULL) {
                cout << "Looking for game window...\n";
                Sleep(1000); 
            }
        }

        Sleep(10);
        
        if (GetAsyncKeyState(VK_F1) & 0x8000) { 
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(hWND, &p);
            cout << "x position: " << p.x << " | y position: " << p.y << "\n";
            Sleep(1000); 
        }
        
        if (GetAsyncKeyState(VK_F2) & 0x8000) { 
            cout << "F2 pressed\n";
            HDC hdc = GetDC(hWND);
			POINT p;
			GetCursorPos(&p);
			ScreenToClient(hWND, &p);
			COLORREF color = GetPixel(hdc, p.x, p.y);
			ReleaseDC(hWND,hdc);
			cout << "Color: " << color; 
			cout << " Red : " << (int)GetRValue(color) 
				 << "| Green: " << (int)GetGValue(color) 
				 << "| Blue: " << (int)GetGValue(color); 
			Sleep(1000); 
        }
        
        if (GetAsyncKeyState(VK_F3) & 0x8000) {  
            cout << "F3 pressed\n";
            Sleep(1000); 
        }
        
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { 
            return 0; // Exit the program
        }
    }

    return 0;
}
