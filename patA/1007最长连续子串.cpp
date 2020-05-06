#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	int A[n];
	for (int i = 0; i < n; i++){
		cin>>A[i];
	}
	//第一个格子放最大值，第二个格子放起始idx
	int f[n][2];
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			f[i][0] = A[i];
			f[i][1] = 0;
		}else {
			if (f[i-1][0] < 0) {
				f[i][0] = A[i];
				f[i][1] = i;
			}else {
				f[i][0] = A[i] + f[i-1][0];
				f[i][1] = f[i-1][1];
			}
		}
	}
	int maxNum = -1, idxA = 0, idxB = 0;
	for (int i = 0; i < n; i++) {
		if (f[i][0] > maxNum) {
			maxNum = f[i][0];
			idxA = f[i][1];
			idxB = i;
		}
	}
	if (maxNum < 0) {
		cout<<"0 0 "<<n-1;
	}else {
		cout<<maxNum<<" "<<A[idxA]<<" "<<A[idxB];
	}
	return 0;
}