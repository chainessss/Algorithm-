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

int parent[MAXN];	//parent[i]Ϊ����i���ڼ��϶�Ӧ�����еĸ����
int n;				//�������
int m;				//�ߵĸ���
int i, j;	

void init(){
	for (i = 1; i <= n; i++) 
		parent[i] = -1;
}

int cmp(const void *a, const void *b){		//ʵ�ִ�С����ıȽϺ���
	return (*(const edge *)a).w - (*(const edge *)b).w;
}

int find(int x){		//���Ҹ����
	int s;		
	for (s = x; parent[s] >= 0; s = parent[s]);

	while (s != x){
		int tmp = parent[x];
		parent[x] = s;
		x = tmp;
	}
	return s;
}

void Union(int R1, int R2)//��������ͬ���ϵ�Ԫ�ؽ��кϲ�
{
	int r1 = find(R1);
	int r2 = find(R2);	
	int temp = parent[r1] + parent[r2];		//�������Ͻ����֮�ͣ�������

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
	qsort(edges, m, sizeof(edges[0]), cmp);	//�Ա߰�Ȩֵ��С��������

	int sum = 0;		//��������Ȩֵ
	int num = 0;		//��ѡ�õıߵ���Ŀ
	
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
	cout << "��С��������Ȩֵ��Ϊ:" << sum << endl;
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