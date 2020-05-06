#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 10010;
#define INF 0x3fffffff
int cmpCount = 0;
bool flag[maxn] = {0};
vector<int> adj[maxn];
int dis[maxn][maxn];

void DFS(int s) {
	flag[s] = true;
	for (int i = 0; i < adj[s].size(); i++) {
		//s邻接的点
		int k = adj[s][i];
		if (!flag[k])
			DFS(k);
	}
}

void Dij(int start) {
	//以start出发到各节点的距离
	int p[maxn];
	//初始化距离为INF，自身节点距离为0
	fill(p, p+maxn, INF);
	p[start] = 0;
	//访问数组，存储已经完成距离计算的节点
	bool vis[maxn] = {0};
	for (int i = 0; i < maxn; i++) {
		//找出本次距离数组最小的节点
		int v = -1;
		int min_dict = INF;
		for (int j = 0; j < maxn; j++) {
			if (!vis[j] && p[j] < min_dict) {
				v = j;
				min_dict = p[j];
			}
		}
		if (v == -1)
			break;
		vis[v] = true;
		//更新与v邻接的节点距离
		for (int j = 0; j < adj[v].size(); j++) {
			// 节点v相邻的节点
			int k = adj[v][j];
			if (p[v] + 1 < p[k] && !vis[k])
				p[k] = p[v]+1;
		}
	}
	for (int i = 0; i < maxn; i++) {
		dis[start][i] = p[i];
	}
}

int main() {
	int n, a, b;
	cin>>n;
	for (int i = 0; i < n - 1; i++) {
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!flag[i]) {
			DFS(i);
			cmpCount++;
		}
	}
	if (cmpCount > 1) {
		cout<<"Error: "<<cmpCount<<" components";
	}else {
		for (int i = 1; i <= n; i++) {
			Dij(i);
		}
		int maxNum = -1;
		set<int> si[n+1];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dis[i][j] >= maxNum) {
					maxNum = dis[i][j];
					si[maxNum].insert(i);
					si[maxNum].insert(j);
				}
			}
		}
		for (set<int>::iterator it = si[maxNum].begin(); it != si[maxNum].end(); it++) {
			cout<<*it<<endl;
		}
	}
	return  0;
}