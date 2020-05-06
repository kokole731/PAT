#include <iostream>
#include <string>
using namespace std;
int X[2] = {0};
int N[2] = {0};

void f(string s, int k) {
	int len = s.size();
	bool isPositive = true, isX = false;
	int tmp = 0;
	for (int i = 0; i < len; i++) {
		char c = s[i];
		if (c == '+' || c == '-') {
			tmp = isPositive ? tmp : -tmp;
			if (isX) {
				X[k] += tmp;
			}else {
				N[k] += tmp;
			}
			isPositive = c == '+';
			isX = false;
			tmp = 0;
		}else if (c <= '9' && c >= '0') {
			tmp = tmp * 10 + (c-'0');
		}else if (c == 'x') {
			if (tmp == 0)
				tmp = 1;
			isX = true;
		}
	}
	tmp = isPositive ? tmp : -tmp;
	if (isX) {
		X[k] += tmp;
	}else {
		N[k] += tmp;
	}
}

int main() {
	string s;
	cin>>s;
	int len = s.size(), p = 0;
	while (s[p] != '=') {
		p++;
	}
	string leftPart = s.substr(0, p);
	string rightPart = s.substr(p+1, len);
	f(leftPart, 0);
	f(rightPart, 1);
	int totalX = X[0]-X[1];
	int totalN = N[1]-N[0];
	if (totalX == 0) {
		if (totalN == 0) {
			cout<<"infinite solutions";
		}else
			cout<<"no solution";
	}else {
		cout<<"x="<<double(totalN)/totalX;
	}
	return 0;
}