#include <iostream>
#include "stdafx.h"
#include <graphics.h>
#include <stdio.h>

using namespace std;

void cursor(int x,int y,int zi)
{
	FORMAT_MESSAGE_ARGUMENT_ARRAY;	//���ĸ�ʽ��������Լ��ú궨�壬����ֱ��д�����Ｔ�� 
		while (!kbhit()) {	//���ް�������˸��� 
			setwritemode(R2_XORPEN);	//��������ͼ��ʽ 
			line(x, y, x, y + zi);	//����� 
			Sleep(100);	//��ʱ 
			line(x, y, x, y + zi);	//�����	
			Sleep(100);	//��ʱ 
		}
}
int main()
{
	char i;
	char a[100];
	int x=0, y=0,count=0,z;
	initgraph(1000, 1000);
	setfont(16, 0,"����");
	cursor(x, y, 16);
	while (kbhit && (i = getch())!=13)
	{
		if (i != key_left && i!= key_right && i!=key_enter)
		{
			a[count] = i;
			count++;
			if (x <= 1000)
			{
				cursor(x, y, 16);
				outtextxy(x, y, i);
				x += textwidth(i);
				cursor(x, y, 16);
			}
			else
			{
				y += textheight(i);
				x = 0;
				cursor(x, y, 16);
				outtextxy(x, y, i);
				cursor(x, y, 16);
			}
		}
		if (i == key_left)
		{
			x -= textwidth(i);
			cursor(x,y,16);
		}
		if (i == key_right)
		{
			x += textwidth(i);
			cursor(x, y, 16);
		}
		if (i == key_enter)
			break;

	}
	closegraph();
	for (z = 0; z <= count; z++)
	{
		printf("%c", a[count]);
	}
	return 0;
}