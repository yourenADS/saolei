#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
int GetMineCount(int** numb, int X, int Y)
{
	int sum = numb[X][Y + 1] + numb[X + 1][Y] + numb[X + 1][Y + 1] + numb[X - 1][Y] + numb[X - 1][Y - 1] + numb[X][Y - 1] + numb[X - 1][Y + 1] + numb[X + 1][Y - 1];
	return sum;
}
void unfolt(char** show, int** numb, int x, int y, int* win)
{
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL) //限制在棋盘内展开，防止越界
	{
		int count = GetMineCount(numb, x, y);//获取雷数

		if (count == 0) //四周没雷，进入递归展开
		{
			show[x][y] = '0';//四周没雷的改为 空格  ' '


			int X = x - 1, Y = y;
			if (show[X][Y] == '.' && X >= 1 && X <= ROW && Y >= 1 && Y <= COL)
				unfolt(show, numb, X, Y, win);
			X = x + 1; Y = y;
			if (show[X][Y] == '.' && X >= 1 && X <= ROW && Y >= 1 && Y <= COL)
				unfolt(show, numb, X, Y, win);
			X = x; Y = y + 1;
			if (show[X][Y] == '.' && X >= 1 && X <= ROW && Y >= 1 && Y <= COL)
				unfolt(show, numb, X, Y, win);
			X = x; Y = y - 1;
			if (show[X][Y] == '.' && X >= 1 && X <= ROW && Y >= 1 && Y <= COL)
				unfolt(show, numb, X, Y, win);
			X = x + 1; Y = y - 1;
			if (show[X][Y] == '.' && X >= 1 && X <= ROW && Y >= 1 && Y <= COL)
				unfolt(show, numb, X, Y, win);
			X = x - 1; Y = y - 1;
			if (show[X][Y] == '.' && X >= 1 && X <= ROW && Y >= 1 && Y <= COL)
				unfolt(show, numb, X, Y, win);
			X = x + 1; Y = y + 1;
			if (show[X][Y] == '.' && X >= 1 && X <= ROW && Y >= 1 && Y <= COL)
				unfolt(show, numb, X, Y, win);
			X = x - 1; Y = y + 1;
			if (show[X][Y] == '.' && X >= 1 && X <= ROW && Y >= 1 && Y <= COL)
				unfolt(show, numb, X, Y, win);
		}
		else   //四周有雷显示雷数
		{
			show[x][y] = count + '0';
		}

		//记录展开的数量
		(*win)++;
	}
}
void check(char** show, int** numb, int x, int y, int* win, int* ifright)
{

	if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
	{
		if (show[x][y] == '.')
		{
			if (numb[x][y] == 1)
			{
				printf("Hit mine, you lose\n");
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
				(*ifright) = 0;
			}
			else
			{
				unfolt(show, numb, x, y, win);
			}
		}
		else
		{

			printf("已经打开,重新输入\n");
		}
	}
	else
	{

		printf("输入非法，请重新输入\n");
	}
}
void mark(char** show, int x, int y, int* flag)
{
	if (show[x][y] == '.' || show[x][y] == '?')
	{
		--(*flag);
		show[x][y] = '!';
	}
	else
		printf("error");
}
void doubt(char** show, int x, int y)
{
	if (show[x][y] == '.' || show[x][y] == '!')
		show[x][y] = '?';
	else
		printf("error");
}
void back(char** show, int x, int y, int* flag)
{
	if (show[x][y] == '?' || show[x][y] == '!')
	{
		++(*flag);
		show[x][y] = '.';
	}
	else
		printf("error");
}
void openmark(char** show, int** numb, int x, int y,int*win, int* ifright)
{
	int sum;
	if (show[x][y] == '.' || show[x][y] == '!' || show[x][y] == '?')
	{
		printf("请对数字操作\n");
	}
	else
	{
		sum = getmark(show, x, y);
		if (sum != (show[x][y] - '0'))
			printf("并未完全标记地雷\n");
		else
		{
			int X = x - 1, Y = y;
			if ((show[X][Y] == '.'||show[X][Y]=='?') && X >= 1 && X <= ROW && Y >= 1 && Y <= COL)
				check(show, numb, X, Y, win, ifright);
			X = x + 1; Y = y;
			if ((show[X][Y] == '.' || show[X][Y] == '?') && X >= 1 && X <= ROW && Y >= 1 && Y <= COL)
				check(show, numb, X, Y, win, ifright);
			X = x; Y = y + 1;
			if ((show[X][Y] == '.' || show[X][Y] == '?') && X >= 1 && X <= ROW && Y >= 1 && Y <= COL)
				check(show, numb, X, Y, win, ifright);
			X = x; Y = y - 1;
			if ((show[X][Y] == '.' || show[X][Y] == '?') && X >= 1 && X <= ROW && Y >= 1 && Y <= COL)
				check(show, numb, X, Y, win, ifright);
			X = x + 1; Y = y - 1;
			if ((show[X][Y] == '.' || show[X][Y] == '?') && X >= 1 && X <= ROW && Y >= 1 && Y <= COL)
				check(show, numb, X, Y, win, ifright);
			X = x - 1; Y = y - 1;
			if ((show[X][Y] == '.' || show[X][Y] == '?') && X >= 1 && X <= ROW && Y >= 1 && Y <= COL)
				check(show, numb, X, Y, win, ifright);
			X = x + 1; Y = y + 1;
			if ((show[X][Y] == '.' || show[X][Y] == '?') && X >= 1 && X <= ROW && Y >= 1 && Y <= COL)
				check(show, numb, X, Y, win, ifright);
			X = x - 1; Y = y + 1;
			if ((show[X][Y] == '.' || show[X][Y] == '?') && X >= 1 && X <= ROW && Y >= 1 && Y <= COL)
				check(show, numb, X, Y, win, ifright);
		}
	}
}
int getmark(char** show, int x, int y)
{
	int count = 0;
	if (show[x-1][y] == '!')
		count++;
	if (show[x - 1][y-1] == '!')
		count++;
	if (show[x - 1][y+1] == '!')
		count++;
	if (show[x][y+1] == '!')
		count++;
	if (show[x][y-1] == '!')
		count++;
	if (show[x + 1][y+1] == '!')
		count++;
	if (show[x +1][y-1] == '!')
		count++;
	if (show[x + 1][y] == '!')
		count++;

	return count;
}