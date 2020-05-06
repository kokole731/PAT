#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	int data;
	bool isStart;
};

bool cmp (Node a, Node b){
	if (a.data != b.data)
		return a.data < b.data;
	else {
		return a.isStart < b.isStart;
	}
}

int main() {
	int n;
	cin>>n;
	int start, end;
	vector<Node> ans;
	for (int i = 0; i < n; i++) {
		cin>>start>>end;
		Node a, b;
		a.data = start;
		a.isStart = true;
		b.data = end;
		b.isStart = false;
		ans.push_back(a);
		ans.push_back(b);
	}
	sort(ans.begin(), ans.end(), cmp);
	int overlap = 0, maxOverlap = 0;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i].isStart) {
			overlap++;
			maxOverlap = max(maxOverlap, overlap);
		}else {
			overlap--;
		}
	}
	cout<<maxOverlap;
	return 0;
}