#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 1000005;

bool prime[maxn];
vector<long long> primes;
long long k;

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
	for (int i = 0; i < maxn; i++) prime[i] = 1;
	for (long long i = 2; i < maxn; i++) {
		if (prime[i]) {
			primes.pb(i);
			for (long long j = i * i; j < maxn; j += i) prime[j] = 0;
		}
	}
//	scanf("%lld", &k);
	cin >> k;
	vector<long long> kdiv;
	kdiv.pb(1);
	vector<pair<int, int> > fact = go(k);
	for (auto pf : fact) {
		int len = kdiv.size();
		long long cur = pf.first;
		int times = pf.second;
		for (int t = 0; t < times * 2; t++) {
			for (int i = 0; i < len; i++) kdiv.pb(kdiv[i] * cur);
			cur *= pf.first;
		}
	}
	vector<long long> a;
	for (auto it : kdiv) a.pb(it + k);
	sort(a.begin(), a.end());
	int n = a.size();
//	printf("%d\n", n);
	cout << n << endl;
//	for (int i = 0; i < n; i++) printf("%lld %lld\n", a[i], a[n - i - 1]);
	for (int i = 0; i < n; i++) cout << a[i] << " " << a[n - i - 1] << endl;
	return 0;
}	