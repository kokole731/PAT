#include <iostream>
using namespace std;

int r[101][101];
bool flag[101][101];

int dp(int n) {
	int f[n+1][n+1];
	for (int i = 0; i <= n; i++)
		f[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			f[i][j] = f[i-1][j];
			if (j >= i)
				f[i][j] += f[i][j-i];
		}
	}
	return f[n][n];
}

int rec(int n, int k) {
	if (flag[n][k])
		return r[n][k];
	if (k == 1||k == n) {
		return 1;
	}
	if (n < k)
		return 0;
	r[n][k] = rec(n-1, k-1) + rec(n-k, k);
	flag[n][k] = true;
	return r[n][k];
}

int main() {
	int n;
	cin>>n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += rec(n, i);
	}
	cout<<ans;
}