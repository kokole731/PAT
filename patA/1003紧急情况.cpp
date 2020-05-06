#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
#define INF INT_MAX
const int maxn = 510;
int adj[maxn][maxn];
int vertex[maxn];
vector<int> path[maxn];

void f(int startP) {
	int distance[maxn];
	bool vis[maxn] = {0};
	fill(distance, distance+maxn, INF);
	//先加入起始点
	distance[startP] = 0;
	for (int i = 0; i < maxn; i++) {
		int minID = -1, minDis = INF;
		for (int j = 0; j < maxn; j++) {
			if (!vis[j] && distance[j] < minDis) {
				minDis = distance[j];
				minID = j;
			}
		}
		if (minID == -1)
			break;
		vis[minID] = true;
		for (int j = 0; j < maxn; j++) {
			if (!vis[j] && adj[minID][j] != INF) {
				if (distance[minID]+adj[minID][j] < distance[j]) {
					distance[j] = distance[minID]+adj[minID][j];
					path[j].clear();
					path[j].push_back(minID);
				}else if (distance[minID]+adj[minID][j] == distance[j]) {
					path[j].push_back(minID);
				}
			}
		}
	}
}
int cnt = 0, maxNum = 0;
void DFS(int startP, int p, int sum) {
	if (p == startP) {
		sum += vertex[p];
		cnt++;
		if (sum > maxNum) {
			maxNum = sum;
		}
		return;
	}
	int n = path[p].size();
	for (int i = 0; i < n; i++) {
		DFS(startP, path[p][i], sum+vertex[p]);
	}
}

int main() {
	fill(adj[0], adj[0]+maxn*maxn, INF);
	int n, m, startP, endP;
	cin>>n>>m>>startP>>endP;
	for (int i = 0; i < n; i++)
		cin>>vertex[i];
	int a, b, p;
	for (int i = 0; i < m; i++) {
		cin>>a>>b>>p;
		adj[a][b] = p;
		adj[b][a] = p;
	}
	f(startP);
	DFS(startP, endP, 0);
	cout<<cnt<<" "<<maxNum;
	return 0;
}