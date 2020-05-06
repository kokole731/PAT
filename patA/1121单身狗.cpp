#include<iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;
map<int, int> mp;
bool flag[maxn] = {0};
bool present[maxn] = {0};

int main() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		mp[a] = b;
		mp[b] = a;
		present[a] = true;
		present[b] = true;
	}
	scanf("%d", &n);
	int A[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
		flag[A[i]] = true;
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (present[A[i]] && flag[mp[A[i]]]) {
			continue;
		}
		ans.push_back(A[i]);
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%05d", ans[i]);
		if (i < ans.size()-1)
			printf(" ");
	}
	return 0;
}