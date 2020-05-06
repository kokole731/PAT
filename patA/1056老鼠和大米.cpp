#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1010;

struct Mouse {
	int weigh;
	int rank;
}mouse[maxn];

int main() {
	int n, k;
	cin>>n>>k;
	for(int i = 0; i < n; i++) {
		cin>>mouse[i].weigh;
	}
	vector<int> vi;
	int order;
	for (int i = 0; i < n; i++) {
		cin>>order;
		vi.push_back(order);
	}
	vector<int> loser;
	vector<int> winner;
	while (vi.size() > 1) {
		loser.clear();
		winner.clear();
		int len = vi.size();
		int group = len % k == 0 ? len / k: len / k + 1;
		for (int i = 0; i < group; i++) {
			int maxIndex = vi[i*k];
			int maxWeigh = -1;
			for (int j = 0; j < k && i*k+j < len; j++) {
				int index = vi[i*k+j];
				if (mouse[index].weigh > maxWeigh) {
					maxWeigh = mouse[index].weigh;
					maxIndex = index;
				}
			}
			for (int j = 0; j < k && i*k+j < len; j++) {
				int index = vi[i*k+j];
				if (index != maxIndex) {
					loser.push_back(index);
				}else {
					winner.push_back(index);
				}
			}
		}
		int winNum = winner.size();
		for (int i = 0; i < loser.size(); i++) {
			mouse[loser[i]].rank = winNum+1;
		}
		vi = winner;
	}
	mouse[winner[0]].rank = 1;
	for (int i = 0; i < n; i++) {
		cout<<mouse[i].rank;
		if (i < n-1)
			cout<<" ";
	}
	return 0;
}