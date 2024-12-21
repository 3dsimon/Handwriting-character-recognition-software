#include"resize.h"
#include"knn.h"

Mat img,save,save_down,identify_down,reset_down;
bool P = false;
Point previousPoint;
int drawimg[100][100] = { 0 };//x,y����
int Slider,Value=9;   //��������Ӧ�ı���������ֵ

void On_mouse(int event, int x, int y, int flags, void*) //���������
{
	if (x > 99)x = 99; if (y > 99)y = 99; if (x < 0)x = 0; if (y < 0)y = 0;
	if (event == EVENT_LBUTTONDOWN) 
	{
		previousPoint = Point(x, y);
	}
	else if (event == EVENT_MOUSEMOVE && (flags & EVENT_FLAG_LBUTTON)) 
	{
		Point pt(x, y);
		line(img, previousPoint, pt, Scalar(0, 0, 0), 2, 5, 0);
		previousPoint = pt;
		drawimg[x][y] = 1;
		imshow("Draw",img);
	}
	if (event == EVENT_LBUTTONUP)
	{
		for (int j = 0; j < 100; j++) { for (int i = 0; i < 100; i++) { cout << drawimg[i][j]; } cout<<endl; }
		cout << endl << endl<<endl;
	}
}

void save_mouse(int event, int x, int y, int flags, void*)//��ť�����
{
	if (event == EVENT_LBUTTONDOWN&&y<98)//�浵��ť
	{
		imshow("Function", save_down);
		string save;
		Mat find,drawimg_resize;
		for (int i = 0; i < 9999; i++) 
		{ 
			/*----��ͼƬ���й�һ��----*/
			int n[4] = { 0,0,0,0 };
			int* iden = n;
			Resize(drawimg, iden);
			drawimg_resize = img(Range(iden[0], iden[1]), Range(iden[2], iden[3]));//�ü�����
			resize(drawimg_resize, drawimg_resize, cv::Size(100,100)); // �Ŵ����
			/*----------------------*/
			save = load(Slider, i); //�ϳɴ浵��ַ
			find = imread(save); //��ѯ����ͼƬ���
			if (find.empty()) 
			{ 
				imwrite(save, drawimg_resize);
				break; 
			}
		}
		cout << "ͼ���ѱ������ַ�"<<Slider<<"�ļ�����" << endl;
	}

	else if(event == EVENT_LBUTTONDOWN && y >107&&y<195)//ʶ��ť
	{
		imshow("Function", identify_down);
		Mat drawimg_resize;
		int coun[10] = { 0,0,0,0,0,0,0,0,0,0 }, top[3][2] = { {0,0},{0,0},{0,0} };
		/*----��ͼƬ���й�һ��----*/
		int n[4] = { 0,0,0,0 };
		int* iden=n;
		Resize(drawimg, iden);
		drawimg_resize = img(Range(iden[0], iden[1]), Range(iden[2], iden[3]));//�ü�����
		resize(drawimg_resize, drawimg_resize, cv::Size(100, 100)); // �Ŵ����
		/*----------------------*/
		imwrite("./save/test.png", drawimg_resize);
		int count=knn();

		rearrange(count);
		cout << "---------------------------------------------------------------------" << endl << endl;
		cout << "ʶ���ַ�" << "                               " << "ŷ�Ͼ���" << endl;
		for (int i = 0; i < 10; i++) 
		{
			cout << nearest[i][0] << "                                      " << nearest[i][1] << endl;
			for (int j = 0; j < 10; j++) 
			{
				if (nearest[i][0] == j)coun[j]++;
			}
		}
		cout << endl<<"---------------------------------------------------------------------" << endl;

		for (int i = 0; i < 10; i++) 
		{
			for (int j = 0; j < 3; j++) 
			{
				if (coun[i] > top[j][1])
				{
					for (int k = 2; k > j; k--)
					{
						top[k][0] = top[k - 1][0];
						top[k][1] = top[k - 1][1];
					}
					top[j][0] = i;
					top[j][1] = coun[i];
					break;
				}
			}
		}
		cout << "---------------------------------------------------------------------" << endl << endl;
		cout << "ʶ���ַ�" << "                               " << "���ưٷֱ�" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << top[i][0] << "                                      " << top[i][1]*10<<"%"<< endl;
		}
		cout << endl << "---------------------------------------------------------------------" << endl;
	}

	else if (event == EVENT_LBUTTONDOWN && y > 200)//���ð�ť
	{
		imshow("Function", reset_down);
		img= imread("background.jpg");
		imshow("Draw", img);
		for (int i = 0; i < 100; i++) 
		{
			for (int j = 0; j < 100; j++)drawimg[i][j] = 0;
		}
	}
	if (event == EVENT_LBUTTONUP)
	{
		imshow("Function", save);
	}
}

int main()
{
	img = imread("background.jpg"); 
	save = imread("save.png"); 
	save_down = imread("save_down.png"); 
	identify_down = imread("identify_down.png");
	reset_down = imread("reset_down.png");
	if (img.empty())
	{
		printf("����ͼ�����\n");
		return -1;
	}
	namedWindow("Draw", cv::WINDOW_NORMAL);
	namedWindow("Function", cv::WINDOW_NORMAL);
	imshow("Draw", img);
    setMouseCallback("Draw", On_mouse, 0);
	imshow("Function", save);
	setMouseCallback("Function", save_mouse, 0);

	//�ڴ����Ĵ����д���һ���������ؼ�
	char TrackbarName[50];
	sprintf(TrackbarName, "������ַ�");
	createTrackbar(TrackbarName, "Function", &Slider, Value, NULL);
    waitKey(0);
    return 0;
}