#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	double sum = 0, tmp;
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &tmp);
		sum += tmp * i * (n-i+1);
	}
	printf("%.2f", sum);
}