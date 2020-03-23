#include<iostream>
#include<iomanip>
using namespace std;

void mergeSort(int arr[], int left, int middle, int right) {
	int k, begin1, begin2, end1, end2;
	begin1 = left;
	end1 = middle;
	begin2 = middle + 1;
	end2 = right;
	
	int *temp = (int *)malloc((right - left + 1) * sizeof(int));

	for (k = 0; begin1 <= end1 && begin2 <= end2; k++) {//自小到大排序
		if (arr[begin1] <= arr[begin2])
			temp[k] = arr[begin1++];
		else
			temp[k] = arr[begin2++];
	}
	if (begin1 <= end1) //左边剩下的  
		memcpy(temp + k, arr + begin1, (end1 - begin1 + 1) * sizeof(int));
	else //右边剩下的  
		memcpy(temp + k, arr + begin2, (end2 - begin2 + 1) * sizeof(int));
	memcpy(arr + left, temp, (right - left + 1) * sizeof(int)); //排序后复制到原数组  
	free(temp);   
}

void merge(int arr[],int left,int right) {
	int middle = (left + right) / 2;
	if (left < right) {
		merge(arr, left, middle);
		merge(arr, middle + 1, right);
		mergeSort(arr,left,middle,right);
	}
}

int main() {
	int arr[10] = { 0,3,5,1,6,4,8,9,2,7 };//数组范围[1,n]，所以arr[0]无意义
	int len = 9;
	

	cout << "排序前："<< endl;
	for (int i = 1; i <= len; ++i) {
		cout << arr[i] << " ";
	}
	merge(arr,1,len);

	cout << "\n\n排序后：" << endl;
	for (int i = 1; i <= len; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}