#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 10010;
int A[maxn];
vector<int> ans;
bool flag = false;

void DFS(int start, int end, int s, vector<int>& vi) {
	if (flag)
		return;
	if (s == 0) {
		if (!flag) {
			ans = vi;
			flag = true;
			return;
		}
		return;
	}
	if (s < 0)
		return;
	for (int i = start; i <= end; i++) {
		vi.push_back(A[i]);
		DFS(i+1, end, s-A[i], vi);
		vi.pop_back();
	}
}

int main() {
	int n, target;
	cin>>n>>target;
	for (int i = 0; i < n; i++) {
		cin>>A[i];
	}
	sort(A, A+n);
	vector<int> vi;
	DFS(0, n-1, target, vi);
	if (flag) {
		for (int i = 0; i < ans.size(); i++) {
			cout<<ans[i];
			if (i < ans.size()-1)
				cout<<" ";
		}
	}else {
		cout<<"No Solution";
	}
	return 0;
}