#include<iostream>
#include"stdafx.h"
#include<graphics.h>
#include<math.h>
using namespace std;

double ang = 0;                       //��ǰ�Ƕ�

void forward(double distance)              //��ǰ�Ƕ���ǰ��d������
{
	double dx = cos(ang)*distance;
	double dy = sin(ang)*distance;
	linerel(dx, dy);
}

void right(double angle)                   //˳ʱ����ת�Ƕ�angle���Ƕȵ�λΪDEG
{
	ang = ang + angle;
}
void left(double angle)                   //��ʱ����ת�Ƕ�angle���Ƕȵ�λΪDEG
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

