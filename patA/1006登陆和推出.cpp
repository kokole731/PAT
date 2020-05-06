#include <iostream>
#include <algorithm>
using namespace std;
// 15:30:28
bool cmp(string a, string b){
	if (a.substr(0, 2) != b.substr(0, 2)) 
		return a.substr(0,2) < b.substr(0,2);
	else {
		if (a.substr(3, 2) != b.substr(3, 2))
			return a.substr(3, 2) < b.substr(3, 2);
		else
			return a.substr(6, 2) < b.substr(6, 2);
	}
}

int main() {
	int m;
	cin>>m;
	string minName, maxName, minTime, maxTime;
	string x, y, z;
	for (int i = 0; i < m; i++) {
		cin>>x>>y>>z;
		if (i == 0) {
			minName = x;
			maxName = x;
			minTime = y;
			maxTime = z;
			continue;
		}
		if (cmp(y, minTime)) {
			minTime = y;
			minName = x;
		}
		if (cmp(z, maxTime) == false) {
			maxName = x;
			maxTime = z;
		}
	}
	cout<<minName<<" "<<maxName;
	return 0;
}