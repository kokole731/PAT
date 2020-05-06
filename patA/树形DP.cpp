#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 6010;
int A[maxn];
vector<int> tree[maxn];

int DFS(int root, bool choice) {
	if (choice) {
		int sum = A[root];
		for (int i = 0; i < tree[root].size(); i++) {
			int child = tree[root][i];
			sum += DFS(child, false);
		}
		return sum;
	}else {
		int sum = 0;
		for (int i = 0; i < tree[root].size(); i++) {
			int child = tree[root][i];
			sum += max(DFS(child, true), DFS(child, false));
		}
		return sum;
	}
}

int DP(int root) {
	
}

int main() {
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++) {
		cin>>A[i];
	}
	bool flag[maxn] = {0};
	int par, child, root = 0;
	for (int i = 0; i < n-1; i++) {
		cin>>child>>par;
		flag[child] = true;
		tree[par].push_back(child);
	}
	for (int i = 1; i <= n; i++) {
		if (!flag[i]) {
			root = i;
			break;
		}
	}
	cout<<max(DFS(root, true), DFS(root, false));
	return 0;
}