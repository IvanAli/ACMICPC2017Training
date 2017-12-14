#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int a[105];

int solve(int x, int y) {
	int ret = 0;
	while (x || y) {
		bool xx = x & 1;
		bool yy = y & 1;
		ret += xx ^ yy;
		x >>= 1;
		y >>= 1;
	}
	return ret;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int ans = 0;
		for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) ans = max(ans, solve(a[i], a[j]));
		cout << ans << endl;
	}
	return 0;
}
