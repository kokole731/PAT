#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;

int start, n, k;

struct Node {
	int address;
	int data;
	int next;
	int index;
}node[maxn];

int f(int data) {
	if (data < 0)
		return 0;
	else if (data>=0 && data<=k)
		return 1;
	else
		return 2;
}

bool cmp(Node a, Node b) {
	if (a.index == maxn || b.index == maxn) 
		return a.index < b.index;
	else {
		if (f(a.data) == f(b.data))
		return a.index < b.index;
	else 
		return f(a.data) < f(b.data);
	}
}

int main() {
	for (int i = 0; i < maxn; i++) 
		node[i].index = maxn;
	scanf("%d%d%d", &start, &n, &k);
	int add, d, next;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &add, &d, &next);
		node[add].address = add;
		node[add].data = d;
		node[add].next = next;
	}
	int cnt = 0;
	while (start != -1) {
		node[start].index = cnt++;
		start = node[start].next;
	}
	sort(node, node+maxn, cmp);
	for (int i = 0; i < cnt; i++) {
		if (i == cnt-1) {
			printf("%05d %d -1", node[i].address, node[i].data);
		}else {
			printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);
		}
	}
	return 0;
}