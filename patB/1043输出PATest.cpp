#include <iostream>
#include <string>
using namespace std;
int table[6] = {0};

int main() {
	string target = "PATest";
	string s;
	cin>>s;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < 6; j++) {
			if (target[j] == s[i]) {
				table[j]++;
			}
		}
	}
	while (true) {
		bool flag = false;
		for (int i = 0; i < 6; i++) {
			if (table[i] > 0) {
				cout<<target[i];
				table[i]--;
				flag = true;
			}
		}
		if (flag == false)
			break;
	}
	return 0;
}