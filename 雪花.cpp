#include<iostream>
#include"stdafx.h"
#include<graphics.h>
#include<math.h>
using namespace std;

double ang = 0;                       //当前角度

void forward(double distance)              //当前角度向前画d长的线
{
	double dx = cos(ang)*distance;
	double dy = sin(ang)*distance;
	linerel(dx, dy);
}

void right(double angle)                   //顺时针旋转角度angle，角度单位为DEG
{
	ang = ang + angle;
}
void left(double angle)                   //逆时针旋转角度angle，角度单位为DEG
{
	ang = ang - angle;
}



void Koch(int n, int len)
{
	if (n == 0)
	{
		forward(len);
	}
	else if(n == 1)
	{
		forward(len / 3);
		left(PI / 3);
		forward(len / 3);
		right(PI*2/3);
		forward(len / 3);
		left(PI/3);
		forward(len / 3);
	}
	else
	{
		Koch(n - 1, len / 3);
	    left(PI/3);
	    Koch(n - 1, len / 3);
	    right(PI*2/3);
	    Koch(n - 1, len / 3);
	    left(PI/3);
	    Koch(n - 1, len / 3);
	}
}

int main()
{
	initgraph(1000, 1000);
	Koch(2, 200);
	system("PAUSE");
	return 0;
}

