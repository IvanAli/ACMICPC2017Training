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

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		long long tot = 0;
		int g = 0;
		for (int i = 0; i < n; i++) {
			int foo; scanf("%d", &foo);
			tot += foo;
			g = __gcd(g, foo);
		}
		printf("%lld %d\n", tot, g);
	}
	return 0;
}