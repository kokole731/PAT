#include <iostream>
#include <algorithm>
using namespace std;
// -2 11 -4 13 -5 -2
int main() {
    int n;
    cin>>n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin>>A[i];
    int f[n+1];
    int ansStart = 0, ansEnd = 0;
    int startP, endP, ans = A[0];
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            f[i] = 0;
            startP = 0;
            endP = 0;
        }else {
            if (f[i-1] <= 0) {
                startP = i;
                f[i] = A[i];
            }else {
                f[i] = f[i-1]+A[i];
            }
            endP = i;
        }
        if (f[i] > ans) {
            ans = f[i];
            ansStart = startP;
            ansEnd = endP;
        }
    }
    cout<<ansStart<<" "<<ansEnd;
    return 0;
}