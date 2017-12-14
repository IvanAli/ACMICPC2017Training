#include <bits/stdc++.h>

using namespace std;

int main () {
	int n; cin >> n;
	int hi = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		hi = max(hi, x);
	}
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
	}
	int k; cin >> k;
	int ans = 0;
	for (int i = 0; i < k; i++) {
		int x; cin >> x;
		ans += x;
	}
	cout << ans + k*hi << endl;
	return 0;
}
