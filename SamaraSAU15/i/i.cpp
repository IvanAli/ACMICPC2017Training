#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 1005;

int n, m, k;
set<int> graph[maxn], bad[maxn], have[maxn];
int from[maxn];
int size[maxn];

int find(int x) {
	if (x == from[x]) return x;
	return from[x] = find(from[x]);
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) from[i] = i, size[i] = 1, have[i].insert(i);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b); a--, b--;
		graph[a].insert(b);
		graph[b].insert(a);
		bad[a].insert(b);
		bad[b].insert(a);
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (!graph[i].count(j)) {
		int x = find(i), y = find(j);
		if (x != y) {
			if (size[x] < size[y]) {
				while (!have[x].empty()) {
					int top = *have[x].begin();
					have[x].erase(have[x].begin());
					if (bad[y].count(top)) return printf("-1\n"), 0;
				}
				while (!bad[x].empty()) {
					int top = *bad[x].begin();
					bad[x].erase(bad[x].begin());
					bad[y].insert(top);
				}
				from[x] = y;
				size[y] += size[x];
			} else {
				while (!have[y].empty()) {
					int top = *have[y].begin();
					have[y].erase(have[y].begin());
					if (bad[x].count(top)) return printf("-1\n"), 0;
				}
				while (!bad[y].empty()) {
					int top = *bad[y].begin();
					bad[y].erase(bad[y].begin());
					bad[x].insert(top);
				}
				from[y] = x;
				size[x] += size[y];
			}
		}
	}
	map<int, int> ma;
	for (int i = 0; i < n; i++) if (!ma.count(find(i))) ma[find(i)], k--;
	if (k < 0) return printf("-1\n"), 0;
	int sz = 0;
	for (auto &it : ma) it.second = sz++;
	for (int i = 0; i < n; i++) {
		if (i > 0) putchar(' ');
		printf("%d", ma[find(i)] + 1);
	}
	putchar('\n');
	return 0;
}