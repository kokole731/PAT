#include <iostream>
#include <algorithm>
using namespace std;

int main () {
	int n;
	cin>>n;
	double A[n];
	for (int i = 0; i < n; i++)
		cin>>A[i];
	sort(A, A+n);
	double x = A[0];
	for (int i = 1; i < n; i++) {
		x = (x+A[i])/2;
	}
	cout<<(int)x;
	return 0;
}