#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	choserank();
	char** show;
	int** numb;
	show = creatshow(ROWS, COLS);
	numb = creatnum(ROWS, COLS,COUNT);
	ingame(show, numb);
	Free(show, numb);
}
int main()
{

	int flag = 1;
	while (flag)
	{
		menu();
		int choose;
		scanf("%d", &choose);
		switch (choose) {
		case 1: {
			game();
			break;
		}
		case 0:{
			flag = 0;
			printf("��Ϸ������\n");
			break;
		}
		default: {
			printf("����������\n");
			break;
		}
		}
	}
	return 0;
}
