#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 12345;

int T;
int n, m;
int a[N];
int dp[N];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) scanf("%d", a + i);
//		memset(dp, , sizeof dp);
		for (int i = 0; i < N; i++) dp[i] = 1 << 30;
		dp[0] = 0;
		for (int i = 0; i < N; i++) for (int j = 0; j < m; j++) dp[i + a[j]] = min(dp[i + a[j]], i + a[j] + dp[i]);
		bool ok = false;
		for (int i = N - 1; i >= 0; i--) {
			if (dp[i] == n) {
				printf("%d\n", i);
				ok = true;
				break;
			}
		}
		if (!ok) printf("-1\n");
	}
	return 0;
}