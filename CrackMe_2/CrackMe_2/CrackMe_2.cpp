#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<Windows.h>
#include <time.h>
#include <process.h>
#include<string>

#define palength 33
#define flaglength 27
using namespace std;
char pass[palength];
char input[palength];

char flag[] = "XtoNRBzq`ubi^rmddddddddq |";

int nSec = 2;
void decrypt();

DWORD WINAPI TimeCount(LPVOID lpParam)
{
	while (nSec > 0)
	{
		--nSec;
		Sleep(1000);
	}
	printf("Time Over!\n");
	Sleep(1500);
	exit(1);

}
int main() {
	//printf("%s", flag);
	srand(time(NULL));
	HANDLE hThread;
	DWORD dwThreadID;
	
	int i ;
	for (i = 0; i < palength-1; ++i) {
		int x= rand() % 10+'0' ;
		
		pass[i] = x;
		
	}
	pass[i] = '\0';
	hThread = ::CreateThread(NULL, NULL, TimeCount, NULL, 0, &dwThreadID);
	
	printf("Please input this number %s in 2 seconds ! \n", pass);
	scanf("%s", input);
	if (!strcmp(input, pass)) {
		printf("suceess!\n");
		decrypt();

	}
	else {
		printf("input failed!\n");
	}
	//::CloseHandle(hThread);
	Sleep(3000);
	system("PAUSE");

}
void decrypt( ) {
	char *c;
	int i = 0;
	for (i = 0; i < flaglength; ++i) {
		flag[i] = flag[i] ^ 1;
	}
	puts(flag);

}