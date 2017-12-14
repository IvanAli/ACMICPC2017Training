#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

int n;
int T;
int a[N];
int dp[N][2];

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i + 1);
    for (int i = 0; i <= n; i++) for (int j = 0; j < 2; j++) dp[i][j] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        if (a[j] <= a[i]) dp[i][0] = max(dp[i][0], dp[j][0] + 1);
        if (a[i] <= a[j]) {
          dp[i][1] = max(dp[i][1], dp[j][0] + 1);
          dp[i][1] = max(dp[i][1], dp[j][1] + 1);
        }
      }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) for (int j = 0; j < 2; j++) ans = max(ans, dp[i][j]); 
    printf("%d\n", ans);
  }
  return 0;
}
