#include <bits/stdc++.h>
using namespace std;

int T, n;

int main() {
	scanf("%d", &T);
	while (T--) {
		 scanf("%d", &n);
		 int x, y;
		 int k = (n + 8) / 13;
		 if (n == 1) x = 0, y = 0;
		 else if (n == 2) x = -1, y = 0;
		 else if (n == 3) x = 0, y = 1;
		 else if (n == 4) x = 1, y = 0;
		 else {
			 if (13 * k - 8 <= n && n <= 13 * k - 8 + 1 + 4 * k) {
			 	x = 2 * k - (n - (13 * k - 8));
			 	y = -k;
			 } else if (13 * k - 8 + 1 + 4 * k < n && n <= 13 * k - 8 + 1 + 4 * k + 1 + 2 * k) {
			 	x = -2 * k - 1 + (n - (13 * k - 8 + 1 + 4 * k));
			 	y = -k + (n - (13 * k - 8 + 1 + 4 * k));
			 } else if (13 * k - 8 + 1 + 4 * k + 1 + 2 * k < n && n < 13 * (k + 1) + 8) {
			 	x = n - (13 * k - 8 + 1 + 4 * k + 1 + 2 * k);
			 	y = k + 1 - (n - (13 * k - 8 + 1 + 4 * k + 1 + 2 * k));
			 } else assert(0);
		 }
		 printf("%d %d\n", x, y);
	}
	return 0;
}
