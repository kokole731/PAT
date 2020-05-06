#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 110;
int tree[maxn][2];
int val[maxn];

void preOrder(int root, int& idx, int A[]) {
	if (root == -1) {
		return;
	}
	preOrder(tree[root][0], idx, A);
	val[root] = A[idx++];
	preOrder(tree[root][1], idx, A);
}

vector<int> layerOrder(int root) {
	queue<int> q;
	q.push(0);
	vector<int> ans;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		ans.push_back(val[front]);
		if (tree[front][0] != -1) {
			q.push(tree[front][0]);
		}
		if (tree[front][1] != -1) {
			q.push(tree[front][1]);
		}
	}
	return ans;
}

int main() {
	int n, leftChild, rightChild;
	cin>>n;
	for (int i = 0; i < n; i++) {
		cin>>leftChild>>rightChild;
		tree[i][0] = leftChild;
		tree[i][1] = rightChild;
	}
	int A[n];
	for (int i = 0; i < n; i++) {
		cin>>A[i];
	}
	sort(A, A+n);
	int idx = 0;
	preOrder(0, idx, A);
	vector<int> ans = layerOrder(0);
	for (int i = 0; i < n; i++) {
		cout<<ans[i];
		if (i < n-1)
			cout<<" ";
	}
	return 0;
}