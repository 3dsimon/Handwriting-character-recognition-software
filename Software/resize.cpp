#include "resize.h"

void Resize(int Matrix[100][100],int* n) 
{
	int row[100] = { 0 }; //ÿһ��1������
	int col[100] = { 0 }; //ÿһ��1������
	int countrow = 0,countcol=0; //������1������
	int newvalue[4] = {0,99,0,99};//�µ��ϱߡ��±ߡ���ߡ��ұ�
	for (int j = 0; j < 100; j++) //���в���
	{
		for (int i = 0; i < 100; i++)
		{
			if (Matrix[i][j] == 1) { row[j]++; countrow++; }
		}
	}
	for (int i = 0; i < 100; i++) //���в���
	{
		for (int j = 0; j < 100; j++)
		{
			if (Matrix[i][j] == 1) { col[i] ++; countcol++; }
		}
	}
	for (int j = 0; j < 99; j++) //�ü��ϱ�
	{
		float percent = (float)row[j]/(float)countrow;
		if (percent < 0.005) newvalue[0] = j + 1;
		else break;
	}
	for (int j = 99; j > 0; j--) //�ü��±�
	{
		float percent = (float)row[j] / (float)countrow;
		if (percent < 0.005) newvalue[1] = j - 1; 
		else break; 
	}
	for (int i = 0; i < 99; i++) //�ü����
	{
		float percent = (float)col[i] / (float)countcol;
		if (percent < 0.005)newvalue[2] = i + 1;
		else break;
	}
	for (int i = 99; i > 0; i--) //�ü��ұ�
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