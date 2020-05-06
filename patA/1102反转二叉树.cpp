#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 11;
//0代表左子树，1代表右子树
int tree[maxn][2];

vector<int> layerOrder(int root) {
	queue<int> q;
	q.push(root);
	vector<int> vi;
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		vi.push_back(front);
		if (tree[front][1] != -1) {
			q.push(tree[front][1]);
		}
		if (tree[front][0] != -1) {
			q.push(tree[front][0]);
		}
	}
	return vi;
}

void inOrder(int root, vector<int>& vi) {
	if (root == -1) {
		return;
	}
	inOrder(tree[root][1], vi);
	vi.push_back(root);
	inOrder(tree[root][0], vi);
}

int main () {
	int n;
	char leftChild, rightChild;
	cin>>n;
	bool flag[maxn] = {0};
	for (int i = 0; i < n; i++) {
		cin>>leftChild>>rightChild;
		if (leftChild >= '0' && leftChild <= '9') {
			int num = leftChild-'0';
			tree[i][0] = num;
			flag[num] = true;
		}else {
			tree[i][0] = -1;
		}
		if (rightChild >= '0' && rightChild <= '9') {
			int num = rightChild - '0';
			tree[i][1] = num;
			flag[num] = true;
		}else {
			tree[i][1] = -1;
		}
	}
	//找到根结点
	int root;
	for (int i = 0; i < n; i++) {
		if (!flag[i]) {
			root = i;
			break;
		}
	}
	vector<int> v1, v2;
	v1 = layerOrder(root);
	inOrder(root, v2);
	for (int i = 0; i < n; i++) {
		cout<<v1[i];
		if (i == n-1)
			cout<<endl;
		else 
			cout<<" ";
	}
	for (int i = 0; i < n; i++) {
		cout<<v2[i];
		if (i == n-1)
			cout<<endl;
		else 
			cout<<" ";
	}
	return 0;
}