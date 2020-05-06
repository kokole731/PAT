#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool flag[1001] = {0};

struct Node {
	// a是指数，b是系数
	int a;
	double b;
}tmp;

bool cmp(Node x, Node y) {
	return x.a > y.a;
}

int main() {
	Node X[11], Y[11];
	int n1, n2;
	scanf("%d", &n1);
	int a;
	double b;
	for (int i = 0; i < n1; i++) {
		scanf("%d %lf", &a, &b);
		X[i].a = a;
		X[i].b = b;
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++) {
		scanf("%d %lf", &a, &b);
		Y[i].a = a;
		Y[i].b = b;
	}
	vector<Node> ans;
	//合并相同指数的项
	for (int i = 0; i < n1; i++) {
		//x的指数项
		a = X[i].a;
		b = X[i].b;
		for (int j = 0; j < n2; j++) {
			if (Y[j].a == a) {
				b += Y[j].b;
				break;
			}
		}
		flag[a] = true;
		tmp.a = a;
		tmp.b = b;
		ans.push_back(tmp);
	}
	for (int i = 0; i < n2; i++) {
		if (!flag[Y[i].a]) {
			ans.push_back(Y[i]);
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	int count = 0;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i].b != 0)
			count++;
	}
	printf("%d", count);
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i].b != 0) {
			printf(" %d %.1f", ans[i].a, ans[i].b);
		}
	}
	return 0;
}