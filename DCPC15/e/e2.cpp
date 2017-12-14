#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
const int lim = 31;

int T, n, q;
int tree[maxn << 6][2];
int leaf[maxn << 6];
int sz;

void add(int p, int foo) {
	int cur = 0;
	for (int i = lim; i >= 0; i--) {
		bool z = foo & (1 << i); 
		if (tree[cur][z] == 0) tree[cur][z] = sz++;
		cur = tree[cur][z];
	}
	if (leaf[cur] == -1) leaf[cur] = p;
}


int get(int foo) {
	int cur = 0;
	for (int i = lim; i >= 0; i--) {
		bool z = foo & (1 << i);
		if (tree[cur][z ^ 1]) cur = tree[cur][z ^ 1];
		else cur = tree[cur][z];
	}
	return leaf[cur];
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	scanf("%d", &T);
	while (T--) {
		memset(leaf, -1, sizeof leaf);
		memset(tree, 0, sizeof tree);
		sz = 1;
		scanf("%d%d", &n, &q);
		for (int i = 0; i < n; i++) {
			int foo; scanf("%d", &foo);
			add(i, foo);
		}
		while (q--) {
			int foo; scanf("%d", &foo);
			int ans = get(foo);
			assert(ans >= 0);
			printf("%d\n", ans + 1);
		}
		printf("\n");
	}
	return 0;
}