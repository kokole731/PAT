#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
const int maxc = 210;
int color[maxc];

int main() {
	int k, m, n;
	cin>>k>>m;
	int c;
	fill(color, color+maxc, -1);
	for (int i = 0; i < m; i++) {
		cin>>c;
		//记录喜欢的颜色的出现次序
		color[c] = i;
	}
	cin>>n;
	int A[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	int f[n];
	f[0] = color[A[0]] != -1;
	for (int i = 1; i < n; i++) {
		if (color[A[i]] == -1) {
			f[i] = 0;
			continue;
		}
		f[i] = 1;
		for (int j = 0; j < i; j++) {
			if (color[A[j]] != -1 && color[A[j]] <= color[A[i]])
				f[i] = max(f[j]+1, f[i]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) 
		ans = max(ans, f[i]);
	cout<<ans;
	return 0;
}