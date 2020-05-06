#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;

int main() {
	int n;
	cin>>n;
	int A[maxn];
	for (int i = 0; i < n; i++) {
		cin>>A[i];
	}
	sort(A, A+n);
	int i;
	for (i = 0; i < n; i++) {
		if (A[i] > n-i) {
			break;
		}
	}
	if (i == n)
		cout<<0;
	else
		cout<<n-i;
	return 0;
}