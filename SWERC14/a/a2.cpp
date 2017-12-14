#include <bits/stdc++.h>
using namespace std;

const int maxn = 15;

int n;
string s[maxn];
int used[maxn];
int digit[256];

long long solve(int j, int carry) {
	int sum = carry;
	if (j < 0) {
		if (carry > 0) return 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < s[i].size(); j++) {
			if (s[i][j] != '$') {
				if (digit[s[i][j]] == 0) return 0;
				break;
			}
		}
		return 1;
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (digit[s[i][j]] == -1) {
			for (int d = (j == 0 ? 1 : 0); d < 10; d++) {
				if (!used[d]) {
					used[d] = 1;
					digit[s[i][j]] = d;
					ret += solve(j, carry);
					used[d] = 0;
				}
			}
			digit[s[i][j]] = -1;
			return ret;
		}
		if (i + 1 < n) sum += digit[s[i][j]];
	}
	carry = sum / 10;
	int d = sum % 10;
	if (digit[s[n - 1][j]] == d) return solve(j - 1, carry);
	return 0;
}


int main() {
	cin >> n;
	int longest = 0;
	for (int i = 0; i < n; i++) cin >> s[i], longest = max(longest, (int)s[i].size());
	int len = (int)s[n - 1].size();
	for (int i = 0; i < n - 1; i++) {
		if ((int)s[i].size() < len) {
			int dif = len - (int)s[i].size();
			for (int j = 0; j < dif; j++) s[i] = "$" + s[i];
		}
	}
	memset(digit, -1, sizeof digit);
	digit['$'] = 0;
	long long ans = solve(len - 1, 0);
	cout << ans << endl;
	return 0;
}