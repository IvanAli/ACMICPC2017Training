#include <bits/stdc++.h>
using namespace std;

int T;
long long n;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%lld", &n);
		long long ans = (n + 1ll) * (n + 1ll) - 1;
		printf("%lld\n", ans);
	}
	return 0;
}
