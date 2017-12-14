#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int a[N];
int ne[N];
int dp[N];
int last[N];

int main() {
  int T; scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    memset(last, -1, sizeof last);
    for (int i = n - 1; i >= 0; i--) {
      ne[i] = last[a[i]];
      last[a[i]] = i;
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++) dp[i + 1] = (int) 1e9;
    for (int i = 0; i < n; i++) {
      dp[i + 1] = min(dp[i + 1], dp[i] + 1);
      dp[ne[i]] = min(dp[ne[i]], dp[i] + 1);
    }
    printf("%d\n", dp[n] - 1);
  }
  return 0;
}