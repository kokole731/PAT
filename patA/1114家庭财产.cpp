#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 10010;
//人的最大数量
int father[maxn];
int cnt[maxn] = {0};
int property[maxn] = {0};
bool flag[maxn] = {0};

struct Node {
	int minId;
	int personNum;
	double aveCnt, aveArea;
};

void init() {
	for (int i = 0; i < maxn; i++) {
		father[i] = i;
	}
}
//寻找根节点
int find(int x) {
	int a = x;
	while (x != father[x]) {
		x = father[x];
	}
	return x;
}

//合并两个团体
void union_(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) {
		father[fy] = fx;
	}
}

bool cmp (Node a, Node b) {
	if (a.aveArea != b.aveArea) {
		return a.aveArea > b.aveArea;
	}else {
		return a.minId < b.minId;
	}
}

int main() {
	init();
	int n;
	cin>>n;
	int person, par1, par2, k, child, propertyNum;
	for (int i = 0; i < n; i++) {
		// cin>>person>>par1>>par2;
		scanf("%d%d%d", &person, &par1, &par2);
		flag[person] = true;
		if (par1 != -1) {
			union_(person, par1);
			flag[par1] = true;
		}
		if (par2 != -1) {
			union_(person, par2);
			flag[par2] = true;
		}
		// cin>>k;
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			// cin>>child;
			scanf("%d", &child);
			union_(person, child);
			flag[child] = true;
		}
		// cin>>k>>propertyNum;
		scanf("%d%d", &k, &propertyNum);
		cnt[person] = k;
		property[person] = propertyNum;
	}
	//家族人数
	int minId[maxn];
	for (int i = 0; i < maxn; i++)
		minId[i] = i;
	int personNum[maxn] = {0};
	double count[maxn] = {0};
	double propSum[maxn] = {0};
	for (int i = 0; i < maxn; i++) {
		if (flag[i] == true) {
			int fi = find(i);
			personNum[fi]++;
			count[fi] += cnt[i];
			propSum[fi] += property[i];
			if (i < minId[fi]) {
				minId[fi] = i;
			}
		}
	}
	vector<Node> ans;
	for (int i = 0; i < maxn; i++) {
		if (personNum[i] > 0) {
			Node family;
			family.minId = minId[i];
			family.personNum = personNum[i];
			family.aveArea = propSum[i]/personNum[i];
			family.aveCnt = count[i] / personNum[i];
			ans.push_back(family);
		}
	}
	printf("%d\n", ans.size());
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++) {
		Node family = ans[i];
		printf("%04d %d %.3f %.3f\n", family.minId, family.personNum, family.aveCnt, family.aveArea);
	}
	return 0;
}