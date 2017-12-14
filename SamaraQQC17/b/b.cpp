#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
using namespace std;

const int maxn = 200005;

int n;
pair<int, int> ab[maxn];

bool ok(long long x) {
	for (int i = 0; i < n; i++) {
		if (x < ab[i].fst) return false;
		x -= ab[i].snd;
	}
	return x >= 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &ab[i].fst, &ab[i].snd);
	sort(ab, ab + n, [&](pair<int, int> a, pair<int, int> b) { 
		return a.fst - a.snd > b.fst - b.snd;
	});
	long long ans = ab[0].fst;
	long long cur = ab[0].fst;
	for (int i = 0; i < n; i++) {
		ans += max(0ll, ab[i].fst - cur);
		cur += max(0ll, ab[i].fst - cur);
		cur -= ab[i].snd;
	}
	printf("%lld\n", ans);
	return 0;
}