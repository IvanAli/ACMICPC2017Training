#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

int T;
int n, m;

int main() {
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		scanf("%d%d", &n, &m);
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			int foo; scanf("%d", &foo);
			if (foo % m) ans += m - (foo % m);
		}
		printf("%lld\n", ans);
	}
	return 0;
}