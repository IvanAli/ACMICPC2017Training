#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000005;

int T, n, k;
long long a[maxn];

bool ok(long long x) {
	long long cur = 1;
	int cnt = 0;
	int g = 0;
	for (int i = 0; i < n; i++) {
		if (max(cur, a[i]) * (cnt + 1) <= x) {
			cur = max(cur, a[i]);
			cnt++;
		} else {
			cur = a[i];
			cnt = 1;
			g++;
		}
		if (cur > x) return false;
	}
	g++;
	if (g <= k) return true;
	return false;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		long long low = 1, high = (long long)1e12, mid;
		while (low < high) {
			mid = low + high >> 1ll;
			if (ok(mid)) high = mid;
			else low = mid + 1;
		}
		cout << low << endl;
	}
	return 0;
}