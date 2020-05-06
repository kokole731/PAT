#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	//Hello World Here I Come
	int len = s.length();
	int preIndex = 0;
	string subStr;
	vector<string> vi;
	for (int i = 0; i < len; i++) {
		if (s[i] == ' ') {
			subStr = s.substr(preIndex, i-preIndex);
			vi.push_back(subStr);
			preIndex = i+1;
		}
		if (i == len-1) {
			subStr = s.substr(preIndex, i-preIndex+1);
			vi.push_back(subStr);
		}
	}
	for (int i = vi.size()-1; i >= 0; i--) {
		cout<<vi[i];
		if (i != 0)
			cout<<" ";
	}
	return 0;
}