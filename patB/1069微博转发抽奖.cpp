#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
map<string, bool> mp;

int main() {
	int m, n, s;
	cin>>m>>n>>s;
	string name[m+1];
	for (int k = 1; k <= m; k++)
		cin>>name[k];
	int i = s;
	vector<string> ans;
	while (i <= m) {
		if (mp.find(name[i]) == mp.end()) {
			mp[name[i]] = true;
			ans.push_back(name[i]);
			i += n;
		}else {
			i += 1;
		}
	}
	if (ans.size() == 0)
		cout<<"Keep going...";
	else {
		for (int k = 0; k < ans.size(); k++) {
			cout<<ans[k]<<endl;
		}
	}
	return 0;
}