#include <iostream>
#include <string>
#include <map>
using namespace std;
//the char and its appear time
map<char, int> mp;

int main() {
    string s;
    getline(cin, s);
    int len = s.length();
    for (int i = 0; i < len; i++) {
        char t = s[i];
        if (t <= 'Z' && t >= 'A')
            t = (t-'A') + 'a';
        if (mp.find(t) != mp.end()) {
            mp[t]+= 1;
        }else
            mp[t] = 1;
    }    
    int maxCnt = 0;
    char maxChar;
    for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        if (!('a' <= it->first && 'z' >= it->first))
            continue;
        if (it->second > maxCnt) {
            maxCnt = it->second;
            maxChar = it->first;   
        }
        if (it->second == maxCnt && it->first < maxChar) {
            maxCnt = it->second;
            maxChar = it->first;
        }   
    }
    cout<<maxChar<<" "<<maxCnt;
    return 0;
}