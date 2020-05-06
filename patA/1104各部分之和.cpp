#include <iostream>
using namespace std;

int main () {
	int n;
	scanf("%d", &n);
	double pre = 0, ans = 0, tmp;
	for (int i = 1; i <= n; i++) {
		cin>>tmp;
		ans += tmp * (n+1-i) * i;
	}
	printf("%.2f", ans);
	return 0;
}