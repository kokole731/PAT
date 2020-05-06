#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;
const int maxn = 220;
const int INF = INT_MAX;
int N, M;
int adj[maxn][maxn];
int ansSum = 0;
int path[maxn];

void f() {
    bool flag[maxn] = {0};
    int d[maxn];
    fill(d, d+maxn, INF);
    d[0] = 0;
    for (int i = 0; i < N; i++){
        int u = -1, minNum = INF;
        for (int j = 0; j < N; j++) {
            if (d[j] < minNum && !flag[j]) {
                minNum = d[j];
                u = j;
            }
        }
        cout<<u<<" ";
        if (u == -1) 
            break;
        flag[u] = true;
        cout<<minNum<<endl;
        ansSum += minNum;
        if (i > 0) {
            cout<<"边为:"<<path[u]<<" "<<u<<endl;
        }
        for (int j = 0; j < N; j++) {
            if (!flag[j] && adj[j][u] != INF && adj[u][j] < d[j]) {
                d[j] = adj[u][j];
                path[j] = u;
            }
        }
    }
}

int main() {
    fill(adj[0], adj[0]+maxn*maxn, INF);
    cin>>N>>M;
    int left,right, weigh;
    for (int i = 0; i < M; i++) {
        cin>>left>>right>>weigh;
        adj[left][right] = weigh;
        adj[right][left] = weigh;
    }
    f();
    cout<<ansSum;
    return 0;
}