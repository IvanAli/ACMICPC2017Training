#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define y1 asdkoadk
using namespace std;

const int vert = 1;

struct pnt {
	long long x, y;
	pnt() {}
	pnt(long long x, long long y) : x(x), y(y) {}
	pnt operator+(const pnt p) { return pnt(x + p.x, y + p.y); }
	pnt operator-() { return pnt(-x, -y); }
	pnt operator-(pnt p) { return *this + -p; }
	pnt operator*(long long s) { return pnt(x * s, y * s); }
	long long operator*(const pnt p) { return x * p.x + y * p.y; }
	long long operator^(const pnt p) { return x * p.y - y * p.x; }
};

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

struct frac {
	long long num, den;
	frac() {}
	frac(long long n, long long d) {
		if (n < 0 && d < 0) n = -n, d = -d;
		if (n >= 0 && d < 0) n = -n, d = -d;
/*		if (n != 0 && d != 0) {
			long long g = gcd(n, d);
			n /= g;
			d /= g;
		} else {
			d = 1;
		}
*/		if (d == 0) n = vert;
		else if (n == 0) d = 1;
		else {
			long long g = gcd(n, d);
			n /= g;
			d /= g;
		}
		num = n, den = d;
	}
	bool operator<(const frac& f) const {
		return num * f.den < f.num * den;
	}
};

struct line {
	pnt a, b, ab;
	line() {}
	line(pnt a, pnt ab) : a(a), ab(ab) {
		b = a + ab;
	}
};

int n;
map<frac, vector<line> > slope;
map<pair<frac, long long>, int> ma;

long long norm2(pnt v) {
	return (long long)v.x * v.x + (long long)v.y * v.y;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (x1 > x2) swap(x1, x2), swap(y1, y2);
		line l = line(pnt(x1, y1), pnt(x2 - x1, y2 - y1));
		slope[frac(y1 - y2, x1 - x2)].pb(l);
	}
	for (auto &s: slope) {
		vector<line> v = s.snd;
		for (int i = (int)(v.size() - 1); i >= 0; i--) {
			line li = v[i];
			li.a = li.a + (li.ab) * -10000;
			li.b = li.b + (li.ab) * 10000;
			li.ab = li.b - li.a;
			v.pop_back();
			for (int j = 0; j < v.size(); j++) {
				line lj = v[j];
				long long darea = ((lj.a - li.a) ^ (li.ab)) * ((lj.a - li.a) ^ (li.ab)); 
//				frac dist = frac(darea, norm2(li.ab));
				ma[{s.fst, darea}]++;
			}
		}
	}
	long long ans = 0;
	for (auto it : ma) {
		frac slope = it.fst.fst;
		long long dist = it.fst.snd;
		frac invslope;
		if (slope.num == 0) assert(slope.den == 1), invslope = frac(vert, 0);
//		else if (slope.num == vert) assert(slope.den == 0), invslope = frac(0, 1);
		else invslope = frac(-slope.den, slope.num);
		long long a = it.snd;
		long long b = ma[{invslope, dist}];
		ans += a * b;
	}
	ans >>= 1ll;
	printf("%lld\n", ans);
	return 0;
}