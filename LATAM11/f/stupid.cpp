#include <bits/stdc++.h>
#define rank sjfisjdf
using namespace std;

const int maxn = 10005 * 60;

int T;
int len;
int step;
int k;
char s[maxn];
char w[maxn];
int b[maxn], d[maxn];
int rank[maxn];
int lcp[maxn];
int maxlen;
int cnt[maxn][65];
int lef[maxn], rig[maxn];
bool start[maxn];
set<long long> st;
int size[maxn];

struct sfx {
	int i;
	int color;
	sfx() {}
	bool operator<(const sfx& sx) const {
		if (step == 0) return s[i] < s[sx.i];
		if (b[i] == b[sx.i]) return b[i + step] < b[sx.i + step];	
		return b[i] < b[sx.i];
	}
	bool operator==(const sfx& sx) const {
		return !(*this < sx) && !(sx < *this);
	}
} sa[maxn];

void upd() {
	int cur = 0;
	for (int i = 0; i < len; i++) {
		if (i > 0 && !(sa[i - 1] == sa[i])) cur++;
		d[sa[i].i] = cur;
	}
	memcpy(b, d, 4 * len);
}

void print() {
	for (int i = 0; i < len; i++) {
		int p = sa[i].i;
		cout << i << ": ";
		for (int j = 0; j + p < len; j++) {
			if (s[j + p] < 'a') cout << "$";
			else cout << s[j + p];
		}
		cout << " | " << sa[i].color;
		cout << endl;
	}
}


long long segtree[maxn << 2];

void update(int p, long long v, int id = 1, int l = 0, int r = len) {
	if (l + 1 == r) {
		segtree[id] |= v;
		return;
	}
	int mid = l + r >> 1;
	if (p < mid) update(p, v, id << 1, l, mid);
	else update(p, v, id << 1 | 1, mid, r);
	segtree[id] = segtree[id << 1] | segtree[id << 1 | 1];
}

long long query(int x, int y, int id = 1, int l = 0, int r = len) {
	if (l >= y || r <= x) return 0;
	if (l >= x && r <= y) return segtree[id];
	int mid = l + r >> 1;
	return query(x, y, id << 1, l, mid) | query(x, y, id << 1 | 1, mid, r);
}

