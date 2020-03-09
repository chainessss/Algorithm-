#include<iostream>
using namespace std;

int map[10][10];                 //�ڽӾ�������Ϣ 
int n,m;						 //�洢�������ͱ�����
int u, v, w;                     //�洢Ȩֵ     
int dis[10];                     //��A������ľ��� 
int vis[10] = { 0};			     //����Ƿ���ʹ�
int i, j;

void Dijkstra()
{
	int t,k,min;				//�����С����
	for (i = 1; i <= n; ++i){
		min = 100000;
		for (j = 1; j <= n; ++j){
			if (vis[j] == 0 && dis[j] < min){
				min = dis[j];
				t = j;
			}
		}
		vis[t] = 1;
		for (k = 1; k <= n; k++){
			if (vis[k] == 0 && dis[k] > dis[t] + map[t][k] && map[t][k] < 100000){
				dis[k] = dis[t] + map[t][k];
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (i = 1; i <= n; ++i) {			//������
		for (j = 1; j <= n; ++j) {
			if (i == j)
				map[i][j] = 0;
			else
				map[i][j] = 10000;
		}
		if (i == 1)
			dis[i] = 0;
		else
			dis[i] = 100000;

	}
	for (int i = 1; i <= m; ++i) {
			cin >> u >> v >> w;
			map[u][v] = w;	
			if (u == 1)
				dis[v] = w;
	}
	Dijkstra();
	cout << "a�㵽h�����̾���Ϊ " << dis[8] << endl;
}

/*test
8 11
1 2 1
2 4 2
3 1 2
4 3 1
4 6 8
6 5 2
5 4 2
5 7 2
7 6 3
7 8 3
8 6 2
*/