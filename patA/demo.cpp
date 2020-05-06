#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin>>n;
	ll ans = 0;
	int left, right, digit, redix = 1;
	while (n / redix) {
		digit = n/redix % 10;
		left = n/ (redix*10);
		right = n%redix;
		if (digit == 0) {
			ans += left * redix;
		}else if (digit == 1) {
			ans += left * redix + right + 1;
		}else {
			ans += (left+1) * redix;
		}
		redix *= 10;
	}
	cout<<ans;
	return 0;
}