int main() {
	while (scanf("%d", &k) && k > 0) {
		memset(cnt, 0, sizeof cnt);
		memset(start, false, sizeof start);
		memset(lcp, 0, sizeof lcp);
		memset(rank, 0, sizeof rank);
		memset(b, 0, sizeof b);
		memset(d, 0, sizeof d);
		memset(size, 0, sizeof size);
		memset(lef, 0, sizeof lef);
		memset(rig, 0, sizeof rig);
		st.clear();
		len = 0;
		maxlen = 0;
		for (int i = 0; i < maxn; i++) s[i] = 0;
		for (int i = 0; i < k; i++) {
			start[len] = true;
			scanf("%s", w);
			if (i == 0) strcpy(s, w);
			else strcat(s, w);
			int wlen = strlen(w);
			size[i] = wlen;
			int oldlen = len;
			len += wlen;
			maxlen = max(maxlen, wlen);
			for (int j = oldlen; j < len; j++) sa[j].i = j, sa[j].color = i;
			sa[len].i = len, sa[len].color = -1;
			s[len++] = i + 1;
		}
/*		assert(len == strlen(s));
		int color = 0;
		for (int i = 0; i < len; i++) {
			sa[i].i = i;
			sa[i].color = color;
			if (s[i] < 'a') sa[i].color = -1, color++;
		}
		assert(k == color);
*/		step = 0;
		sort(sa, sa + len);
		upd();
		step = 1;
		while (step < len) {
			sort(sa, sa + len);
			upd();
			step <<= 1;
		}
		for (int i = 0; i < len; i++) rank[sa[i].i] = i;
		for (int i = 0, t = 0; i < len; i++, t = max(0, t - 1)) {
			if (rank[i] == len - 1) {
				t = 0;
				continue;
			}
			int j = sa[rank[i] + 1].i;
			while (i + t < len && j + t < len && s[i + t] == s[j + t]) t++;
			lcp[rank[i]] = t;
		}
		int ans = 0;
		for (int i = k; i < len; i++) {
			for (int j = 0; j < k; j++) cnt[i][j] += cnt[i - 1][j]; 
			if (s[sa[i].i] < 'a') continue;
			cnt[i][sa[i].color]++;
		}
		lef[0] = -1;
		for (int i = 1; i < len; i++) {
			lef[i] = i - 1;
			int j = i;
			while (lef[i] > -1 && lcp[lef[i]] >= lcp[i]) j = lef[i], 
			lef[i] == lef[lef[i]] ? lef[i] = lef[i] - 1 : lef[i] = lef[lef[i]]; 
			if (lef[i] > -1) lef[i] = j;
		}
		rig[len - 1] = len;
		for (int i = len - 2; i >= 0; i--) {
			rig[i] = i + 1;
			int j = i;
			while (rig[i] < len && lcp[rig[i]] >= lcp[i]) j = rig[i], 
			rig[i] == rig[rig[i]] ? rig[i] = rig[i] + 1 : rig[i] = rig[rig[i]];
			if (rig[i] < len) rig[i] = j;
		}
		/*
		int top; int tt[maxn];		
        top = 0; tt[0] = -1;
        for (int i = 0; i < len; i++) {
            while (top && lcp[tt[top]] >= lcp[i]) --top;
            lef[i] = tt[top] + 1;
            tt[++top] = i;
        }
        top = 0; tt[0] = len;
        for (int i = len - 1; i >= 0; i--) {
            while (top && lcp[tt[top]] >= lcp[i]) --top;
            rig[i] = tt[top] - 1;
            tt[++top] = i;
        }
        */
		
		memset(segtree, 0, sizeof segtree);
		for (int i = 0; i < len; i++) if (sa[i].color > -1) update(i, 1ll << sa[i].color);
/*		for (int i = k; i < len; i++) {
			if (sa[i].color == -1) continue;
			if (start[sa[i].i]) {
				assert(sa[i].color > -1);
				if (lcp[i] >= size[sa[i].color]) continue;
				if (i > 0 && lcp[i - 1] >= size[sa[i].color]) continue;
				st.insert(1ll << sa[i].color);
			}
			if (lcp[i] == 0) {
				if (i > 0 && lcp[i - 1] == 0 && sa[i].color > -1) {
					st.insert(1ll << sa[i].color);
				}
				continue;
			}
			if (lef[i] == -1 || rig[i] == len) continue;
			int x = max(lef[i], 0);
			int y = min(rig[i] + 1, len);
			long long mask = 0;
			//for (int it = 0; it < 26; it++) {
			//	int r = cnt[y][it];
			//	int l = x > 0 ? cnt[x - 1][it] : 0;
				if (r - l > 0) mask |= 1ll << it;
			//}
			mask = query(x, y + 1);
			st.insert(mask);	
		}
*/		for (int i = k; i < len; i++) if (sa[i].color > -1 && lcp[i]) {
			int x = lef[i], y = rig[i];
			assert(x >= 0);
			assert(y < len);
//			fprintf(stderr, "x: %d y: %d\n", x, y + 1);
			long long mask = query(x, y + 2);
			st.insert(mask);
		}
		for (int i = k; i < len; i++) if (start[sa[i].i]) {
			if (lcp[i] >= size[sa[i].color]) continue;
			if (i > 0 && lcp[i - 1] >= size[sa[i].color]) continue;
			assert(sa[i].color > -1);
			st.insert(1ll << sa[i].color);
		}
		printf("%lld\n", (long long)st.size());
	}
	return 0;
}