#pragma once
#include <windows.h>

// Top window size and position
#define TOP_WINDOW1_XPOS 100
#define TOP_WINDOW1_YPOS 100
#define TOP_WINDOW1_WIDTH 400
#define TOP_WINDOW1_LENGTH 200

//Bottom window size and position
#define BOT_WINDOW1_XPOS 100
#define BOT_WINDOW1_YPOS 320
#define BOT_WINDOW1_WIDTH 400
#define BOT_WINDOW1_LENGTH 200

//Struct
struct Window1 {
  int ncount = 0;
  TCHAR* msg;
};


LRESULT CALLBACK Wnd1Proc(HWND, UINT, WPARAM, LPARAM);