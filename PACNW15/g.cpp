#include <bits/stdc++.h>
#define set jsidj
using namespace std;

struct pt {
	long long x, y;
	pt() {}
};

const int maxn = 100005;
int n, r, w, h;
pt xy[maxn];
int fen[maxn];
int p[maxn];

void set(int i, int val) {
	while (i < maxn) {
		fen[i] = max(fen[i], val);
		i += i & -i;
	}
}

int get(int i) {
	int ret = 0;
	while (i > 0) {
		ret = max(ret, fen[i]);
		i -= i & -i;
	}
	return ret;
}

int main() {
	cin >> n >> r >> w >> h;
	for (int i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		xy[i].x = x * r + y;
		xy[i].y = y - x * r;
		p[i] = i;
	}
	sort(p, p + n, [&](int i, int j) {
		if (xy[i].y == xy[j].y) return xy[i].x < xy[j].x;
		return xy[i].y < xy[j].y;
	});
	for (int i = 0; i < n; i++) xy[p[i]].y = i + 1;
	sort(xy, xy + n, [&](pt i, pt j) {
		if (i.x == j.x) return i.y < j.y;
		return i.x < j.x;
	});
	set(xy[0].y, 1);
	for (int i = 1; i < n; i++) {
		int q = get(xy[i].y);
		set(xy[i].y, q + 1);
	}
	cout << get(n + 1) << endl;
	return 0;
}
