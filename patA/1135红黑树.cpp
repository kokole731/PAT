#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int maxn = 31;

struct Node {
	bool isBlack;
	int data;
	Node *left, *right;
};

void createTree(Node*& root, int data) {
	if (root == NULL) {
		root = new Node();
		root->data = abs(data);
		root->isBlack = data > 0;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	if (abs(data) < root->data)
		createTree(root->left, data);
	else
		createTree(root->right, data);
}

int depth(Node* root) {
	if (root == NULL)
		return 0;
	return max(depth(root->left), depth(root->right))+1;
}

bool isBalanced(Node* root) {
	if (root == NULL)
		return true;
	bool flag = abs(depth(root->left)-depth(root->right)) <= 1;
	return flag && isBalanced(root->left) && isBalanced(root->right);
}

//检查红色节点的字节点是否都为黑节点
bool checkChildBlack(Node* root) {
	if (root == NULL)
		return true;
	if (root->isBlack) {
		return checkChildBlack(root->left) && checkChildBlack(root->right);
	}else {
		bool flag = true;
		if (root->left != NULL)
			flag &= root->left->isBlack;
		if (root->right != NULL)
			flag &= root->right->isBlack;
		return flag && checkChildBlack(root->left) && checkChildBlack(root->right);
	}
}

bool helper(Node* root, int sum, int& ansNum, int& ans) {
	if (root == NULL) {
		if (ansNum == 0) {
			ansNum++;
			ans = sum;
			return true;
		}else {
			ansNum++;
			return ans == sum;
		}
	}
	if (root->isBlack)
		sum++;
	return helper(root->left, sum, ansNum, ans) && helper(root->right, sum, ansNum, ans);
}

bool checkNumFlag = true;
//检查路径上的黑色节点数量
void checkNum (Node* root) {
	if (root == NULL)
		return;
	checkNum(root->left);
	int ansNum = 0, ans = 0;
	checkNumFlag &= helper(root, 0, ansNum, ans);
	checkNum(root->right);
}

int main() {
	int K, N, data;
	cin>>K;
	vector<string> ans;
	for (int i = 0; i < K; i++) {
		cin>>N;
		// cout<<i<<endl;
		checkNumFlag = true;
		Node* tree = NULL;
		for (int j = 0; j < N; j++) {
			cin>>data;
			createTree(tree, data);
		}
		bool flag = tree->isBlack;
		// flag &= isBalanced(tree);
		// cout<<"是否平衡："<<isBalanced(tree)<<endl;
		flag &= checkChildBlack(tree);
		// cout<<"孩子黑节点是否满足："<<checkChildBlack(tree)<<endl;
		checkNum(tree);
		flag &= checkNumFlag;
		// cout<<"路径黑色节点个数："<<checkNum(tree, 0)<<endl;
		ans.push_back(flag? "Yes": "No");
	}
	for (int i = 0; i < ans.size(); i++)
		cout<<ans[i]<<endl;
	return 0;
}