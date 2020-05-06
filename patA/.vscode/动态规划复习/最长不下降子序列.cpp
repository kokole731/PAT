#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// 8
// 1 2 3 -9 3 9 0 11
//把答案策略也记下来
int main() {
    int n;
    cin>>n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin>>A[i];
    }
    int f[n];
    int choice[n][n], k, maxK;
    for (int i = 0; i < n; i++) {
        choice[i][i] = 1;
        f[i] = 1;
        if (i > 0){
            k = i, maxK = 1;
            for (int j = 0; j < i; j++) {
                if (A[i] >= A[j] && (f[j]+1) > maxK) {
                    maxK = f[j]+1;
                    k = j;
                }
            }
            f[i] = maxK;
            if (k == i) {
                for (int j = 0; j < i; j++)
                    choice[i][j] = 0;
            }
            for (int j = 0; j < i; j++) {
                choice[i][j] = (j <= k)? choice[k][j]: 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (choice[n-1][i]) {
            cout<<A[i]<<" ";
        }
    }
    return 0;
}