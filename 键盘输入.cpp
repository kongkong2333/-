#include <iostream>
#include "stdafx.h"
#include <graphics.h>
#include <stdio.h>

using namespace std;

void cursor(int x,int y,int zi)
{
	FORMAT_MESSAGE_ARGUMENT_ARRAY;	//光标的格式，具体的自己用宏定义，或者直接写在这里即可 
		while (!kbhit()) {	//若无按键，闪烁光标 
			setwritemode(R2_XORPEN);	//设置异或绘图方式 
			line(x, y, x, y + zi);	//画光标 
			Sleep(100);	//延时 
			line(x, y, x, y + zi);	//擦光标	
			Sleep(100);	//延时 
		}
}
int main()
{
	char i;
	char a[100];
	int x=0, y=0,count=0,z;
	initgraph(1000, 1000);
	setfont(16, 0,"宋体");
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