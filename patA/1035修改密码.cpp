#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

map<char, char> mp;

int main() {
	mp['1'] = '@';
	mp['0'] = '%';
	mp['l'] = 'L';
	mp['O'] = 'o';
	int n, len;
	string s, tmp;
	cin>>n;
	getchar();
	vector<string> ans;
	bool flag;
	for (int i = 0; i < n; i++) {
		tmp = "";
		flag = false;
		getline(cin, s);
		len = s.size();
		int j = 0;
		while (s[j] != ' ') {
			tmp += s[j];
			j++;
		}
		tmp += ' ';
		j++;
		for (; j < len; j++) {
			if (mp.find(s[j]) != mp.end()) {
				tmp += mp[s[j]];
				flag = true;
			}else {
				tmp += s[j];
			}
		}
		if (flag)
			ans.push_back(tmp);
	}
	if (n == 1 && ans.size() == 0) {
		cout<<"There is 1 account and no account is modified";
	}else if (n > 1 && ans.size() == 0) {
		cout<<"There are "<<n<<" accounts and no account is modified";
	}else {
		cout<<ans.size()<<endl;
		for (int i = 0; i < ans.size(); i++) {
			cout<<ans[i]<<endl;
		}
	}
	return 0;
}