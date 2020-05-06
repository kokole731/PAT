#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int INF = INT_MAX;
int adj[maxn][maxn];
int cost[maxn][maxn];
int N, M, S, D;
vector<int> path[maxn];

void f(int start) {
	int d[maxn];
	fill(d, d+maxn, INF);
	bool flag[maxn] = {0};
	d[start] = 0;
	for (int i = 0; i < N; i++) {
		int u = -1, minD = INF;
		for (int j = 0; j < N; j++) {
			if (d[j] < minD && !flag[j]) {
				u = j;
				minD = d[j];
			}
		}
		if (u == -1)
			break;
		flag[u] = true;
		for (int j = 0; j < N; j++) {
			if (flag[j])
				continue;
			if (adj[u][j] != INF && adj[u][j]+d[u] < d[j]) {
				d[j] = adj[u][j] + d[u];
				path[j].clear();
				path[j].push_back(u);
			}else if (adj[u][j] != INF && adj[u][j]+d[u] == d[j]) {
				path[j].push_back(u);
			}
		}
	}
}
vector<int> ans;
int minCost = INF;
int minDis = 0;
void DFS(int end, int start, vector<int> vi, int sum, int dis) {
	if (start == end) {
		if (sum < minCost) {
			minCost = sum;
			ans = vi;
		}
		minDis = dis;
		return;
	}
	int k;
	for (int i = 0; i < path[start].size(); i++) {
		k = path[start][i];
		vi.push_back(k);
		DFS(end, k, vi, sum + cost[start][k], dis+adj[start][k]);
		vi.pop_back();
	}
}

int main() {
	fill(adj[0], adj[0]+maxn*maxn, INF);
	cin>>N>>M>>S>>D;
	int left, right, distance, costP;
	for (int i = 0; i < M; i++) {
		cin>>left>>right>>distance>>costP;
		adj[left][right] = distance;
		adj[right][left] = distance;
		cost[left][right] = costP;
		cost[right][left] = costP;
	}
	f(S);
	vector<int> vi;
	vi.push_back(D);
	DFS(S, D, vi, 0, 0);
	for (int i = ans.size()-1; i >= 0; i--)
		cout<<ans[i]<<" ";
	cout<<minDis<<" "<<minCost;
	return 0;
}