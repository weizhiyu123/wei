#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;
int main()
{
	int a = 0;
	int b = 0;
	int mode = 0;//0:�� 1:�� 2:�� 3:��
	int i = 0;
	int c[5] = { 0,30,1,100,1 };//�Ƿ��ƣ������������Ƿ��г˳�����ֵ���ޡ���ֵ���ޡ�
	srand((unsigned)time(NULL)); //��ʼ���������������ʹ��ÿ���������ɵ��������ͬ
	printf("�Ƿ��ƣ�������1��������0��");
	cin >> c[0];
	if (c[0] == 0)
	{
		for (i = 0; i < 30; i++) //����ʮ��
		{
			a = rand() % 100; //����һ��0~99֮��������
			b = rand() % 100; //����һ��0~99֮��������
			mode = rand() % 4; //����һ��0~3֮�������������������
			printf("%d", a); //��ӡ��ʽ
			switch (mode) //ȷ�������
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
		cout << "�������������:";
		cin >> c[1];
		cout << "�Ƿ񺬳˳���������1��������0:";
		cin >> c[2];
		cout << "��ֵ����:";
		cin >> c[3];
		cout << "��ֵ����:";
		cin >> c[4];
		for (i = 0; i < c[1]; i++) //��������
		{
			a = rand() % (c[3] - c[4] + 1) + c[4]; //�����޶��������
			b = rand() % (c[3] - c[4] + 1) + c[4]; //�����޶��������
			if (c[2] == 1) {
				mode = rand() % 4; //����һ��0~3֮�������������������
				printf("%d", a); //��ӡ��ʽ
				switch (mode) //ȷ�������
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
				mode = rand() % 2; //����һ��0~3֮�������������������
				printf("%d", a); //��ӡ��ʽ
				switch (mode) //ȷ�������
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