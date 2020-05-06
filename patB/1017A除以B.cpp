#include <iostream>
using namespace std;
const int maxn = 1010;

struct Bign {
	int len;
	int data[maxn];
	Bign () {}
	Bign (string s) {
		len = s.length();
		for (int i = 0; i < len; i++) {
			data[i] = s[i]-'0';
		}
	}
};


int main() {
	string s;
	int n;
	cin>>s>>n;
	Bign x = Bign(s);
	int remain = 0;
	int ans[maxn];
	for (int i = 0; i < x.len; i++) {
		remain = remain * 10 + x.data[i];
		ans[i] = remain / n;
		remain = remain % n;
	}
	int start = 0;
	while (ans[start] == 0 && start < x.len)
		start++;
	if (start == x.len)
		cout<<0;
	for (int i = start; i < x.len; i++) {
		cout<<ans[i];
	}
	cout<<" "<<remain;
	return 0;
}