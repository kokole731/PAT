#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100010;
vector<int> tree[maxn];
int depthArr[maxn] = {0};

void DFS(int root, int depth) {
	if (tree[root].size() == 0) {
		depthArr[depth] += 1;
	}
	for (int i = 0; i < tree[root].size(); i++) {
		DFS(tree[root][i], depth+1);
	}
}

int main() {
	int n;
	double p, r;
	scanf("%d%lf%lf", &n, &p, &r);
	for (int i = 0; i < n; i++) {
		int k, child;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &child);
			tree[i].push_back(child);
		}
	}
	DFS(0, 0);
	int d = 0, sum = 0;
	for (int i = 0; i < maxn; i++) {
		if (depthArr[i] > 0) {
			d = i;
			sum = depthArr[i];
			break;
		}
	}
	double ans = p;
	for (int i = 0; i < d; i++) {
		ans *= (1+r/100);
	}
	printf("%.4f %d", ans, sum);
	return 0;
}