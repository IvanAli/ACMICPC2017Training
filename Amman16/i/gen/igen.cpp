#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000;
const int maxl = 200000;

int main() {
	srand(time(0));
	int T = 123;
	printf("%d\n", T);
	for (int tc = 0; tc < T; tc++) {
		int n = rand() % maxn + 1, m = rand() % maxn + 1;
		printf("%d %d ", n, m);
		int len = rand() % maxl + 1;
		for (int i = 0; i < len; i++) {
			int dir = rand() % 4;
			if (dir == 0) putchar('^');
			if (dir == 1) putchar('<');
			if (dir == 2) putchar('v');
			if (dir == 3) putchar('>');
		}
		putchar('\n');
	}
	return 0;
}