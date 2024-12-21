#include "resize.h"

void Resize(int Matrix[100][100],int* n) 
{
	int row[100] = { 0 }; //每一行1的总数
	int col[100] = { 0 }; //每一列1的总数
	int countrow = 0,countcol=0; //矩阵中1的总数
	int newvalue[4] = {0,99,0,99};//新的上边、下边、左边、右边
	for (int j = 0; j < 100; j++) //按行查找
	{
		for (int i = 0; i < 100; i++)
		{
			if (Matrix[i][j] == 1) { row[j]++; countrow++; }
		}
	}
	for (int i = 0; i < 100; i++) //按列查找
	{
		for (int j = 0; j < 100; j++)
		{
			if (Matrix[i][j] == 1) { col[i] ++; countcol++; }
		}
	}
	for (int j = 0; j < 99; j++) //裁剪上边
	{
		float percent = (float)row[j]/(float)countrow;
		if (percent < 0.005) newvalue[0] = j + 1;
		else break;
	}
	for (int j = 99; j > 0; j--) //裁剪下边
	{
		float percent = (float)row[j] / (float)countrow;
		if (percent < 0.005) newvalue[1] = j - 1; 
		else break; 
	}
	for (int i = 0; i < 99; i++) //裁剪左边
	{
		float percent = (float)col[i] / (float)countcol;
		if (percent < 0.005)newvalue[2] = i + 1;
		else break;
	}
	for (int i = 99; i > 0; i--) //裁剪右边
	{
		float percent = (float)col[i] / (float)countcol;
		if (percent < 0.005) newvalue[3] = i - 1;
		else break;
	}
		n[0] = newvalue[0] - 1;		if (n[0] < 0)n[0] = 0;
		n[1] = newvalue[1] + 2;     if (n[1] > 99)n[1] = 99;
		n[2] = newvalue[2] - 1;     if (n[2] < 0)n[2] = 0;
		n[3] = newvalue[3] + 2;     if (n[3] > 99)n[3] = 99;
}