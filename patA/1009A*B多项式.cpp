#include <iostream>
// #include <algorithm>
using namespace std;
const int maxn = 1000010;
double p[maxn] = {0};

int main() {
	int n1, n2;
	int a;
	double b;
	scanf("%d", &n1);
	double x[1001] = {0};
	double y[1001] = {0};
	for (int i = 0; i < n1; i++) {
		scanf("%d %lf", &a, &b);
		x[a] = b;
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++) {
		scanf("%d %lf", &a, &b);
		y[a] = b;
	}
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			p[i+j] += x[i] * y[j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < maxn; i++) {
		if (p[i] != 0)
			cnt++;
	}
	printf("%d", cnt);
	for (int i = maxn-1; i >= 0; i--) {
		if (p[i] != 0)
			printf(" %d %.1f", i, p[i]);
	}
	return 0;
}