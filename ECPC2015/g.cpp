#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
using namespace std;

const int maxn = 100005;
const long long inf = 1e14;

int T, n, m, k;

struct node {
	int u;
	long long c, w;
	node() {}
	node(int u, long long c, long long w) : u(u), c(c), w(w) {};
	bool operator<(node& n) {
		if (c == n.c) return w < n.w;
		return c < n.c;
	}
};

vector<node> graph[maxn];
long long dist[maxn];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) graph[i].clear();
		for (int i = 0; i < m; i++) {
			int s1, s2, c, w;
			cin >> s1 >> s2 >> c >> w;
			s1--, s2--;
			graph[s1].pb(node(s2, c, w));
			graph[s2].pb(node(s1, c, w));
		}
		int low = 0, high = 1e9, mid;
		int ans = -1;
		while (low <= high) {
			mid = (low + high) >> 1;
			for (int i = 0; i < n; i++) dist[i] = inf;
			priority_queue<pair<pair<long long, long long>, int >, vector<pair<pair<long long, long long>, int > >, greater<pair<pair<long long, long long>, int > > > pq;
			dist[0] = 0;
			pq.push({{0, 0}, 0});
			while (!pq.empty()) {
				auto top = pq.top(); pq.pop();
				int cur = top.snd;
				long long c = top.fst.fst, w = top.fst.snd;
				if (c > dist[cur]) continue;
				for (auto to : graph[cur]) {
					int nxt = to.u;
					long long tow = to.w, toc = to.c;
					if (max(w, tow) <= mid && toc + dist[cur] < dist[nxt]) {
						dist[nxt] = toc + dist[cur];
						pq.push({{toc + dist[cur], max(w, tow)}, nxt});
					}
				}
			}
			if (dist[n - 1] < k) {
				ans = mid;
				high = mid - 1;
			}
			else low = mid + 1;
		}
		cout << ans << endl;
	}
	return 0;
}
