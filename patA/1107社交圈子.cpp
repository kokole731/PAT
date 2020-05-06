#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1010;
//father数组代表每个人的团体
int father[maxn], hobby[maxn] = {0};

//团体初始化，每个人起初自己一个团体
void init() {
	for (int i = 0; i < maxn; i++){
		father[i] = i;
	}
}

//寻找团体
int find(int x) {
	while (father[x] != x) {
		x = father[x];
	}
	return x;
}

//人与人之间联合
void union_(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) {
		father[fy] = fx;
	}
}

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	int n;
	scanf("%d", &n);
	//初始化并查集
	init();
	for (int i = 1; i <= n; i++) {
		int k, h;
		scanf("%d:", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &h);
			//如果该爱好还没人认领
			if (hobby[h] == 0) {
				hobby[h] = i;
			}
			//这个人与有这个爱好的团体联合
			union_(i, hobby[h]);
		}
	}
	int root[maxn] = {0}, ans = 0;
	for (int i = 1; i <= n; i++) {
		root[find(i)]++;
	}
	for (int i = 1; i <= n; i++) {
		if (root[i] != 0)
			ans++;
	}
	cout<<ans<<endl;
	sort(root+1, root+n+1, cmp);
	cout<<root[1];
	int j = 2;
	while (root[j] != 0) {
		cout<<" "<<root[j++];
	}
	cout<<find(2);
	return 0;
}