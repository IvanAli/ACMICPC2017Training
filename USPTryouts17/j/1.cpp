#include <bits/stdc++.h>

using namespace std;

const int N = 20;

char n[N], k[N];
int len_n, len_k;
long long dp[9 * N][N][10][2];

void add() {
  bool ok = false;
  for (int i = len_n - 1; i >= 0; i--) {
    int d = n[i] - '0';
    if (d < 9) {
      n[i]++;
      ok = true;
      break;
    } else {
      n[i] = '0';
    }
  }
  if (!ok) {
    for (int i = 0; i < len_n; i++) n[i + 1] = 0;
    n[0] = 1;
    len_n++;
  }  
}

int main() {
  scanf("%s %s", n, k);
  len_n = strlen(n);
  len_k = strlen(k);
  add();
  int sum = 0;
  for (int i = 0; i < len_k; i++) {
    int d = k[i] - '0';
    sum += d;
  }
  for (int d = 0; d < 10; d++) {
    int dn = n[len_n - 1] - '0';
    if (d < dn) dp[d][1][d][1] = 1;
    else dp[d][1][d][0] = 1;
  }
  for (int s = 0; s <= sum; s++) for (int l = 1; l < len_n; l++) for (int d1 = 0; d1 < 10; d1++) for (int d2 = 0; d2 < 10; d2++) {
    int dk = n[len_n - l - 1];
    if (d1 < dk) {
      for (int i = 0; i < 2; i++) {
        if (d1 > -1) dp[s + d1][l + 1][d1][1] += dp[s][l][d2][i];
      }
    } else if (d1 == dk) {
      for (int i = 0; i < 2; i++) {
        if (d1 > -1) dp[s + d1][l + 1][d1][i] += dp[s][l][d2][i];
      }
    } else {
      for (int i = 0; i < 2; i++) {
        if (d1 > -1) dp[s + d1][l + 1][d1][0] += dp[s][l][d2][i];
      }
    }
    /*if (d2 < dk) {
      for (int i = 0; i < 2; i++) {
        if (d2 > 0) dp[s + d1][l + 1][d2][1] += l * dp[s][l][d2][i];
      }
    } else if (d2 == dk) {
      for (int i = 0; i < 2; i++) {
        if (d2 > 0) dp[s + d1][l + 1][d2][i] += l * dp[s][l][d2][i];
      }
    } else {
      for (int i = 0; i < 2; i++) {
        if (d2 > 0) dp[s + d1][l + 1][d2][0] += l * dp[s][l][d2][i];
      }
    } */
  }
  int sum_k = sum;
  long long ans = 0;
  for (int i = 0; i < len_k; i++) {
    int dk = k[i] - '0';
    for (int s = 0; s < sum_k; s++) for (int l = 0; l <= len_k; l++) for (int d = 0; d < 10; d++) {
      ans += dp[s][l][d][1];
      if (l < len_n) ans += dp[s][l][d][0];
    }
    for (int l = 0; l < len_k; l++) for (int d = 0; d < 10; d++) {
      ans += dp[sum_k][l][d][1];
      if (l < len_n) ans += dp[sum_k][l][d][0];
    }
    for (int d = 0; d < dk; d++) {
      ans += dp[sum_k][len_k - i][d][1];
      if (len_k - i < len_n) ans += dp[sum_k][len_k - i][d][0];
    }
    sum_k -= dk;
  }
  printf("%lld\n", ans);
  return 0;
}