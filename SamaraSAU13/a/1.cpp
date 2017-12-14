#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 2505;
const int L = 0;
const int R = 1;
const int U = 2;
const int D = 3;

int n, m;
int go[N][N][4];
char grid[N][N];
int q;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", grid[i]);
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '#') cnt = 0;
			else if (grid[i][j] == '.') cnt++;
			go[i][j][L] = cnt; 
		}
	}
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = m - 1; j >= 0; j--) {
			if (grid[i][j] == '#') cnt = 0;
			else if (grid[i][j] == '.') cnt++;
			go[i][j][R] = cnt;
		}
	}
	for (int j = 0; j < m; j++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (grid[i][j] == '#') cnt = 0;
			else if (grid[i][j] == '.') cnt++;
			go[i][j][U] = cnt;
		}
	}
	for (int j = 0; j < m; j++) {
		int cnt = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (grid[i][j] == '#') cnt = 0;
			else if (grid[i][j] == '.') cnt++;
			go[i][j][D] = cnt;
		}
	}
	scanf("%d", &q);
	while (q--) {
		int r1, c1, r2, c2; scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		r1--, c1--, r2--, c2--;
		if (r1 == r2) {
			int c = min(c1, c2);
			if (go[r1][c][R] >= max(c1, c2) - min(c1, c2)) printf("YES\n");
			else printf("NO\n");
		} else if (c1 == c2) {
			int r = min(r1, r2);
			if (go[r][c1][D] >= max(r1, r2) - min(r1, r2)) printf("YES\n");
			else printf("NO\n");
		} else {
			int rr = r1 - r2;
			int cc = c1 - c2;
			if (rr < 0) {
				if (cc < 0) {
					if (go[r1][c2][D] >= r2 - r1 && go[r1][c2][L] >= c2 - c1) printf("YES\n");
					else if (go[r2][c1][U] >= r2 - r1 && go[r2][c1][R] >= c2 - c1) printf("YES\n");
					else printf("NO\n");
				} else {
					if (go[r1][c2][D] >= r2 - r1 && go[r1][c2][R] >= c1 - c2) printf("YES\n");
					else if (go[r2][c1][U] >= r2 - r1 && go[r2][c1][L] >= c1 - c2) printf("YES\n");
					else printf("NO\n");
				}
			} else {
				if (cc < 0) {
					if (go[r1][c2][U] >= r1 - r2 && go[r1][c2][L] >= c2 - c1) printf("YES\n");
					else if (go[r2][c1][D] >= r1 - r2 && go[r2][c1][R] >= c2 - c1) printf("YES\n");
					else printf("NO\n");
				} else {
					if (go[r1][c2][U] >= r1 - r2 && go[r1][c2][R] >= c1 - c2) printf("YES\n");
					else if (go[r2][c1][D] >= r1 - r2 && go[r2][c1][L] >= c1 - c2) printf("YES\n");
					else printf("NO\n");
				}
			}
		}
	}
	return 0;
}