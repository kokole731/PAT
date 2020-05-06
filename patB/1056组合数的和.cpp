#include <iostream>
#include <algorithm>
using namespace std;
int f[101];

int main() {
	fill(f, f+101, 0);
	int n;
	cin>>n;
	int A[n], sum = 0;
	for (int i = 0; i < n; i++) {
		cin>>A[i];
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++){
			int a = A[i]*10 + A[j];
			int b = A[j]*10 + A[i];
			f[a] = 1;
			f[b] = 1;
		}
	}
	for (int i = 0; i < 101; i++)
		sum += i * f[i];
	cout<<sum;
	return 0;
}