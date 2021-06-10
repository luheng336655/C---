//五子棋小游戏。2021、6、9，倪琳。

#ifndef __GAME_H__  //宏定义，将头文件的内容放在#ifndef和#endif中，可防止两个C文件都include同一个头文件而产生的大量声明冲突。
//#ifndef能防止头文件重复包含和编译。
                         //#ifndef定义：#ifndef x 先测试x是否被宏定义过。
//x<标识>应为唯一，命名规则一般是头文件名全大写，前后加下划线，并把文件名中的"."也变成下划线
#define __GAME_H__            //        #define x 如果没有宏定义下面就宏定义x并编译下面的语句        
                              //        ... 
# define _CRT_SECURE_NO_WARNINGS      //#endif  如果已经定义了则编译#endif后面的语句

#include <stdio.h>
#include <stdlib.h>  //定义了四个变量类型、一些宏（NULL空指针常量的值）和通用工具函数(rand函数、srand函数） 
#include <time.h>    //定义了四个变量类型、两个宏（NULL)和各种操作日期和时间的函数
#include <string.h>
//定义五子棋棋盘的尺寸大小
#define ROW 10   //棋盘的宽度
#define COL 10  //五子棋棋盘的高度

void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);      //函数的声明

#endif  __GAME_H__#pragma once
