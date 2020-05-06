#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node {
	string data;
	Node *left, *right;
};

Node* createNode(string val) {
	Node* root = new Node;
	root->data = val;
	root->left = NULL;
	root->right = NULL;
	return root;
}

void postOrder(Node* T, vector<string> &vi) {
	if (T == NULL)
		return;
	postOrder(T->left, vi);
	postOrder(T->right, vi);
	vi.push_back(T->data);
}

int main() {
	Node* T = createNode("1");
	T->left = createNode("2");
	cout<<T->left->data;
	return 0;
}