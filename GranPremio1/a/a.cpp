#include <bits/stdc++.h>
#define rank asdkaosdakdo
using namespace std;

const int maxn = 200005;

int n;
string s, s1, s2;
char c1[maxn], c2[maxn];
int segtree[maxn << 2];
int b[maxn], d[maxn];
int lcp[maxn];
int cnt[2];
int step;
int rank[maxn];

struct suffix {
	int i, color;
	suffix() {}
	bool operator<(const suffix& suf) const {
		if (step == 0) return s[i] < s[suf.i];
		if (b[i] == b[suf.i]) return b[i + step] < b[suf.i + step];
		return b[i] < b[suf.i];
	}
	bool operator==(const suffix& suf) const {
		return !(*this < suf) && !(suf < *this);
	}
} sa[maxn];

void upd() {
	int cur = 0;
	memset(d, 0, sizeof d);
	for (int i = 0; i < n; i++) {
		if (i > 0 && !(sa[i] == sa[i - 1])) cur++;
		d[sa[i].i] = cur;
	}
	memcpy(b, d, n * 4);
}

int query(int x, int y, int id = 1, int l = 0, int r = n) {
	if (l >= x && r <= y) return segtree[id];
	if (l >= y || r <= x) return 1 << 30;
	int mid = l + r >> 1;
	return min(query(x, y, id << 1, l, mid), query(x, y, id << 1 | 1, mid, r));
}

void build(int id = 1, int l = 0, int r = n) {
	if (l + 1 == r) {
		segtree[id] = lcp[l];
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	segtree[id] = min(segtree[id << 1], segtree[id << 1 | 1]);
}

int main() {
	scanf("%s%s", c1, c2);
	s1 = string(c1), s2 = string(c2);
	s = s1 + "#" + s2 + "$";
	int n = s.size();
	int color = 0;
	for (int i = 0; i < 2; i++) cnt[i] = 0;
	for (int i = 0; i < n; i++) lcp[i] = 0, b[i] = 0, d[i] = 0;
	for (int i = 0; i < n; i++) {
		sa[i].i = i;
		sa[i].color = color;
		if (s[i] == '#' || s[i] == '$') color++;
	}
	assert(color == 2);
	step = 0;
	sort(sa, sa + n);
	upd();
	step = 1;
	while (step < n) {
		sort(sa, sa + n);
		upd();
		step <<= 1;
	}
	for (int i = 0; i < n; i++) rank[sa[i].i] = i;
	for (int i = 2, k = 0; i < n; i++, k = max(k - 1, 0)) {
		if (rank[i] == n - 1) continue;
		int j = sa[rank[i] + 1].i;
		while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
		lcp[rank[i]] = k;
	}
	int cur = 0;
	int ans = 0;
	build(1, 0, n);
	for (int i = 2, j = 2; i < n; i++) {
		while (cur < 2 && j < n) {
			cnt[sa[j].color]++;
			if (cnt[sa[j].color] == 1) cur++;
			j++;
		}
		if (cur < 2) break;
		ans = max(ans, query(i, j - 1));
		cnt[sa[i].color]--;
		if (cnt[sa[i].color] == 0) cur--;
	}
	printf("%d\n", ans);
	return 0;
}