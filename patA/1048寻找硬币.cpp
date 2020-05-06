#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
map<int, int> mp;

int main() {
	int n, k, x;
	cin>>n>>k;
	int minX = 510;
	for (int i = 0; i < n; i++) {
		cin>>x;
		if (mp.find(x) != mp.end()) {
			minX = min(minX, x);
			if (k-x > 0)
				minX = min(minX, k-x);
		}
		mp[k-x] = x;
	}
	if (minX > 500)
		cout<<"No Solution";
	else {
		cout<<minX<<" "<<k-minX;
	}
	return 0;
}