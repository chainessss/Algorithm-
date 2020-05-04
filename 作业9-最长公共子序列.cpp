#include <iostream>
#include<string>

using namespace std;
void LCSLength(int m, int n, string x, string y, int c[20][20], int b[20][20]){

	int i, j;

	//初始化
	for (i = 0; i <= m; i++)
		c[i][0] = 0;
	for (j = 1; j <= n; j++)
		c[0][j] = 0;

	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			if (x[i - 1] == y[j - 1]){
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;//删除两个
			}
			else if (c[i - 1][j] >= c[i][j - 1]){
				c[i][j] = c[i - 1][j];
				b[i][j] = 2;//删除x
			}
			else{
				c[i][j] = c[i][j - 1];
				b[i][j] = 3;//删除y
			}
		}
	}
}


void LCS(int i, int j, string x, int b[20][20])
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 1){
		LCS(i - 1, j - 1, x, b);
		cout << x[i - 1];
	}
	else if (b[i][j] == 2)
		LCS(i - 1, j, x, b);
	else
		LCS(i, j - 1, x, b);
}

int main()
{
	string x = "ABCD";
	string y="BAD";
	cout << "x序列为： " << x << endl;
	cout << "y序列为： " << y << endl;

	int b[20][20], c[20][20];
	int m, n;

	m = x.length();
	n = y.length(); 

	LCSLength(m, n, x, y, c, b);
	LCS(m, n, x, b);
	cout << "长度为：" << c[m][n] << endl;
	return 0;
}