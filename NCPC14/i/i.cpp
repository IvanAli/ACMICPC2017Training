#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

const int maxn = 2005;
const int inf = 20005;

int n;
pair<int64, int64> p1[maxn];
pair<int64, int64> p2[maxn];

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

struct frac {
	long long num, den;
	frac() {}
	frac(long long _num, long long _den) : num(_num), den(_den) {
		if (num < 0 && den < 0) num = -num, den = -den;
		if (den < 0 && num >= 0) num = -num, den = -den;
		if (den == 0) {
			num = inf, den = 1;
		}
		long long g = gcd(num, den);
		if (g > 1) num /= g, den /= g; 
	} 
	bool operator<(const frac& f) const {
		return num * f.den < den * f.num; 
	}
	frac operator+(frac f) {
		long long g = gcd(den, f.den);
		long long mul = (den * f.den) / g;
		return frac((mul / den) * num + (mul / f.den) * f.num, mul);
	}
	frac operator-() {
		return frac(-num, den);
	}
	frac operator-(frac f) {
		return *this + -f;
	}
	frac operator*(frac f) {
		return frac(num * f.num, den * f.den);
	}
};

map<frac, set<int> > ma;
map<pair<frac, frac>, int> mb;
/*
double dist(double xi, double yi, double xj, double yj) {
	return sqrt((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj));
}
*/

frac ddist(frac x1, frac y1, frac x2, frac y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		p1[i] = {x1, y1};
		p2[i] = {x2, y2};
		int xx = x1 - x2;
		int yy = y1 - y2;
		ma[frac(yy, xx)].insert(i);
	}
	for (auto it : ma) {
		int64 a = it.first.den, b = it.first.num;
		for (auto i : it.second) {
//			int64 xinum = a * b * (b * p1[i].first + a * p1[i].second);
//			int64 xiden = (a * (b * b + a * a));
			int64 xinum = b * b * p1[i].first - a * b * p1[i].second;
			int xiden = b * b + a * a;
			int64 yinum = b * xinum - b * p1[i].first + a * p1[i].second;
			int64 yiden = a;
			for (auto j : it.second) {
				if (j <= i) continue;
				if (b == inf && a == 1) {
					frac dd = frac((p1[i].first - p1[j].first) * (p1[i].first - p1[j].first), 1);
					mb[{it.first, dd}]++;
					continue;
				}
//				int64 xjnum = a * b * (b * p1[j].first + a * p1[j].second);
//				int64 xjden = (a * (b * b + a * a));
				int64 xjnum = b * b * p1[j].first - a * b * p1[j].second;
				int64 xjden = b * b + a * a;
				int64 yjnum = b * xjnum - b * p1[j].first + a * p1[j].second;
				int64 yjden = a;
				frac dd = ddist(frac(xinum, xiden), frac(yinum, yiden), frac(xjnum, xjden), frac(yjnum, yjden));
				mb[{it.first, dd}]++;
			}
		}
	}
	int64 ans = 0;
	for (auto it : mb) {
		frac slope = it.first.first;
		frac dd = it.first.second;
		int64 cnt = it.second;
		frac pslope = frac(-slope.den, slope.num);
		if (slope.num == inf) pslope = frac(0, 1);
		ans += cnt * mb[{pslope, dd}];
	}
	ans >>= 1ll;
	printf("%lld\n", ans);
	return 0;
}
