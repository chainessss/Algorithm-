#include<iostream>
#include<math.h> 
#include<fstream>  
#include<algorithm>  

using namespace std;
#define MAX 0x3f3f3f3f  //���������
#define M 99999


/*test
15
5 10
9 1
10 12
10 19
13 15
15 19
16 20
19 9
24 0
24 12
31 32
32 24
38 29
40 56
45 23
*/

struct point {
	double x;
	double y;
}p[M];

int a[M];// �������������

int cmpX(const point& a, const point& b){  //��������
	return a.x < b.x;
}

int cmpY(int &a, int &b){   //��������
	return p[a].y < p[b].y;
}

inline double min(double a, double b){   //��������ֵ�н�С��
	return a < b ? a : b;
}
inline double dist(const point& a, const point& b){
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
double closeset(int low, int high){
	int i, j, c = 0;
	int mid;
	double ans;

	if (low == high)
		return MAX;

	if (low + 1 == high)  //��n=2����������֮��ľ���
		return dist(p[low], p[high]);
	
	mid = (low + high) >> 1;  //����һλ���൱�ڳ���2�������Ƶ������ٶȸ��죬��ʹ��(low+high)/2���м�λ���������
	ans = min(closeset(low, mid), closeset(mid + 1, high));  //�ݹ����������С����
	
	for (i = low; i <= high; i++) { //ͳ����Щ��λ���������ڣ�����¼
		if (p[mid].x - ans <= p[i].x && p[i].x <= p[mid].x + ans)
			a[c++] = i;
	}
	sort(a, a + c, cmpY);
	for (i = 0; i < c; i++) {//�Ƚ�s1�������ڵĵ��s2�������ڵĵ�ľ����Ƿ������С��������С�Ե�
		int k = i + 7 > c ? c : i + 7;
		for (j = i + 1; j < k; j++){
			if (p[a[j]].y - p[a[i]].y > ans)  //���λ����λ������ĵ�ľ������anx��������һ��ѭ��
				break;
			ans = min(dist(p[a[i]], p[a[j]]), ans);   //�����������С�����������ԣ���ѡ����С�ĵ�
		}
	}
	return ans;
}

int main(){

	double totaltime;
	int n;
	double dmin;

	cout << "�������Ϊ��";
	cin >> n;
	cout << "�������Ϊ��" << endl;
	
	for (int i = 0; i < n; i++) {
		cout << "p" << i + 1 << ":";
		cin >> p[i].x >> p[i].y;
	}
	sort(p, p + n, cmpX); //����x������
	dmin = closeset(0, n - 1);
	cout << "����ľ����ǣ�" << dmin << endl;
	return 0;

}