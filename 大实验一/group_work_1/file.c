#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

void product_num(float score[], int size) {//���������������
	int i;
	for (i = 0; i < size; i++)
		score[i] = rand() % 100;
}


void sort(float num[], int size) {//ʹ��ð����������
	int i, j;
	for (i = 0; i < size; i++)
		for (j = 0; j < size - i - 1; j++)
			if (num[j] < num[j + 1])
			{
				float tmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmp;

			}
}
void calculate(int num) {

	float max, min, avg, sum = 0;
	float* score = (float*)malloc(sizeof(float) * num);//����ѧ����������
	int i;
	int Havg = 0;
	product_num(score, num);
	min = max = score[0];
	for (i = 0; i < num; i++) //�ж����ֵ����Сֵ
	{
		if (score[i] > max)
			max = score[i];
		if (score[i] < min)
			min = score[i];
		sum += score[i];
	}
	avg = sum / num;//����ƽ����
	sort(score, num);//����
	for (i = 0; i < num; i++)
	{
		if (i && i % 5 == 0)
			putchar('\n');
		printf("%5.2f ", score[i]);
		if (score[i] > avg)//�������ƽ���ֵ�����
			Havg++;
	}
	printf("\n��߷�:%.2f \n��ͷ�:%.2f\nƽ����:%.2f\n����ƽ���ֵ�����:%d", max, min, avg, Havg);
	free(score);
	return ;
}


double calculate_S(double x) // ����S��ֵ
{
	double S = 0, t;
	int n;
	for (n = 1; ; n++) {
		t = pow((-1), (n + 1)) * n / pow(x, n - 1);//����ÿһ���ֵt
		S += t;//��t��ֵ�ۼӵ�S
		if (fabs(t) < 1e-5)//����n��ľ���ֵС��1e-6������ѭ��
			break;
	}
	printf("S=%f", S);
	return 0;
}

void calculate_year() { //��������
	int count = 1;

	for (int year = 1900; year <= 2500; year++) {
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
			printf("%d ", year);
			if (count % 3 == 0) {
				printf("\n");
			}
			count++;
		}
	}
}

int interface() {//ͼ�ν���
	int num;
	printf("*************************************\n");
	printf("*               �˵�                *\n");
	printf("*  1.����S��ֵ                      *\n");
	printf("*  2.����1900-2500֮�������        *\n");
	printf("*  3.���������ͼ���               *\n");
	printf("*  0.�����㣬�˳�                   *\n");
	printf("*************************************\n\n");
	printf("���ñ��1��2��3��0ѡ������Ĺ��ܣ�");
	scanf("%d", &num);

	return num;
}

int main()
{
	double x;
	int num;
	srand((unsigned)time(NULL));
	while (1) {
		num = interface();//��ȡ���
		while (1) {
			if (num >= 0 && num <= 3)
			{
				break;
			}
			else {//��Ŵ�����
				system("cls");
				printf("��Ŵ����������룡��\n");
				num = interface();
			}
		}

		switch (num) {
		case 1://����S
			system("cls");
			printf("����һ������Ϊx(x>1):");
			while (1) {
				scanf("%lf", &x);
				if (x > 1) {
					calculate_S(x); 
					break;
				}
				else {
					system("cls");
					printf("���������������:");
				}
			}
			break;
		case 2://��������
			system("cls");
			calculate_year();
			break;
		case 3://����ɼ�
			system("cls");
			calculate(10);
			break;
		case 0://�˳�switch
			break;
		}
		
		if (num == 0) {//�˳�����
			break;
		}
		printf("\n");
		system("pause");
		system("cls");
		
	}
	return 0;
}