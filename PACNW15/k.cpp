#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int B = 0;
const int W = 1;
int dx[] = {-1, 1, 1, -1};
int dy[] = {-1, -1, 1, 1};

int n;
int grid[30][30];
set<int> graph[700];
int have[4];
int used[4][700];
set<pair<int, int> > e[4];

bool check(int x, int y) {
	int odd = 0;
	bool ok = false;
	for (int i = 0; i < 700; i++) {
		if (graph[i].size() % 2) {
			odd++;
			if (x * n + y == i) ok = true;
		}
	}
	bool ret = odd == 0 || odd == 2;
	if (odd == 2) ret &= ok;
	return ret;
}

bool build(int x, int y, int z) {
	int u = x * n + y;
	used[z][u] = 1;
	for (int k = 0; k < 4; k++) {
		int xk = x + dx[k] * 2;
		int yk = y + dy[k] * 2;
		int xw = x + dx[k];
		int yw = y + dy[k];
		if (xw < 0 || xw >= n || yw < 0 || yw >= n) continue;
		if (grid[xw][yw] != W) continue;
		if (xk < 0 || xk >= n || yk < 0 || yk >= n) return false;
		if (grid[xk][yk] == B) continue;
		int to = xk * n + yk;
		graph[u].insert(to);
		graph[to].insert(u);
		e[z].insert({min(u, to), max(u, to)});
		if (used[z][to]) continue;
		// graph[u].pb(to);
		// graph[to].pb(u);
		if (!build(xk, yk, z)) return false;
	}
	return true;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '.' || s[j] == '_') grid[i][j] = -1;
			if (s[j] == 'W') grid[i][j] = W;
			if (s[j] == 'B') grid[i][j] = B;
		}
	}
	int wx = -1, wy = -1;
	int wcnt = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (grid[i][j] == W) {
			wcnt++;
			if (wx == -1) {
				assert(wy == -1);
				wx = i % 2;
				wy = j % 2;
			} else {
				if (i % 2 != wx || j % 2 != wy) return cout << "None" << endl, 0;
			}
		}
	}
	int ansx = -1, ansy = -1;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (grid[i][j] == B) {
			if (i % 2 == wx) {
				assert(j % 2 == wy);
			} else {
				assert(j % 2 == 1 - wy);
				if (!have[(i + j) % 4]) {
					for (int k = 0; k < 700; k++) graph[k].clear();
					bool ok = build(i, j, (i + j) % 4);
					ok &= check(i, j);
					ok &= (wcnt == e[(i + j) % 4].size());
					if (ok) have[(i + j) % 4] = 1;
					else have[(i + j) % 4] = -1;
					if (ok) ansx = i, ansy = j;
				} else if (have[(i + j) % 4] > 0) have[(i + 4) % 4]++;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) if (have[i] > -1) ans += have[i];
	if (ans > 1) cout << "Multiple" << endl;
	else if (ans == 1) cout << (char)(ansy + 'a') << n - ansx << endl;
	else cout << "None" << endl;
	return 0;
}
