#include <windows.h>
#include <mmsystem.h>

struct
{
	int ncount;
	TCHAR* msg;
}Window2;

LRESULT CALLBACK Wnd2Proc(HWND hwnd2, UINT message, WPARAM wParam, LPARAM lParam) {
	HDC		hdc;
	PAINTSTRUCT ps;
	RECT	rect;

	switch (message) {
	case WM_CREATE://additional things to do when window is created
		PlaySound(TEXT("hellowin.wav"), NULL, SND_FILENAME | SND_ASYNC);
		return 0;

	case WM_PAINT://what to do when a paint msg occurs
		hdc = BeginPaint(hwnd2, &ps);//get a handle to a device context for drawing
		GetClientRect(hwnd2, &rect);//define drawing area for clipping

		DrawText(hdc, TEXT("This is wndow2"), -1, &rect,
			DT_SINGLELINE | DT_CENTER | DT_VCENTER);//write text to the context

		EndPaint(hwnd2, &ps);//release the device context
		return 0;

	case WM_DESTROY://how to handle a destroy (close window app) msg
		PostQuitMessage(0);
		return 0;
	}
	//return the message to windows for further processing
	return DefWindowProc(hwnd2, message, wParam, lParam);
}