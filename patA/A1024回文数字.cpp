#include <iostream>
#include <string>
using namespace std;
const int maxn = 110;

struct Bign {
	int data[maxn];
	int len;
	Bign() {}
	Bign(string s) {
		len = s.length();
		for (int i = 0; i <= len-1; i++) {
			data[i] = s[len-i-1] - '0';
		}
	}
};

//判断该大整数是否为回文数字
bool isPal(Bign n) {
	int len = n.len;
	for (int i = 0; i <= len/2; i++) {
		if (n.data[i] != n.data[len-i-1])
			return false;
	}
	return true;
}

Bign process(Bign a) {
	Bign b = a;
	int tmp;
	// 找出a的对称数b
	for (int i = 0; i < a.len/2; i++) {
		tmp = b.data[i];
		b.data[i] = b.data[b.len-i-1];
		b.data[b.len-i-1] = tmp;
	}
	//初始化c
	Bign c = Bign();
	c.len = a.len;
	//进位
	int x = 0;
	for (int i = 0; i < a.len; i++) {
		//逐位相加，包括进位
		int t = a.data[i] + b.data[i] + x;
		c.data[i] = t % 10;
		x = t / 10;
	}
	if (x == 1) {
		c.data[c.len] = 1;
		c.len++;
	}

	return c;
}

int main() {
	string s;
	int maxStep;
	cin>>s>>maxStep;
	Bign x = Bign(s);
	int step = 0;
	while (step < maxStep && !isPal(x)) {
		
		x = process(x);
		step++;
	}
	for (int i = x.len-1; i >= 0; i--)
		cout<<x.data[i];
	cout<<endl;
	cout<<step;
	return 0;
}