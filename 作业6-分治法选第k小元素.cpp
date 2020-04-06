#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 7

int split(int a[], int low, int high) {//分组
	int part_element = a[low];
	for (;;) {
		while (low < high && part_element <= a[high])
			high--;
		if (low >= high) 
			break;
		a[low++] = a[high];

		while (low < high && a[low] <= part_element)
			low++;

		if (low >= high) 
			break;
		
		a[high--] = a[low];
	}

	a[high] = part_element;
	return high;
}

int selectmink(int a[], int low, int high, int k){ //选择第k小的数
	int middle;
	for (;;) {
		middle = split(a, low, high);
		if (middle == k)
			return a[k];
		else if (middle < k)
			low = middle + 1;
		else 
			high = middle - 1;
	}
}


int main(){
	int k, r;
	int a[N] = { 3,6,1,7,2,0,8 };

	printf("datas:  3 6 1 7 2 0 8 \n");

	printf("please input the k:");
	scanf_s("%d", &k);
	if (k >= 0 && k <= N - 1) {
		r = selectmink(a, 0, N - 1, k);
		printf("result=%d\n", r);
	}
	else
		printf("input error: k=%d\n", k);

	return 0;
}

