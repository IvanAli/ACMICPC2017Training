#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

int T;
int n, m, k;
vector<tuple<int, int>> graph[N];
int dist[N];

double test(int n, int k) {
	double cur = 0;
	for (int i = 0; i < 1500000; i++) cur += pow((double)(n - 1) / n, i - 1) * i;
	cur *= ((double)k / n);
	return cur;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) graph[i].clear();
		for (int i = 0; i < m; i++) {
			int a, b, c; cin >> a >> b >> c; a--, b--;
			graph[a].pb(mt(b, c));
			graph[b].pb(mt(a, c));
		}
		double cur = 0;
		for (int i = 0; i < 1500; i++) cur += pow((double)(n - 1) / n, i - 1) * i;
		cur *= ((double)k / n);
//		double ans = cur;
		double ans = n * k;
		priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> pq;
		pq.push(mt(0, 0));
		for (int i = 1; i < n; i++) dist[i] = 1 << 30;
		dist[0] = 0;
		while (!pq.empty()) {
			int v, d, to; tie(d, v) = pq.top(); pq.pop();
			if (d > dist[v]) continue;
			for (auto nxt : graph[v]) {
				int to, d; tie(to, d) = nxt; 
				if (dist[v] + d < dist[to]) {
					dist[to] = dist[v] + d;
					pq.push(mt(dist[to], to));
				}
			}
		}
		ans = min(ans, (double)dist[n - 1]);
		cout << setprecision(12) << fixed << ans << endl;
	}
	return 0;
}