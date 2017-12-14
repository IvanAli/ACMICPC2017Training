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
int dp[N];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%s%d", s, &f);
		n = strlen(s);
		for (int i = 0; i <= n; i++) dp[i] = 1;
		for (int i = 0; i < n; i++) for (int j = 0; j < i; j++) {
			if (((s[j] - 'a' + f) % 26) <= s[i] - 'a') dp[i] = max(dp[i], dp[j] + 1);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) ans = max(ans, dp[i]);
		printf("%d\n", ans);
	}
	return 0;
}
