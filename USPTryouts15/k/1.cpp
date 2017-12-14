#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 2005;
const double eps = 1e-4;

int T;
int n;
double a[N];

int main() {
//	scanf("%d", &T);
	cin >> T;
	while (T--) {
//		scanf("%d", &n);
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		double ans = 1e9;
		for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
			double xmin = max(a[i], a[j]) - min(a[i], a[j]);
			double xmax = a[i] + a[j];
			int mini = upper_bound(a, a + n, xmin) - a;
			int maxi = lower_bound(a, a + n, xmax) - a; 
			maxi--;
			while (mini == i || mini == j) mini++;
			while (maxi == i || maxi == j) maxi--;
			if (mini <= maxi) {
				double smini = (a[i] + a[j] + a[mini]) / 2.0;
				double smaxi = (a[i] + a[j] + a[maxi]) / 2.0;
				double tarea; tarea = sqrt(smini * (smini - a[i]) * (smini - a[j]) * (smini - a[mini]));
				ans = min(ans, tarea);
				tarea = sqrt(smaxi * (smaxi - a[i]) * (smaxi - a[j]) * (smaxi - a[maxi]));
				ans = min(ans, tarea);
			}
		}
		if (fabs(ans - 1e9) < eps) cout << -1 << endl;
		else cout << setprecision(12) << fixed << ans << endl;
	}
	return 0;
}