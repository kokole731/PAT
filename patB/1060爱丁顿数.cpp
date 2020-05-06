/*
10
6 7 6 9 3 10 8 2 7 8
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	int A[n+1];
	for (int i = 1; i <= n; i++)
		cin>>A[i];
	sort(A+1, A+n+1);
	reverse(A+1, A+n+1);
	int i;
	for (i = 1; i <= n; i++) {
		if (A[i] <= i)
			break;
	}
	cout<<i-1;
	return 0;
}