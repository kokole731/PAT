#include <iostream>
#include <set>
using namespace std;

double f(set<int> a, set<int> b) {
	// 把b中的元素插入到a中去
	// int sizeA = a.size();
	// int sizeB = b.size();
	// for (set<int>::iterator it = b.begin(); it != b.end(); it++) {
	// 	a.insert(*it);
	// }
	// double commen = sizeA + sizeB - a.size();
	// return commen / a.size() * 100;
	double sum = 0;
	int size = b.size();
	for (set<int>::iterator it = a.begin(); it != a.end(); ++it) {
		if (b.find(*it) != b.end())
			sum++;
		else
			size++;
	}
	return sum / size * 100; 
}

int main() {
	//n--total set number,   m--query number
	int n, m;
	cin>>n;
	set<int> setArr[n+1];
	for (int i = i; i <= n; i++)
		setArr[i].clear();
	int set_num;
	for (int i = 1; i <= n; i++) {
		cin>>set_num;
		int t;
		for (int j = 0; j < set_num; j++) {
			cin>>t;
			setArr[i].insert(t);
		}
	}
	cin>>m;
	int q_a, q_b;
	for (int i = 0; i < m; i++) {
		cin>>q_a>>q_b;
		double rst = f(setArr[q_a], setArr[q_b]);
		printf("%02.1f%%", rst);
		if (i < m-1)
			printf("\n");
	}
	return 0;
}