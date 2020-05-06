#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 1010;
char s[maxn];

bool judge(int n) {
	if (n == 0 || n == 1)
		return false;
	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int str2int(int start, int len) {
	int sum = 0;
	for (int i = 0; i < len; i++) {
		char c = *(s+start+i);
		sum = sum * 10 + (c - '0');
	}
	return sum;
}

int main() {
	int n, len;
	scanf("%d%d", &n, &len);
	for (int i = 0; i < n; i++)
		scanf("%c", s+i);
	bool flag = false;
	int i;
	for (i = 0; i < n-len; i++) {
		if (judge(str2int(i, len))){
			flag = true;
			break;
		}
	}
	if (flag) {
		for (int j = 0; j < len; j++)
			printf("%c", *(s+i+j));
	}else
		printf("404");
	return 0;
}