#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int T;
long long n;
long long k;

long long inv(long long x) {
	long long e = mod - 2;
	long long ret = 1, res = x;
	if (e < 0) return 0;
	while (e) {
		if (e & 1) (ret *= res) %= mod;
		(res *= res) %= mod;
		e >>= 1;
	}
	return ret;
}

long long get() {
	long long ret;
	ret = ((((((n - 1) * n) % mod) * (((2 * n) % mod) - 3)) % mod) * inv(6)) % mod;
	(ret -= ((((((((k - 2) * (k - 1)) % mod) * (((2 * k) % mod) - 5)) % mod) * inv(6)) % mod) + mod)) %= mod;
	(ret += (((((n - 1) * (n)) % mod) * inv(2)))) %= mod;
	(ret -= (((((k - 2) * (k - 1)) % mod) * inv(2)) + mod)) %= mod;
	return ret;
}

long long g(long long n) {
	return (((((n * n) % mod) + n) % mod) * inv(2)) % mod;
}

int main() {
	scanf("%d", &T);
	int tc = 1;
	while (T--) {
		scanf("%lld", &n);
		cerr << "ok" << endl;
		k = (n + 2) / 2;
		long long ans = k * get();
		(ans += (((n - k + 1) * g(k)) % mod)) %= mod;
		(ans += ((g(k - 1) * k) % mod)) %= mod;
		printf("Case #%d: %lld\n", tc, ans);
		tc++;
	}
	return 0;
}
