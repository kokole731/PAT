#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin>>n>>m;
	m = m % n;
	int A[n+1];
	for (int i = 1; i <= n; i++) {
		cin>>A[i];
	}
	reverse(A+1, A+1+n-m);
	reverse(A+1+n-m, A+n+1);
	reverse(A+1, A+n+1);
	for (int i = 1; i <= n; i++) {
		cout<<A[i];
		if (i < n)
			cout<<" ";
	}
	return 0;
}