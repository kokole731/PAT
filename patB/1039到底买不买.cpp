#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int hashTable[80];

int change(char c) {
	if (c <= '9' && c >= '0')
		return c-'0';
	else if (c <= 'z' && c >= 'a')
		return c-'a'+10;
	else
		return c-'A'+36;
}

int main() {
	fill(hashTable, hashTable+80, 0);
	string s, target;
	cin>>s>>target;
	for (int i = 0; i < s.length(); i++) {
		int num = change(s[i]);
		hashTable[num]++;
	}
	int mis = 0;
	for (int i = 0; i < target.length(); i++) {
		int num = change(target[i]);
		hashTable[num]--;
		if (hashTable[num] < 0) {
			mis++;
		}
	}
	if (mis == 0)
		cout<<"Yes "<<s.length()-target.length();
	else
		cout<<"No "<<mis;
	return 0;
}