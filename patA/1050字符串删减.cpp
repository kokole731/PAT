#include <iostream>
using namespace std;

int flag[128] = {0};
int main() {
	string s, t;
	getline(cin, s);
	getline(cin, t);
	for (int i = 0; i < t.length(); i++) {
		flag[t[i]] = true;
	}
	for (int i = 0; i < s.length(); i++) {
		if (!flag[s[i]])
			cout<<s[i];
	}
	return 0;
}