#include"knn.h"
#include<math.h>
string load(int savenum, int num) { return (stringstream() << "./save/" << savenum << "/" << num << ".png").str(); }
int myresult[100000][2] = { 0 }, nearest[10][2];
int knn() 
{
	Mat searchimg;
	Mat testimg = imread("./save/test.png");
	int** search = new int* [100];            //��ʼ��һ�����а��еľ���
	for (int i = 0; i < 100; i++)
	{
		search[i] = new int[100];
	}
	int** test = new int* [100];            //��ʼ��һ�����а��еľ���
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
	readImg(testimg, test);//��ͼƬת���ɶ�ά����
	int count=0;
	String str;
	for (int number = 0; number < 10; number++) 
	{
		for (int num = 0; num < 9999; num++)
		{
			str = load(number, num);
			searchimg = imread(str);
			if (searchimg.empty() != 1) //���ͼƬ�Ƿ����
			{
				for (int i = 0; i < 100; i++)
				{
					for (int j = 0; j < 100; j++)
					{
						search[i][j] = 0;
					}
				}
				myresult[count][0] = number;
				readImg(searchimg, search);//��ͼƬת���ɶ�ά����
				for (int i = 0; i < 100; i++)
				{
					for (int j = 0; j < 100; j++)
					{
						myresult[count][1]+=pow((search[i][j]-test[i][j]),2);//ŷʽ���������㷨
					}
				}
				myresult[count][1] = sqrt(myresult[count][1]);

/*				for (int j = 0; j < 100; j++) { for (int i = 0; i < 100; i++) { cout << search[i][j]; } cout << endl; }
				cout << endl << endl << endl;
				cout << "�ַ�:" << myresult[count][0] << "             ŷ�Ͼ���:" << myresult[count][1] << endl;               *///debug��

				count++;
			}
			else 
			{
				break;//��Ѱ�ҵ�ͼƬ�����ڣ����������ڱ��������ֵ��ļ��У�������һ�����ֵ��ļ���
			}
		}
	}
	return count;//����ͳ������
}

void readImg(Mat img,int** read) //��ͼƬת���ɶ�ά����
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

void rearrange(int count) //�ɽ���Զ��ŷʽ����������������
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