#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int len = s.length();
	int sum = 0;
	for (int i = 0; i < len; i++) {
		char c = s[i];
		if (c >= 'A' && c <= 'Z') {
			sum += c-'A'+1;
		}else if (c >= 'a' && c <= 'z') {
			sum += c-'a'+1;
		}else {
			continue;
		}
	}
	int cnt[2] = {0};
	while (sum != 0) {
		int x = sum % 2;
		sum /= 2;
		cnt[x]++;
	}
	cout<<cnt[0]<<" "<<cnt[1];
	return 0;
}