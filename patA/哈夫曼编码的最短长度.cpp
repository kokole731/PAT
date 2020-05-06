#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
const int maxn = 110;
int idx = 0;

struct Node {
    //节点的值，代表字符出现的次数
    int data;
    int left, right;
}node[maxn];

struct cmp {
    //这边是相反的
    bool operator() (int a, int b) const {
        //最小的在最前面
        return node[a].data > node[b].data;
    }
};

int createTree(int left, int right) {
    node[idx].data = node[left].data + node[right].data;
    node[idx].left = left;
    node[idx].right = right;
    return idx++;
}

void DFS(int root, int& sum, int depth) {
    if (root == -1)
        return;
    if (node[root].left == -1 && node[root].right == -1) {
        sum += node[root].data * depth;
    }
    DFS(node[root].left, sum, depth+1);
    DFS(node[root].right, sum, depth+1);
}

int main() {
    string s;
    cin>>s;
    int hash[128] = {0};
    for (int i = 0; i < s.size(); i++) {
        int x = s[i];
        hash[x]++;
    }
    priority_queue<int, vector<int>, cmp> q;
    for (int i = 0; i < 128; i++) {
        if (hash[i] != 0) {
            node[idx].data = hash[i];
            node[idx].left = node[idx].right = -1;
            q.push(idx++);
        }
    }
    int num1, num2, newNum;
    while (q.size() > 1) {
        num1 = q.top();
        q.pop();
        num2 = q.top();
        q.pop();
        newNum = createTree(num1, num2);
        q.push(newNum);
    }
    int root = idx-1, ans = 0;
    DFS(root, ans, 0);
    cout<<ans;
    return 0;
}