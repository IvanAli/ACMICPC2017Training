#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 1234567;
int n;
vector<int> primes;
bool prime[maxn];


vector<pair<int, int> > go(int n) {
	int i = 0, pf = primes[0];
	vector<pair<int, int> > ret;
	while (pf * pf <= n) {
		if (n % pf == 0) {
			int times = 0;
			while (n % pf == 0) {
				times++;
				n /= pf;
			}
			ret.pb({pf, times});
		}
		pf = primes[++i];
	}
	if (n > 1) ret.pb({n, 1});
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < maxn; i++) prime[i] = 1;
	for (long long i = 2; i < maxn; i++) {
		if (prime[i]) {
			primes.pb(i);
			for (long long j = i * i; j < maxn; j += i) prime[j] = 0;
		}
	}
	if (n == 1) return printf("%d\n", 1), 0;
	vector<pair<int, int> > fact = go(n);
//	if (fact.size() == 1 && fact[0].first == n && fact[0].second == 1) return printf("%d\n", (n + 1) / 2), 0; 
	long long mul = 1;
	for (int i = fact[0].first == 2 ? 1 : 0; i < fact.size(); i++) {
		for (int j = 0; j < fact[i].second; j++) {
			mul *= ((fact[i].first + 1) / 2);
		}
	}
	if (fact[0].first == 2) {
		long long tmp = 1;
		for (int j = 0; j < fact[0].second - 1; j++) {
			tmp *= 2;
		}	
		tmp++;
		mul *= tmp;
	}
	printf("%lld\n", mul);
	return 0;
}