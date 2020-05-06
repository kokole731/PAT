#include <iostream>
#include <vector>
using namespace std;
bool flag = true;
struct Node {
	int data;
	Node *left, *right;
};

Node* createtree(int* pre, int* post, int len) {
	if (pre == NULL || post == NULL || len <= 0) {
		return NULL;
	}
	Node* root = new Node;
	root->data = *pre;
	if (len == 1)
		return root;
	int *p = pre+1, *q = post;
	while (*q != *p) {
		q++;
	}
	int leftCnt = q-post+1;
	int rightCnt = len-1-leftCnt;
	root->left = createtree(p, post, leftCnt);
	root->right = createtree(p+leftCnt, post+leftCnt, rightCnt);
	return root;
}

void inOrder(Node* root, vector<int>& vi) {
	if (root == NULL)
		return;
	inOrder(root->left, vi);
	if ((root->left==NULL&&root->right!=NULL)||(root->left!=NULL&&root->right==NULL)) {
		flag = false;
	}
	vi.push_back(root->data);
	inOrder(root->right, vi);
}

int main() {
	int n;
	cin>>n;
	int pre[n], post[n];
	for (int i = 0; i < n; i++)
		cin>>pre[i];
	for (int i = 0; i < n; i++)
		cin>>post[i];
	Node* tree = createtree(pre, post, n);
	vector<int> ans;
	inOrder(tree, ans);
	if (flag)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	cout<<ans[0];
	for (int i = 1; i < ans.size(); i++) {
		cout<<" "<<ans[i];
	}
	
	return 0;
}