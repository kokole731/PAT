#include <iostream>
#include <string>
using namespace std;

string f(string s) {
	//s == "12"
	int len = s.length();
	string ans = "";
	char tmp;
	int cnt;
	for (int i = 0; i < len; i++) {
		if (i == 0){
			tmp = s[0];
			cnt = 1;
			continue;
		}
		if (s[i] == tmp) {
			cnt++;
		}else {
			ans+=tmp;
			ans+=to_string(cnt);
			tmp = s[i];
			cnt = 1;
		}
	}
	ans+=tmp;
	ans+=to_string(cnt);
	return ans;
}

int main() {
	int d, n;
	cin>>d>>n;
	string t = to_string(d);
	for (int i = 1; i < n; i++) {
		t = f(t);
	}
	cout<<t;
	return 0;
}