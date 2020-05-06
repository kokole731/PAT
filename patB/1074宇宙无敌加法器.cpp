#include <iostream>
#include <string>
using namespace std;
const int maxn = 25;

int main() {
	string s, a, b;
	cin>>s>>a>>b;
	int len = s.size();
	int t[maxn];
	for (int i = 0; i < len; i++) {
		t[i] = s[len-1-i]-'0';
		if (t[i] == 0)
			t[i] = 10;
	}
	int c[maxn] = {0}, A[maxn] = {0}, B[maxn] = {0};
	for (int i = 0; i < a.size(); i++) {
		A[i] = a[a.size()-1-i]-'0';
	}
	for (int i = 0; i < b.size(); i++)
		B[i] = b[b.size()-i-1]-'0';
	int add = 0;
	len = 0;
	for (int i = 0; i < a.size()||i < b.size(); i++) {
		int tmp = A[i] + B[i] + add;
		c[i] = tmp % t[i];
		add = tmp / t[i];
		len = i+1;
	}
	if (add != 0) {
		c[len] = add;
		len++;
	}
	while (c[len-1] == 0) {
		len--;
	}
	for (int i = len-1; i >= 0; i--)
		cout<<c[i];
	return 0;
}