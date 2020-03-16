#include<iostream>
#define MAX 10000

using namespace std;

int t[MAX];
int x,n;

//test : n=10 
//1 5 20 45 55 56 57 78 99 134

void seqSearch(int key) {
	int i;
	for (i = 0; i < n; ++i) {
		if (t[i] == key) {
			cout << "查找成功！下标为：" << i+1 << endl;
			break;
		}			
	}
	if (i == n)
		cout << "未在数列中查找到"<< key << endl;

}

void binarySearch(int key) {
	int left,middle,right;
	left = 0;
	right = n - 1;
	
	while ( left <= right) {
		middle = (left+right) / 2;
		if (key == t[middle]) {
			cout << "查找成功！下标为：" << middle + 1 << endl;
			break;
		}
		else if (key < t[middle])
			right = middle - 1;
		else
			left = middle + 1;

	}
	if (left > right)
		cout << "未在数列中查找到" << key << endl;
}

int main() {
	
	cout << "请输入数列的数量：";
	cin >> n;
	
	cout << "请输入数列：" << endl;
	for (int i = 0; i < n; ++i)
		cin >> t[i];
	
	cout << "请输入需要查找的数：";
	cin >> x;

	seqSearch(x);
	binarySearch(x);
	
	return 0;
}



