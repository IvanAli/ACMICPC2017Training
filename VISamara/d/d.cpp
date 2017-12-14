#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;
//const int mod = 1e9 + 9;
const int mod = 1000000009;

int n;
int fact[maxn];

int power(int n, int e) {
	long long ret = 1;
	long long res = n;
	while (e) {
		if (e & 1) (ret *= res) %= mod;
		(res *= res) %= mod;
		e >>= 1;
	}
	return ret;
}

int inv(int n) {
	return power(n, mod - 2);
}

int c(int n, int k) {
	long long ret = fact[n];
	(ret *= inv(fact[n - k])) %= mod;
	(ret *= inv(fact[k])) %= mod;
	return ret;
}

int main() {
	scanf("%d", &n);
	fact[0] = 1;
	for (long long i = 1; i < maxn; i++) fact[i] = (fact[i - 1] * i) % mod;
	long long ans = 0;
	for (int i = 1; i <= n - 1; i++) (ans += (((long long)c(n, i) * (long long)((power(2, n - i) - 1 + mod) % mod)) % mod)) %= mod;
	printf("%lld\n", ans);
	return 0;
}