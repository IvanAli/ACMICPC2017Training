#include <bits/stdc++.h>
using namespace std;

const int maxn = 20005;
const int mod = 1e9 + 7;

int T, n, m;
long long fact[maxn];

long long inv(long long x) {
	int e = mod - 2;
	long long ret = 1;
	long long cur = x;
	while (e) {
		if (e & 1) (ret *= cur) %= mod;
		(cur *= cur) %= mod;
		e >>= 1;
	}
	return ret;
}

long long c(int n, int k) {
	long long ret = fact[n] * inv(fact[n - k]);
	ret %= mod;
	ret *= inv(fact[k]);
	ret %= mod;
	return ret;
}

int main() {
	fact[0] = 1;
	for (long long i = 1; i < maxn; i++) fact[i] = (i * fact[i - 1]) % mod;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		cout << c(a + b, a) << endl;
	}
	return 0;
}