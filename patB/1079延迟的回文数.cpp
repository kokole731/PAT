#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1010;

struct Bign {
	int data[maxn], len;
	Bign(string s) {
		len = s.size();
		fill(data, data+maxn, 0);
		for (int i = len-1; i >= 0; i--) {
			data[i]= s[len-i-1]-'0';
		}
	}
};

bool checkPa(Bign x) {
	int len = x.len;
	for (int i = 0; i < len/2+1; i++) {
		if (x.data[i] != x.data[len-1-i])
			return false;
	}
	return true;
}

string bign2string(Bign x) {
	string s = "";
	for (int i = x.len-1; i >= 0; i--) {
		s += x.data[i]+'0';
	}
	return s;
}

void printAdd(Bign x, Bign y, Bign z) {
	cout<<bign2string(x)<<" + "<<bign2string(y)<<" = "<<bign2string(z)<<endl;
}

Bign add(Bign x) {
	Bign y = Bign("");
	y.len = x.len;
	for (int i = 0; i < y.len; i++) {
		y.data[i] = x.data[y.len-1-i];
	}
	int idx = y.len-1;
	while (y.data[idx] == 0) {
		y.len--;
		idx--;
	}
	int t = 0;
	Bign z = Bign("");
	z.len = x.len;
	for (int i = 0; i < x.len; i++) {
		int tmp = x.data[i]+y.data[i]+t;
		z.data[i] = tmp % 10;
		t = tmp / 10;
	}
	if (t == 1) {
		z.data[z.len] = 1;
		z.len++;
	}
	printAdd(x, y, z);
	return z;
}



int main() {
	string s;
	cin>>s;
	Bign num = Bign(s);
	int cnt = 0;
	while (checkPa(num) == false) {
		if (cnt == 10)
			break;
		num = add(num);
		cnt++;
	}
	if (checkPa(num)) {
		cout<<bign2string(num)<<" is a palindromic number.";
	}else {
		cout<<"Not found in 10 iterations.";
	}

	return 0;
}