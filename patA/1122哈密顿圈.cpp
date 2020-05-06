#include <iostream>
#include <climits>
#include <string>
#include <vector>
using namespace std;
const int INF = INT_MAX;
const int maxn = 210;
int adj[maxn][maxn];
int cnt[maxn] = {0}, n, m;

bool judge(vector<int> vi) {
	int len = vi.size();
	if (len != n+1 || vi[0] != vi[len-1])
		return false;
	fill(cnt, cnt+maxn, 0);
	for (int i = 0; i < len-1; i++) {
		if (cnt[vi[i]] > 0||adj[vi[i]][vi[i+1]] == INF)
			return false;
		cnt[vi[i]] = 1;
	}
	return true;
}

int main() {
	fill(adj[0], adj[0]+maxn*maxn, INF);
	cin>>n>>m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin>>a>>b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	int k, num, vertex;
	cin>>k;
	string ans[k];
	for (int i = 0; i < k; i++) {
		cin>>num;
		vector<int> tmp;
		for (int j = 0; j < num; j++) {
			cin>>vertex;
			tmp.push_back(vertex);
			ans[i] = judge(tmp) ? "YES": "NO";
		}	
	}
	for (int i = 0; i < k; i++)
		cout<<ans[i]<<endl;
	return 0;
}