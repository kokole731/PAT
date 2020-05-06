#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> number[5];

int main() {
	int n;
	cin>>n;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin>>tmp;
		number[tmp % 5].push_back(tmp);
	}
	int even_sum = 0;			
	for (int i = 0; i < number[0].size(); i++) {
		if (number[0][i] % 2 == 0)
			even_sum+=number[0][i];
	}
	if (even_sum == 0)
		cout<<"N ";
	else
		cout<<even_sum<<" ";
	// -------
	int now = 1, sum_1 = 0;
	for (int i = 0; i < number[1].size(); i++) {
		if(now == 1)
			sum_1 += number[1][i];
		else
			sum_1 -= number[1][i];
		now = 1-now;
	}
	if (number[1].size() == 0)
		cout<<"N ";
	else
		cout<<sum_1<<" ";
	// --------
	if (number[2].size() == 0)
		cout<<"N ";
	else
		cout<<number[2].size()<<" ";
	// --------
	double sum_3 = 0;
	for (int i = 0; i < number[3].size(); i++) {
		sum_3 += number[3][i];
	}
	if (number[3].size() == 0)
		cout<<"N ";
	else
		printf("%.1f ", sum_3/number[3].size());
	// --------
	int max_num = 0;
	for (int i = 0; i < number[4].size(); i++) {
		if (number[4][i] > max_num)
			max_num = number[4][i];
	}
	if (max_num == 0)
		cout<<"N";
	else 
		cout<<max_num;
	return 0;
}