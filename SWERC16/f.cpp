#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define INF 1e9
#define rank asdajif
using namespace std;

const int maxn = 100005;

int e;
long long fen[maxn];
int maxr;
long long ans[maxn];
int rank[maxn], value[maxn];
int root;
vector<int> tree[maxn];

long long query(int i) {
	long long ret = 0;
	while (i > 0) {
		ret += fen[i];
		i -= i & -i;
	}
	return ret;
}

void add(int i, int val) {
	while (i <= maxr) {
		fen[i] += val;
		i += i & -i;
	}
}

void dfs(int u) {
	for (auto to : tree[u]) {
		long long prev = query(rank[u] - 1);
		dfs(to);
		ans[u] += query(rank[u] - 1) - prev;
	}
	add(rank[u], value[u]);
}

int main() {
	cin >> e;
	root = -1;
	for (int i = 0; i < e; i++) {
		int m, r, t;
		cin >> m >> r >> t;
		if (m != -1) tree[m - 1].pb(i);
		else root = i;
		rank[i] = r + 1;
		value[i] = t;
		maxr = max(maxr, rank[i]);
	}
	assert(root > -1);
	dfs(root);
	for (int i = 0; i < e; i++) cout << ans[i] << endl;
	return 0;
}
