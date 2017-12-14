#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

int T;
int n, k;

int used[N];
int which[N];
//map<string, vector<string>> graph;
vector<int> graph[N];
char ss[N][15];
int in[N];
char tmp[15];
map<string, int> ma;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		fill(used, used + n, 0);
		for (int i = 0; i < n; i++) graph[i].clear();
		fill(in, in + n, 0);
		fill(which, which + n, 0);
		ma.clear();
		for (int i = 0; i < n; i++) for (int j = 0; j < 15; j++) ss[i][j] = 0;
		for (int i = 0; i < 15; i++) tmp[i] = 0;
		for (int i = 0; i < n; i++) {
			int t;
			scanf("%s%d", ss[i], &t);
			string v = string(ss[i]);
			ma[v] = i;
			while (t--) {
				char tos[15];
				for (int i = 0; i < 15; i++) tos[i] = 0;
				scanf("%s", tos);
				string to = string(tos);
				int j = ma[to];
				if (i == j) continue;
				graph[i].pb(j);
				in[j]++;
			}
		}
		string s;
		for (int i = 0; i < k; i++) {
			scanf("%s", tmp);
			s = string(tmp);
//			which.insert(s);
			which[ma[s]] = 1;
		}
		queue<int> q;
		for (int i = 0; i < n; i++) if (in[i] == 0) q.push(i);
		while (!q.empty()) {
			int v = q.front(); q.pop();
//			used.insert(v);
			used[v] = 1;
//			bool ok = which.count(v);
			bool ok = which[v];
			for (auto to : graph[v]) if (!used[to]) {
				if (ok) which[to] = 1;
				in[to]--;
				if (in[to] == 0) q.push(to);
			}
		}
		for (int i = 0; i < n; i++) if (which[i]) printf("%s\n", ss[i]);
	}
	return 0;
}