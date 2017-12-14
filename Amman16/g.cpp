#include <bits/stdc++.h>
using namespace std;

const int maxn = 100055;

int c[] = {1, 5, 10, 20, 50};
int T, n, m;
int a[maxn];
int dp[maxn];
int cnt[maxn][5];

int main() {
	for (int i = 0; i < maxn; i++) dp[i] = 1 << 30;
	dp[0] = 0;
//	for (int i = 0; i < maxn; i++) for (int j = 0; j < 5; j++) dp[i + c[j]] = min(dp[i + c[j]], dp[i] + 1); 
	for (int i = 0; i < maxn; i++) for (int j = 0; j < 5; j++) {
		if (dp[i] + 1 < dp[i + c[j]]) {
			dp[i + c[j]] = dp[i] + 1;
			for (int k = 0; k < 5; k++) cnt[i + c[j]][k] = cnt[i][k];
			cnt[i + c[j]][j]++;
		}		
	} 
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) scanf("%d", &a[i]);
		int ansi = a[0];
		for (int i = 0; i < m; i++) {
			if (dp[a[i]] < dp[ansi]) ansi = a[i];
		}
		for (int i = 0; i < 5; i++) {
			if (i > 0) printf(" ");
			printf("%d", cnt[ansi][i]);
		}
		printf("\n");
	}
	return 0;
}
