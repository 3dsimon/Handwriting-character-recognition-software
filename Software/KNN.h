#define _CRT_SECURE_NO_WARNINGS
#include "opencv2/opencv.hpp"
#include<iostream>
using namespace std;
using namespace cv;

extern int myresult[100000][2],nearest[10][2];//ȫ�ֱ���
string load(int savenum, int num);//�ϳ�Ӳ�̼�����ַ
int knn();//��ѵ���⵼������ͼƬ���л���ѵ����Ȼ�����ŷʽ���������㷨�������ʵ�����
void readImg(Mat img, int** read); //��ͼƬת���ɶ�ά����
void rearrange(int count);//�ɽ���Զ��ŷʽ����������������