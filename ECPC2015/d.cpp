#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
using namespace std;

const int maxn = 400005;

int T, n, q;
long long a[maxn];
vector<pair<int, int> > tree[maxn];
long long fen[maxn];
map<int, int> ma;
int p[maxn];
long long ans[maxn];
long long qq[maxn];

long long query(int i) {
	long long ret = 0;
	while (i > 0) {
		ret += fen[i];
		i -= i & -i;
	}
	return ret;
}

void add(int i, int val) {
	while (i < maxn) {
		fen[i] += val;
		i += i & -i;
	}
}

void dfs(int u = 0) {
	if (tree[u].empty()) {
		int low = 0, high = q - 1, mid;
		while (low < high) {
			mid = (low + high) >> 1;
			if (qq[p[mid]] >= a[u]) high = mid;
			else low = mid + 1;
		}
		add(ma[p[low]], 1);
	}
	for (auto to : tree[u]) {
		a[to.fst] += a[u] + to.snd;
		dfs(to.fst);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		ma.clear();
		for (int i = 0; i < n; i++) tree[i].clear();
		for (int i = 0; i < maxn; i++) fen[i] = 0, a[i] = 0;
		for (int i = 0; i + 1 < n; i++) {
			int p, c;
			cin >> p >> c;
			p--;
			tree[p].pb({i + 1, c});
		}
		for (int i = 0; i < n; i++) {
			int mn = maxn;
			for (auto to : tree[i]) {
				mn = min(mn, to.snd);
			}
			for (auto &to : tree[i]) {
				if (to.snd > mn) to.snd = mn + (to.snd - mn) * 2;
			}
		}
		cin >> q;
		int cnt = 0;
		for (int i = 0; i < q; i++) cin >> qq[i], p[i] = i;
		sort(p, p + q, [&](int i, int j) {
			return qq[i] < qq[j];
		});
		for (int i = 0; i < q; i++) ma[p[i]] = ++cnt;
		dfs();
		for (int i = 0; i < q; i++) {
			ans[p[i]] = query(ma[p[i]]);
		}
		for (int i = 0; i < q; i++) cout << ans[i] << endl;
	}
	return 0;
}
