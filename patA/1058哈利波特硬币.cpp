#include <iostream>
#include <map>
using namespace std;
// map<int, int> mp = {
// 	{0: 29},
// 	{1: 17},
// }

struct Money{
	int G, S, K;
	Money(int g, int s, int k) {
		G = g;
		S = s;
		K = k;
	}
};

Money add(Money a, Money b) {
	int add = 0, g, s, k;
	for (int i = 0; i < 3; i++) {
		switch(i) {
			case 0:
				k = (a.K + b.K) % 29;
				add = (a.K + b.K) / 29;
				break;
			case 1:
				s = (a.S + b.S + add) % 17;
				add = (a.S + b.S + add) /17;
				break;
			case 2:
				g = a.G + b.G + add;
				break;
			default:
				break;
		}
	}
	return Money(g, s, k);
}

int main() {
	int g, s, k;
	scanf("%d.%d.%d", &g, &s, &k);
	Money a = Money(g, s, k);
	scanf("%d.%d.%d", &g, &s, &k);
	Money b = Money(g, s, k);
	Money c = add(a, b);
	printf("%d.%d.%d", c.G, c.S, c.K);	
	return 0;
}