#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100010;
int A[maxn];

int main() {
	int n;
	cin>>n;
	cout<<(n%2? 1: 0)<<" ";
	for (int i = 0; i < n; i++) {
		cin>>A[i];
	}
	sort(A, A+n);
	ll minSum = 0, maxSum = 0;
	for (int i = 0; i < n; i++) {
		if (i < n/2)
			minSum += A[i];
		else 
			maxSum += A[i];
	}
	cout<<maxSum-minSum;
	return 0;
}