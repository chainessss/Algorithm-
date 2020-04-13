#include<iostream>
using namespace std;

int main() {
	int m=5, n=4;//m万元钱，n项投资
	int i, j;
	int tmp_m, tmp_F = 0, t = 0;//tem_m代表给第i个项目投入的钱数  0<=tmp<=j;tmp_F代表一次循环中的钱数
	int f[10][10] = { {0 , 11, 12, 13, 14,15}, 
					  {0 , 0 , 5 , 10, 15, 20},
				      {0 , 2 , 10, 30, 32, 40},
				      {0 , 20, 21, 22, 23, 24 }
	};
	int F[10][10],Max[10][10];

	cout << m << "万元钱   " << n << "项投资" << endl;
	cout << "\n各项投资的收益为:" << endl;

	for (i = 0; i < n; ++i) {
		for (j = 0; j < m+1; ++j) {
			cout << f[i][j] << " ";
		}
		cout << endl;
	}

	for (j = 0; j < m + 1; ++j) {
		F[0][j] = f[0][j];
		Max[0][j] = j;
	}
	for (i = 1; i < n; ++i) {
		for (j = 0; j < m + 1; ++j) {
			for (tmp_m = 0; tmp_m <= j; ++tmp_m) {
				tmp_F = F[i - 1][j - tmp_m] + f[i][tmp_m];
				if (tmp_F > F[i][j]) {
					F[i][j] = tmp_F;
					Max[i][j] = tmp_m;
				}
			}
		}
	}

	cout << "\n最大收益为 : " << F[n - 1][m] << endl;
}


