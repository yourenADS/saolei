#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int ROW,ROWS;
int COL, COLS;
int COUNT;
void choserank();
void menu();
char** creatshow(int row, int col);
int** creatnum(int row, int col, int count);
void print(char  **show,int row,int col);
void printin(int** show, int row, int col);
void check(char** show,int** numb,int x,int y,int* win, int* ifright);
void mark(char** show,int x, int y,int*flag);
int GetMineCount(int** show,int X,int Y);
void doubt(char** show, int x, int y);
void unfolt(char** show, int** numb, int x, int y,int* win);
void ingame(char** show, int** numb);
void back(char** show, int x, int y,int*flag);
void openmark(char** show, int** numb, int x, int y,int*win, int* ifright);
int getmark(char** show, int x, int y);
void Free(char** show, int** numb);