#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s;
    cin>>s;
    int p1 = 1, p2 = 4, idx = 0;
    int A[10];
    for (int i = 0; i < s.size(); i++) {
        if (i == p1 ||i == p2)
            continue;
        A[idx++] = s[i]-'0';
    }
    int ans = 0;
    for (int i = 0; i < 9; i++) {
        ans += A[i] * (10-i);
    }
    s += '-';
    switch (ans % 11)
    {
    case 10:
        s += 'X';
        break;
    case 11:
        s += '0';
        break;
    default:
        s += ans % 11 + '0';
        break;
    }
    cout<<s;
    return 0;
}