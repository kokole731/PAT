#include <iostream>
#include <map>
#include <string>
using namespace std;

map<int, string> mp;
char f[13] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};

int main() {
	string s;
	int a, b;
	for (int i = 0; i < 169; i++) {
		s = "";
		if (i == 0) {
			mp[i] = "00";
		}else if (i <= 12) {
			s += '0';
			s += f[i];
			mp[i] = s;
		}else {
			a = i / 13;
			b = i % 13;
			s += f[a];
			s += f[b];
			mp[i] = s;
		}
	}
	int x, y, z;
	cin>>x>>y>>z;
	cout<<"#"<<mp[x]<<mp[y]<<mp[z];
	return 0;
}