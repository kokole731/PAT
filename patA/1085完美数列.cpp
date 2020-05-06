#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;
typedef long long ll;

int main() {
	int n, p;
	scanf("%d %d", &n, &p);
	ll A[maxn];
	for (int i = 0; i < n; i++) {
		scanf("%lld", &A[i]);
	}
	sort(A, A+n);
	int i, j, ans = 1;
	i = j = 0;
	while (i < n && j < n) {
		while (A[i] * p >= A[j] && j <= n-1) {
			++j;
		}
		ans = max(ans, j-i);
		if (j == n)
			break;
		++i;
	}
	printf("%d", ans);
	return 0;
}