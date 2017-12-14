#include <bits/stdc++.h>
#define dbg(x) cerr << #x << " = " << x << endl;
using namespace std;

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
};

int T;
int x, y;
set<frac> used;
frac xy;

int main() {
	freopen("zanzibar.in", "r", stdin);
	scanf("%d", &T);
	queue<frac> q;
	q.push(frac(0, 1));
	used.insert(frac(0, 1));
	while (!q.empty()) {
		frac cur = q.front(); q.pop();
		used.insert(cur);
		for (int a = 1; a < 13; a++) for (int b = a + 1; b <= 13; b++) {
			frac nxt = cur + frac(a, b);
			if (nxt.num >= nxt.den) continue;
			if (!used.count(nxt)) q.push(nxt), used.insert(nxt);
		}
	}
	for (int tc = 0; tc < T; tc++) {
		scanf("%d%d", &x, &y);
		xy = frac(x, y);
		set<frac>::iterator it = used.lower_bound(xy);
		frac ans = frac(1, 1);
		if (it != used.end()) {
			frac res = *it;
			ans = res - xy;
		}
		if (x > 0) {
			it--;
			frac res = *it;
			if (xy - res < ans) ans = xy - res;
		}
		printf("Case %d: ", tc + 1);
		printf("%lld/%lld\n", ans.num, ans.den);
	}
	return 0;
}	