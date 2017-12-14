#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000005;

int T;
unsigned long long a, b;
int n, p;
unsigned long long dp[2][205];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> a >> b >> n >> p;
		assert(a < b);
		double m = (double)a;
		m /= b;
		// stringstream stream;
		// stream << fixed << setprecision(n + 5) << m;
		// string s = stream.str();
		string s(maxn, '\0');
		// std::string s(maxn, '\0');
		auto written = std::snprintf(&s[0], s.size(), "%.1000000f", (double)m);
		s.resize(written);
		reverse(s.begin(), s.end());
		while (!s.empty() && s.back() != '.') s.pop_back();
		if (!s.empty()) s.pop_back();
		reverse(s.begin(), s.end());
		while (s.size() < n) s += '0';
		while (s.size() > n) s.pop_back();
		memset(dp, 0, sizeof dp);
		dp[0][(s[0] - '0') % p] = 1;
		unsigned long long ans = dp[0][0];
		assert(s.size() == n);
		for (int i = 0; i + 1 < n; i++) {
			int i1 = (i + 1) % 2;
			int ii = i % 2;
			for (int j = 0; j < p; j++) dp[i1][j] = 0;
			for (int j = 0; j < p; j++) dp[i1][(j * 10 + (s[i + 1] - '0')) % p] += dp[ii][j];
			dp[i1][(s[i + 1] - '0') % p]++;
			ans += dp[i1][0];
		}
		cout << ans << endl;
	}
	return 0;
}
