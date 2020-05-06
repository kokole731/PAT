#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 10010;
const int maxm = 110;
vector<int> ans[maxn][maxm];
int f[maxn][maxn];

void vectorEqual(vector<int>& a, vector<int> b) {
	for (int i = 0; i < b.size(); i++) {
		a.push_back(b[i]);
	}
}

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n, m;
	cin>>n>>m;
	int A[n+1];
	for (int i = 1; i <= n; i++) {
		cin>>A[i];
	}
	vector<int> emptyVi;
	emptyVi.clear();
	sort(A+1, A+n+1, cmp);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0) {
				ans[i][j] = emptyVi;
				f[i][j] = 0;
			}else {
				if(f[i-1][j-A[i]] == j-A[i]) {
					vectorEqual(ans[i][j], ans[i-1][j-A[i]]);
					ans[i][j].push_back(A[i]);
					f[i][j] = j;
				}else {
					f[i][j] = f[i-1][j];
					vectorEqual(ans[i][j], ans[i-1][j]);
				}
			}
		}
	}
	if (ans[n][m].size() > 0) {
		for (int i = ans[n][m].size()-1; i >= 0; i--) {
			cout<<ans[n][m][i];
			if (i != 0)
				cout<<" ";
		}
	}else {
		cout<<"No Solution";
	}
	return 0;
}