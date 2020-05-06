#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin>>s;
	int n = s.length(), n1, n2, n3;
	for (int i = 3; i <= n; i++) {
		int tmp = n+2-i;
		if (tmp % 2 == 0 && tmp / 2 <= i) {
			n1=n3=tmp/2;
			n2 = i;
			break;
		}
	}
	int space = n2-2;
	for (int i = 0; i < n1; i++) {
		if (i != n1-1) {
			cout<<s[i];
			for (int j = 0; j < space; j++)
				cout<<" ";
			cout<<s[n-i-1];
			cout<<endl;
		}else {
			for (int j = 0; j < n2; j++) {
				cout<<s[j+n1-1];
			}
		}
	}
	return 0;
}