#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 1000005;
vector<long long> primes;
bitset<maxn> prime;

int T;
long long n;

long long power(long long x, int e) {
	long long ret = 1;
	long long res = x;
	while (e) {
		if (e & 1) ret *= res;
		res *= res;
		e >>= 1;
	}
	return ret;
}

int main() {
	prime.set();
	for (long long i = 2; i < maxn; i++) {
		if (prime[i]) {
			primes.pb(i);
			for (long long j = i * i; j < maxn; j += i) prime[j] = 0;
		}
	} 
	scanf("%d", &T);
	while (T--) {
		scanf("%lld", &n);
		long long ans = 1;
		long long tmp = n;
		for (int i = 0; primes[i] * primes[i] <= tmp; i++) {
			int cnt = 0;
			while (tmp % primes[i] == 0) tmp /= primes[i], cnt++;
			ans *= ((power(primes[i], cnt + 1) - 1) / (primes[i] - 1));
		}
//		fprintf(stderr, "sum1: %lld\n", ans);
		if (tmp > 1) ans *= ((power(tmp, 2) - 1) / (tmp - 1));
		ans -= n;
//		fprintf(stderr, "sum: %lld\n", ans);
		if (ans < n) printf("deficient\n");
		else if (ans == n) printf("perfect\n");
		else if (ans > n) printf("abundant\n");
	}
	return 0;
}
