#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

void postOrder(Node* T, vector<int>& vi) {
	if (T == NULL)
		return;
	postOrder(T->left, vi);
	postOrder(T->right, vi);
	vi.push_back(T->data);
}

void layerOrder(Node* T, vector<int>& vi) {
	queue<Node*> q;
	q.push(T);
	while (!q.empty()) {
		Node* front = q.front();
		vi.push_back(front->data);
		q.pop();
		if (front->left != NULL)
			q.push(front->left);
		if (front->right != NULL)
			q.push(front->right);
	}
}

Node* createNode (int* a, int* b, int len) {
	if (len <= 0)
		return NULL;
	Node* root = new Node;
	int* p = b;
	while (*p != *(a+len-1)) {
		p++;
	}
	root->data = *p;
	int leftCnt= p-b;
	int rightCnt = len-(p-b)-1;
	root->left = createNode(a, b, leftCnt);
	root->right = createNode(a+leftCnt, b+leftCnt+1, rightCnt);
	return root;
}

int main() {
	int n;
	cin>>n;
	int a[n], b[n];
	for (int i = 0; i < n; i++)
		cin>>a[i];
	for (int i = 0; i < n; i++)
		cin>>b[i];
	Node* T = createNode(a, b, n);
	vector<int> vi;
	layerOrder(T, vi);
	for (int i = 0; i < n; i++) {
		cout<<vi[i];
		if (i < n-1)
			cout<<" ";
	}
	return 0;
}