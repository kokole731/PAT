#include <iostream>
#include <string>
using namespace std;

int main () {
	string s;
	cin>>s;
	int len = s.length();
	//以s[i]结尾的字符串含有几个P，T
	int left[len], right[len];
	for (int i = 0; i < len; i++) {
		if (i == 0) {
			left[i] = s[i] == 'P' ? 1 : 0;
			right[i] = s[i] == 'T' ? 1 : 0;
		}else {
			left[i] = s[i] == 'P' ? left[i-1]+1 : left[i-1];
			right[i] = s[i] == 'T' ? right[i-1]+1 : right[i-1];
		}
	}
	int ans = 0, rightTotal = right[len-1];
	for (int i = 1; i < len-1; i++) {
		if (s[i] == 'A') {
			ans += left[i-1] * (rightTotal-right[i]);
			ans %= 1000000007;
		}
	}
	cout<<ans;
	return 0;
}