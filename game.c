#include "game.h"

// 菜单。游戏开始界面
menu()
{
	printf("\n");
	printf("*******************************\n");
	printf("****  欢迎来到五子棋游戏！ ****\n");
	printf("****      1.进入游戏       ****\n");
	printf("****      0.退出游戏       ****\n");
	printf("*******************************\n");
}

//棋盘的初始化。在ROW、COL的范围内形成棋盘，将棋盘初始化为‘ ’（空格）
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;  //定义两个变量，分别表示下棋时棋子位置的宽度和高度

	for (i = 0; i < row; i++)  
	{
		for (j = 0; j < col; j++)  
		{
			board[i][j] = ' ';    //利用循环语句的嵌套依次用坐标来初始化五子棋盘
		}
	}    //当棋子落子位置位于棋盘之内时，将棋子落子位置设为空格，即棋盘的初始化，为之后的落子做准备 
}

//打印棋盘。用竖线和横线把棋盘封装起来，并在棋盘外标坐标位置提醒
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		printf("  %d ", i + 1); //打印棋盘 x 轴坐标提示
	}
	printf("\n");

	for (j = 0; j < col; j++)
	{
		printf("---|"); //打印第一行棋盘
	}
	printf("\n");

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c |", board[i][j]); //打印竖标
		}
		printf(" %d ", i + 1); //打印棋盘 y 轴坐标提示
		printf("\n");

		for (j = 0; j < col; j++)
		{
			printf("---|"); //打印横标
		}
		printf("\n");
	}
}

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走:>\n");  //提示词

	while (1)
	{   //利用srand（）和rand（）函数让电脑在棋盘上随机下棋
		x = rand() % row;  //rand函数，C语言中用来产生一个随机数的函数
		y = rand() % col;
		//防止落子位置重复的机制
		if (board[x][y] == ' ')
		{
			board[x][y] = '0';
			break;
		}
		else
		{
			continue;
		}
	}
}

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("玩家走:>\n");
	printf("请输入坐标(%d,%d): >", row, col);  //玩家下棋提示词

	while (1)
	{
		scanf_s("%d %d", &x, &y);  //玩家输入下的五子棋的坐标
		if (x >= 1 && x <= row && y >= 1 && y <= col)  //控制落子位置处于棋盘上
		{
			// 成功下棋。玩家的落子会在棋盘上显示出一个'x'图案
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'x';
				break;
			}
			// 输入的坐标已被占用
			else
			{
				printf("该坐标已经被占用\n");
				printf("请重新输入:>");
				continue;
			}
		}
		// 输入的坐标是非法的判断。若玩家输入的坐标不在棋盘上，则提示玩家该坐标非法
		else
		{
			printf("坐标非法\n");
			printf("请重新输入:>");
			continue;
		}
	}
}

//判断平局
static int IsFull(char board[ROW][COL], int row, int col)  //static关键字使用恰当能大幅提高程序的模块特性，有利于拓展和维护。
{                                                          //此为定义静态函数。其中静态函数只能在声明它的文件中可见，其他文件不能引用该函数
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}

	//棋盘没有空位置了还没有判断出输赢，则平局
	return 1;
}

//判断输赢
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	// 横线上五子连成一线，赢家产生
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col - 4; j++)
		{
			if (board[i][j] == board[i][j + 1]
				&& board[i][j + 1] == board[i][j + 2]
				&& board[i][j + 2] == board[i][j + 3]
				&& board[i][j + 3] == board[i][j + 4]
				&& board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}

	// 竖线上五子连成一线，赢家产生
	for (j = 0; j < col; j++)
	{
		for (i = 0; i < row - 4; i++)
		{
			if (board[i][j] == board[i + 1][j]
				&& board[i + 1][j] == board[i + 2][j]
				&& board[i + 2][j] == board[i + 3][j]
				&& board[i + 3][j] == board[i + 4][j]
				&& board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}

	// 斜线上五子连成一线，赢家产生
	for (i = 0; i < row - 4; i++)
	{
		if (board[i][i] == board[i + 1][i + 1]
			&& board[i + 1][i + 1] == board[i + 2][i + 2]
			&& board[i + 2][i + 2] == board[i + 3][i + 3]
			&& board[i + 3][i + 3] == board[i + 4][i + 4]
			&& board[i][i] != ' ')
		{
			return board[i][i];
		}

		if (board[i][i + 4] == board[i + 1][i + 3]
			&& board[i + 1][i + 3] == board[i + 2][i + 2]
			&& board[i + 2][i + 2] == board[i + 3][i + 1]
			&& board[i + 3][i + 1] == board[i + 4][i]
			&& board[i][i + 4] != ' ')
		{
			return board[i][i + 4];
		}
	}

	//游戏平局
	if (IsFull(board, row, col))
	{
		return 'p';
	}

	//游戏结束
	return ' ';

}