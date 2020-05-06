#include <iostream>
using namespace std;
const int maxn = 10010;
int father[maxn];
int bird[maxn];

int find(int x) {
	int a = x;
	while (x != father[x]) {
		x = father[x];
	}
	while (a != x) {
		father[a] = x;
		a = father[a];
	}
	return x;
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		father[x] = y;
	}
}

int main() {
	for (int i = 0; i < maxn; i++)
		father[i] = i;
	int N;
	cin>>N;
	for (int i = 0; i < N; i++) {
		int k, idx, pre;
		cin>>k;
		for (int j = 0; j < k; j++) {
			cin>>idx;
			bird[idx] = 1;
			if (j == 0) {
				pre = idx;
			}else {
				Union(pre, idx);
			}
		}
	}
	int treeSum = 0, birdSum = 0;
	for (int i = 1; i < maxn; i++) {
		birdSum += bird[i];
		if (find(i) == i && bird[i] == 1)
			treeSum++;
	}
	cout<<treeSum<<" "<<birdSum<<endl;
	int k;
	cin>>k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin>>a>>b;
		if (find(a) == find(b))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}