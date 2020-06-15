#include<stdio.h>
#include<math.h>
int n;
double minlen = 10000;
double x[100];
double r[100];//�ֱ�Ϊ��СԲ���г��ȣ�ÿ��Բ�ĺ����꣬ÿ��Բ�뾶
double order[1000];//��СԲ���еİ뾶˳��

double center(int t) {//Բ������
	double temp = 0;
	for (int j = 1; j < t; j++) {
		double xvalue = x[j] + 2.0 * sqrt(r[t] * r[j]);
		if (xvalue > temp) {
			temp = xvalue;
		}
	}
	return temp;
}
void swap(double& a, double& b) {
	double t = a;
	a = b;
	b = t;
}
void compute() {
	double low = 0, high = 0;//��ʾ���������ұ߽�
	for (int i = 1; i <= n; i++) {
		if (x[i] - r[i] < low) {
			low = x[i] - r[i];
		}
		if (x[i] + r[i] > high) {
			high = x[i] + r[i];
		}
	}
	if (high - low < minlen) {
		minlen = high - low;
		for (int i = 1; i <= n; i++) {
			order[i] = r[i];
		}
	}
}
void backtrack(int t) {
	if (t > n) {
		compute();
	}
	else {
		for (int j = t; j <= n; j++) {
			swap(r[t], r[j]);
			double centerx = center(t);//��ȡԲ�ĺ�����
			
			if (centerx + r[t] + r[1] < minlen) {
				x[t] = centerx;
				backtrack(t + 1);
			}
			swap(r[t], r[j]);
		}
	}
}
int main() {
	printf("Բ�ĸ���Ϊ��");
	scanf_s("%d", &n);
	
	printf("ÿ��Բ�İ뾶�ֱ�Ϊ:\n");
	for (int i = 1; i <= n; i++) {
		scanf_s("%lf", &r[i]);
	}

	backtrack(1);

	printf("���е�˳���Ӧ�İ뾶�ֱ�Ϊ:");
	for (int i = 1; i <= n; i++) {
		printf("%.2f ", order[i]);
	}
	printf("\n");

	printf("��СԲ�����г���Ϊ��%.2f\n", minlen);
}