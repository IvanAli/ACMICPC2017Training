#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;
const double pi = acos(-1.0);

int T;

int l;
double a;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%lf", &l, &a);
		a *= pi;
		a /= 180.;
		printf("%.6lf\n", (l * l * (a - sin(a))) / 2);
	}
	return 0;
}