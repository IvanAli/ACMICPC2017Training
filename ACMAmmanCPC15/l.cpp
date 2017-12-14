#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

const int maxn = 100005;

int T;
int n, k;
string s;
int segtree[maxn << 2];
int dp[maxn];
int pos[maxn];

int query(int x, int y, int id = 1, int l = 0, int r = n + 1) {
	if (l >= y || r <= x) return INF;
	if (l >= x && r <= y) return segtree[id];
	int mid = (l + r) >> 1;
	return min(query(x, y, id * 2, l, mid), query(x, y, id * 2 + 1, mid, r));
}

void update(int x, int val, int id = 1, int l = 0, int r = n + 1) {
	if (l + 1 == r) {
		segtree[id] = val;
		return;
	}
	int mid = (l + r) >> 1;
	if (x < mid) update(x, val, id * 2, l, mid);
	else update(x, val, id * 2 + 1, mid, r);
	segtree[id] = min(segtree[id * 2], segtree[id * 2 + 1]);
}

void updall(int x, int y, int val, int id = 1, int l = 0, int r = n + 1) {
	if (l >= y || r <= x) return;
	if (l >= x && r <= y) {
		segtree[id] = val;
		return;
	}
	int mid = (l + r) >> 1;
	updall(x, y, val, id * 2, l, mid);
	updall(x, y, val, id * 2 + 1, mid, r);
	segtree[id] = min(segtree[id * 2], segtree[id * 2 + 1]);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> k;
		cin >> s;
		pos[n] = n;
		for (int i = n - 1; i > 0; i--) {
			pos[i] = n;
			if (s[i] == s[i - 1]) pos[i] = i;
			pos[i] = min(pos[i], pos[i + 1]);
		}
		pos[0] = pos[1];
		dp[n] = 0;
		updall(0, n, INF);
		for (int i = n - 1; i >= 0; i--) {
			bool ok = false;
			int cur = 1 + dp[i + 1];
			if (pos[i + 1] < n) cur = min(cur, 1 + query(pos[i + 1] + 1, i + k + 1));
			update(i, cur);
			dp[i] = cur;
		}
		cout << dp[0] - 1 << endl;
	}
	return 0;
}
