#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// 1 2 3 4 5 6 7 8
// 3 5 8 6 2 1 4 7 
// 2 3 5 2 3 5 3 1

int main() {
	int n;
	cin>>n;
	int A[n+1];
	for (int i = 1; i <= n; i++) {
		cin>>A[i];
	}
	int cnt[n+1];
	for (int i = 0; i <= n; i++)
		cnt[i] = 0;
	for (int i = 1; i <= n; i++) {
		//差值绝对值
		int k = A[i] - i >= 0 ? A[i] - i : i - A[i];
		cnt[k] += 1;
	}
	vector<pair<int, int> > ans;
	for (int i = n-1; i >= 0; i--) {
		if (cnt[i] >= 2) {
			ans.push_back(make_pair(i, cnt[i]));
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout<<ans[i].first<<" "<<ans[i].second;
		if (i < ans.size()-1)
			cout<<endl;
	}
	return 0;
}