#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 110;

int change(string s, int A[], int k) {
	while (s.length() > 0 && s[0] == '0')
		s.erase(s.begin());
	int len = s.size();
	int left[maxn] = {0}, right[maxn] = {0};
	int p = 0, leftLen, rightLen;
	while (s[p] != '.' && p < len) {
		left[p] = s[p]-'0';
		p++;
	}
	leftLen = p;
	if (p == len)
		rightLen = 0;
	else
		rightLen = len-p-1;
	for (int i = p+1; i < len-1; i++) {
		right[i-p-1] = s[i]-'0';
	}
	for (int i = 0; i < k; i++) {
		if (i <= leftLen-1) {
			A[i] = left[i];
		}else {
			int idx = i-leftLen;
			A[i] = right[idx];
		}
	}
	return leftLen;
}

int main() {
	int k;
	cin>>k;
	string s1, s2;
	cin>>s1>>s2;
	int A1[maxn], A2[maxn];
	int a1 = change(s1, A1, k);
	int a2 = change(s2, A2, k);
	bool flag = a1 == a2;
	for (int i = 0; i < k; i++) {
		if (A1[i] != A2[i]) {
			flag = false;
		}
	}
	if (flag) {
		cout<<"YES 0.";
		for (int i = 0; i < k; i++)
			cout<<A1[i];
		cout<<"*10^"<<a1;
	}else {
		cout<<"NO ";
		cout<<"0.";
		for (int i = 0; i < k; i++)
			cout<<A1[i];
		cout<<"*10^"<<a1;
		cout<<" ";
		cout<<"0.";
		for (int i = 0; i < k; i++)
			cout<<A2[i];
		cout<<"*10^"<<a2;
	}
	return 0;
}