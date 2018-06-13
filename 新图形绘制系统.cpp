#include <iostream>
#include "stdafx.h"
#include <graphics.h>
#include <math.h>
using namespace std;

double ang=0;                       //当前角度

void forward(double distance)              //当前角度向前画d长的线
{
	double dx = cos(ang)*distance;
	double dy = sin(ang)*distance;
	linerel(dx, dy);
}

void turn(double angle)                   //顺时针旋转角度angle，角度单位为DEG，当angle为负数时逆时针旋转
{
	ang = ang + angle;
}

void move(double distance)               //沿当前方向移动笔（不画线），长度为distance，当distance为负数时后退
{
	double dx = cos(ang)*distance;
	double dy = sin(ang)*distance;
	moverel(dx, dy);
}
void diamond(int len)                           //沿当前方向画菱形(长为len,其中一角为60度)并回到当前位置与角度
{
	int i;
	for (i = 0; i < 2; i++)
	{
		forward(len);
		turn(2 * PI / 6);
		forward(len);
		turn(2 * PI / 3);
	}
}
void hexag(int len)                             //以当前位置为原点沿当前方向画六边形(长为len)并回到当前位置与角度
{
	int i;
	move(2 * len);
	turn(2 * PI / 3);
	for (i = 1; i <= 6; i++)
	{
		forward(2 * len);
		turn(2 * PI / 6);
	}
	turn(2 * PI / 6);
	move(2 * len);
	turn(PI);
}

int main()
{
	initgraph(1000, 1000);
	int i;
	int dia_len = 200;
	moveto(500, 500);
	turn(-PI / 2);
	for (i = 1; i <= 18; i++)                        //画玩回到原点方向PI/2
	{
		diamond(dia_len);
		turn(PI / 9);
	}
	for (i = 1; i <= 3; i++)
	{
		hexag(dia_len);
		turn(PI / 9);
	}
	getch();
	closegraph();
	return 0;
}