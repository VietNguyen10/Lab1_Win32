#include <windows.h>
#include <cstdio>
#include <mmsystem.h>
#include "Window1.h"
#include <iostream>

LRESULT CALLBACK Wnd1Proc(HWND hwnd1, UINT message, WPARAM wParam, LPARAM lParam) {
	HDC		hdc;
	RECT	rect;
	PAINTSTRUCT ps;
	Window1* pCDATA;

	switch (message) {
	case WM_CREATE://additional things to do when window is created
		PlaySound(TEXT("hellowin.wav"), NULL, SND_FILENAME | SND_ASYNC);
		
		//Check if lParam is not null and store the pointer in clsextra
		if (lParam != NULL) {
			CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam;
			Window1* pState = (Window1*)(pCreate->lpCreateParams);
			SetClassLongPtr(hwnd1, GCL_CBCLSEXTRA, (LONG_PTR)pState);
		}

		//Increment ncount by 1 each time a window is created
		pCDATA = (Window1*)GetClassLongPtr(hwnd1, GCL_CBCLSEXTRA);
		if (pCDATA != NULL) {
			pCDATA->ncount+=1;
			std::cout<< pCDATA->ncount<<std::endl;
		}

		return 0;

	case WM_PAINT://what to do when a paint msg occurs
		hdc = BeginPaint(hwnd1, &ps);//get a handle to a device context for drawing
		GetClientRect(hwnd1, &rect);//define drawing area for clipping

		DrawText(hdc, TEXT("Hello Windows"), -1, &rect,
			DT_SINGLELINE | DT_CENTER | DT_VCENTER);//write text to the context

		EndPaint(hwnd1, &ps);//release the device context
		return 0;

	case WM_DESTROY://how to handle a destroy (close window app) msg
		//pCDATA->ncount -= 1;
		//if(pCDATA->ncount == 0) {
			PostQuitMessage(0);
			return 0;
		//}
	}
	//return the message to windows for further processing
	return DefWindowProc(hwnd1, message, wParam, lParam);
}