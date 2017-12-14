#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back

using namespace std;


int comp(int x, int y, int nx, int ny) {
	int dx = abs(x - nx), dy = abs(y - ny);
	return dx/2 + dy/2 + dx%2 + dy%2;
}

int main () {
	int x, y; cin >> x >> y;
	pair<int, int> mov;
	string dir; cin >> dir;
	if (dir[0] == 'L') {
		mov = {-1, 0};
	}
	else if (dir[0] == 'R') {
		mov = {1, 0};
	}
	else if (dir[0] == 'U') {
		mov = {0, 1};
	}
	else if (dir[0] == 'D') {
		mov = {0, -1};
	}
	else throw;
	int n; cin >> n;
	int best = 1<<30;
	string ans;
	for (int i = 0; i < n; i++) {
		int xi, yi; string name; cin >> name >> xi >> yi;
		int lo = 0, hi = 10000000;
		while (lo < hi) {
			int mid = (lo+hi) / 2;
			int dx, dy;
			tie(dx, dy) = mov;
			int nx = x + dx*mid, ny = y + dy*mid;
			int cost = comp(nx, ny, xi, yi);
			if (cost <= mid) {
				hi = mid;
			}
			else {
				lo = mid + 1;
			}
		}
		if (lo < best) {
			best = lo;
			ans = name;
		}
	}
	cout << ans << endl;


	return 0;
}
