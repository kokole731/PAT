#include <iostream>
#include <string>
using namespace std;
const int maxn = 22;

struct Node {
	string data;
	int left, right;
}node[maxn];

string helper(int root, int startPos) {
	if (root == -1)
		return "";
	if (node[root].left != -1 || node[root].right != -1) {
		string s = helper(node[root].left, startPos)+node[root].data+helper(node[root].right, startPos);
		if (root != startPos)
			s = '('+s+')';
		return s;
	}else {
		return node[root].data;
	}
}

int main() {
	int n;
	cin>>n;
	int leftChild, rightChild;
	string s;
	bool flag[maxn] = {0};
	for (int i = 1; i <= n; i++) {
		cin>>s>>leftChild>>rightChild;
		node[i].left = leftChild;
		node[i].right = rightChild;
		node[i].data = s;
		if (leftChild != -1)
			flag[leftChild] = true;
		if (rightChild != -1)
			flag[rightChild] = true;
	}
	int root = 0;
	for (int i = 1; i <= n; i++)
		if (flag[i] == false) {
			root = i;
			break;
		}
	cout<<helper(root, root);
	return 0;
}