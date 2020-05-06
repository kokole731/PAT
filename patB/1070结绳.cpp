#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	double A[n];
	for (int i = 0; i < n; i++)
		cin>>A[i];
	sort(A, A+n);
	for (int i = 0; i < n-1; i++) {
		A[i+1] = (A[i] + A[i+1]) / 2;
	}
	cout<<(int)A[n-1];
}