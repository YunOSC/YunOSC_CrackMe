#include<Windows.h>
#include"resource.h"

char  ID[128];  //
char  Password[128];//

BOOL Check(char *, char *);

INT_PTR CALLBACK MainDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	BOOL bRet = TRUE;
	switch (uMsg) {
		case WM_CLOSE:
			EndDialog(hDlg, 0);
			break;
		case WM_COMMAND:
			if (LOWORD(wParam) == IDC_BUTTON1 && HIWORD(wParam) == BN_CLICKED)
			{
				GetWindowText(GetDlgItem(hDlg, IDC_EDIT1), ID, 128);
				GetWindowText(GetDlgItem(hDlg, IDC_EDIT2), Password, 128);
				if (*ID != 0 && *Password != 0) {
					if (Check(ID, Password)) {
						MessageBox(hDlg,"You got it!", "HAHAHAHYou got it!",MB_OK);
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

BOOL Check(char *ID, char *Password) {
	return TRUE;
}