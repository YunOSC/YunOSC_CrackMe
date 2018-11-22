#include"resource.h"
#include<Windows.h>
INT_PTR CALLBACK MainDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL Check(char *);
void Encrypt(char *);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow) {
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, MainDlgProc);
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
			char  Str[128];  //
			

			GetWindowText(GetDlgItem(hDlg, IDC_EDIT1), Str, 128);
			Encrypt(Str);
			
			if (*Str != 0 ) {
				if (Check(Str)) {
					MessageBox(hDlg, "Congratulations~", "Success", MB_OK);
				}
				else {
					MessageBox(hDlg, "Try again~~", "Failed", MB_OK);
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
void Encrypt(char *Str) {
	for (int i = 0; i < strlen(Str); ++i) {
		Str[i] ^= 1;
	}
}
BOOL Check(char *Str) {
	char  flag[] = "XtoNRBz^yns^dobsxqu|";
	if (!strcmp(Str, flag)) {
		return TRUE;
	}
	return FALSE;
}

