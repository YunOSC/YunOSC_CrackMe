#include<Windows.h>
#include"resource.h"

char  Input[128];  //


BOOL Check(char *);

INT_PTR CALLBACK MainDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	BOOL bRet = TRUE;
	switch (uMsg) {
	case WM_CLOSE:
		EndDialog(hDlg, 0);
		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDC_BUTTON1 && HIWORD(wParam) == BN_CLICKED)
		{
			GetWindowText(GetDlgItem(hDlg, IDC_EDIT1), Input, 128);
			
			if (*Input != 0 ) {
				if (Check(Input)) {
					MessageBox(hDlg, "You got it!", "HAHAHAHYou got it!", MB_OK);
				}
			}
		}
		break;

	default:
		bRet = FALSE;

	}
	return bRet;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow) {
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, MainDlgProc);
}

BOOL Check(char* Input) {
	return TRUE;
}