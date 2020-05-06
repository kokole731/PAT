#include <iostream>
#include <stack>
#include <string>
using namespace std;
int m, n, k;

string f(int A[]) {
	if (m == 0)
		return "NO";
	stack<int> s;
	int index = 1;
	for (int i = 1; i <= n; i++) {
		//若栈为空，入栈元素
		if (s.empty())
			s.push(index++);
		//当前出栈元素不等于栈顶元素，继续入栈（还有元素可以入栈）
		while (A[i] != s.top() && index <= n) {
			s.push(index++);
		}
		//当前栈内元素大于规定值
		if (s.size() > m)
			break;
		//出栈
		if (A[i] == s.top()) {
			s.pop();
		}
	}
	return s.empty() ? "YES" : "NO";
}

string f2(int A[]) {
	int index = 1;
	stack<int> s;
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		//每次入栈
		s.push(i);
		if (s.size() > m) {
			flag = false;
			break;
		}
		//出栈所有能出栈的元素
		while (!s.empty() && s.top() == A[index]) {
			s.pop();
			index++;
		}
	}
	if (flag && s.empty())
		return "YES";
	else
		return "NO";
}

int main() {
	cin>>m>>n>>k;
	int A[k][n+1];
	string ans[k];
	for (int i = 0; i < k; i++) {
		for (int j = 1; j <= n; j++) {
			cin>>A[i][j];
		}
		ans[i] = f2(A[i]);
	}
	for (int i = 0; i < k; i++) {
		cout<<ans[i];
		if (i < k-1)
			cout<<endl;
	}
	return 0;
}