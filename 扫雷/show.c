#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("请选择是否开始游戏\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
}
void print(char** show, int row, int col)
{

	int i = 0, j = 0;
	for (j = 0; j < col; j++)
	{
		printf("--");
	}
	printf("-\n");
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
			printf("|%c", show[i][j]);
		printf("|\n");
		for (j = 0; j < col; j++)
		{
			printf("--");
		}
		printf("-\n");
	}
}
void printin(int** show, int row, int col)
{
	int i = 1, j = 1;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
			printf("%d ", show[i][j]);
		printf("\n");
	}
}
char** creatshow(int row, int col)
{
	int x = row, y = col;
	char** show = (char**)malloc(sizeof(char*) * x);
	int i = 0, j = 0;
	for (i = 0; i < x; i++)
	{
			show[i] = (char*)malloc(sizeof(char) * y);
		
	}
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			show[i][j] = '.';
		}
	}
	return(show);
}
int** creatnum(int row, int col, int count)
{
	int x = row, y = col;
	int** show = (int**)malloc(sizeof(int*) * x);
	int i = 0, j = 0;
	for (i = 0; i < x; i++)
	{
			show[i] = (int*)malloc(sizeof(int) * y);
	}
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			show[i][j] = 0;
		}
	}
	srand((unsigned int)time(0));
	while (count != 0)
	{
		int x = rand() % (row - 2) + 1;
		int y = rand() % (col - 2) + 1;
		if (show[x][y] == 0)
		{
			show[x][y] = 1;
			count--;
		}
	}
	return (show);
}
void Free(char** show, int** numb)
{
	int i = 0, j = 0;
	for (i = 0; i < ROWS; i++)
	{
			free(show[i]);
	}
	for (j = 0; j < ROWS; j++)
	{
		free(numb[j]);
	}
}