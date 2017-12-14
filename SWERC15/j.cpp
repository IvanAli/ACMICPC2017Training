#include <bits/stdc++.h>
#define pb push_back
#define yn asdadjk
using namespace std;

int n, m;
int xn[10005], yn[10005];
int xm[50005], ym[50005];
vector<int> hull;

long long dir(int i, int j, int k) {
	long long xi = xn[i], yi = yn[i], xj = xn[j], yj = yn[j], xk = xn[k], yk = yn[k];
	long long x1 = xj - xi;
	long long y1 = yj - yi;
	long long x2 = xk - xi;
	long long y2 = yk - yi;
	return x1 * y2 - x2 * y1;
}

int dir(int xi, int yi, int xj, int yj, int xk, int yk) {
	long long x1 = xj - xi;
	long long y1 = yj - yi;
	long long x2 = xk - xi;
	long long y2 = yk - yi;
	long long ret = x1 * y2 - x2 * y1;
	if (ret > 0) return 1;
	else if (ret < 0) return -1;
	return 0;
}

bool ok(int xp, int yp, int xi, int yi, int xj, int yj, int xk, int yk) {
	int sgn[3], xpt[3], ypt[3];
	xpt[0] = xi, ypt[0] = yi;
	xpt[1] = xj, ypt[1] = yj;
	xpt[2] = xk, ypt[2] = yk;
	// for (int i = 0; i < 3; i++) sgn[i] = dir(xm[im], ym[im], xn[pt[i]], yn[pt[i]], xn[pt[(i + 1) % 3]], yn[pt[(i + 1) % 3]]);
	for (int i = 0; i < 3; i++) sgn[i] = dir(xp, yp, xpt[i], ypt[i], xpt[(i + 1) % 3], ypt[(i + 1) % 3]);
	for (int i = 0; i < 3; i++) if (sgn[i] * sgn[(i + 1) % 3] == -1) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	vector<pair<int, int> > pn, pm;
	pn = vector<pair<int, int> >(n);
	for (int i = 0; i < n; i++) cin >> pn[i].first >> pn[i].second;
	cin >> m;
	pm = vector<pair<int, int> >(m);
	for (int i = 0; i < m; i++) cin >> pm[i].first >> pm[i].second;
	sort(pn.begin(), pn.end());
	for (int i = 0; i < n; i++) xn[i] = pn[i].first, yn[i] = pn[i].second;
	for (int i = 0; i < m; i++) xm[i] = pm[i].first, ym[i] = pm[i].second;
	int k = 0;
	hull = vector<int>(2 * n);
	for (int i = 0; i < n; i++) {
		while (k >= 2 && dir(hull[k - 2], hull[k - 1], i) <= 0) k--;
		hull[k++] = i;
	}
	for (int i = n - 2, t = k + 1; i >= 0; i--) {
		while (k >= t && dir(hull[k - 2], hull[k - 1], i) <= 0) k--;
		hull[k++] = i;
	}
	hull.resize(k);
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int low = 1, high = hull.size() - 3, mid;
		while (low <= high) {
			mid = (low + high) >> 1;
			int xpr1 = dir(xn[hull[0]], yn[hull[0]], xn[hull[mid]], yn[hull[mid]], xm[i], ym[i]);
			int xpr2 = dir(xn[hull[0]], yn[hull[0]], xm[i], ym[i], xn[hull[mid + 1]], yn[hull[mid + 1]]);
			if (xpr1 >= 0 && xpr2 >= 0 && ok(xm[i], ym[i], xn[hull[0]], yn[hull[0]], xn[hull[mid]], yn[hull[mid]], xn[hull[mid + 1]], yn[hull[mid + 1]])) {
				ans++;
				break;
			}
			if (xpr1 < 0) high = mid - 1;
			else low = mid + 1;
		}
	}
	cout << ans << endl;
	return 0;
}
