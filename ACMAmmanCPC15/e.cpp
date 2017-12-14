#include <bits/stdc++.h>
using namespace std;

int T, n, mx;
int a[105];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		mx = 0;
		for (int i = 0; i < n; i++) cin >> a[i], mx = max(mx, a[i]);
		int add = 100 - mx;
		if (add < 0) add = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			a[i] += add;
			if (a[i] >= 50) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
