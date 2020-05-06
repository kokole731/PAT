#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin>>n;
	int A[100001] = {0};
	int t;
	for (int i = 2; i <= n; i++) {
		cin>>t;
		A[i] = A[i-1] + t;
	}
	cin>>t;
	int sum = A[n] + t;
	vector<int> ans;
	int m, a, b;
	cin>>m;
	for (int i = 0; i < m; i++) {
		cin>>a>>b;
		int x = abs(A[b] - A[a]);
		int y = sum - x;
		ans.push_back(min(x, y));
	}
	for (int i = 0; i < m; i++)
		cout<<ans[i]<<endl;
	return 0;
}