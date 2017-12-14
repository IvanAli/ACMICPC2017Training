#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int x, y;
string s;
int n;
int dx, dy;

bool ok(int xi, int yi, int t) {
	int xt = x + dx * t;
	int yt = y + dy * t;
	int xx = abs(xt - xi);
	int yy = abs(yt - yi);
	return xx / 2 + (xx % 2) + yy / 2 + (yy % 2) <= t;
}

int main() {
	cin >> x >> y;
	cin >> s;
	cin >> n;
	int ans = inf;
	string name;
	if (s == "LEFT") dx = -1, dy = 0;
	if (s == "RIGHT") dx = 1, dy = 0;
	if (s == "UP") dx = 0, dy = 1;
	if (s == "DOWN") dx = 0, dy = -1;
	for (int i = 0; i < n; i++) {
		string w;
		int xi, yi;
		cin >> w >> xi >> yi;
		int low = 0, high = 1000000, mid;
		while (low < high) {
			mid = (low + high) >> 1;
			if (ok(xi, yi, mid)) high = mid;
			else low = mid + 1;
		}
		// ans = min(ans, low);
		if (low < ans) {
			ans = low;
			name = w;
		}
	}
	cout << name << endl;
	return 0;
}
