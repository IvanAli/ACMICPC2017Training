#include <bits/stdc++.h>
using namespace std;

int n, k;
long long xlef[1005], xrig[1005], mlef[1005], mrig[1005];
int l, r;
int plef[1005], prig[1005];

int main() {
	cin >> n >> k;
//	for (int i = 0; i < n; i++) cin >> x[i] >> m[i];
	for (int i = 0; i < n; i++) {
		int foo, bar;
		cin >> foo >> bar;
		if (foo < 0) foo = -foo, xlef[l] = foo, mlef[l] = bar, l++;
		else xrig[r] = foo, mrig[r] = bar, r++;
	} 
	for (int i = 0; i < l; i++) plef[i] = i;
	for (int i = 0; i < r; i++) prig[i] = i;
	sort(plef, plef + l, [&](int i, int j) { return xlef[i] > xlef[j]; });
	sort(prig, prig + r, [&](int i, int j) { return xrig[i] > xrig[j]; });
	long long ans = 0;
	int xi = 0, xj = 0;
	while (xi < l && xj < r) {
		while (xi + 1 < l && mlef[plef[xi]] < 0) mlef[plef[xi + 1]] += mlef[plef[xi]], xi++;
		if (mlef[plef[xi]] < 0) xi++;
		if (xi >= l) break;
		while (xj + 1 < r && mrig[prig[xj]] < 0) mrig[prig[xj + 1]] +=  mrig[prig[xj]], xj++;
		if (mrig[prig[xj]] < 0) xj++;
		if (xj >= r) break;
		if (xlef[plef[xi]] > xrig[prig[xj]]) {
			int t = mlef[plef[xi]] / k + (mlef[plef[xi]] % k > 0);
			ans += xlef[plef[xi]] * t * 2;
			if (xi + 1 < l) mlef[plef[xi + 1]] -= (t * k - mlef[plef[xi]]);
			xi++;  
		} else {
			int t = mrig[prig[xj]] / k + (mrig[prig[xj]] % k > 0);
			ans += xrig[prig[xj]] * t * 2;
			if (xj + 1 < r) mrig[prig[xj + 1]] -= (t * k - mrig[prig[xj]]);
			xj++;
		}
	}
	while (xi < l) {
		while (xi + 1 < l && mlef[plef[xi]] < 0) mlef[plef[xi + 1]] += mlef[plef[xi]], xi++;
		if (xi >= l) break;
		if (mlef[plef[xi]] < 0) break;
		int t = mlef[plef[xi]] / k + (mlef[plef[xi]] % k > 0);
		ans += xlef[plef[xi]] * t * 2;
		if (xi + 1 < l) mlef[plef[xi + 1]] -= (t * k - mlef[plef[xi]]);
		xi++;  
	}
	while (xj < r) {
		while (xj + 1 < r && mrig[prig[xj]] < 0) mrig[prig[xj + 1]] += mrig[prig[xj]], xj++;
		if (xj >= r) break;
		if (mrig[prig[xj]] < 0) break;
		int t = mrig[prig[xj]] / k + (mrig[prig[xj]] % k > 0);
		ans += xrig[prig[xj]] * t * 2;
		if (xj + 1 < r) mrig[prig[xj + 1]] -= (t * k - mrig[prig[xj]]);
		xj++;
	}
	cout << ans << endl;
	return 0;
}