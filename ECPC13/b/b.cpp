#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
using namespace std;

const int maxn = 100005;

int T;
int n, m;
vector<int> graph[maxn];
vector<pair<int, pair<int,int>>> e;
vector<pair<int, pair<int,int>>> lazy[maxn];
vector<int> com[maxn];
int ans[maxn];
int from[maxn];

int find(int v) {
	if (v == from[v]) return v;
	return from[v] = find(from[v]);
}

int main() {
	freopen("road.in", "r", stdin);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) graph[i].clear();
		for (int i = 0; i < n; i++) from[i] = i;
		for (int i = 0; i < n; i++) com[i].clear(), com[i].pb(i);
		for (int i = 0; i < n; i++) lazy[i].clear();
		e.clear();
		memset(ans, 0, sizeof ans);
		for (int i = 0; i < m; i++) {
			int a, b, c; cin >> a >> b >> c; a--, b--;
			e.pb({c, {min(a, b), max(a, b)}});
		}
		sort(e.begin(), e.end());
		for (int i = 0; i < e.size(); i++) {
			auto cur = e[i];
			int c = cur.fst;
			int u = e[i].snd.fst, v = e[i].snd.snd;
			int x = find(u), y = find(v);
			if (x != y) {
				if (com[x].size() > com[y].size()) {
					if (!lazy[y].empty()) {
						vector<pair<int, int>> tmp;
						for (int j = com[y].size() - 1; j >= 0; j--) {
							if (!lazy[y].empty() && lazy[y].back().fst == j + 1) {
								tmp.pb(lazy[y].back().snd);
								lazy[y].pop_back();
							}
							int vj = com[y][j];
							for (auto it : tmp) ans[vj] += it.fst * it.snd;
						}
					} 
					for (int j = 0; j < com[y].size(); j++) {
						int vj = com[y][j];
						ans[vj] += c * com[x].size();
					}
					lazy[x].pb({com[x].size(), {com[y].size(), c}});
					while (!com[y].empty()) {
						int last = com[y].back();
						com[x].pb(last);
						com[y].pop_back();
					}
					from[y] = x;
				} else {
					if (!lazy[x].empty()) {
						vector<pair<int, int>> tmp;
						for (int j = com[x].size() - 1; j >= 0; j--) {
							if (!lazy[x].empty() && lazy[x].back().fst == j + 1) {
								tmp.pb(lazy[x].back().snd);
								lazy[x].pop_back();
							}
							int vj = com[x][j];
							for (auto it : tmp) ans[vj] += it.fst * it.snd;
						}
					} 
					for (int j = 0; j < com[x].size(); j++) {
						int vj = com[x][j];
						ans[vj] += c * com[y].size();
					}
					lazy[y].pb({com[y].size(), {com[x].size(), c}});
					while (!com[x].empty()) {
						int last = com[x].back();
						com[y].pb(last);
						com[x].pop_back();
					}
					from[x] = y;
				}
			}	
		}
		for (int i = 0; i < n; i++) if (!lazy[i].empty()) {
			vector<pair<int, int>> tmp;
			for (int j = com[i].size() - 1; j >= 0; j--) {
				if (!lazy[i].empty() && lazy[i].back().fst == j + 1) {
					tmp.pb(lazy[i].back().snd);
					lazy[i].pop_back();
				}
				int vj = com[i][j];
				for (auto it : tmp) ans[vj] += it.fst * it.snd;
			}
		}
		cout << "Case " << tc + 1 << ":" << endl;
		for (int i = 0; i < n; i++) cout << ans[i] << endl;
	}
	return 0;
}