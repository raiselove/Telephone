#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Tele_book.h"
int main()
{
	Tele ptele;
	int input = 1;
	initiate(&ptele);
	system("color b");
	while (input)
	{
		menu();
		printf("\t\tPlease Enter your choice<0~8>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:Input(&ptele);
			break;
		case 2:Display(&ptele);
			break;
		case 3:Delete(&ptele);
			break;
		case 4:Search(&ptele);
			break;
		case 5:Modify(&ptele);
			break;
		case 6:Insert(&ptele);
			break;
		case 7:Sort(&ptele);
			break;
		case 8:Save(&ptele);
			break;
		case 0:exit(EXIT_SUCCESS);
			break;
		}
	}
	return 0;
}