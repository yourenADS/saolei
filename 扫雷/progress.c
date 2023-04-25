#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
int GetMineCount(int** numb, int X, int Y)
{
	int sum = numb[X][Y + 1] + numb[X + 1][Y] + numb[X + 1][Y + 1] + numb[X - 1][Y] + numb[X - 1][Y - 1] + numb[X][Y - 1] + numb[X - 1][Y + 1] + numb[X + 1][Y - 1];
	return sum;
}
void unfolt(char** show, int** numb, int x, int y, int* win)
{
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL) //������������չ������ֹԽ��
	{
		int count = GetMineCount(numb, x, y);//��ȡ����

		if (count == 0) //����û�ף�����ݹ�չ��
		{
			show[x][y] = '0';//����û�׵ĸ�Ϊ �ո�  ' '


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
		else   //����������ʾ����
		{
			show[x][y] = count + '0';
		}

		//��¼չ��������
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

			printf("�Ѿ���,��������\n");
		}
	}
	else
	{

		printf("����Ƿ�������������\n");
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
		printf("������ֲ���\n");
	}
	else
	{
		sum = getmark(show, x, y);
		if (sum != (show[x][y] - '0'))
			printf("��δ��ȫ��ǵ���\n");
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