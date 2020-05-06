#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 65;

struct Bign {
	bool  symbol;
	int data[maxn];
	int len;
	Bign(ll x) {
		symbol = x >= 0;
		len = 0;
		x = abs(x);
		fill(data, data+maxn, 0);
		while (x != 0) {
			data[len++] = x%10;
			x/=10;
		}
	}
};

bool cmp (Bign a, Bign b) {
	if (a.symbol != b.symbol)
		return a.symbol > b.symbol;
	else {
		if (a.symbol == false) {
			if (a.len != b.len)
				return a.len < b.len;
			for (int i = a.len-1; i >= 0; i--) {
				if (a.data[i] != b.data[i])
					return a.data[i] < b.data[i];
			}
			return false;
		}else {
			if (a.len != b.len)
				return a.len > b.len;
			for (int i = a.len-1; i >= 0; i--) {
				if (a.data[i] != b.data[i])
					return a.data[i] > b.data[i];
			}
			//完全相同的情况下返回false
			return false;
		}
	}
}

Bign add(Bign a, Bign b, bool symbol) {
	int add = 0;
	Bign c = Bign(0);
	c.len = max(a.len, b.len);
	c.symbol = symbol;
	for (int i = 0; i < maxn; i++) {
		int tmp = a.data[i]+b.data[i]+add;
		c.data[i] = tmp % 10;
		add = tmp / 10;
		if (i >= a.len-1 && i >= a.len-1 && add == 1)
			c.len++;
	}
	return c;
}

Bign minus()

int main() {
	int n;
	cin>>n;
	vector<string> ans;
	ll a, b, c;
	for (int i = 0; i < n; i++) {
		cin>>a>>b>>c;
		Bign a1 = Bign(a);
		Bign b1 = Bign(b);
		Bign x;
		if (a >= 0 && b >= 0) {
			x = add(a1, b1, true);
		}else if (a >= 0 && b < 0) {
			x = minus(a1, b1, true);
		}else if (a < 0 && b >= 0) {
			x = minus(a1, b1, false);
		}else {
			x = add(a1, b1, false);
		}
	}
	return 0;
}