#include <Windows.h>

HINSTANCE hinst;
//窗口句炳
HWND hwnd;
LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLime, int nCmdShow) {

	//定義窗口類別
	WNDCLASSEX wcx;

	MSG msg;
	BOOL fGOtMessage;
	wcx.cbSize = sizeof(wcx);
	wcx.style = CS_HREDRAW | CS_VREDRAW;
	wcx.lpfnWndProc = MainWndProc;
	wcx.cbClsExtra = 0;
	wcx.cbWndExtra = 0;
	wcx.hInstance = hinstance;
	wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcx.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcx.lpszMenuName = NULL;

	wcx.lpszClassName = "MainWClass";
	wcx.hIconSm = (HICON)LoadImage(hinstance, MAKEINTRESOURCE(5),
		IMAGE_ICON,
		GetSystemMetrics(SM_CXSMICON),
		GetSystemMetrics(SM_CYSMICON),
		LR_DEFAULTCOLOR
	);

	//註冊窗口
	if (!RegisterClassEx(&wcx)) {
		return 1;
	}
	//使用窗口類創建窗口
	/*hwnd = CreateWindow(wcx.lpszClassName,
		"CrackMe_3",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		(HWND)NULL,
		(HMENU)NULL,
		hinstance,
		(LPVOID)NULL);*/

	hwnd = CreateWindow(wcx.lpszClassName,
		"Win32_Analysis",
		WS_OVERLAPPEDWINDOW,
		800,
		500,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		(HWND)NULL,
		(HMENU)NULL,
		hinstance,
		(LPVOID)NULL);


	//創建窗口
	if (!hwnd) {
		return 1;
	}
	//顯示窗口
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	//消息循環
	while ((fGOtMessage = GetMessage(&msg, (HWND)NULL, 0, 0)) != 0) {
		//轉送消息
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

//窗口過程函數 ,處理消息
LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
		//關閉窗口 退出主線程
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}