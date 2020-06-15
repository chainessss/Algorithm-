#include<stdio.h>

typedef struct {
	int start;
	int end;
}activtity;

/*
10
1 4
2 6
2 13
3 5
4 9
5 7
5 9
6 10
8 11
8 12
*/


int main()
{
	activtity a[100];
	int i;
	int n;
	int k = 0;

	scanf_s("%d", &n);
	for (i = 1; i <= n; i++){
		scanf_s("%d %d", &a[i].start, &a[i].end);
	}
	for (i = 1; i < n - 1; i++){
		for (int j = 1; j < n - i - 1; j++){
			activtity t;
			if (a[j].end > a[j + 1].end)
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	for (i = 1; i < n; i++){ //对于和前面的活动相容的活动输出
		if (a[i].start > a[k].end){
			k = i;
			printf("活动%d:开始%d\t结束%d\n", i, a[i].start, a[i].end);
		}
	}

	
	return 0;
}