#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int maxn = 10010;
vector<int> adj[maxn];
int vertex[maxn];
int n, m, k;

bool judge() {
	int size;
	for (int i = 0; i < n; i++) {
		size = adj[i].size();
		for (int j = 0; j < size; j++) {
			if (vertex[i] == vertex[adj[i][j]]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	cin>>n>>m;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cin>>k;
	for (int i = 0; i < k; i++) {
		int t;
		set<int> st;
		for (int j = 0; j < n; j++) {
			cin>>t;
			vertex[j] = t;
			st.insert(t);
		}
		if(judge()) {
			cout<<st.size()<<"-coloring"<<endl;
		}else {
			cout<<"No"<<endl;
		}
	}
	return 0;
}