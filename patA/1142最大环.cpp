#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 210;
int adj[maxn][maxn] = {0};
bool flag[maxn] = {0};
int n, m;

//判断是否能够构成环（每两个节点之间都相连）
bool isClique() {
	for (int i = 1; i <= n; i++) {
		if (flag[i]) {
			for (int j = 1; j <= n; j++) {
				if (flag[j] && adj[i][j] == 0 && i != j)
					return false;
			}
		}
	}
	return true;
}

bool isMaximal() {
	for (int i = 1; i <= n; i++) {
		bool verdict = true;
		if (!flag[i]) {
			//检查与所有标记节点的连接情况
			for (int j = 1; j <= n; j++) {
				if (flag[j] && i != j) {
					verdict &= adj[i][j] == 1;
				}
			}
			//如果全部能连接上，说明不是最大
			if (verdict)
				return false;
		}
	}
	//如果没有符合要求的节点，则为最大环
	return true;
}

int main() {
	int k, left, right;
	cin>>n>>m;
	for (int i = 0; i < m; i++) {
		cin>>left>>right;
		adj[left][right] = 1;
		adj[right][left] = 1;
	}
	cin>>k;
	int num, vertex;
	for (int i = 0; i < k; i++) {
		fill(flag, flag+maxn, 0);
		cin>>num;
		for (int j = 0; j < num; j++) {
			cin>>vertex;
			flag[vertex] = true;
		}
		if (!isClique() && num > 1) {
			cout<<"Not a Clique"<<endl;
		}else {
			if (isMaximal()) {
				cout<<"Yes"<<endl;
			}else {
				cout<<"Not Maximal"<<endl;
			}
		}
	}
	return 0;
}