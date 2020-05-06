#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100010;
//flag 为 false 代表没坏， 为true代表坏了
bool flag[128] = {0};

int main() {
	char p[128];
	scanf("%s", p);
	for (int i = 0; i < strlen(p); i++) {
		char c = p[i];
		if (c >= 'A' && c <= 'Z') {
			c  = c-'A'+'a';
		}
		flag[c] = true;
	}
	char s[maxn];
	scanf("%s", s);
	for (int i = 0; i < strlen(s); i++) {
		char c = s[i];
		if (c <= 'Z' && c >= 'A') {
			c = c-'A'+'a';
			if (flag['+'] == false)
				printf("%c", c);
		}
		else {
			if (flag[c] == false)
				printf("%c", c);
		}
	}
	printf("\n");
	return 0;
}