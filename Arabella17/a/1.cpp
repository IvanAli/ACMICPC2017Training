#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 200005;

int T;
char s[N];
int pos[N];
int sz;
int n;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", s);
		int len = 0;
		sz = 0;
		int one = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') len++;
			if (s[i] == '1') one++;
			if (s[i] == '1') pos[sz++] = len, len = 0;
		}
		pos[sz++] = len;
		if (one == 0) {
			printf("0\n");
			continue;
		}
		long long odd = 0, even = 0;
		for (int i = 0; i < sz; i++) if (i & 1) odd += pos[i] + 1; else even += pos[i] + 1;
		long long ans = odd * even + one;
		ans -= 2 * (odd + even);
		ans += pos[0] + pos[sz - 1] + (one > 0 ? 2 : 0);
		printf("%lld\n", ans);
	}
	return 0;
}