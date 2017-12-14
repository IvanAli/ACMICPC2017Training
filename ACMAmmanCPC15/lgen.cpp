#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(NULL));
	int T = rand() % 50;
	T++;
	cout << T << endl;
	while (T--) {
		int n = rand() % 50;
		n++;
		int k = n - (rand() % 25);
		k = max(k, 2);
		if (n < k) n += 5;
		cout << n << " " << k << endl;
		for (int i = 0; i < n; i++) {
			int ok = rand() % 2;
			cout << ok;
		}
		cout << endl;
	}
	return 0;
}
