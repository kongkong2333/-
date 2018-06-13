#include <iostream>
#include "stdafx.h"
#include "graphics.h"
#include <stdio.h>

int main()
{
	initgraph(1000, 1000);
	struct mouse_msg m;
	setwritemode(   R2_XORPEN);
	for (;is_run(); delay_fps(60))
	{
		while(mousemsg())
		{
				m = getmouse();
				lineto(m.x, m.y);
		}
	}
	getch();
	closegraph();
	return 0;
}
