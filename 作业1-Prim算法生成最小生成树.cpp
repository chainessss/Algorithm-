#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxx = 1100;
int e[maxx][maxx], dis[maxx];
bool book[maxx];
int n, m;
void init()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j)e[i][j] = 0;
			else
				e[i][j] = inf;
}
int prim(int e[][maxx], int n)
{
	int ans = 0;
	memset(book, false, sizeof(book));
	book[0] = true;
	for (int i = 1; i < n; i++)
		dis[i] = e[0][i];
	for (int i = 1; i < n; i++)
	{
		int minn = inf, u = -1;
		for (int j = 0; j < n; j++)
		{
			if (!book[j] && dis[j] < minn)
			{
				minn = dis[j];
				u = j;
			}
		}
		if (ans == inf)
			return -1;
		ans += minn;
		book[u] = true;
		for (int v = 0; v < n; v++)
			if (!book[v])
				dis[v] = min(dis[v], e[u][v]);
	}
	return ans;
}
int main()
{
	cout << "输入边信息的时候，A->1  B->2  C->3……以此类推\n" << endl;
	while (cin >> m >> n)
	{
		init();
		for (int i = 0; i < n; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			if (e[a - 1][b - 1] > c)
				e[a - 1][b - 1] = e[b - 1][a - 1] = c;
		}
		cout<<"最小生成树权重为： " << prim(e, m) << endl;
	}
	return 0;
}
