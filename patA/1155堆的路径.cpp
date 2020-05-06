#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1010;
int tree[maxn];
vector<vector<int> > ans;
// 0为增序的路径条数 1为减序的路径条数
int path[2] = {0};
int n;
vector<int> vi;
//右-根-左
void DFS(int root) {
	int pre = *(vi.end()-1);
	if (root*2 > n && root*2+1 > n) {
		ans.push_back(vi);
	}
	if (root*2+1 <= n) {
		vi.push_back(tree[root*2+1]);
		if (tree[root*2+1] > pre)
			path[0]++;
		if (tree[root*2+1] < pre)
			path[1]++;
		DFS(root*2+1);
		vi.pop_back();
	}
	if (root*2 <= n) {
		vi.push_back(tree[root*2]);	
		if (tree[root*2] > pre)
			path[0]++;
		if (tree[root*2] < pre)
			path[1]++;
		DFS(root*2);
		vi.pop_back();
	}
	
}

int main() {
	cin>>n;
	for (int i = 1; i <= n; i++)
		cin>>tree[i];
	vi.push_back(tree[1]);
	DFS(1);
	int size = ans.size(), s1;
	for (int i = 0; i < size; i++) {
		s1 = ans[i].size();
		for (int j = 0; j < s1; j++) {
			cout<<ans[i][j];
			if (j < s1-1)
				cout<<" ";
		}
		cout<<endl;
	}
	if (path[0] > 0 && path[1] > 0)
		cout<<"Not Heap";
	else if (path[0] > 0 && path[1] == 0)
		cout<<"Min Heap";
	else if (path[0] == 0 && path[1] > 0)
		cout<<"Max Heap";
}