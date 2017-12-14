#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define rank rk
using namespace std;

const int N = 100005;
const int M = N << 2;

int T;
int n;
int tree[N << 2][26];
int all[N << 2];
char s[N];
int sz;
int rank[N];
int lst[N << 2];
int lsz;
int from[N << 2];
int where[N], which[N << 2], what[N << 2];
int nxt[N << 2];
int ans[N << 2];
int tot, ord;
int depth[N << 2];

inline void tadd(int k) {
	int v = 0;
	for (int i = 0; s[i]; i++) {
		int to = s[i] - 'a';
		if (!tree[v][to]) {
			tree[v][to] = sz;
			from[sz] = v;
			sz++;
		}
		v = tree[v][to];
	}
	which[v] = k;
	where[k] = v;
}

inline void dfs(int v = 0) {
	for (int i = 0; i < 26; i++) {
		int to = tree[v][i];
		if (to > 0) {
			depth[to] = depth[v] + 1;
			dfs(to);
		}
	}
	if (which[v] > -1) rank[which[v]] = ord++;
}

inline void solve(int v = 0) {
	int lsz = 0;
	int w = what[v];
	if (w == -1) return;
	while (w > -1) lst[lsz++] = all[w], w = nxt[w];
	if (lsz == 0) return;
	sort(lst, lst + lsz, [&](const int i, const int j) { return rank[i] < rank[j]; });
	for (int i = 0; i < lsz; i++) ans[lst[i]] = min(ans[lst[i]], depth[v] + min(1 + i, 1 + lsz - i));
}

int main() {
	scanf("%d", &T);
//	memset(which, -1, sizeof which);
//	memset(what, -1, sizeof what);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < min(N << 2, n << 2 + 5); i++) {
			which[i] = -1;
			what[i] = -1;
			for (int j = 0; j < 26; j++) tree[i][j] = 0;
		}
		ord = 0;
		sz = 1;
		tot = 0;
		for (int i = 0; i < n; i++) ans[i] = 1 << 30;
		for (int i = 0; i < n; i++) {
			scanf("%s", s);
			tadd(i);
		}
		dfs();
		for (int i = 0; i < n; i++) {
			int v = where[i];
			while (true) {
				all[tot] = i; 
				nxt[tot] = what[v];
				what[v] = tot; 
				tot++;
				if (v == from[v]) break;
				v = from[v];
			}
		}
		for (int i = 0; i < sz; i++) solve(i);
		for (int i = 0; i < n; i++) {
			if (i > 0) putchar(' ');
			printf("%d", ans[i]);
		}
		putchar('\n');
	}
	return 0;
}