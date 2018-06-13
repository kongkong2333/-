#include <iostream>
#include "stdafx.h"
#include <graphics.h>
#include <math.h>
using namespace std;

double ang=0;                       //��ǰ�Ƕ�

void forward(double distance)              //��ǰ�Ƕ���ǰ��d������
{
	double dx = cos(ang)*distance;
	double dy = sin(ang)*distance;
	linerel(dx, dy);
}

void turn(double angle)                   //˳ʱ����ת�Ƕ�angle���Ƕȵ�λΪDEG����angleΪ����ʱ��ʱ����ת
{
	ang = ang + angle;
}

void move(double distance)               //�ص�ǰ�����ƶ��ʣ������ߣ�������Ϊdistance����distanceΪ����ʱ����
{
	double dx = cos(ang)*distance;
	double dy = sin(ang)*distance;
	moverel(dx, dy);
}
void diamond(int len)                           //�ص�ǰ��������(��Ϊlen,����һ��Ϊ60��)���ص���ǰλ����Ƕ�
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
void hexag(int len)                             //�Ե�ǰλ��Ϊԭ���ص�ǰ����������(��Ϊlen)���ص���ǰλ����Ƕ�
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
	for (i = 1; i <= 18; i++)                        //����ص�ԭ�㷽��PI/2
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