#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 110;
bool flag[maxn][maxn] = {0};
int a, b;
bool cmp(int x, int y) {
	return x > y;
}

bool judge(int x, int y) {
	if (x < 0 || y < 0 || x >= a || y >= b || flag[x][y] == true)
		return false;
	return true;
}

int main () {
	int n;
	cin>>n;
	int A[n];
	for (int i = 0; i < n; i++)
		cin>>A[i];
	sort(A, A+n, cmp);
	int x = (int)sqrt(n), k;
	for (k = x; k >= 0; k--) {
		if (n % k == 0)
			break;
	}
	//行和列
	a = n/k, b = k;
	// int ans[maxn][maxn];
	int ans[a][b];
	//方向: 1,0 | 0,-1 | -1, 0 | 0, 1
	int A1[4] = {0, 1, 0, -1};
	int A2[4] = {1, 0, -1, 0};
	int dirction = 0, x0 = 0, x1 = 0;
	for (int i = 0; i < n; i++) {
		ans[x0][x1] = A[i];
		flag[x0][x1] = true;
		if (judge(x0+A1[dirction], x1+A2[dirction])) {
			x0 += A1[dirction];
			x1 += A2[dirction];
		}else {
			dirction = (dirction+1) % 4;
			x0 += A1[dirction];
			x1 += A2[dirction];
		}
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cout<<ans[i][j];
			if (j < b-1)
				cout<<" "; 
		}
		cout<<endl;
	}
	return 0;
}