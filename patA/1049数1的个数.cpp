#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin>>n;
	ll ans = 0;
	int left = n / 10;
	int right = 0, digit, redix = 1;
	while (n != 0) {
		digit = n % 10;
		n /= 10;
		if (digit == 0) {
			ans += left * redix;
		}else if (digit == 1) {
			ans += left * redix + right + 1;
		}else {
			ans += (left+1) * redix;
		}
		left /= 10;
		right = right * 10 + digit;
		redix *= 10;
	}
	cout<<ans;
	return 0;
}