#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

void product_num(float score[], int size) {//生成随机测试数据
	int i;
	for (i = 0; i < size; i++)
		score[i] = rand() % 100;
}


void sort(float num[], int size) {//使用冒泡排序法排序
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
	float* score = (float*)malloc(sizeof(float) * num);//创建学生分数数组
	int i;
	int Havg = 0;
	product_num(score, num);
	min = max = score[0];
	for (i = 0; i < num; i++) //判断最大值与最小值
	{
		if (score[i] > max)
			max = score[i];
		if (score[i] < min)
			min = score[i];
		sum += score[i];
	}
	avg = sum / num;//计算平均分
	sort(score, num);//排序
	for (i = 0; i < num; i++)
	{
		if (i && i % 5 == 0)
			putchar('\n');
		printf("%5.2f ", score[i]);
		if (score[i] > avg)//计算高于平均分的人数
			Havg++;
	}
	printf("\n最高分:%.2f \n最低分:%.2f\n平均分:%.2f\n高于平均分的人数:%d", max, min, avg, Havg);
	free(score);
	return ;
}


double calculate_S(double x) // 计算S的值
{
	double S = 0, t;
	int n;
	for (n = 1; ; n++) {
		t = pow((-1), (n + 1)) * n / pow(x, n - 1);//计算每一项的值t
		S += t;//将t的值累加到S
		if (fabs(t) < 1e-5)//当第n项的绝对值小于1e-6则跳出循环
			break;
	}
	printf("S=%f", S);
	return 0;
}

void calculate_year() { //计算闰年
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

int interface() {//图形界面
	int num;
	printf("*************************************\n");
	printf("*               菜单                *\n");
	printf("*  1.计算S的值                      *\n");
	printf("*  2.计算1900-2500之间的闰年        *\n");
	printf("*  3.程序的排序和计算               *\n");
	printf("*  0.不计算，退出                   *\n");
	printf("*************************************\n\n");
	printf("请用编号1，2，3，0选择所需的功能：");
	scanf("%d", &num);

	return num;
}

int main()
{
	double x;
	int num;
	srand((unsigned)time(NULL));
	while (1) {
		num = interface();//获取编号
		while (1) {
			if (num >= 0 && num <= 3)
			{
				break;
			}
			else {//编号错误处理
				system("cls");
				printf("编号错误，重新输入！！\n");
				num = interface();
			}
		}

		switch (num) {
		case 1://计算S
			system("cls");
			printf("输入一个数作为x(x>1):");
			while (1) {
				scanf("%lf", &x);
				if (x > 1) {
					calculate_S(x); 
					break;
				}
				else {
					system("cls");
					printf("输入错误，重新输入:");
				}
			}
			break;
		case 2://计算闰年
			system("cls");
			calculate_year();
			break;
		case 3://计算成绩
			system("cls");
			calculate(10);
			break;
		case 0://退出switch
			break;
		}
		
		if (num == 0) {//退出程序
			break;
		}
		printf("\n");
		system("pause");
		system("cls");
		
	}
	return 0;
}