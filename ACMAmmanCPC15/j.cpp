#include <bits/stdc++.h>
using namespace std;

int T, n, m;
int a[20], b[55];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		for (int i = 0; i < 20; i++) a[i] = 0;
		for (int i = 0; i < 55; i++) b[i] = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			a[x]++;
		}
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			b[x]++;
		}
		for (int i = 1, j = 1; i <= 15; i++) {
			if (a[i] > 0) {
				while (j <= 50 && b[j] < a[i]) j++;
				if (j <= 50) n -= a[i], b[j] = 0;
			}
		}
		if (n == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
