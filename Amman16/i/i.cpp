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
	int xmax = x;
	if (x < 0 || x >= n) return 1 << 30;
	int ret = x;
	for (int i = 0; i < len; i++) {
		assert(0 <= x && x < n);
		x += dx[c[i]];
		if (x < 0) {
			if (xmax < n - 1) xmax++, ret++;
			x = 0;
		}
		else if (x >= n) x = n - 1;
		xmax = max(xmax, x);
	}
	return ret;
}


int fy(int y) {
	int ymax = y;
	if (y < 0 || y >= m) return 1 << 30;
	int ret = y;
	for (int i = 0; i < len; i++) {
		assert(0 <= y && y < m);
		y += dy[c[i]];
		if (y < 0) {
			if (ymax < m - 1) ymax++, ret++;
			y = 0;
		}
		else if (y >= m) y = m - 1;
		ymax = max(ymax, y);
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
		int x = fx(0), y = fy(0);
		int ans = f(x, y);
		printf("%d\n", ans);
	}
}