#include <iostream>
using namespace std;
const int maxn = 1010;
int A[maxn], tree[maxn], n;

void inOrder(int root, int& index) {
	if (root > n) {
		return;
	}
	inOrder(root*2, index);
	tree[root] = A[index++];
	inOrder(root*2+1, index);
}

int main() {
	cin>>n;
	for (int i = 0; i < n; i++)
		cin>>A[i];
	sort(A, A+n);
	int idx = 0;
	inOrder(1, idx);
	for (int i = 1; i <= n; i++) {
		cout<<tree[i];
		if (i < n)
			cout<<" ";
	}
	return 0;
}