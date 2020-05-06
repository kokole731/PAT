#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

void PostOrder(Node* root, vector<int>& vi) {
	if (root == NULL)
		return;
	PostOrder(root->left, vi);
	PostOrder(root->right, vi);
	vi.push_back(root->data);
}

Node* create(int* a, int* b, int len) {
	if (len <= 0)
		return NULL;
	int rootData = *a;
	int* p = b;
	while (*p != rootData)
		p++;
	int leftNum = p-b;
	int rightNum = len-leftNum-1;
	Node* root = new Node;
	root->data = rootData;
	root->left = create(a+1, b, leftNum);
	root->right = create(a+leftNum+1, p+1, rightNum);
	return root;
}

int main() {
	int n;
	cin>>n;
	int A[n];
	int B[n];
	string instr;
	int num;
	stack<int> st;
	int m = 0, t = 0;
	for (int i = 0; i < 2*n; i++) {
		cin>>instr;
		if (instr == "Push") {
			cin>>num;
			st.push(num);
			A[m++] = num;
		}else {
			B[t++] = st.top();
			st.pop();
		}
	}
	Node* T = create(A, B, n);
	vector<int> ans;
	PostOrder(T, ans);
	for (int i = 0; i < n; i++) {
		cout<<ans[i];
		if (i < n - 1)
			cout<<" ";
	}
	return 0;
}