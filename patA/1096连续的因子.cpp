#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 50;

int main() {
	ll n;
	cin>>n;
	int maxNum = 1;
	int maxStart = 1;
	for (int i = 2; i < maxn-1; i++) {
		ll product = i;
		for (int j = i+1; j < maxn; j++) {
			product *= j;
			if (n % product == 0) {
				if (j-i+1 > maxNum) {
					maxNum = j-i+1;
					maxStart = i;
				}
			}
		}
	}
	if (maxNum == 1) {
		maxStart = n;
	}
	cout<<maxNum<<endl;
	cout<<maxStart;
	for (int i = 1; i <= maxNum-1; i++) {
		cout<<"*"<<maxStart+i;
	}
	return 0;
}