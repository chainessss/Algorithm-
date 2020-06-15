#include <iostream>
#include <fstream>
using namespace std;

/*
0 1 1 1 0
1 0 1 1 1
1 1 0 1 0
0 1 1 0 1
0 1 0 1 0
*/


const int N = 5;//ͼ�Ķ�����
const int M = 3;//ɫ����

class Color
{
	friend int mColoring(int, int, int **);
private:
	bool Ok(int k);
	void Backtrack(int t);
	int n,		//ͼ�Ķ�����
		m,		//���õ���ɫ��
		**a,	//ͼ���ڽӾ���
		*x;		//��ǰ��
	long sum;	//��ǰ���ҵ��Ŀ�m��ɫ������
};

int mColoring(int n, int m, int **a);

int main()
{
	int **a = new int *[N + 1];
	for (int i = 1; i <= N; i++)
	{
		a[i] = new int[N + 1];
	}
		
	cout << "ͼG���ڽӾ���Ϊ:" << endl;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cin >> a[i][j];
		}
	}

	cout << "ͼG����ɫ�������£�" << endl;
	cout << "��m=" << M << "ʱ��ͼG�Ŀ�����ɫ������ĿΪ��" << mColoring(N, M, a) << endl;
	for (int i = 1; i <= N; i++)
	{
		delete[] a[i];
	}
	delete[]a;
}

void Color::Backtrack(int t)
{
	if (t > n)
	{
		sum++;
		for (int i = 1; i <= n; i++)
			cout << x[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = 1; i <= m; i++) {
			x[t] = i;
			if (Ok(t)) Backtrack(t + 1);
		}
	}
}

bool Color::Ok(int k)// �����ɫ������
{
	for (int j = 1; j <= n; j++)
	{
		if ((a[k][j] == 1) && (x[j] == x[k])) //��������ɫ��ͬ
		{
			return false;
		}
	}
	return true;
}

int mColoring(int n, int m, int **a)
{
	Color X;

	//��ʼ��X
	X.n = n;
	X.m = m;
	X.a = a;
	X.sum = 0;
	int *p = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		p[i] = 0;
	}
	X.x = p;
	X.Backtrack(1);
	delete[] p;
	return X.sum;
}