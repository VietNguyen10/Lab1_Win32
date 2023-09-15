#include <windows.h>
#include <mmsystem.h>
#include "Window1.h"
#include "Window2.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCMLine, int iCmdShow) {
	MSG		msg;//holds any message retrieved from the msg queue

	//---------------------------WND1-----------------------------

	static TCHAR wnd1Name[] = TEXT("wind1");//name of app
	HWND	 hwnd1;//holds handle to the main window
	WNDCLASS wnd1class;//class registration for window #1

	//defn wndclass attributes for this application
	wnd1class.style = CS_HREDRAW | CS_VREDRAW;//redraw on refresh both directions
	wnd1class.lpfnWndProc = Wnd1Proc;//wnd proc to handle windows msgs/commands
	wnd1class.cbClsExtra = 0;//class space for expansion/info carrying
	wnd1class.cbWndExtra = 0;//wnd space for info carrying
	wnd1class.hInstance = hInstance;//application instance handle
	wnd1class.hIcon = LoadIcon(NULL, IDI_APPLICATION);//set icon for window
	wnd1class.hCursor = LoadCursor(NULL, IDC_ARROW);//set cursor for window
	wnd1class.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//set background
	wnd1class.lpszMenuName = NULL;//set menu
	wnd1class.lpszClassName = wnd1Name;//set application name

	//register wndclass to O/S so approp. wnd msg are sent to application
	if (!RegisterClass(&wnd1class)) {
		MessageBox(NULL, TEXT("This program requires Windows 95/98/NT"),
			wnd1Name, MB_ICONERROR);//if unable to be registered
		return 0;
	}

	//create the main window and get it's handle for future reference
	hwnd1 = CreateWindow(wnd1Name,		//window class name
		TEXT("Hello World for Windows"), // window caption
		WS_OVERLAPPEDWINDOW,	//window style
		TOP_WINDOW1_XPOS,		//initial x position
		TOP_WINDOW1_YPOS,		//initial y position
		TOP_WINDOW1_WIDTH,		//initial x size
		TOP_WINDOW1_LENGTH,		//initial y size
		NULL,				//parent window handle
		NULL,				//window menu handle
		hInstance,			//program instance handle
		NULL);				//creation parameters
	ShowWindow(hwnd1, iCmdShow);//set window to be shown
	UpdateWindow(hwnd1);//force an update so window is drawn

	hwnd1 = CreateWindow(wnd1Name,		//window class name
		TEXT("Hello World for Windows"), // window caption
		WS_OVERLAPPEDWINDOW,	//window style
		BOT_WINDOW1_XPOS,		//initial x position
		BOT_WINDOW1_YPOS,		//initial y position
		BOT_WINDOW1_WIDTH,		//initial x size
		BOT_WINDOW1_LENGTH,		//initial y size
		NULL,				//parent window handle
		NULL,				//window menu handle
		hInstance,			//program instance handle
		NULL);				//creation parameters
	ShowWindow(hwnd1, iCmdShow);//set window to be shown
	UpdateWindow(hwnd1);//force an update so window is drawn

	//---------------------------WND2-----------------------------

	static TCHAR wnd2Name[] = TEXT("wind2");//name of app
	HWND	 hwnd2;//holds handle to the main window
	WNDCLASS wnd2class;//class registration for window #2

	//defn wndclass attributes for this application
	wnd2class.style = CS_HREDRAW | CS_VREDRAW;//redraw on refresh both directions
	wnd2class.lpfnWndProc = Wnd2Proc;//wnd proc to handle windows msgs/commands
	wnd2class.cbClsExtra = 0;//class space for expansion/info carrying
	wnd2class.cbWndExtra = 0;//wnd space for info carrying
	wnd2class.hInstance = hInstance;//application instance handle
	wnd2class.hIcon = LoadIcon(NULL, IDI_APPLICATION);//set icon for window
	wnd2class.hCursor = LoadCursor(NULL, IDC_ARROW);//set cursor for window
	wnd2class.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//set background
	wnd2class.lpszMenuName = NULL;//set menu
	wnd2class.lpszClassName = wnd2Name;//set application name

	//register wndclass to O/S so approp. wnd msg are sent to application
	if (!RegisterClass(&wnd2class)) {
		MessageBox(NULL, TEXT("This program requires Windows 95/98/NT"),
			wnd2Name, MB_ICONERROR);//if unable to be registered
		return 0;
	}

	//create the main window and get it's handle for future reference
	hwnd2 = CreateWindow(wnd2Name,		//window class name
		TEXT("Hello World for Windows"), // window caption
		WS_OVERLAPPEDWINDOW,	//window style
		TOP_WINDOW2_XPOS,		//initial x position
		TOP_WINDOW2_YPOS,		//initial y position
		TOP_WINDOW2_WIDTH,		//initial x size
		TOP_WINDOW2_LENGTH,		//initial y size
		NULL,				//parent window handle
		NULL,				//window menu handle
		hInstance,			//program instance handle
		NULL);				//creation parameters
	ShowWindow(hwnd2, iCmdShow);//set window to be shown
	UpdateWindow(hwnd2);//force an update so window is drawn

	hwnd2 = CreateWindow(wnd2Name,		//window class name
		TEXT("Hello World for Windows"), // window caption
		WS_OVERLAPPEDWINDOW,	//window style
		BOT_WINDOW2_XPOS,		//initial x position
		BOT_WINDOW2_YPOS,		//initial y position
		BOT_WINDOW2_WIDTH,		//initial x size
		BOT_WINDOW2_LENGTH,		//initial y size
		NULL,				//parent window handle
		NULL,				//window menu handle
		hInstance,			//program instance handle
		NULL);				//creation parameters
	ShowWindow(hwnd2, iCmdShow);//set window to be shown
	UpdateWindow(hwnd2);//force an update so window is drawn

	//------------------------------------------------------------


	//messgae loop
	while (GetMessage(&msg, NULL, 0, 0) > 0) {//get message from queue
		TranslateMessage(&msg);//for keystroke translation
		DispatchMessage(&msg);//pass msg back to windows for processing
		//note that this is to put windows o/s in control, rather than this app
	}

	return msg.wParam;
}