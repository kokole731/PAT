#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int maxn = 2010;
int adj[maxn][maxn] = {0};
map<int, string> id2person;
map<string, int> person2id;
int personId = 0;

bool flag[maxn] = {0};

vector<vector<int> > group;
int groupID = 0;
int groupSum = 0;

void DFS(int x) {
    flag[x] = true;
    group[groupID].push_back(x);
    for (int i = 0; i < personId; i++) {
        if (!flag[i] && adj[i][x] != 0){
            groupSum += adj[i][x];
            DFS(i);
        }
    }
}

struct Group
{   
    int x;
    string head;
} g;

bool cmp (Group a, Group b) {
    return a.head < b.head;
}

int main() {
    int n, k;
    cin>>n>>k;
    string a, b;
    int tmp;
    fill(adj[0], adj[0] + maxn*maxn, 0);
    for (int i = 0; i < n; i++) {
        cin>>a>>b>>tmp;
        //将a、b的名称转换为id
        if (person2id.find(a) == person2id.end()){
            person2id[a] = personId;
            id2person[personId++] = a;
        }
        if (person2id.find(b) == person2id.end()){
            person2id[b] = personId;
            id2person[personId++] = b;
        }
        adj[person2id[a]][person2id[b]] += tmp;
        adj[person2id[b]][person2id[a]] += tmp;
    }
    for (int i = 0; i < personId; i++) {
        if (!flag[i]) {
            groupSum = 0;
            vector<int> vi;
            group.push_back(vi);
            DFS(i);
            if (group[groupID].size() <= 2)
                group.pop_back();
            else
                groupID++;
        }
    }
    vector<Group> ans;
    for (int i = 0; i < group.size(); i++) {
        int maxNum = 0, x, tmp, maxId;
        int total = 0;
        for (int j = 0; j < group[i].size(); j++){
            tmp = 0;
            x = group[i][j];
            for (int m = 0; m < personId; m++) {
                tmp += adj[x][m];
                total += adj[x][m];
            }
            if (tmp > maxNum) {
                maxNum = tmp;
                maxId = x;
            }
        }
        if (total <= k * 2)
            continue;
        g.x = group[i].size();
        g.head = id2person[maxId];
        ans.push_back(g);
    }
    cout<<ans.size()<<endl;
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++) {
        cout<<ans[i].head<<" "<<ans[i].x<<endl;
    }
    return 0;
}
