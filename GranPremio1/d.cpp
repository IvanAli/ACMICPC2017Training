#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int T;
int n;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		vector<int> dv;
		for (int i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				dv.pb(i);
				if (i != n / i && i > 1) dv.pb(n / i);
			}
		}
		int ans = 0;
		for (int i = 0; i < dv.size(); i++) ans += dv[i];
		if (ans < n) printf("deficient\n");
		else if (ans == n) printf("perfect\n");
		else if (ans > n) printf("abundant\n");
	}
	return 0;
}
