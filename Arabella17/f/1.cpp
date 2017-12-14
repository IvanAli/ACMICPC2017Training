#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

int T;
int n, m;
set<int> all, st;
set<int> fen[N];

void fset(int i, int v, bool b) {
	while (i < N) {
		if (b) {
			if (fen[i].count(v)) fen[i].erase(v);
			else fen[i].insert(v);		
		} else {
			fen[i].erase(v);
		}
		i += i & -i;
	}
}

void fget(int i) {
	while (i > 0) {
		for (auto it : fen[i]) st.insert(it);
		i -= i & -i;
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		all.clear(); st.clear();
		for (int i = 0; i < n + 5; i++) fen[i].clear();
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) {
			int x, l, k; scanf("%d%d%d", &x, &l, &k);
			if (x - 2 > 0) fset(x - 2, l, 1);
			fset(x + 3, l, 0);
			all.insert(l);
		}
		fget(n);
//		int ans = st.size();
		int ans = 0;
		for (auto it : all) if (!st.count(it)) ans++;
		printf("%d\n", ans);
	}
	return 0;
}