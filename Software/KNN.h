#define _CRT_SECURE_NO_WARNINGS
#include "opencv2/opencv.hpp"
#include<iostream>
using namespace std;
using namespace cv;

extern int myresult[100000][2],nearest[10][2];//全局变量
string load(int savenum, int num);//合成硬盘检索地址
int knn();//从训练库导出所有图片进行机器训练，然后根据欧式距离向量算法算出最合适的数字
void readImg(Mat img, int** read); //将图片转化成二维数组
void rearrange(int count);//由近至远按欧式距离向量进行排序