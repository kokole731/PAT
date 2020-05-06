#include <iostream>
#include <vector>
using namespace std;
const int maxn = 101;
int n;
bool isGood[maxn];
int personId[maxn];
vector<int> ans;
bool findAns = false;

void DFS(int index, int cnt) {
	if (index == n+1) {
		if (cnt == 2) {
			int a = ans[0], b = ans[1];
			int sum = 0;
			int w = 0;
			for (int i = 1; i <= n; i++) {
				//是不是坏人
				bool isBad = (personId[i] == a||personId[i] == b);
				if (isGood[i] == isBad){
					//狼人说谎
					if (i == a || i == b)
						w++;
					sum++;
				}
			}
			if (sum == 2 && w == 1 && !findAns) {
				cout<<a<<" "<<b;
				findAns = true;
			}
		}
		return;
	}
	if (cnt > 2)
		return;
	ans.push_back(index);
	DFS(index+1, cnt+1);
	ans.pop_back();
	DFS(index+1, cnt);
}

int main() {
	cin>>n;
	int index;
	char c;
	for (int i = 1; i <= n; i++) {
		//person i 说 index 是狼人吗
		cin>>c>>index;
		isGood[i] = c == '+';
		personId[i] = index;
	}
	DFS(1, 0);
	if (!findAns)
		cout<<"No Solution";
	return 0;
}