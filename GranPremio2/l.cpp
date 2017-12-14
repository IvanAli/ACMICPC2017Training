#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define fst first
#define snd second
using namespace std;

const int N = 1000005;

int T;
int n;
int prime[N];
vector<int> primes;

vector<int> go(int n) {
	vector<int> ret;
	int i = 0;
	long long pf = primes[i];
	while (pf * pf <= n) {
		if (n % pf == 0) {
			ret.pb(pf);
			while (n % pf == 0) n /= pf;
		}
		i++; pf = primes[i];
	}
	if (n > 1) ret.pb(n);
	return ret;
}

int phi(int n) {
	int res = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) n /= i;
			res -= res / i;
		}
	}
	if (n > 1) res -= res / n;
	return res;
}

long long get(long long n, long long p) {
	long long ret = (p * ((n - 1) / p) * (((n - 1) / p) + 1)) / 2;
	return ret;
}

int main() {
	for (int i = 2; i < N; i++) prime[i] = 1;
	for (long long i = 2; i < N; i++) {
		if (prime[i]) {
			for (long long j = i * i; j < N; j += i) prime[j] = 0;
			primes.pb(i);
		}
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		vector<int> fact = go(n);
		int len = fact.size();
		long long ans = (double)n * (n - 1) / 2;
		for (int mask = 1; mask < (1 << len); mask++) {
			long long sum = 0;
			long long cur = 1;
			for (int i = 0; i < len; i++) {
				if (mask & (1 << i)) cur *= fact[i]; 
			}
			sum = get(n, cur);
			if (__builtin_popcount(mask) % 2) ans -= sum;
			else ans += sum;
		}
		printf("%d %.6f\n", phi(n), (double)ans / n);
	}
	return 0;
}
