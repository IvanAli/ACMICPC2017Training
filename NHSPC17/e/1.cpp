#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

int T;
int n;
int have[N];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		fill(have, have + N, 0);
		bool ok = false;
		for (int i = 0; i < n; i++) {
			int foo; scanf("%d", &foo);
			have[foo]++;
			if (have[foo] > 1) ok = true;
		}
		long long ans = 0;
		for (int i = 1; i < N; i++) ans += (long long)have[i] * (n - have[i]);
		ans >>= 1;
		ans += ok;
		printf("%lld\n", ans);
	}	
	return 0;
}