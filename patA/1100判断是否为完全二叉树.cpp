#include <iostream>
#include <vector>
using namespace std;
const int maxn = 64;
int node[maxn][2];
int complete[maxn];

void DFS(int root, int idx) {
	//若便利到空节点
	if (root == -1){
		complete[idx] = -1;
		return;
	}
	complete[idx] = root;
	DFS(node[root][0], idx*2);
	DFS(node[root][1], idx*2+1);
}

int main () {
	int n;
	cin>>n;
	string a, b;
	bool flag[maxn] = {0};
	for (int i = 0; i < n; i++) {
		cin>>a>>b;
		if(a == "-") {
			node[i][0] = -1;
		}else {
			node[i][0] = stoi(a);
			flag[stoi(a)] = true;
		}
		if (b == "-")
			node[i][1] = -1;
		else {
			node[i][1] = stoi(b);
			flag[stoi(b)] = true;
		}
	}
	int rootIdx = 1, root = 0;
	for (int i = 0; i < n; i++) {
		if (flag[i] == false) {
			root = i;
			break;
		}
	}
	DFS(root, rootIdx);
	int isCom = true;
	for (int i = 1; i <= n; i++) {
		if (complete[i] == -1) {
			isCom = false;
			break;
		}
	}
	if (isCom) {
		cout<<"YES "<<complete[n];
	}else {
		cout<<"NO "<<root;
	}
	return 0;
}