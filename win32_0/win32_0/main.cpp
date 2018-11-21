#include<Windows.h>
#include"resource.h"



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
				char  ID[128];  //
				char  Password[128];//

				GetWindowText(GetDlgItem(hDlg, IDC_EDIT1), ID, 128);
				GetWindowText(GetDlgItem(hDlg, IDC_EDIT2), Password, 128);
				if (*ID != 0 && *Password != 0) {
					if (Check(ID, Password)) {
						MessageBox(hDlg,"YunOSC{First_Win32!!!!}", "You got it!",MB_OK);
					}
					else {
						MessageBox(hDlg,  "Try again~~", "Failed", MB_OK);
					}
				}
				else {
					MessageBox(hDlg, "Please input , thanks....", "Error", MB_OK);
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
	if (!strcmp(ID, "YunOSC") && !strcmp(Password, "hahahasoqjowfjlasdfjpoqrghasldfjaposdg")) {
		return TRUE;
	}
	return FALSE;
}