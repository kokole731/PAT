#include <iostream>
#include <algorithm>
using namespace std;

int n;

bool checkSame(int A[], int B[]) {
	for (int i = 0; i < n; i++) {
		if (A[i] != B[i])
			return false;
	}
	return true;
}

void mergeSort(int A[], int k) {
	int i;
	for (i = 0; i <= n-k; i += k) {
		sort(A+i, A+i+k);
	}
	if (i < n-k)
		sort(A+i+k, A+n);
}

int main() {
	cin>>n;
	int A[n], B[n];
	for (int i = 0; i < n; i++) {
		cin>>A[i];
	}
	for (int i = 0; i < n; i++)
		cin>>B[i];
	bool flag = true;
	int k;
	for (k = 1; k < n; k++) {
		if (B[k] < B[k-1]) 
			break;
	}
	int m = k, x = B[k];
	for (; k < n; k++) {
		if (A[k] != B[k])
			flag = false;
	}
	if (flag == true) {
		cout<<"Insertion Sort"<<endl;
		for (int j = m-1; j >= 0; j--) {
			if (B[j] > B[j+1]) {
				int tmp = B[j];
				B[j] = B[j+1];
				B[j+1] = tmp;
			}
		}
	}else {
		cout<<"Merge Sort"<<endl;
		int q = 1;
		while (!checkSame(A, B)) {
			q = q * 2;
			mergeSort(A, q);
		}
		mergeSort(B, q * 2);
	}
	for (int i = 0; i < n; i++) {
		cout<<B[i];
		if (i < n-1)
			cout<<" ";
	}
	return 0;
}
