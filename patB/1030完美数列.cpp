#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;
typedef long long ll;

bool judge(ll a, ll b, int p) {
	return a <= b * p;
}

int main() {
	ll A[maxn];
	int n, p;
	cin>>n>>p;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &A[i]);
	}
	sort(A, A+n);
	int ans = 1;
	for (int i = 0; i < n-1; i++) {
		int j = upper_bound(A+i+1, A+n, A[i]*p)-A;
		ans = max(ans, j-i);
	}
	printf("%d", ans);
	return 0;
}