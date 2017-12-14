#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int T, n, q;
int segtree[maxn << 2];
int win[maxn];
int tot[maxn];

void update(int p, int v, int id = 1, int l = 0, int r = n) {
	if (l + 1 == r) {
		tot[l] += v;
		return;
	}
	int mid = l + r >> 1;
	if (p < mid) update(p, v, id << 1, l, mid);
	else update(p, v, id << 1 | 1, mid, r);
	segtree[id] = tot[segtree[id << 1]] >= tot[segtree[id << 1 | 1]] ? segtree[id << 1] : segtree[id << 1 | 1];
}

void build(int id = 1, int l = 0, int r = n) {
	if (l + 1 == r) {
		segtree[id] = l;
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		memset(tot, 0, sizeof tot);
		scanf("%d%d", &n, &q);
		build();
		for (int i = 0; i < q; i++) {
			int x, p; scanf("%d%d", &x, &p); x--;
			update(x, p);
			win[i] = segtree[1];
		}
		int ans = -1;
		for (int i = q - 1; i >= 0; i--) {
			if (win[i] != win[q - 1]) {
				break;
			}
			ans = i;
		}
		printf("%d\n", ans == 0 && win[q - 1] == 0 ? ans : ans + 1);
	}
	return 0;
}