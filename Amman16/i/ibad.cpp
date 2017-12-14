#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;

int n, m;
int T;
int len;
char s[maxn];
int c[maxn];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int fx(int x) {
	if (x < 0 || x >= n) return 1 << 30;
	int ret = 0;
	for (int i = 0; i < len; i++) {
		assert(0 <= x && x < n);
		x += dx[c[i]];
		if (x < 0) ret++, x = 0;
		else if (x >= n) ret++, x = n - 1;
	}
	return ret;
}


int fy(int y) {
	if (y < 0 || y >= m) return 1 << 30;
	int ret = 0;
	for (int i = 0; i < len; i++) {
		assert(0 <= y && y < m);
		y += dy[c[i]];
		if (y < 0) ret++, y = 0;
		else if (y >= m) ret++, y = m - 1;
	}
	return ret;
}


int f(int x, int y) {
	if (x < 0 || x >= n) return 1 << 30;
	if (y < 0 || y >= m) return 1 << 30;
	int ret = 0;
	for (int i = 0; i < len; i++) {
		x += dx[c[i]];
		y += dy[c[i]];
		if (x < 0) ret++, x = 0;
		else if (x >= n) ret++, x = n - 1;
		else if (y < 0) ret++, y = 0;
		else if (y >= m) ret++, y = m - 1;
	}
	return ret;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%s", &n, &m, s);
		len = strlen(s);
		for (int i = 0; s[i]; i++) {
			if (s[i] == '<') c[i] = 1;
			if (s[i] == '>') c[i] = 3;
			if (s[i] == '^') c[i] = 0;
			if (s[i] == 'v') c[i] = 2;
		}
		int x = 0, y = 0;
		int xlo = 0, xhi = n - 1, ylo = 0, yhi = m - 1, m1, m2;
		while (xhi - xlo > 2) {
			m1 = xlo + (xhi - xlo) / 3;
			m2 = xhi - (xhi - xlo) / 3;
			if (fx(m1) > fx(m2)) xlo = m1;
			else xhi = m2;
		}
		if (fx(xlo) < fx(x)) x = xlo;
		if (fx(xlo + 1) < fx(x)) x = xlo + 1;
		if (fx(xhi) < fx(x)) x = xhi;
		while (yhi - ylo > 2) {
			m1 = ylo + (yhi - ylo) / 3;
			m2 = yhi - (yhi - ylo) / 3;
			if (fy(m1) < fy(m2)) ylo = m1;
			else yhi = m2;
		}
		if (fy(ylo) < fy(y)) y = ylo;
		if (fy(ylo + 1) < fy(y)) y = ylo + 1;
		if (fy(yhi) < fy(y)) y = yhi;
		int ans = f(x, y);
		printf("%d\n", ans);
	}
}