#include <iostream>
using namespace std;
const int maxn = 1010;
int ans[maxn] = {0};

struct Node {
	int data;
	Node *left, *right;
};

void insert(int data, Node*& root) {
	if (root == NULL) {
		root = new Node;
		root->data = data;
		return;
	}
	if (data <= root->data)
		insert(data, root->left);
	else
		insert(data, root->right);
}

void DFS(Node* root, int depth) {
	if (root == NULL)
		return;
	ans[depth]++;
	DFS(root->left, depth+1);
	DFS(root->right, depth+1);
}

int main() {
	int n, n1, n2, k;
	cin>>n;
	Node* root = NULL;
	for (int i = 0; i < n; i++) {
		cin>>k;
		insert(k, root);
	}
	if (n == 1) {
		cout<<"1 + 0 = 1";
		return 0;
	}
	DFS(root, 0);
	int res[2], idx = 0;
	for (int i = maxn-1; i >= 0; i--) {
		if (idx < 2 && ans[i] > 0) {
			res[idx++] = ans[i];
		}
		if (idx == 2)
			break;
	}
	cout<<res[0]<<" + "<<res[1]<<" = "<<res[0]+res[1];
	return 0;
}