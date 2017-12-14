#include <bits/stdc++.h>
#define y1 aoksoda
using namespace std;


int main() {
	srand(time(0));
	int T = rand() % 300 + 1;
	printf("%d\n", T);
	while (T--) {
		int n = rand() % 10000 + 1;
		printf("%d\n", n);
		for (int i = 0; i < n; i++) {
			int x1, y1, x2, y2;
			x1 = rand() % 200;
			y1 = rand() % 200;
			x2 = rand() % 200;
			y2 = rand() % 200;
			if (rand() % 2) x1 *= -1;
			if (rand() % 2) y1 *= -1;
			if (rand() % 2) x2 *= -1;
			if (rand() % 2) y2 *= -1;
			printf("%d %d %d %d\n", x1, y1, x2, y2);
		}
	}
	return 0;
}