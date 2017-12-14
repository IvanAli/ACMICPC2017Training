#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

typedef long long int64;

long long a, b;

long long gcd(long long a, int64 b, int64 &x, int64 &y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	int64 x1, y1;
	int64 ret = gcd(b, a % b, x, y);
	x1 = y;
	y1 = x - (a / b) * y;
	x = x1;
	y = y1;
	return ret;
}

long long lcm(int64 a, int64 b) {
	int64 x, y;
	return (long long)a * b / gcd(a, b, x, y);
}

int main() {
	scanf("%lld%lld", &a, &b);
	long long x, y;
	long long g = gcd(a, b, x, y);
	long long ans = lcm(a, b);
	if (a == 1 && b == 1) ans = min(ans, 1ll);
	else if (a == 1 || b == 1) ans = min(ans, 2ll);
	else if (g == 1) {
		if (x < 0) swap(x, y), swap(a, b);
		ans = min(ans, (x - ((x - 1) / b) * b) * a);	
		ans = min(ans, (y + ((abs(y) / a) + 1) * a) * b);
	}
	printf("%lld\n", ans);
	return 0;
}