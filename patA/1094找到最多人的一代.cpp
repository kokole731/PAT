#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 110;
int n, m;
vector<int> tree[maxn];
int layer[maxn] = {0};

void BFS(int root) {
	queue<int> q;
	q.push(root);
	layer[root] = 1;
	while (!q.empty()) {
		int front = q.front(), num = tree[front].size();
		q.pop();
		for (int i = 0; i < num; i++) {
			int child = tree[front][i];
			q.push(child);
			layer[child] = layer[front]+1;
		}
	}
}

int main() {
	cin>>n>>m;
	int parId, k, chId;
	for (int i = 0; i < m; i++) {
		cin>>parId>>k;
		for (int j = 0; j < k; j++) {
			cin>>chId;
			tree[parId].push_back(chId);
		}
	}
	BFS(1);
	int cnt[maxn] = {0};
	for (int i = 1; i <= n; i++) {
		cnt[layer[i]]++;
	}
	int maxNum = 1, maxLayer = 1;
	for (int i = 1; i < maxn; i++) {
		if (cnt[i] > maxNum) {
			maxNum = cnt[i];
			maxLayer = i;
		}
	}
	cout<<maxNum<<" "<<maxLayer;
	return 0;
}