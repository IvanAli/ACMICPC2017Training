#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eps 1e-5
using namespace std;

int n;
int xt, yt;
int l[25];
int rlo[25], rhi[25];
vector<pair<double, double> > ans;

inline int sq(int x) {
	return x * x;
}

double dist(double x, double y) {
	return sqrt(x * x + y * y);
}

double dist(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double tarea(double a, double b, double c) {
	double s = (a + b + c) / 2.;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

void build(double xt, double yt, int k = n - 1) {
	ans.pb({xt, yt});
	if (k == 0) return;
	double d = dist(xt, yt);
	// double r1 = max(d, (double)l[k]);
	double r2 = l[k];
	double r1 = max(d - r2, r2 - d) + 0.01;
	r1 = max(r1, (double)rlo[k - 1]);
	r1 = min(r1, (double)rhi[k - 1]);
	if (d < eps) {
		build(r2, 0, k - 1);
		return;
	}
	// fprintf(stderr, "r: [%d, %d]\n", rlo[k - 1], rhi[k - 1]);
	// fprintf(stderr, "picked r: %f point: (%f, %f)\n", r1, xt, yt);
	double a = (d * d - r2 * r2 + r1 * r1) / (d * 2.);
	double xm = xt * a / d;
	double ym = yt * a / d;
	double h2 = r1 * r1 - a * a;
	if (fabs(h2) < eps) h2 = fabs(h2);
	double h = sqrt(h2);
	// fprintf(stderr, "OPERATION: %f\n", r1 * r1 - a * a);
	// fprintf(stderr, "xm: %f, ym: %f, h: %f a: %f, r1: %f\n", xm, ym, h, a, r1);
	// double xn = xm + (h * ym) / (ym + xm);
	// double yn = ym - xm / (ym + xm);
	double xn = xm - h * (yt) / d;
	double yn = ym + h * (xt) / d;
	// x3 = x2 +- h ( y1 - y0 ) / d
	// y3 = y2 -+ h ( x1 - x0 ) / d
	build(xn, yn, k - 1);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> l[i];
	cin >> xt >> yt;
	sort(l, l + n);
	rlo[0] = rhi[0] = l[0];
	for (int i = 1; i < n; i++) {
		rhi[i] = rhi[i - 1] + l[i];
		if (rhi[i - 1] < l[i]) rlo[i] = l[i] - rhi[i - 1];
	}
	if (xt == 0 && yt == 0) {
		if (sq(rlo[n - 1]) <= sq(xt) + sq(yt) && sq(xt) + sq(yt) <= sq(rhi[n - 1])) build(0, 0);
		else if (sq(xt) + sq(yt) < rlo[n - 1]) build(rlo[n - 1], 0);
		else build(0, 0);
	} else {
		if (sq(rlo[n - 1]) <= sq(xt) + sq(yt) && sq(xt) + sq(yt) <= sq(rhi[n - 1])) build(xt, yt);
		else if (sq(xt) + sq(yt) < rlo[n - 1]) build((rlo[n - 1] / dist(xt, yt)) * xt, (rlo[n - 1] / dist(xt, yt)) * yt);
		else build((rhi[n - 1] / dist(xt, yt)) * xt, (rhi[n - 1] / dist(xt, yt)) * yt);
	}
	for (int i = ans.size() - 1; i >= 0; i--) cout << fixed << setprecision(3) << ans[i].fst << " " << ans[i].snd << endl;
	// cerr << dist(ans.back().fst, ans.back().snd) << endl;
	// for (int i = ans.size() - 1; i > 0; i--) cerr << dist(ans[i - 1].fst, ans[i - 1].snd, ans[i].fst, ans[i].snd) << endl;
	// cerr << "ans[0]: " << ans[0].fst << " " << ans[0].snd << endl;
	return 0;
}
