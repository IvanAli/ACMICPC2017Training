#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define fst first
#define snd second
using namespace std;

const int N = 1005;

int T;
int n, f;
char s[N];
int dp[N][26];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%s%d", s, &f);
		n = strlen(s);
		for (int i = 1; i <= n; i++) for (int j = 0; j < 26; j++) dp[i][j] = -(1 << 30);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 26; j++) {
				dp[i + 1][(j + f) % 26] = max(dp[i + 1][(j + f) % 26], dp[i][j] + (((j + f) % 26) == s[i] - 'a'));
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			}
		}
		int ans = 0;
		for (int i = 0; i < 26; i++) ans = max(ans, dp[n][i]);
		printf("%d\n", ans);
	}
	return 0;
}
