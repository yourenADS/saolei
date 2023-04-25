#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void choserank()
{
	int x, flag = 1;
	printf("------请输入你希望的游戏难度------\n");
	printf("--1.初级--2.中级-- 3.高级--4.自定义--\n ");
	scanf("%d", &x);
	while (flag == 1)
	{
		switch (x)
		{
		case 1: {
			ROW = 9;
			ROWS = 11;
			COL = 9;
			COLS = 11;
			flag = 0;
			COUNT = 10;
		
			break;
		}
		case 2: {
			ROW = 16;
			ROWS = 18;
			COL = 16;
			COLS = 18;
			flag = 0;
			COUNT = 40;
		
			break;
		}
		case 3: {
			ROW = 16;
			ROWS = 18;
			COL = 30;
			COLS = 32;
			flag = 0;
			COUNT = 99;
			
			break;
		}
		case 4: {
			printf("请输入你希望的行数与列数：\n");
			int a = 0, b = 0;
			scanf("%d %d", &a, &b);
			if (a > 24 || b > 30)
				printf("太大了请重新输入\n");
			else
			{
				ROW = a;
				COL = b;
				ROWS = a + 2;
				COLS = b + 2;
				flag = 0;
			}
			printf("请输入地雷大小，不超过80\n");
			int c;
			scanf("%d", &c);
			COUNT = c;
			break;
		}

		default:
			break;
		}
	}
}
void ingame(char** show,int** numb)
{
	int flag = COUNT;//记录剩余的地雷数；
	int win =0;//记录已经安全打开的步数，当win等于ROW*COL-COUNT时成功；
	int count = 0;//记录操作次数；
	int unsure = 0;//记录不确定标记
	int step;//选择的操作；
	int ifright=1;
	while (win != (ROW * COL - COUNT)&&ifright==1)
	{
		print(show, ROW, COL);
		printin(numb, ROW, COL);
		printf("-------您已经操作%d次，还剩下地雷%d个--------\n", count, flag);
		printf("Game in progress\n");
		printf("请选择你的操作\n");
		printf("----1.check--2.markmine--3.doubt--4.back--9.openmark---\n");
		scanf("%d", &step);
		int x, y;
		printf("请输入你操作的对象\n");
		scanf("%d %d", &x, &y);
		if (step == 1)
		{
			count++;
			check(show, numb, x, y, &win, &ifright);
		}
		if (step == 2)
		{
			count++;
			mark(show,x,y,&flag);
		}
		if (step == 3)
		{
			count++;
			doubt(show,x,y);
		}
		if (step == 4)
		{
			back(show,x,y,&flag);
			count++;
		}
		if (step == 9)
		{
			openmark(show,numb,x,y,&win,&ifright);
			count++;
		}
	}
	if (win == (ROW * COL - COUNT))
	{
		int i = 1, j = 1;
		for (i = 1; i <= ROW; i++)
		{
			for (j = 1; j <= COL; j++)
			{
				if (numb[i][j] == 1)
					show[i][j] = '*';
			}
		}
		print(show, ROW, COL);
		printf("you win!!!\n");
	}
}