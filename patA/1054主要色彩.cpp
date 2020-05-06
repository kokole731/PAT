#include <iostream>
#include <map>
using namespace std;
//数字对应个数
map<int, int> mp;

int main() {
	int n, m;
	cin>>n>>m;
	int t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &t);
			//如果找得到
			if (mp.find(t) != mp.end()) {
				mp[t] += 1;
			}else {
				mp[t] = 1;
			}
		}
	}
	int size = n*m;
	for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		if (it->second > size / 2) {
			printf("%d", it->first);
			break;
		}
	}
	return 0;
}