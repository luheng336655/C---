//������С��Ϸ��2021��6��9�����ա�

#ifndef __GAME_H__  //�궨�壬��ͷ�ļ������ݷ���#ifndef��#endif�У��ɷ�ֹ����C�ļ���includeͬһ��ͷ�ļ��������Ĵ���������ͻ��
//#ifndef�ܷ�ֹͷ�ļ��ظ������ͱ��롣
                         //#ifndef���壺#ifndef x �Ȳ���x�Ƿ񱻺궨�����
//x<��ʶ>ӦΪΨһ����������һ����ͷ�ļ���ȫ��д��ǰ����»��ߣ������ļ����е�"."Ҳ����»���
#define __GAME_H__            //        #define x ���û�к궨������ͺ궨��x��������������        
                              //        ... 
# define _CRT_SECURE_NO_WARNINGS      //#endif  ����Ѿ������������#endif��������

#include <stdio.h>
#include <stdlib.h>  //�������ĸ��������͡�һЩ�꣨NULL��ָ�볣����ֵ����ͨ�ù��ߺ���(rand������srand������ 
#include <time.h>    //�������ĸ��������͡������꣨NULL)�͸��ֲ������ں�ʱ��ĺ���
#include <string.h>
//�������������̵ĳߴ��С
#define ROW 10   //���̵Ŀ��
#define COL 10  //���������̵ĸ߶�

void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);      //����������

#endif  __GAME_H__#pragma once
