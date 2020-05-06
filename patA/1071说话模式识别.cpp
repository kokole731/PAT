#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, int> mp;

bool isVal(char c) {
	if (c <= 'z' && c >= 'a')
		return true;
	else if (c <= 'Z' && c >= 'A')
		return true;
	else if (c <= '9' && c >= '0')
		return true;
	return false;
}

int main() {
	string s;
	getline(cin, s);
	s += '\n';
	int len = s.length();
	int index = 0;
	bool preIsVa = false;
	string t = "";
	for (int i = 0; i < len; i++) {
		char x = s[i];
		if (isVal(x)) {
			preIsVa = true;
			if (x <= 'Z' && x >= 'A')
				x = 'a' + (x - 'A');
			t += x;
		}else {
			if (preIsVa) {
				if (mp.find(t) != mp.end())
					mp[t] += 1;
				else
					mp[t] = 1;
			}
			t = "";
			preIsVa = false;
		}
	}
	int maxCnt = 0;
	string maxString = "";
	for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		if (it->second > maxCnt || (it->second == maxCnt && it->first < maxString)) {
			maxCnt = it->second;
			maxString = it->first;
		}
	}
	cout<<maxString<<" "<<maxCnt;
	return 0;
}