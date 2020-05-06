#include <iostream>
#include <stack>
#include <string>
using namespace std;
const int maxn = 100010;
//一个组内元素的个数
const int groupn = 316;
stack<int> st;
int number[maxn] = {0};
int group[groupn+1] = {0};

void push() {
	int num;
	cin>>num;
	number[num]++;
	group[num/groupn]++;
	st.push(num);
}

void pop() {
	if (st.empty()) {
		cout<<"Invalid"<<endl;
		return;
	}
	cout<<st.top()<<endl;
	group[st.top()/groupn]--;
	number[st.top()]--;
	st.pop();
}

void peekMedian() {
	if (st.empty()) {
		cout<<"Invalid"<<endl;
		return;
	}
	int k = st.size() % 2 ? st.size()/2+1 : st.size()/2;
	int sum = 0, idx = 0;
	while (sum < k && idx < groupn+1) {
		sum += group[idx];
		idx++;
	}
	sum -= group[idx-1];
	idx = (idx-1)*groupn;
	while (sum < k) {
		sum += number[idx];
		idx++;
	}
	cout<<idx-1<<endl;
}

int main() {
	int n;
	cin>>n;
	string s;
	for (int i = 0; i < n; i++) {
		cin>>s;
		if (s == "Pop")
			pop();
		else if (s == "Push")
			push();
		else
			peekMedian();
	}
	return 0;
}