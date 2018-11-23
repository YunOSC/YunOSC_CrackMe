#include<Windows.h>
#include"resource.h"




//AD
BOOL CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	RECT       rcDialog;
	HBITMAP    hBitmap;
	static BITMAP s_bm;
	static HDC    s_hdcMem;

	switch (message)
	{
	case WM_INITDIALOG:
		
		

		
		hBitmap = (HBITMAP)LoadImage(NULL, "AD.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		if (hBitmap == NULL)
		{
			MessageBox(hDlg, "LoadImage failed", "Error", MB_ICONERROR);
			exit(0);
		}
		else
		{
		
			HDC        hdc;
			hdc = GetDC(hDlg);
			s_hdcMem = CreateCompatibleDC(hdc);
			SelectObject(s_hdcMem, hBitmap);
			ReleaseDC(hDlg, hdc);

		
			GetObject(hBitmap, sizeof(s_bm), &s_bm);
		}

		return 0;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDC_BUTTON2 && HIWORD(wParam) == BN_CLICKED)
		{
			EndDialog(hDlg, 0);
			break;
		}
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			DeleteDC(s_hdcMem);
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;


	case WM_SIZE:
		InvalidateRect(hDlg, NULL, TRUE);
		return TRUE;

	case WM_CTLCOLORDLG:
		GetClientRect(hDlg, &rcDialog);
		
		SetStretchBltMode((HDC)wParam, COLORONCOLOR);
		StretchBlt((HDC)wParam, 0, 0, rcDialog.right, rcDialog.bottom, s_hdcMem, 0, 0, s_bm.bmWidth, s_bm.bmHeight, SRCCOPY);
		return (BOOL)((HBRUSH)GetStockObject(NULL_BRUSH));
	}
	return FALSE;
}

INT_PTR CALLBACK MainDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	BOOL bRet = TRUE;
	switch (uMsg) {
	case WM_CLOSE:
		EndDialog(hDlg, 0);
		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDC_BUTTON1 && HIWORD(wParam) == BN_CLICKED)
		{
			MessageBox(hDlg, "Welcome", "~~~~~", MB_OK);
		}
		break;
	
	default:
		bRet = FALSE;

	}
	return bRet;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow) {
	
	
	//DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG2), NULL, DlgProc);
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG2), NULL, DlgProc);
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, MainDlgProc);
	
	
}


