#include <iostream>
using namespace std;

int f(int n, int k) {
	int N = n;
	int product = 1;
	while (n != 0) {
		n /= 10;
		product *= 10;
	}
	int rst = k * N * N;
	return rst % product;
}

int main() {
	int m;
	cin>>m;
	int num;
	for (int i = 0 ; i < m; i++) {
		cin>>num;
		if (num == 0) {
			cout<<"0 0";
		}else {
			int k;
			bool flag = false;
			for (k = 1; k < 10; k++) {
				if (num == f(num, k)) {
					flag = true;
					cout<<k<<" "<<num*num*k;
					break;
				}
			}
			if (!flag) {
				cout<<"No";
			}
		}
		if (i < m-1)
			cout<<endl;
	}
}