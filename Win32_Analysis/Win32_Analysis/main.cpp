#include <Windows.h>

HINSTANCE hinst;
//���f�y��
HWND hwnd;
LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLime, int nCmdShow) {

	//�w�q���f���O
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

	//���U���f
	if (!RegisterClassEx(&wcx)) {
		return 1;
	}
	//�ϥε��f���Ыص��f
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


	//�Ыص��f
	if (!hwnd) {
		return 1;
	}
	//��ܵ��f
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	//�����`��
	while ((fGOtMessage = GetMessage(&msg, (HWND)NULL, 0, 0)) != 0) {
		//��e����
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

//���f�L�{��� ,�B�z����
LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
		//�������f �h�X�D�u�{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}