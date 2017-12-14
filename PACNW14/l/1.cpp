#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 65;

int T;
int n, w, q;
char ss[N][20];
char sa[N], sb[N];
long long x[N], y[N], z[N];
double dist[N][N];
vector<pair<int, double>> graph[N];
map<string, int> ma;
set<pair<int, int>> edge;

double euclidean(int i, int j) {
	double ret = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j]);
	return sqrt(ret);
}

int main() {
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		printf("Case %d:\n", tc + 1);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) graph[i].clear();
		edge.clear();
		ma.clear();
		for (int i = 0; i < n; i++) {
			scanf("%s%d%d%d", ss[i], &x[i], &y[i], &z[i]);
			ma[string(ss[i])] = i;
		}
		for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
			double d = euclidean(i, j);
			graph[i].pb({j, d});
			graph[j].pb({i, d});
		}
		scanf("%d", &w);
		for (int i = 0; i < w; i++) {
			scanf("%s%s", sa, sb);
			int aa = ma[string(sa)];
			int bb = ma[string(sb)];
			edge.insert({aa, bb});
		}
		scanf("%d", &q);
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dist[i][j] = 1e15;
		for (int i = 0; i < n; i++) dist[i][i] = 0;
		for (int i = 0; i < n; i++) for (auto to : graph[i]) dist[i][to.fst] = to.snd;
		for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			int aa = ma[string(ss[i])];
			int bb = ma[string(ss[j])];
			if (edge.count({aa, bb})) dist[i][j] = 0;
			else dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
		}
		while (q--) {
			scanf("%s%s", sa, sb);
			int aa = ma[string(sa)];
			int bb = ma[string(sb)];
			printf("The distance from %s to %s is %.0f parsecs.\n", sa, sb, round(dist[aa][bb]));
		}
	}
	return 0;
}