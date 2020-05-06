#include <iostream>
using namespace std;
const int maxn = 1000;
const int INF = 1000000000;
int n, m;
int adj[maxn][maxn];

int f() {
	int d[maxn], ans=0;
	fill(d, d+maxn, INF);
	bool vis[maxn] = {0};
	d[0] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, minD = INF;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && d[j] < minD) {
				minD = d[j];
				u = j;
			}
		}
		if (u == -1)
			break;
		vis[u] = true;
		ans+=d[u];
		for (int j = 0; j < n; j++) {
			if (!vis[j] && adj[u][j] != INF && adj[u][j] < d[j]) {
				d[j] = adj[u][j];
			}
		}
	}
	return ans;
}

int main() {
	fill(adj[0], adj[0]+maxn*maxn, INF);
	cin>>n>>m;
	int a, b, p;
	for (int i = 0; i < m; i++) {
		cin>>a>>b>>p;
		adj[a][b] = adj[b][a] = p;
	}
	cout<<f();
	return 0;
}