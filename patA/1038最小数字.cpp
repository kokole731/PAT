#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	string s1 = a+b;
	string s2 = b+a;
	return s1<s2;
}

int main() {
	int n;
	cin>>n;
	string A[n];
	for (int i = 0; i < n; i++) {
		cin>>A[i];
	}
	sort(A, A+n, cmp);
	string ans = "";
	for (int i = 0; i < n; i++) {
		ans += A[i];
	}
	//012
	int j = 0, len = ans.size();
	while (j < len) {
		if (ans[j] == '0') {
			j++;
		}else {
			 break;
		}
	}
	cout<<ans.substr(j, len-j);
	return 0;
}