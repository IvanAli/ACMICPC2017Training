#include <bits/stdc++.h>
using namespace std;

const int maxn = 800005;

int n, q;
int a[maxn], s[maxn], x[maxn];
int fen[maxn][2];
map<int, int> ma;
int sz;

void add(int i, int v, int which) {
	while (i < maxn) {
		fen[i][which] += v;
		i += i & -i;
	}
}

int get(int i, int which) {
	int ret = 0;
	while (i > 0) {
		ret += fen[i][which];
		i -= i & -i;
	}
	return ret;
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", s + i, a + i), ma[a[i]];
	scanf("%d", &q);
	for (int i = 0; i < q; i++) scanf("%d", x + i), ma[x[i]], ma[-x[i]];
	sz = 1;
	for (auto &it : ma) it.second = sz++;
	for (int i = 0; i < n; i++) {
		if (s[i] == 1) add(ma[a[i]], 1, 0);
		else if (s[i] == -1) add(ma[a[i]], 1, 1);
		else assert(0);
	}
	for (int i = 0; i < q; i++) {
		int ans = get(ma[x[i]], 0) + get(ma[-x[i]], 1);
		printf("%d\n", ans);
	}
	return 0;
}