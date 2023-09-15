#pragma once
#include <windows.h>

#define TOP_WINDOW2_XPOS (GetSystemMetrics(SM_CXSCREEN)-500)
#define TOP_WINDOW2_YPOS 100
#define TOP_WINDOW2_WIDTH 400
#define TOP_WINDOW2_LENGTH 200

//Bottom window size and position
#define BOT_WINDOW2_XPOS (GetSystemMetrics(SM_CXSCREEN)-500)
#define BOT_WINDOW2_YPOS 320
#define BOT_WINDOW2_WIDTH 400
#define BOT_WINDOW2_LENGTH 200

//Struct
struct {
	int ncount;
	TCHAR* msg;
}Window2;

LRESULT CALLBACK Wnd2Proc(HWND, UINT, WPARAM, LPARAM);
