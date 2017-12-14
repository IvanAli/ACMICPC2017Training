#include <bits/stdc++.h>
using namespace std;

int T;
int n;
string s;

bool ok(int d, int k) {
	int remove[n + k];
	memset(remove, 0, sizeof remove);
	int add = 0;
	for (int i = 0; i + k <= n; i++) {
		add -= remove[i];
		int need = 0;
		int cur = s[i] - '0';
		(cur += add) %= 10;
		need = (10 + d - cur) % 10;
		add += need;
		remove[i + k] = need;
	}
	for (int i = n - k + 1; i < n; i++) {
		add -= remove[i];
		int cur = s[i] - '0';
		(cur += add) %= 10;
		if (cur != d) return false;
	}
	return true;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> s;
		n = s.length();
		for (int k = n; k >= 1; k--) {
			bool bad = true;
			for (int d = 0; d <= 9; d++) {
				if (ok(d, k)) {
					cout << k << endl;
					bad = false;
					break;
				}
			}
			if (!bad) break;
		}
	}
	return 0;
}
