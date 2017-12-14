#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

int n;
map<int, int> ma;
int ans[N];
int where[N];
int pre[N];
//map<int, int> where;
//map<int, int> pre, pos;
//int pre[N], pos[N];
int target;
int c[N], r[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", c + i, r + i), ma[c[i]], ma[r[i]];
	ma[1];
	int tot = 0;
	for (auto &it : ma) it.snd = tot++;
	for (int i = 0; i < n; i++) {
		if (ma[r[i]] > pre[ma[c[i]]]) {
			pre[ma[c[i]]] = ma[r[i]];
			where[ma[c[i]]] = i;
		}
		if (i + 1 == n) target = ma[c[i]];
	}
	for (int i = 0; i < N; i++) {
//		pos[i] = where[i];
		if (i > 0) {
			if (pre[i - 1] > pre[i]) {
				pre[i] = pre[i - 1];
//				pos[i] = pos[i - 1];
				where[i] = where[i - 1];
			}
		}
	}
	int cur = ma[1];
	int sz = 0;
	bool ok = false;
	while (true) {
		if (cur >= target) {
			break;
		}
		if (pre[cur] <= cur) return printf("No such luck\n"), 0;
		ans[sz++] = where[cur];
		cur = pre[cur];
	}
	printf("%d\n", sz + 1);
	for (int i = 0; i < sz; i++) {
		printf("%d ", ans[i] + 1);
	}
	printf("%d\n", n);
	return 0;
}