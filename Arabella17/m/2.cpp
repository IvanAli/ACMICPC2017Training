#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

int T;
int c, n;
char s[10];
string ss;
double val;
map<string, double> ma;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &c, &n);
		for (int i = 0; i < c; i++) {
			scanf("%s%lf", s, &val);
			ss = string(s);
			ma[ss] = val;
		}
		ma["JD"] = 1;
		double ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lf%s", &val, s);
			ss = string(s);
			ans += val * ma[ss];
		}
		printf("%.6lf\n", ans);
	}
	return 0;
}