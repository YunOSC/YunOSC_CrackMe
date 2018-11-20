#include<stdio.h>
#include<Windows.h>

int main() {
	char flag[] = "YunOSC{Hello Reverse!}";
	int i = 300;
	while (i>0) {
		
		printf("Flag appears after %d seconds", i);
		Sleep(1000);
		system("cls");
		i--;
	}
	
	printf("HAHAHAHAHAHAHA Just Kidding~");
	system("PAUSE");
}