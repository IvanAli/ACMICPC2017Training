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
//string s;
char s[10];
double val;
map<char*, double> ma;

int main() {
	ios_base::sync_with_stdio(0);
//	cin >> T;
	scanf("%d", &T);
	while (T--) {
//		ma.clear();
//		cin >> c >> n;
		scanf("%d%d", &c, &n);
		for (int i = 0; i < c; i++) {
//			cin >> s >> val;
			scanf("%s%lf", s, &val);
			ma[s] = val;
		}
		strcpy(s, "JD");
		ma[s] = 1;
		double ans = 0;
		for (int i = 0; i < n; i++) {
//			cin >> val >> s;
			scanf("%lf%s", &val, s);
			ans += val * ma[s];
		}
//		cout << setprecision(6) << fixed << ans << endl;
		printf("%.6lf\n", ans);
	}
	return 0;
}