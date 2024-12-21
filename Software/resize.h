#define _CRT_SECURE_NO_WARNINGS
#include "opencv2/opencv.hpp"
#include<iostream>
using namespace std;
using namespace cv;

void Resize(int Matrix[100][100],int* n);//裁剪出新的图片高度和宽度，防止因为绘画文字大小问题识别失误(归一化)