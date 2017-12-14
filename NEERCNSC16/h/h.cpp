#include <bits/stdc++.h>
using namespace std;

struct rec { int x, y, l; };
vector<rec> v; 
int memo[65][65][65][65];
int T;
int wi, hi;

int solve(int x = 0, int y = 0, int w = wi, int h = hi) {
	if (w == h) {
		v.pb({x, y, w});
		return 1;
	}
	if (memo[x][y][w][h] != -1) return memo[x][y][w][h];
	int ret = 1 << 30;
	for (int i = 1; i < w; i++) {
		ret = min(ret, solve(x, y, i, h) + solve(x + i, y, w - i, h));
	}
	for (int i = 1; i < h; i++) {
		ret = min(ret, solve(x, y, w, i) + solve(x, y + i, w, h - i));
	}
	return memo[x][y][w][h] = ret;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> wi >> hi;
		v.clear();
		memset(memo, -1, sizeof memo);
		int ans = solve();
		cout << ans << endl;
		for (auto i : v) cout << v.x << " " << v.y << " " << v.l << endl;
	}
	return 0;
}