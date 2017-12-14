#include <bits/stdc++.h>

using namespace std;

long long n, k;
long long dp[20 * 9][20][10][2];

int get_len(long long k) {
  if (k == 0) return 1;
  int ret = 0;
  while (k) {
    ret++;
    k /= 10;
  }
  return ret;
}

int get_sum(long long k) {
  int ret = 0;
  while (k) {
    int d = k % 10;
    ret += d;
    k /= 10;
  }
  return ret;
}

int main() {
  scanf("%lld %lld\n", &n, &k);
  // sum length first_digit
  for (int i = 0; i < 10; i++) {
    if (i < n) dp[i][1][i][1] = 1;
    else dp[i][1][i][0] = 1;
  }
  int len = get_len(k);
  int sum = get_sum(k);
  string s = to_string(k);
  for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) for (int l = 2; l <= len; l++) for (int s = 0; s <= sum; s++) {
    dp[i][l][s + i] += dp[j][l - 1][s];
  }
  int sub = 0;
  long long lf = 0, rg = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    int d = s[i] - '0';
    for (int j = 0; j < d; j++) for (int l = 0; l <= len; l++) for (int s = 0; s <= sum - sub; s++) {
      lf += dp[j][l][s];
    }
    sub += d;
  }
  printf("%lld\n", lf + 1);
  return 0;
}         