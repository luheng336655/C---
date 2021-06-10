#include "game.h"

extern void game(void);
extern void test(void);  //用extern声明函数

int main()
{
	test();
	return 0;
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));  //srand函数是随机数发生器的初始化函数。它初始化随机种子，
	                                  //会提供一个种子，这个种子会对应一个随机数

	do
	{
		menu();
		printf("请选择:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
		}
	} while (input);
}

// 游戏开始执行
void game()
{
	int ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);

	// 下棋
	while (1)
	{
		ComputerMove(board, ROW, COL); //电脑走
		ret = IsWin(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
		system("CLS"); //清屏，优化界面
		DisplayBoard(board, ROW, COL); //打印棋盘
		printf("\n");

		PlayerMove(board, ROW, COL); //玩家走
		ret = IsWin(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
		DisplayBoard(board, ROW, COL); //打印棋盘
		printf("\n");
	}

	// 判断输赢或平局
	if (ret == 'p')
	{
		printf("平局\n");
		DisplayBoard(board, ROW, COL); //打印棋盘
	}
	else if (ret == 'x')
	{
		printf("玩家赢\n");
		DisplayBoard(board, ROW, COL); //打印棋盘
	}
	else if (ret == '0')
	{
		printf("电脑赢\n");
		DisplayBoard(board, ROW, COL); //打印棋盘
	}
}