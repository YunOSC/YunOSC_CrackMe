
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<Windows.h>

int main() {
	char flag[] = "YunOSC{Welcome to Reverse!}";
	printf("Welcome to Reverse You should crackme!\n");
	int pass;
	scanf("%d", &pass);
	if (pass == 30678) {
		printf("%s\n", flag);
	}
	else {
		printf("Hang in here~~~");
	}
	system("PAUSE");
	

}