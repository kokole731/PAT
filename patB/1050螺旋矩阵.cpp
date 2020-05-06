#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[4] = {0, 1, 0, -1};
int b[4] = {1, 0, -1, 0};

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int N;
	cin>>N;
	int A[N];
	for (int i = 0; i < N; i++) {
		cin>>A[i];
	}
	int m, n;
	for (int i = (int)sqrt(N); i <= N; i++) {
		if (N % i == 0) {
			m = i;
			n = N / i;
			break;
		}
	}
	if (m < n)
		swap(m, n);
	sort(A, A+N, cmp);
	int B[m+1][n+1];
	bool flag[m+1][n+1];
	for (int u = 1; u <= m; u++)
		for (int v = 1; v <= n; v++)
			flag[u][v] = false;
	int direction = 0;
	int j = 1, k = 1;
	for (int i = 0; i < N; i++) {
		int data = A[i];
		B[j][k] = data;
		flag[j][k] = true;
		j += a[direction];
		k += b[direction];
		if (j < 1 || k < 1 || j > m || k > n ||flag[j][k]) {
			j -= a[direction];
			k -= b[direction];
			direction = (direction+1) % 4;
			j += a[direction];
			k += b[direction];
		}
	}
	for (int u = 1; u <= m; u++) {
		for (int v = 1; v <= n; v++){
			cout<<B[u][v];
			if (v < n)
				cout<<" ";
		}
		cout<<"\n";
	}
	return 0;
}