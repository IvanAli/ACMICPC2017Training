#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
using namespace std;

int T, n, m;
int dp[123][123][1234];
int a[123][123];

int main() {
	cin >> T;
	while (T--) {
		cin >> n >> m;
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
			int tmp, n2, n3;
			tmp = a[i][j];
			n2 = 0, n3 = 0;
			while (tmp % 2 == 0) tmp /= 2, n2++;
			while (tmp % 3 == 0) tmp /= 3, n3++;
			for (int k = n3; k < 1207; k++) dp[i][j][k] = max(i ? dp[i - 1][j][k - n3] : 0, j ? dp[i][j - 1][k - n3] : 0) + n2;
		}
		int ans = 0;
		for (int i = 0; i < 1207; i++) ans = max(ans, min(dp[n - 1][m - 1][i], i));
		cout << ans << endl;
	}
	return 0;
}
