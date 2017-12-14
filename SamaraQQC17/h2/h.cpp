#include <bits/stdc++.h>
using namespace std;

const int maxn = 500005;

int n;
int dp[maxn];
char s[maxn];

bool ok() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') cnt++;
		else if (s[i] == ')') cnt--;
		else assert(0);
		if (cnt < 0) return false;
	}
	return cnt == 0;
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	dp[n] = n / 2;
	for (int i = n - 1; i >= 0; i--) dp[i] = min(i, max((i + 1) / 2, dp[i + 1] - (s[i] == '(')));
	for (int i = 0; i < n; i++) if (s[i] == '?') {
		if (dp[i] == dp[i + 1]) s[i] = ')';
		else s[i] = '(';
	}
//	if (s[0] == '?') s[0] = '(';
	if (ok()) printf("%s\n", s);
	else printf("Impossible\n");
	return 0;
}