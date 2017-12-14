#include <bits/stdc++.h>
using namespace std;

int w1, h1, w2, h2;

int main() {
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w+", stdout);
	cin >> w1 >> h1 >> w2 >> h2;
	if (w1 < h1) swap(w1, h1);
	if (w2 < h2) swap(w2, h2);
	int ww1 = w1, hh1 = h1, ww2 = w2, hh2 = h2;
	if (w1 < w2 || h1 < h2) return cout << -1 << endl, 0;
	int ans = 0;
	int cur = 0;
	while (w2 < w1 - w1 / 2) cur++, w1 -= w1 / 2;
	if (w2 < w1) cur++;
	while (h2 < h1 - h1 / 2) cur++, h1 -= h1 / 2;
	if (h2 < h1) cur++;
	ans = cur;
	w1 = ww1, h1 = hh1, w2 = ww2, h2 = hh2;
	if (w1 >= h2 && h1 >= w2) {
		cur = 0;
		swap(w2, h2);
		while (w2 < w1 - w1 / 2) cur++, w1 -= w1 / 2;
		if (w2 < w1) cur++;
		while (h2 < h1 - h1 / 2) cur++, h1 -= h1 / 2;
		if (h2 < h1) cur++;
		ans = min(ans, cur);
	}
	cout << ans << endl;
	return 0;
}