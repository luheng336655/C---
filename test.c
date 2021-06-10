#include "game.h"

extern void game(void);
extern void test(void);  //��extern��������

int main()
{
	test();
	return 0;
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));  //srand������������������ĳ�ʼ������������ʼ��������ӣ�
	                                  //���ṩһ�����ӣ�������ӻ��Ӧһ�������

	do
	{
		menu();
		printf("��ѡ��:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������\n");
		}
	} while (input);
}

// ��Ϸ��ʼִ��
void game()
{
	int ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);

	// ����
	while (1)
	{
		ComputerMove(board, ROW, COL); //������
		ret = IsWin(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
		system("CLS"); //�������Ż�����
		DisplayBoard(board, ROW, COL); //��ӡ����
		printf("\n");

		PlayerMove(board, ROW, COL); //�����
		ret = IsWin(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
		DisplayBoard(board, ROW, COL); //��ӡ����
		printf("\n");
	}

	// �ж���Ӯ��ƽ��
	if (ret == 'p')
	{
		printf("ƽ��\n");
		DisplayBoard(board, ROW, COL); //��ӡ����
	}
	else if (ret == 'x')
	{
		printf("���Ӯ\n");
		DisplayBoard(board, ROW, COL); //��ӡ����
	}
	else if (ret == '0')
	{
		printf("����Ӯ\n");
		DisplayBoard(board, ROW, COL); //��ӡ����
	}
}