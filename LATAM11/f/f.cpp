#include <bits/stdc++.h>
#define rank sjfisjdf
using namespace std;

const int maxn = 100005;
/*
struct cmp {
	bool operator()(const pair<int, int> p1, const pair<int, int> p2) {
		int ii = p1.first;
		int jj = p2.first;
		int i = 0, j = 0;
		while (i < p1.second && j < p2.second) {
			if (s[i + ii] != s[j + jj]) return s[i + ii] < s[j + jj];
		}
	}
};
*/

int T;
int len;
int step;
int k;
char s[maxn];
char w[maxn];
int b[maxn], d[maxn];
int rank[maxn];
int lcpx[maxn];
int dp[maxn][25];
int maxlen;
int lg[maxn];
int cnt[maxn][65];
set<long long> st;

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

int rmq(int l, int r) {
	int sz = lg[r - l + 1];
	return min(dp[l][sz], dp[r - (1 << sz) + 1][sz]);
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

int main() {
	while (scanf("%d", &k) && k > 0) {
		for (int i = 2; i < maxn; i++) lg[i] = lg[i >> 1] + 1;
		memset(cnt, 0, sizeof cnt);
		memset(dp, 0, sizeof dp);
		char cur = 1;
		len = 0;
		maxlen = 0;
		for (int i = 0; i < maxn; i++) s[i] = 0;
		for (int i = 0; i < k; i++) {
			scanf("%s", w);
			if (i == 0) strcpy(s, w);
			else strcat(s, w);
			int wlen = strlen(w);
			len += wlen;
			maxlen = max(maxlen, wlen);
			s[len++] = cur++;
		}
		assert(len == strlen(s));
		int color = 0;
		for (int i = 0; i < len; i++) {
			sa[i].i = i;
			sa[i].color = color;
			if (s[i] < 'a') color++;
		}
		assert(k == color);
		step = 0;
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
			lcpx[rank[i]] = t;
		}
		for (int i = 0; i < len; i++) dp[i][0] = lcpx[i];
		for (int j = 1; 1 << j <= len; j++) for (int i = 0; i + (1 << j) <= len; i++) {
			dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
		}
		int ans = 0;
		for (int i = k; i < len; i++) {
			for (int j = 0; j < k; j++) cnt[i][j] += cnt[i - 1][j]; 
			if (s[sa[i].i] < 'a') continue;
			cnt[i][sa[i].color]++;
//			if (cnt[i][sa[i].color] == 1) t++;
//			pre[i] = t;
		}
		st.clear();
		for (int i = k, j = k; i < len; i++) {
			j = i;
			if (lcpx[i] == 0) {
				if (!st.count(1 << sa[i].color)) {
					cerr << "[" << i << ", " << i << "]" << endl;
				}
				st.insert(1 << sa[i].color);
				continue;
			}
			int first = 1 << 30;
			while (j < len && lcpx[j] >= lcpx[i]) {
				if (lcpx[j] > lcpx[i]) first = min(first, j);
				j++;
			}
//			if (lcpx[i] < lcpx[j]) {
				int t = 0;
				long long mask = 0;
				for (int it = 0; it < 26; it++) if (cnt[j][it] - cnt[i - 1][it] > 0) mask |= (1 << it);
				if (__builtin_popcountll(mask) > 1) {
					if (!st.count(mask)) {
						cerr << "[" << i << ", " << j << "]" << endl;
					}
					st.insert(mask);
					ans++;
					/*if (!st.count({sa[i].i, lcpx[i]})) {
						ans++;
						st.insert({sa[i].i, lcpx[i]});
					}*/
				}
//			}
			i = min(first - 1, j - 1);
		}
//		printf("%d\n", ans);
		printf("%lld\n", (long long)st.size());
	}
	return 0;
}