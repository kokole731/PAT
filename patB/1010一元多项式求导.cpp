#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int a, b;
    vector<pair<int, int> > vi;
    while (scanf("%d %d", &a, &b) != EOF && b != 0) {
        a *= b;
        b --;
        vi.push_back(make_pair(a, b));
    }
    for (int i = 0; i < vi.size(); i++) {
        cout<<vi[i].first<<" "<<vi[i].second;
        if (i < vi.size()-1)
            cout<<" ";
    }
    if (vi.size() == 0)
        cout<<"0 0";
    return 0;
}
