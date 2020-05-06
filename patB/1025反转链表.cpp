#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;
// 00100 6 2
// 00000 4 99999
// 00100 1 12309
// 68237 6 -1
// 33218 3 00000
// 99999 5 68237
// 12309 2 33218


struct Node {
	int data;
	int address;
	int next;
	int rank;
}node[maxn];

bool cmp(Node a, Node b) {
	return a.rank < b.rank;
}

int main() {
	for (int i = 0; i < maxn; i++){
		node[i].rank = maxn;
	}
	int start, n, k;
	// cin>>start>>n>>k;
	scanf("%d%d%d", &start, &n, &k);
	int add, data, next;
	for (int i = 0; i < n; i++) {
		// cin>>add>>data>>next;
		scanf("%d%d%d", &add, &data, &next);
		node[add].address = add;
		node[add].next = next;
		node[add].data = data;
	}
	int q = start, cnt = 0;
	while (q != -1) {
		node[q].rank = cnt++;
		q = node[q].next;
	}
	sort(node, node+maxn, cmp);
	int time = n / k;
	for (int i = 0; i < time; i++) {
		reverse(node+i*k, node+(i+1)*k);
	}
	for (int i = 0; i < cnt; i++) {
		if (i == cnt-1)
			node[i].next = -1;
		else {
			node[i].next = node[i+1].address;
		}
	}
	for (int i = 0; i < cnt; i++) {
		if (node[i].next == -1) {
			printf("%05d %d -1\n", node[i].address, node[i].data);
		}else {
			printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);
		}
	}
	return 0;
}