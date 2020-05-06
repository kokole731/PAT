#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 50;
int n;
vector<int> adj[maxn];
int inDegree[maxn];

bool f() {
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}
	int num = 0;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i = 0; i < adj[front].size(); i++) {
			inDegree[adj[front][i]]--;
			if (inDegree[adj[front][i]] == 0)
				q.push(adj[front][i]);
		}
		adj[front].clear();
		num++;
	}
	return num == n;
}

int main() {
	return 0;
}