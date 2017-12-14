#include <bits/stdc++.h>

using namespace std;

const int P = 55;
const int M = 1234;

int dp[P][M];

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < P; i++) for (int j = 1; j < M; j++) dp[i][j] = (int) 1e9;
  dp[0][0] = 0;
  for (int i = 1; i < M; i++) dp[1][i] = i;
  for (int i = 2; i < P; i++) {
    for (int j = 1; j < M; j++) {
      for (int k = 1; k <= j; k++) {
        dp[i][j] = min(dp[i][j], max(dp[i - 1][k - 1] + 1, dp[i][j - k] + 1));
      }
    }
  }
  for (int tc = 0; tc < T; tc++) {
    printf("Case %d: ", tc + 1);
    int p, m; scanf("%d %d", &p, &m);
    printf("%d\n", dp[p][m]);
  }
  return 0;
}