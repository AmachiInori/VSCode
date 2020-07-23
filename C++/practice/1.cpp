#include <graphics.h>
#include <time.h>
#include <conio.h>

int main()
{
	// 设置随机函数种子
	srand((unsigned) time(NULL));

	// 初�?�化图形模式
	initgraph(640, 480);

	int  x, y;
	char c;


	// 设置颜色
	settextcolor(GREEN);
	setlinecolor(BLACK);

	for (int i = 0; i <= 479; i++)
	{
		// 在随机位�?显示三个随机字母
		for (int j = 0; j < 3; j++)
		{
			x = (rand() % 80) * 8;
			y = (rand() % 20) * 24;
			c = (rand() % 26) + 65;
			outtextxy(x, y, c);
		}

		// 画线擦掉一�?像素�?
		line(0, i, 639, i);

		Sleep(10);					// 延时
		if (i >= 479)	i = -1;		// �?�?处理
		if (_kbhit())	break;		// 按任意键退�?
	}

	// 关闭图形模式
	closegraph();
}