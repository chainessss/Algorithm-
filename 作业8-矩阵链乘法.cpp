#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
int a[100];
int m[100][100];
int q;

int RecursiveMatrixChain(int* p, int i, int j) {//递归

	if (i == j)
		return 0;
	m[i][j] = 100000000;//无穷大
	for (int k = i; k <= j - 1; ++k)
	{
		int q = RecursiveMatrixChain(p, i, k) + RecursiveMatrixChain(p, k + 1, j)
			+ p[i - 1] * p[k] * p[j];
		if (q < m[i][j])
			m[i][j] = q;
	}
	return m[i][j];
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for (int i = 1; i <= n - 1; i++){
		m[i][i] = 0;
	}
	

	// 迭代算法	
	for (int r = 2; r <= n - 1; r++){//循环长度		
		for (int i = 1; i <= (n - 1) - r + 1; i++){//循环起点
			int j = i + r - 1;
			m[i][j] = 100000000;//无穷大
			for (int k = i; k < i + r; k++){
				q = m[i][k] + m[k + 1][j] + a[i] * a[k + 1] * a[j + 1];
				if (q <= m[i][j]){
					m[i][j] = q;
				}
			}
		}
	}

	//递归
	//RecursiveMatrixChain(a, 1, n);
	
	cout <<"最少次数："<< m[1][n - 1] << endl;

}

