#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e4+10;
int N, M, K;
vector<int> adj[maxn];
bool flag[maxn] = {0};

struct Edge {
	int a, b;
}edge[maxn];

bool judge() {
	bool verdict;
	for (int i = 0; i < M; i++) {
		verdict = flag[edge[i].a] || flag[edge[i].b];
		if (verdict == false)
			return false;
	}
	return true;
}

int main() {
	cin>>N>>M;
	int left, right;
	for (int i = 0; i < M; i++) {
		cin>>left>>right;
		edge[i].a = left;
		edge[i].b = right;
	}
	cin>>K;
	int num, vertex;
	vector<string> ans;
	for (int i = 0; i < K; i++) {
		cin>>num;
		fill(flag, flag+maxn, 0);
		for (int j = 0; j < num; j++) {
			cin>>vertex;
			flag[vertex] = true;
		}
		ans.push_back(judge()? "Yes": "No");
	}
	for (int i = 0; i < ans.size(); i++) {
		cout<<ans[i]<<endl;
	}
	return 0;
}

