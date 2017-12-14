#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;

int n;
set<int> st[maxn];
int ans[maxn];
bool have[maxn];
bool used[maxn];

int main() {
	cin >> n;
	if (n == 1) return cout << "A 1" << endl, 0;
	for (int i = 0; i < (n + 1) / 2; i++) {
		cout << 'Q' << ' ' << i + 1 << ' ' << i + 1 + n / 2 - 1 << endl;
		cout.flush();
		for (int j = 0; j < n / 2; j++) {
			int p; cin >> p; have[p] = 1;
			st[i].insert(p);
		}
		if (i > 0) {
			for (auto it : st[i - 1]) if (!st[i].count(it)) {
				ans[i - 1] = it;
				used[it] = 1;
				break;
			}
			for (auto it : st[i]) if (!st[i - 1].count(it)) {
				ans[i + n / 2 - 1] = it;
				used[it] = 1;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) if (ans[i] == 0) for (int j = 1; j <= n; j++) if (!used[j] && have[j]) {
		ans[i] = j;
		break;
	}
	for (int i = 1; i <= n; i++) if (!have[i]) {
		ans[n - 1] = i;
		break;
	}
	cout << 'A';
	for (int i = 0; i < n; i++) {
		cout << ' ';
		cout << ans[i];
	}
	cout << endl;
	return 0;
}