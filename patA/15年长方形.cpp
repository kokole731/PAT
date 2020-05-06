#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int f(int m, int n) {
    if (m == n)
        return 1;
    else if (m > n)
        return f(m-n, n)+1;
    else
        return f(n-m, m)+1;
}

int main() {
    int n, m;
    cin>>n>>m;
    cout<<f(n, m);
    return 0;
}