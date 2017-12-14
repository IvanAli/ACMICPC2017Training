#include <bits/stdc++.h>
using namespace std;


int main() {
	srand(time(0));
	int T = rand() % 10000 + 1;
	cout << T << endl;
	while (T--) {
		int n, h, k;
		n = rand() % 10 + 1;
		h = rand() % 50 + 1;
		k = rand() % n + 1;
		cout << n << ' ' << h << ' ' << k << endl;
		for (int i = 0; i < n; i++) {
			int x, y;
			x = rand() % 50 + 1, y = rand() % 50 + 1;
			cout << x << ' ' << y << endl;
		}
	}
	return 0;
}