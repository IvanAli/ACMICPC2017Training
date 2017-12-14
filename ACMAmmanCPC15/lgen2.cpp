#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(NULL));
	int T = 128;
	cout << T << endl;
	while (T--) {
		int n = 100000;
		int k = n - (rand() % 256);
		cout << n << " " << k << endl;
		for (int i = 0; i < n; i++) {
			int ok = rand() % 2;
			cout << ok;
		}
		cout << endl;
	}
	return 0;
}
