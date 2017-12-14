#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;

int n, p, q;
int a[maxn];

bool ok(int x) {
	long long cur = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] - (long long)x * q > 0) {
			if (p == q) return false;
			cur += (a[i] - (long long)x * q) / (p - q) + ((a[i] - (long long)x * q) % (p - q) > 0);
		}
	}
	return cur <= x;
}

int main() {
	scanf("%d%d%d", &n, &p, &q);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int low = 0, high = 1000 * 1000 * 1000, mid;
	while (low < high) {
		mid = low + high >> 1;
		if (ok(mid)) high = mid;
		else low = mid + 1;
	}
	printf("%d\n", low);
	return 0;
}