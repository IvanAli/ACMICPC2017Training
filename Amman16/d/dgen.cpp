#include <bits/stdc++.h>
using namespace std;


int main() {	
	srand(time(0));
	int T = 1000;
	printf("%d\n", T);	
	while (T--) {
		int n = rand() % 20 + 1;
		int m = rand() % 20 + 1;
		printf("%d %d\n", n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (j > 0) putchar(' ');
				int ran = rand() % 5 + 1;
				printf("%d", ran);
			}
			putchar('\n');
		}
	}
	return 0;
}