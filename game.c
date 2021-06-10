#include "game.h"

// �˵�����Ϸ��ʼ����
menu()
{
	printf("\n");
	printf("*******************************\n");
	printf("****  ��ӭ������������Ϸ�� ****\n");
	printf("****      1.������Ϸ       ****\n");
	printf("****      0.�˳���Ϸ       ****\n");
	printf("*******************************\n");
}

//���̵ĳ�ʼ������ROW��COL�ķ�Χ���γ����̣������̳�ʼ��Ϊ�� �����ո�
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;  //���������������ֱ��ʾ����ʱ����λ�õĿ�Ⱥ͸߶�

	for (i = 0; i < row; i++)  
	{
		for (j = 0; j < col; j++)  
		{
			board[i][j] = ' ';    //����ѭ������Ƕ����������������ʼ����������
		}
	}    //����������λ��λ������֮��ʱ������������λ����Ϊ�ո񣬼����̵ĳ�ʼ����Ϊ֮���������׼�� 
}

//��ӡ���̡������ߺͺ��߰����̷�װ���������������������λ������
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		printf("  %d ", i + 1); //��ӡ���� x ��������ʾ
	}
	printf("\n");

	for (j = 0; j < col; j++)
	{
		printf("---|"); //��ӡ��һ������
	}
	printf("\n");

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c |", board[i][j]); //��ӡ����
		}
		printf(" %d ", i + 1); //��ӡ���� y ��������ʾ
		printf("\n");

		for (j = 0; j < col; j++)
		{
			printf("---|"); //��ӡ���
		}
		printf("\n");
	}
}

//��������
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������:>\n");  //��ʾ��

	while (1)
	{   //����srand������rand���������õ������������������
		x = rand() % row;  //rand������C��������������һ��������ĺ���
		y = rand() % col;
		//��ֹ����λ���ظ��Ļ���
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

//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("�����:>\n");
	printf("����������(%d,%d): >", row, col);  //���������ʾ��

	while (1)
	{
		scanf_s("%d %d", &x, &y);  //��������µ������������
		if (x >= 1 && x <= row && y >= 1 && y <= col)  //��������λ�ô���������
		{
			// �ɹ����塣��ҵ����ӻ�����������ʾ��һ��'x'ͼ��
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'x';
				break;
			}
			// ����������ѱ�ռ��
			else
			{
				printf("�������Ѿ���ռ��\n");
				printf("����������:>");
				continue;
			}
		}
		// ����������ǷǷ����жϡ��������������겻�������ϣ�����ʾ��Ҹ�����Ƿ�
		else
		{
			printf("����Ƿ�\n");
			printf("����������:>");
			continue;
		}
	}
}

//�ж�ƽ��
static int IsFull(char board[ROW][COL], int row, int col)  //static�ؼ���ʹ��ǡ���ܴ����߳����ģ�����ԣ���������չ��ά����
{                                                          //��Ϊ���徲̬���������о�̬����ֻ�������������ļ��пɼ��������ļ��������øú���
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

	//����û�п�λ���˻�û���жϳ���Ӯ����ƽ��
	return 1;
}

//�ж���Ӯ
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	// ��������������һ�ߣ�Ӯ�Ҳ���
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

	// ��������������һ�ߣ�Ӯ�Ҳ���
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

	// б������������һ�ߣ�Ӯ�Ҳ���
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

	//��Ϸƽ��
	if (IsFull(board, row, col))
	{
		return 'p';
	}

	//��Ϸ����
	return ' ';

}