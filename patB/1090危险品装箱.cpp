#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
const int maxn = 100010;
map<int, vector<int> > mp;
bool flag[maxn] = {0};
bool f[maxn] = {0};

void reset() {
	for (int i = 0; i < maxn; i++)
		flag[i] = false;
}

int main () {
	int n, m;
	cin>>n>>m;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin>>x>>y;
		mp[x].push_back(y);
		mp[y].push_back(x);
		f[x] = true;
		f[y] = true;
	}
	string ans[m];
	int k, tmp;
	bool danger;
	for (int i = 0; i < m; i++) {
		danger = false;
		reset();
		cin>>k;
		for (int j = 0; j < k; j++) {
			cin>>tmp;
			flag[tmp] = true;
			if (f[tmp]) {
				for (int u = 0; u < mp[tmp].size(); u++) {
					if (flag[mp[tmp][u]]) {
						danger = true;
						break;
					}
				}
			}
		}
		if (danger)
			ans[i] = "No";
		else
			ans[i] = "Yes";
	}
	for (int i = 0; i < m; i++)
		cout<<ans[i]<<endl;
	return 0;
}