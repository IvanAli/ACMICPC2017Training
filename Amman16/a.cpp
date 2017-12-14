#include <bits/stdc++.h>
using namespace std;

const int maxn = 15;

int n;
string s[maxn];
int used[maxn];
int digit[256];
long long ans;

long long solve(int j, int carry) {
	int sum = carry;
	int ret = 0;
	if (j < 0) {
		ans++;
		return 1;
	}
	for (int i = 0; i < n - 1; i++) {
		if (digit[s[i][j]] == -1) {
			for (int it = 0; it < 10; it++) {
				if (!used[it]) {
					digit[s[i][j]] = it;
					used[it] = 1;
					ret += solve(j, carry);
					used[it] = 0;
				}
			}
			digit[s[i][j]] = -1;
		} else {
			sum += digit[s[i][j]];
		}
	}
	if (digit[s[n - 1][j]] == -1) {
//		if (used[sum % 10]) return 0; 
		if (!used[sum % 10]) {
			digit[s[n - 1][j]] = sum % 10;
			used[sum % 10] = 1;
			ret += solve(j - 1, sum / 10);
			used[sum % 10] = 0;
			digit[s[n - 1][j]] = -1;
		}
	} else {
//		if (digit[s[n - 1][j]] != sum % 10) return 0; 
		if (digit[s[n - 1][j]] == sum % 10) {
			ret += solve(j - 1, sum / 10);
		}
	}
	return ret;
}

int main() {
	cin >> n;
	int longest = 0;
	for (int i = 0; i < n; i++) cin >> s[i], longest = max(longest, (int)s[i].size());
	for (int i = 0; i < n; i++) {
		int len = s[i].size();
		if (len < longest) for (int j = 0; j < len; j++) s[i] = "$" + s[i];
	}
	memset(digit, -1, sizeof digit);
	digit['$'] = 0;
//	long long ans = solve(longest - 1, 0);
	solve(longest - 1, 0);
	cout << ans << endl;
	return 0;
}