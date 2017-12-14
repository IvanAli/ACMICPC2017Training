#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int n, k;
long long g[1005];

int main() {
	cin >> n >> k;
	int m = n % (k + 1);
	if (m > 0) {
		g[0] = 2 * (m - 1) - 1;
	}
	for (int i = 1; i < 1005; i++) g[i] = (2 * g[i - 1] + 2 * k + 1) % mod;
	cout << g[n / (k + 1)] << endl;
	return 0;
}
