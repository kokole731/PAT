/*
5 3
1001 992 0 233 6
8 0 2018 0 2008
36 18 0 1024 4
*/

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1010;

struct Mooncake {
	int id;
	int sellNum;
}mooncake[maxn];

bool cmp(Mooncake a, Mooncake b) {
	if(a.sellNum == b.sellNum)
		return a.id < b.id;
	else
		return a.sellNum > b.sellNum;
}

int main() {
	int n, m;
	cin>>n>>m;
	int sellTmp;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin>>sellTmp;
			mooncake[j].id = j;
			mooncake[j].sellNum += sellTmp;
		}
	}
	sort(mooncake+1, mooncake+n+1, cmp);
	int max_num = mooncake[1].sellNum;
	cout<<max_num<<endl;
	cout<<mooncake[1].id;
	for (int i = 2; i <= n; i++) {
		if (mooncake[i].sellNum != max_num)
			break;
		cout<<" "<<mooncake[i].id;
	}
	return 0;
}