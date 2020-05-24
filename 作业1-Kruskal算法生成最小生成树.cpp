#include<iostream>
using namespace std;

#define MAXN 20
#define MAXM 20		
struct edge			
{
	int u;
	int v;
	int w;
}edges[MAXM];		

int parent[MAXN];	//parent[i]为顶点i所在集合对应的树中的根结点
int n;				//顶点个数
int m;				//边的个数
int i, j;	

void init(){
	for (i = 1; i <= n; i++) 
		parent[i] = -1;
}

int cmp(const void *a, const void *b){		//实现从小到大的比较函数
	return (*(const edge *)a).w - (*(const edge *)b).w;
}

int find(int x){		//查找根结点
	int s;		
	for (s = x; parent[s] >= 0; s = parent[s]);

	while (s != x){
		int tmp = parent[x];
		parent[x] = s;
		x = tmp;
	}
	return s;
}

void Union(int R1, int R2)//将两个不同集合的元素进行合并
{
	int r1 = find(R1);
	int r2 = find(R2);	
	int temp = parent[r1] + parent[r2];		//两个集合结点数之和（负数）

	if (parent[r1] > parent[r2]){
		parent[r1] = r2;
		parent[r2] = temp;
	}
	else{
		parent[r2] = r1;
		parent[r1] = temp;
	}
}

void Kruskal(){
	qsort(edges, m, sizeof(edges[0]), cmp);	//对边按权值从小到大排序

	int sum = 0;		//生成树的权值
	int num = 0;		//已选用的边的数目
	
	init();			
	for (i = 0; i < m; i++){
		if (find(edges[i].u) != find(edges[i].v)){
			sum += edges[i].w; 
			num++;
			Union(edges[i].u, edges[i].v);
		}
		if (num >= n - 1) 
			break;
	}
	cout << "最小生成树的权值和为:" << sum << endl;
}

void main()
{
	cin >> n >> m;	
	for (int i = 0; i < m; i++)
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	
	Kruskal();
}

/*test
6 10
1 2 6
1 5 5
1 6 1
2 3 3
2 6 5
3 4 6
3 6 6
4 5 2
4 6 4
5 6 5
*/