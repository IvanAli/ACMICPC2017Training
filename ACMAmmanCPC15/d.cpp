#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int T;
int n, k;
string s;
int dp[1005];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> k;
		cin >> s;
		memset(dp, 0, sizeof dp);
		dp[n] = 0;
		for (int i = n - 1; i >= 0; i--) {
			bool ok = false;
			dp[i] = INF;
			for (int j = i; j - i + 1 <= k && j < n; j++) {
				if (i < j && s[j] == s[j - 1]) ok = true;
				if (i == j || ok) dp[i] = min(dp[i], 1 + dp[j + 1]);
			}
		}
		cout << dp[0] - 1 << endl;
	}
	return 0;
}
