#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100010;
bool isPrime[maxn] = {0};
bool flag[maxn] = {0};

void initPrime() {
	for (int i = 2; i < maxn; i++) {
		if (!flag[i]) {
			isPrime[i] = true;
			for (int j = i+i; j < maxn; j+=i) {
				flag[j] = true;
			}
		}
	}
}

bool f(int n, int d) {
	if (!isPrime[n])
		return false;
	vector<int> data;
	while (n != 0) {
		data.push_back(n % d);
		n /= d;
	}
	int sum = 0;
	for (int i = 0; i < data.size(); i++) {
		sum = sum * d + data[i];
	}
	return isPrime[sum];
}

int main() {
	initPrime();
	int n, d;
	while (cin>>n && n >= 0) {
		cin>>d;
		cout<<(f(n, d)?"Yes":"No")<<endl;
	}
	return 0;
}