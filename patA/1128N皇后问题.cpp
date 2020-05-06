#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1010;
int k, n;
int maze[maxn];
int cnt[maxn];

string judge(int n) {
	fill(cnt, cnt+maxn, 0);
	for (int i = 1; i <= n; i++){
		cnt[maze[i]]++;
		if (cnt[maze[i]] > 1)
			return "NO";
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if ((j-i) == abs(maze[j]-maze[i]))
				return "NO";
		}
	}
	return "YES";
}

int main() {
	cin>>k;
	string ans[k];
	for (int i = 0; i < k; i++) {
		cin>>n;
		for (int j = 1; j <= n; j++) {
			cin>>maze[j];
		}
		ans[i] = judge(n);
	}
	for (int i = 0; i < k; i++)
		cout<<ans[i]<<endl;
	return 0;
}