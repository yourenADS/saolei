#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void choserank()
{
	int x, flag = 1;
	printf("------��������ϣ������Ϸ�Ѷ�------\n");
	printf("--1.����--2.�м�-- 3.�߼�--4.�Զ���--\n ");
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
			printf("��������ϣ����������������\n");
			int a = 0, b = 0;
			scanf("%d %d", &a, &b);
			if (a > 24 || b > 30)
				printf("̫��������������\n");
			else
			{
				ROW = a;
				COL = b;
				ROWS = a + 2;
				COLS = b + 2;
				flag = 0;
			}
			printf("��������״�С��������80\n");
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
	int flag = COUNT;//��¼ʣ��ĵ�������
	int win =0;//��¼�Ѿ���ȫ�򿪵Ĳ�������win����ROW*COL-COUNTʱ�ɹ���
	int count = 0;//��¼����������
	int unsure = 0;//��¼��ȷ�����
	int step;//ѡ��Ĳ�����
	int ifright=1;
	while (win != (ROW * COL - COUNT)&&ifright==1)
	{
		print(show, ROW, COL);
		printin(numb, ROW, COL);
		printf("-------���Ѿ�����%d�Σ���ʣ�µ���%d��--------\n", count, flag);
		printf("Game in progress\n");
		printf("��ѡ����Ĳ���\n");
		printf("----1.check--2.markmine--3.doubt--4.back--9.openmark---\n");
		scanf("%d", &step);
		int x, y;
		printf("������������Ķ���\n");
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