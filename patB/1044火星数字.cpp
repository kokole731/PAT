#include <iostream>
#include <string>
#include <map>
using namespace std;

string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
				"jly", "aug", "sep", "oct", "nov", "dec"};
string b[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes",
				 "hei", "elo", "syy", "lok", "mer", "jou"};

map<string, int> mar2earth;
map<int, string> earth2mar;

void make_table () {
	string s;
	for (int i = 0; i < 169; i++) {
		if (i < 13) {
			s = a[i];
			earth2mar[i] = s;
			mar2earth[s] = i;
		}else {
			if (i % 13 == 0) {
				s = b[i/13];
				earth2mar[i] = s;
				mar2earth[s] = i;
			}else {
				int x = i / 13;
				int y = i % 13;
				s = "";
				s += b[x];
				s += " ";
				s += a[y];
				earth2mar[i] = s;
				mar2earth[s] = i;
			}
		}
	}
}

int main() {
	int n;
	cin>>n;
	string A[n+1];
	string tmp;
	for (int i = 0; i <= n; i++) {
		getline(cin, tmp);
		A[i] = tmp;
	}
	make_table();
	for (int i = 1; i <= n; i++) {
		if (A[i][0] <= '9' && A[i][0] >= '0') {
			int sum = 0;
			for (int j = 0; j < A[i].length(); j++) {
				sum = sum * 10 + (A[i][j]-'0');
			}
			cout<<earth2mar[sum];
		}
		else {
			cout<<mar2earth[A[i]];
		}
		if ( i < n )
			cout<<endl;
	}
	return 0;
}