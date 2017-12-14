#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

bitset<N> prime;
int pre[N];
int T;

int main() {
	prime.set();
	for (long long i = 2; i < N; i++) if (prime[i]) {
		for (long long j = i * i; j < N; j += i) prime[j] = 0;
	}
	prime[1] = 0;
	prime[0] = 0;
	for (int i = 0; i < N; i++) {
		if (prime[__builtin_popcount(i)]) pre[i] = 1;
		if (i > 0) pre[i] += pre[i - 1];
	}
	scanf("%d", &T);
	while (T--) {
		int l, r; scanf("%d%d", &l, &r);
		int ans = pre[r];
		if (l > 0) ans -= pre[l - 1];
		printf("%d\n", ans);
	}
	return 0;
}