#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define fst first
#define snd second
using namespace std;

const int N = 1000005;
const int mod = 1e9 + 7;

int n, x, y;
long long cnt[N];

int power(int n, int e) {
	long long ret = 1;
	long long res = n;
	while (e) {
		if (e & 1) (ret *= res) %= mod;
		(res *= res) %= mod;
		e >>= 1;
	}
	return ret;
}

int get(int x) {
	return -1;
}

int main() {
	for (int i = 2; i < N; i++) {
		if (cnt[i] == 0) for (int j = i; j < N; j += i) cnt[j]++;
	}
	for (int i = 1; i < N; i++) (cnt[i] += cnt[i - 1]) %= mod;
	while (scanf("%d%d%d", &n, &x, &y) && n + x + y > 0) {
		long long ans = 0;
		//for (int i = 1; i <= y - x; i++) {
			//(ans += cnt[i]) %= mod;
		//}
		ans = cnt[y - x];
		(ans *= (long long)power(2, y - x - 1)) %= mod;
		printf("%lld\n", ans);
	}
	
	return 0;
}
