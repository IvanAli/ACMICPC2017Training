#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define fmax asda
#define smax fdfd
using namespace std;

const int M = 63211239;
const int N = 1005;
const int B = 1000005;
const int mod = 1000000001;

int T;
int n;
long long a[N], b[N];
vector<pair<int, int>> fact[N];
map<int, int> fmax, smax;
bitset<M> prime;
vector<int> primes;

int mul(int a, int b) {
	return (long long) a * b % mod;
}

vector<pair<int, int>> go(int n) {
	vector<pair<int, int>> ret;
	for (auto pf : primes) {
		if (pf * pf > n) break;
		if (n % pf == 0) {
			int cnt = 0;
			while (n % pf == 0) n /= pf, cnt++;
			ret.pb({pf, cnt});
			if (fmax[pf] < cnt) smax[pf] = fmax[pf], fmax[pf] = cnt;
			else smax[pf] = max(smax[pf], cnt);
		}
	}
	if (n > 1) {
		int cnt = 1;
		ret.pb({n, cnt});
		if (fmax[n] < cnt) smax[n] = fmax[n], fmax[n] = cnt;
		else smax[n] = max(smax[n], cnt);
	}
	return ret;
}

int power(int n, int e) {
	int ret = 1, res = n;
	while (e) {
		if (e & 1) ret = mul(ret, res);
		res = mul(res, res);
		e >>= 1;
	}
	return ret;
}


int gcd(int a, int b) {
	while (b > 0) {
		int aa = b;
		int bb = a % b;
		a = aa, b = bb;
	}
	return a;
}

long long lcm(int a, int b) {
	return (long long) a * b / gcd(a, b);
}

int main() {
	prime.set();
	for (long long i = 2; i < B; i++) {
		if (prime[i]) {
			primes.pb(i);
			for (long long j = i * i; j < B; j += i) prime[j] = 0;
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld", a + i), a[i] %= mod;
	for (int i = 0; i < n; i++) fact[i] = go(a[i]);
	for (int i = 0; i < n; i++) {
		b[i] = 1;
		for (auto pf : fact[i]) {
			int dif = pf.snd - smax[pf.fst];
			if (dif > 0) b[i] = mul(b[i], power(pf.fst, dif));
		}
	}
	long long ans = 1;
	for (int i = 0; i < n; i++) ans = lcm(ans, b[i]) % mod;
	printf("%d\n", ans);
	return 0;
}
