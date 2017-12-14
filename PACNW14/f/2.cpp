#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;
const int mod = 1e9 + 9;

int dx[] = {1, 2, -1, -2, -2, -1, 1, 2};
int dy[] = {2, 1, 2, 1, -1, -2, -2, -1};
int T;
int n, m;
int dp[1 << 8][1 << 8], dp2[1 << 8][1 << 8];

int add(int a, int b) {
	int ret = a + b;
	if (ret >= mod) ret -= mod;
	return ret;
}

bool ok(int msk1, int msk2, int msk3) {
	for (int i = 0; i < n; i++) if (msk3 & (1 << i)) {
		if (i + 2 < n && (msk2 & (1 << (i + 2)))) return false;
		if (i - 2 >= 0 && (msk2 & (1 << (i - 2)))) return false;
		if (i + 1 < n && (msk1 & (1 << (i + 1)))) return false;
		if (i - 1 >= 0 && (msk1 & (1 << (i - 1)))) return false;
	}
	return true;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		int ans = 0;
		memset(dp, 0, sizeof dp);
		memset(dp2, 0, sizeof dp2);
		for (int msk = 0; msk < 1 << n; msk++) dp[0][msk] = 1;
		for (int i = 1; i < m; i++) {
//			memset(dp2, 0, sizeof dp2);
			for (int msk1 = 0; msk1 < 1 << n; msk1++) for (int msk2 = 0; msk2 < 1 << n; msk2++) for (int msk3 = 0; msk3 < 1 << n; msk3++) {
				if (ok(msk1, msk2, msk3)) {
					dp2[msk2][msk3] = add(dp2[msk2][msk3], dp[msk1][msk2]);
				}
			}
//			for (int msk1 = 0; msk1 < 1 << n; msk1++) for (int msk2 = 0; msk2 < 1 << n; msk2++) ans += dp2[msk1][msk2], dp[msk1][msk2] = dp2[msk1][msk2];
			memcpy(dp, dp2, sizeof dp);
		}
		for (int i = 0; i < 1 << n; i++) for (int j = 0; j < 1 << n; j++) ans = add(ans, dp[i][j]);
		printf("%d\n", ans);
	}
	return 0;
}