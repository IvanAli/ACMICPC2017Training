#include <bits/stdc++.h>
using namespace std;


int main() {
	srand(time(0));
	int n = rand() % 10;
	n++;
	int m = rand() % 50;
	m++;
	printf("%d %d\n", n, m);
	for (int i = 0; i < n; i++) {
		int p = rand() % 50;
		p++;
		int w = rand() % 70;
		w++;
		int d = rand() % 70;
		d++;
		printf("%d %d %d\n", p, w, d);
	}
	return 0;
}
