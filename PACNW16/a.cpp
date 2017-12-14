#include <bits/stdc++.h>
#define pb push_back
using namespace std;

string s;
int dp[55][30];

int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) for (int j = 0; j < 26; j++) dp[i + 1][j + 1] = 1 << 30;
	for (int i = 0; i < 26; i++) dp[0][i + 1] = i + 1;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < 26; j++) {
			for (int k = 0; k <= i + 1; k++) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[k][j] + (s[i] != j + 'a')); 
		}
	}
	int ans = 1 << 30;
	for (int i = 0; i < s.size(); i++) ans = min(ans, dp[i + 1][26]);
	cout << ans << endl;
	return 0;
}