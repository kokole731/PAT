#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int maxn = 110;
int f[maxn][maxn];

int helper(string a, string b) {
    int lenA = a.size();
    int lenB = b.size();
    if (f[lenA][lenB] >= 0)
        return f[lenA][lenB];
    if(lenA == 0 || lenB == 0){
        f[lenA][lenB] = 0;
        return 0;
    }
    if(a[lenA-1] == b[lenB-1]) {
        f[lenA][lenB] = helper(a.substr(0, lenA-1), b.substr(0, lenB-1))+1;
        return f[lenA][lenB];
    }else {
        f[lenA][lenB] = max(helper(a.substr(0, lenA-1), b.substr(0, lenB)), helper(a.substr(0, lenA), b.substr(0, lenB-1)));
        return  f[lenA][lenB];
    }
}

int main() {
    fill(f[0], f[0]+maxn*maxn, -1);
    string a, b;
    cin>>a>>b;
    // cout<<helper(a, b);
    int la = a.size(), lb = b.size();
    int dp[maxn+1][maxn+1];
    for (int i = 0; i <= la; i++) {
        for (int j = 0; j <= lb; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else {
                if (a[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+1;
                }else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }
    cout<<dp[la][lb];
    return 0;
}