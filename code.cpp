#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;
int main()
{
	int a = 0;
	int b = 0;
	int mode = 0;//0:加 1:减 2:乘 3:除
	int i = 0;
	int c[5] = { 0,30,1,100,1 };//是否定制，出题数量、是否有乘除、数值上限、数值下限。
	srand((unsigned)time(NULL)); //初始化随机数发生器，使得每次运行生成的随机数不同
	printf("是否定制？是输入1，否输入0：");
	cin >> c[0];
	if (c[0] == 0)
	{
		for (i = 0; i < 30; i++) //做三十题
		{
			a = rand() % 100; //生成一个0~99之间的随机数
			b = rand() % 100; //生成一个0~99之间的随机数
			mode = rand() % 4; //生成一个0~3之间的随机数，代表运算符
			printf("%d", a); //打印算式
			switch (mode) //确定运算符
			{
			case 0:
				printf("+%d = \n", b);
				break;
			case 1:
				printf("-%d = \n", b);
				break;
			case 2:
				printf("*%d = \n", b);
				break;
			case 3:
				printf("/%d = \n", b);
				break;
			default:
				printf("somethingis wrong!\n");
				break;
			}
		}
	}
	else {
		cout << "请输入出题数量:";
		cin >> c[1];
		cout << "是否含乘除？是输入1，否输入0:";
		cin >> c[2];
		cout << "数值上限:";
		cin >> c[3];
		cout << "数值下限:";
		cin >> c[4];
		for (i = 0; i < c[1]; i++) //定制题数
		{
			a = rand() % (c[3] - c[4] + 1) + c[4]; //生成限定的随机数
			b = rand() % (c[3] - c[4] + 1) + c[4]; //生成限定的随机数
			if (c[2] == 1) {
				mode = rand() % 4; //生成一个0~3之间的随机数，代表运算符
				printf("%d", a); //打印算式
				switch (mode) //确定运算符
				{
				case 0:
					printf("+%d = \n", b);
					break;
				case 1:
					printf("-%d = \n", b);
					break;
				case 2:
					printf("*%d = \n", b);
					break;
				case 3:
					printf("/%d = \n", b);
					break;
				default:
					printf("somethingis wrong!\n");
					break;
				}
			}
			else {
				mode = rand() % 2; //生成一个0~3之间的随机数，代表运算符
				printf("%d", a); //打印算式
				switch (mode) //确定运算符
				{
				case 0:
					printf("+%d = \n", b);
					break;
				case 1:
					printf("-%d = \n", b);
					break;
				default:
					printf("somethingis wrong!\n");
					break;
				}

			}
		}

	}

	return 0;

}