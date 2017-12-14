#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

const int N = 100005;

int T;
double n, r, p;

double power(double n, int e) {
	double ret = 1;
	double res = n;
	while (e) {
		if (e & 1) ret *= res;
		res *= res;
		e >>= 1;
	}
	return ret;
}

bool ok(int x) {
	double res = n * power(1 + r / 100., x);
	return res >= p;
}

int main() {
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		printf("Case %d: ", tc + 1);
		scanf("%lf%lf%lf", &n, &r, &p);
		int low = 0, high = 5000, mid;
		while (low < high) {
			mid = low + high >> 1;
			if (ok(mid)) high = mid;
			else low = mid + 1;
		}
		printf("%d\n", low);
	}
	return 0;
}