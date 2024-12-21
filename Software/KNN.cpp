#include"knn.h"
#include<math.h>
string load(int savenum, int num) { return (stringstream() << "./save/" << savenum << "/" << num << ".png").str(); }
int myresult[100000][2] = { 0 }, nearest[10][2];
int knn() 
{
	Mat searchimg;
	Mat testimg = imread("./save/test.png");
	int** search = new int* [100];            //初始化一个百行百列的矩阵
	for (int i = 0; i < 100; i++)
	{
		search[i] = new int[100];
	}
	int** test = new int* [100];            //初始化一个百行百列的矩阵
	for (int i = 0; i < 100; i++)
	{
		test[i] = new int[100];
	}
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			test[i][j] = 0;
		}
	}
	readImg(testimg, test);//将图片转化成二维数组
	int count=0;
	String str;
	for (int number = 0; number < 10; number++) 
	{
		for (int num = 0; num < 9999; num++)
		{
			str = load(number, num);
			searchimg = imread(str);
			if (searchimg.empty() != 1) //检查图片是否存在
			{
				for (int i = 0; i < 100; i++)
				{
					for (int j = 0; j < 100; j++)
					{
						search[i][j] = 0;
					}
				}
				myresult[count][0] = number;
				readImg(searchimg, search);//将图片转化成二维数组
				for (int i = 0; i < 100; i++)
				{
					for (int j = 0; j < 100; j++)
					{
						myresult[count][1]+=pow((search[i][j]-test[i][j]),2);//欧式距离向量算法
					}
				}
				myresult[count][1] = sqrt(myresult[count][1]);

/*				for (int j = 0; j < 100; j++) { for (int i = 0; i < 100; i++) { cout << search[i][j]; } cout << endl; }
				cout << endl << endl << endl;
				cout << "字符:" << myresult[count][0] << "             欧氏距离:" << myresult[count][1] << endl;               *///debug用

				count++;
			}
			else 
			{
				break;//若寻找的图片不存在，则跳出正在遍历的数字的文件夹，遍历下一个数字的文件夹
			}
		}
	}
	return count;//返回统计数字
}

void readImg(Mat img,int** read) //将图片转化成二维数组
{
	for (int row = 0; row < 100; row++) {
		for (int col = 0; col < 100; col++) {
			if (img.at<Vec3b>(row, col)[0] == 0 || img.at<Vec3b>(row, col)[1] == 0 && img.at<Vec3b>(row, col)[2] == 0)
			{
				read[col][row] = 1;
			}
		}
	}
}

void rearrange(int count) //由近至远按欧式距离向量进行排序
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			nearest[i][j] = 10000;
		}
	}
	for (int i = 0; i < count; i++) 
	{
		for (int j = 0; j < 10; j++) {
			if (myresult[i][1] < nearest[j][1]) 
			{
				for (int k = 9; k > j; k--) 
				{
					nearest[k][0] = nearest[k-1][0];
					nearest[k][1] = nearest[k-1][1];
				}
				nearest[j][0] = myresult[i][0];
				nearest[j][1] = myresult[i][1];
				break;
			}
		}
	}
}