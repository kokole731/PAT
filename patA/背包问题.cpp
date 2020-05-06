#include <iostream>
using namespace std;
// 6
// 1 2 4
int main() {
	int n, T;
	cin>>n>>T;
	int A[n+1];
	for (int i = 1; i <= n; i++)
		cin>>A[i];

	int f[T+1];
	int pai[T+1];
	memset(f, 0, (T+1) * sizeof(int));
	f[0] = 1;
	for (int i = 1; i <= T; i++) {
		for (int j = 1; j <= n; j++) {
			if (i >= A[j]) {
				f[i] += f[i-A[j]];
				if (f[i-A[j]] > 0) {
					pai[i] = A[j];
				}
			}
		}
	}
	cout<<f[T]<<endl;
	cout<<T<<" = "<<endl;
	while (T != 0) {
		cout<<pai[T]<<endl;
		T -= pai[T];
	}
	return 0;
}