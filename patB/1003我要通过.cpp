#include <iostream>
#include <string>
using namespace std;

bool judge(string s) {
	int n = s.size();
	//记录PAT字母的出现次数
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < n; i++) {
		char m = s[i];
		switch(m) {
			case 'P':
				a++;
				break;
			case 'A':
				b++;
				break;
			case 'T':
				c++;
				break;
			default:
				return false;
		}
	}
	if (a != 1 || c != 1 || b < 1)
		return false;
	int P = s.find('P'), T = s.find('T');
	if (P > T)
		return false;
	int x = 0, y = 0, z = 0;
	for (int i = 0; i < n; i++) {
		char m = s[i];
		if (m == 'A') {
			if (i < P) 
				x++;
			else if (i > P && i < T)
				y++;
			else if (i > T)
				z++;
		}
	}
	if (x * y != z)
		return false;
	return true;
}

int main() {
	int n;
	cin>>n;
	string s;
	for (int i = 0; i < n; i++) {
		cin>>s;
		if (judge(s))
			cout<<"YES"<<endl;
		else 
			cout<<"NO"<<endl;
	}

	return 0;
}