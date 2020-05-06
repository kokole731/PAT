#include <iostream>
#include <string>
using namespace std;
char head[5] = {'S', 'H', 'C', 'D', 'J'};

int main() {
	string A[55], tmp;
	for (int i = 0; i < 5; i++) {
		if (i == 4) {
			A[i * 13+1] = "J1";
			A[i * 13+2] = "J2";
		}else {
			for (int j = 1; j <= 13; j++) {
				tmp = "";
				tmp += head[i];
				A[i*13+j] = tmp + to_string(j);
			}
		}
	}
	int n, B[55];
	string copy[55];
	cin>>n;
	for (int i = 1; i <= 54; i++) {
		cin>>B[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 54; j++) {
			copy[j] = A[j];
		}
		for (int j = 1; j <= 54; j++) {
			A[B[j]] = copy[j]; 
		}
	}
	for (int i = 1; i <= 54; i++) {
		cout<<A[i];
		if (i <= 53)
			cout<<" ";
	}
	return 0;
}