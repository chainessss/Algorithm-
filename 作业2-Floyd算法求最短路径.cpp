#include<iostream>
#include<math.h>

#define INF 0x3f3f3f3f
#define MAXN 8

using namespace std;
int map[MAXN][MAXN];
int A[MAXN][MAXN];
int path[MAXN][MAXN];
int n;

void Floyd() {
	int i, j, k;
	
	//????
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			A[i][j] = map[i][j];
			if (i != j && A[i][j] < INF)
				path[i][j] = i;
			else
				path[i][j] = -1;
		}
	}

	//核心算法
	for (k = 0; k < n; ++k) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				if (k==i||k==j)
					continue;

				if (A[i][k] + A[k][j] < A[i][j]) {
					A[i][j] = A[i][k] + A[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
}

int main(){
	int i, j;
	int u, v, w;
	cin >> n;

	//输入矩阵
	while (1) {
		cin >> u >> v >> w;
		
		if (u == -1 && v == -1 && w == -1)
			break;
		
		map[u][v] = w;
	}

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (i == j)
				map[i][j] = 0;
			else if (map[i][j] == 0)
				map[i][j] = INF;
		}
	}

	Floyd();//开始运算

	//输出测试
	int test[MAXN];
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (i == j)
				continue;

			cout << i << "->" << j << " 的最短路径长度:" << A[i][j] << "   ";
			memset(test, 0, sizeof(test));
			
			int k = 0;
			test[k] = j;//第一个存储的下标
			while (path[i][test[k]] != i) {//不等于起点
				k++;
				test[k] = path[i][test[k - 1]];
			}
			k++;
			test[k] = i;
			for (int t = k; t > 0; t--)
				cout << test[t] <<"--";
			cout << test[0] << endl;
		}
	}
	return 0;
}

/*
测试数据：
4
0 1 2
0 2 6
0 3 4
1 2 3
2 0 7
2 3 1
3 0 5
3 2 12
-1 -1 -1
*/