#include <bits/stdc++.h>
using namespace std;

const int maxn = 65;

int n;
char a[maxn];
char b[maxn];

int main() {
	scanf("%d%s%s", &n, a, b);
	long long la = 0, ra = (1ll << n) - 1;
	long long lb = 0, rb = (1ll << n) - 1;
	bool ta = 1, tb = 1;
	for (int i = 0; i < n; i++) {
		long long ma = la + ra >> 1ll;
		long long mb = lb + rb >> 1ll;
		if (a[i] == '1') {
			if (ta) la = ma + 1;
			else ra = ma;
			ta = !ta;
		} else {
			if (ta) ra = ma;
			else la = ma + 1;
		}
		if (b[i] == '1') {
			if (tb) lb = mb + 1;
			else rb = mb;
			tb = !tb;
		} else {
			if (tb) rb = mb;
			else lb = mb + 1;
		}
	}
	assert(la == ra);
	assert(lb == rb);
	long long ans = rb - ra - 1;
	printf("%lld\n", ans);
	return 0;
}