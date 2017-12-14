#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;

int n;
int a[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += max(0, a[i] - a[i - 1]);
		ans += max(0, a[i] - a[i + 1]);
	}
	ans >>= 1;
	printf("%lld\n", ans);
	return 0;
}