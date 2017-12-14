#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000005;

int T;
long long a, b;
int n, p;
long long dp[maxn][205];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> a >> b >> n >> p;
		assert(a < b);
		string s = to_string((double)a / b);
		// cerr << "s first: " << s << endl;
		reverse(s.begin(), s.end());
		bool pt = false;
		// for (int i = 0; i < 2; i++) s.pop_back();
		for (int i = 0; i < 2; i++) {
			if (s.back() == '.') pt = true;
			s.pop_back();
		}
		assert(pt);
		reverse(s.begin(), s.end());
		while (s.size() < n) s += '0';
		while (s.size() > n) s.pop_back();
		// cerr << "s now: " << s << endl;
		for (int i = 0; i < n; i++) for (int j = 0; j < p; j++) dp[i][j] = 0;
		dp[0][(s[0] - '0') % p] = 1;
		long long ans = dp[0][0];
		// for (int i = 0; i + 1 < n; i++) {
		// 	for (int j = 0; j < p; j++) dp[i ^ 1][j] = 0;
		// 	for (int j = 0; j < p; j++) dp[i ^ 1][(j * 10 + (s[i + 1] - '0')) % p] += dp[i][j];
		// 	dp[i ^ 1][(s[i + 1] - '0') % p]++;
		// 	ans += dp[i ^ 1][0];
		// }
		for (int i = 0; i + 1 < n; i++) {
			for (int j = 0; j < p; j++) dp[i + 1][j] = 0;
			for (int j = 0; j < p; j++) dp[i + 1][(j * 10 + (s[i + 1] - '0')) % p] += dp[i][j];
			dp[i + 1][(s[i + 1] - '0') % p]++;
			ans += dp[i + 1][0];
		}
		cout << ans << endl;
	}
	return 0;
}
