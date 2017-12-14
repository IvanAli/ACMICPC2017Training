#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
using namespace std;

const int maxn = 100005;

int T, n, m;
vector<pair<int, pair<int, int> > > edges;
int from[maxn];

int find(int x) {
	if (x == from[x]) return x;
	return from[x] = find(from[x]);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> m;
		edges.clear();
		for (int i = 0; i < n; i++) from[i] = i;
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			a--, b--;
			edges.pb({c, {a, b}});
		}
		sort(edges.begin(), edges.end());
		int ans = 0;
		for (int i = 0; i < edges.size(); i++) {
			int a = edges[i].snd.fst, b = edges[i].snd.snd, c = edges[i].fst;
			int x = find(a), y = find(b);
			if (x != y) {
				from[x] = y;
				ans = max(ans, c);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
