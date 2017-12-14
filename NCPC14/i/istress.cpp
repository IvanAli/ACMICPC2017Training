#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define y1 asdasd
using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

struct pnt {
	long long x, y;
	pnt() {}
	pnt(long long x, long long y) : x(x), y(y) {}
	pnt operator+(const pnt p) { return pnt(x + p.x, y + p.y); }
	pnt operator-() { return pnt(-x, -y); }
//	pnt operator-(pnt p) { return *this + -p; }
	pnt operator-(const pnt p) { return pnt(x - p.x, y - p.y); }
	pnt operator*(long long s) { return pnt(x * s, y * s); }
	pnt operator/(long long s) { return pnt(x / s, y / s); }
	long long operator*(const pnt p) const { return x * p.x + y * p.y; }
//	long long operator^(const pnt p) const { return x * p.y - y * p.x; }
	long long operator^(const pnt p) const { return y*p.x-x*p.y; }
	pnt normalize() { (*this) / (max(1ll, gcd(llabs(x), llabs(y))) * (x < 0 || x == 0 && y < 0 ? -1 : 1)); }
	long long norm2() { return x * x + y * y; }
};


struct line {
	 pnt a, b, ab;
	 line() {}
	 line(long long x1, long long y1, long long x2, long long y2) {
	 	a = pnt(x1, y1);
	 	b = pnt(x2, y2);
	 	ab = (b - a).normalize();
//		ab = b - a;
	 	b = a + ab;
	 }
	 line(pnt _a, pnt _ab) {
	 	a = _a;
	 	ab = _ab.normalize();
	 	b = a + ab;
	 }
	 line transverse() const {return line(a.x,a.y,a.x-ab.y,a.y+ab.x);}
	 line parallel() const {
	 	return line(this->a, pnt(this->ab.y, -this->ab.x));
	 }
	 bool operator<(const line& other) const {
	 	return ((const pnt)ab ^ (const pnt)other.ab) < 0;
	 }
//	 long long dist(line& other) {return abs(pnt(-ab.y, ab.x) * pnt(other.a - a));}
	 long long dist(line& other) {
	 	long long ret = ((other.a - a) ^ (ab)) * ((other.a - a) ^ (ab)); 
		return ret;
	 }
		
/*	 long long dist(line other) {
	 	pnt ac = other.a - a;
	 	pnt proj = ab * (ac * ab / ab.norm2());
	 	pnt perp = ac - proj;
	 	return (ac.x - proj.x) * (ac.x - proj.x) + (ac.y - proj.y) * (ac.y - proj.y);
	 }*/
};

int n;
//map<line, vector<line> > lines;



struct Vec{
  long long x,y;
  long long operator^(Vec const &a) const {return y*a.x-x*a.y;}
  long long operator*(Vec const &a) const {return x*a.x+y*a.y;}
  Vec operator-(Vec const &a) const {return {x-a.x,y-a.y};}
  Vec operator/(long long const a) const {return {x/a,y/a};}
  Vec normalise() const {return (*this)/(max(1ll,gcd(abs(x),abs(y)))*(x<0 or x==0 and y<0? -1: +1));}
};



struct Line{
  Vec o,v;
  Line(long long a,long long b,long long c,long long d) {o=(Vec{a,b}), v=(Vec{c,d}-o).normalise();}
  Line transverse() const {return Line(o.x,o.y,o.x-v.y,o.y+v.x);}
  long long dist(Line const &a) const {return abs(Vec{-v.y,v.x}*(a.o-o));}
  bool operator<(Line const &a) const {return (v ^ a.v) < 0;}
};



int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		map<line, vector<line> > lines;
		lines.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			line l = line(x1, y1, x2, y2);
			lines[l].pb(l);
		}
		long long ans = 0;
		for (auto a : lines) {
//			line b = a.fst.parallel();
			line b = a.fst.transverse();
			if (!lines.count(b)) continue;
			map<long long, long long> have;
			for (int i = 0; i < a.snd.size(); i++) for (int j = i + 1; j < a.snd.size(); j++) {
				have[a.snd[i].dist(a.snd[j])]++;
			}
			for (int i = 0; i < lines[b].size(); i++) for (int j = i + 1; j < lines[b].size(); j++) {
//				if (have[lines[b][i].dist(lines[b][j])]) ans += have[lines[b][i].dist(lines[b][j])];
				ans += have[lines[b][i].dist(lines[b][j])];
			}
		}
		ans >>= 1;
		printf("%lld\n", ans);
	}
	return 0;
}