#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin>>a>>b;
	int c = a * b;
	int sum = 0;
	while (c != 0) {
		sum = sum * 10 + c % 10;
		c /= 10;
	}
	cout<<sum;
	return 0;
}