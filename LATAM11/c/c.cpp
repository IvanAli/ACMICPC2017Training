#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 100005;

int n;
long long c[maxn];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	while (scanf("%d", &n) && n > 0) {
		for (int i = 0; i < n; i++) scanf("%d", &c[i]);
		long long g = 0;
		for (int i = 0; i < n; i++) g = gcd(g, c[i]);
		vector<long long> gdiv;
		for (long long i = 1; i * i <= g; i++) {
			if (g % i == 0) {
				gdiv.pb(i);
				if (i != g / i) gdiv.pb(g / i);
			}
		}
		sort(gdiv.begin(), gdiv.end());
		long long ans = 0;
		for (int i = 0; i < gdiv.size(); i++) {
			int cur = gdiv[i];
			long long res = ((c[0] - 1) / cur) / n;
			assert(c[0] % cur == 0);
			long long rem = (c[0] / cur) % n;
			bool ok = true;
			for (int j = 0; j < n; j++) {
				assert(c[j] % cur == 0);
				if (c[j] / cur <= n || (c[j] / cur) % n != rem) ok = false;
				res = min(res, ((c[j] - 1) / cur) / n);
			}
			if (ok) ans += res;
		}
		printf("%lld\n", ans);
	} 
	return 0;
}