#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
int n, k;
struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* createLayerTree() {
	queue<Node*> q;
	Node* root = new Node();
	q.push(root);
	int size = 1;
	while (!q.empty()) {
		Node* front = q.front();
		q.pop();
		if (size == n)
			break;
		front->left = new Node();
		size++;
		q.push(front->left);
		if (size == n)
			break;
		front->right = new Node();
		size++;
		q.push(front->right);
	}
	return root;
}

vector<int> layerOrder(Node* root) {
	queue<Node*> q;
	vector<int> vi;
	q.push(root);
	while (!q.empty()) {
		Node* front = q.front();
		q.pop();
		vi.push_back(front->data);
		if (front->left != NULL)
			q.push(front->left);
		if (front->right != NULL)
			q.push(front->right);
	}
	return vi;
}

void inOrder(int A[], int& index, Node* root) {
	if (root == NULL || index >= n)
		return;
	inOrder(A, index, root->left);
	root->data = A[index++];
	inOrder(A, index, root->right);
}

int main() {
	cin>>n;
	int A[n];
	for (int i = 0; i < n; i++)
		cin>>A[i];
	Node* root = createLayerTree();
	int idx = 0;
	sort(A, A+n);
	inOrder(A, idx, root);
	vector<int> ans = layerOrder(root);
	for (int i = 0; i < ans.size(); i++) {
		cout<<ans[i];
		if (i < ans.size()-1)
			cout<<" ";
	}
	return 0;
}