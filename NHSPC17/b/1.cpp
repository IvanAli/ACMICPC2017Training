#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

int T;
int n, r;
unsigned long long p;

bool ok() {
	if (p % n > 0) return true;
	unsigned long long cur = p / n;
	while (cur % 10 == 0) {
		cur /= 10;
	}
	if (cur == 1) return false;
	return true;
}

int main() {
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		printf("Case %d: ", tc + 1);
		scanf("%d%d%llu", &n, &r, &p);
		long long ans = log10(p / (double)n) / log10(1. + r / 100.); 
		ans += ok();
		printf("%lld\n", ans);
	}
	return 0;
}