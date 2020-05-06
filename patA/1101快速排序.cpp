#include <iostream>
using namespace std;
const int maxn = 1e5+10;
const int INF = 1e9+10;
int A[maxn];

int main() {
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++) {
		cin>>A[i];
	}
	A[0] = -1;
	A[n+1] = INF;
	int leftMax[maxn];
	int rightMin[maxn];
	leftMax[0] = A[0];
	rightMin[n+1] = A[n+1];
	for (int i = 1; i <= n; i++) {
		leftMax[i] = max(leftMax[i-1], A[i-1]);
	}
	for (int i = n; i >= 1; i--) {
		rightMin[i] = min(rightMin[i+1], A[i+1]);
	}
	int f[maxn], idx = 0;
	for (int i = 1; i <= n; i++) {
		if (A[i] > leftMax[i] && A[i] < rightMin[i]) {
			f[idx++] = A[i];
		}
	}
	if (idx == 0)
		cout<<0<<endl;
	else {
		cout<<idx<<endl;
		for (int i = 0; i < idx; i++) {
			cout<<f[i];
			if (i < idx-1)
				cout<<" ";
			else 
				cout<<endl;
		}
	}
	return 0;
}