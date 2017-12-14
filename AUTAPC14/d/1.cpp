#include <bits/stdc++.h>

using namespace std;

const int N = 1234;
const int mod = (int) 1e9 + 7;

int n, q;
char grid[N][N];
int dp1[N][N];
int dp2[N][N];
int mx1[N][N];
int mx2[N][N];

int add(int a, int b) {
  int ret = a + b;
  if (ret >= mod) ret -= mod;
  return ret;
}

int mul(int a, int b) {
  return (long long) a * b % mod;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%s", grid[i] + 1);
  mx1[0][0] = -1;
  mx1[0][1] = -1;
  mx1[1][0] = -1;
  mx2[n + 1][n] = -1;
  mx2[n][n + 1] = -1;
  dp1[1][1] = 1;
  mx1[1][1] = grid[1][1] == 'C';
  mx2[n][n] = grid[n][n] == 'C';
  dp2[n][n] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int c = grid[i][j] == 'C';
      if (mx1[i - 1][j] + c > mx1[i][j]) {
        mx1[i][j] = mx1[i - 1][j] + c;
        dp1[i][j] = dp1[i - 1][j];
      } else if (mx1[i - 1][j] + c == mx1[i][j]) {
        dp1[i][j] = add(dp1[i][j], dp1[i - 1][j]);
      }
      if (mx1[i][j - 1] + c > mx1[i][j]) {
        mx1[i][j] = mx1[i][j - 1] + c;
        dp1[i][j] = dp1[i][j - 1];
      } else if (mx1[i][j - 1] + c == mx1[i][j]) {
        dp1[i][j] = add(dp1[i][j], dp1[i][j - 1]);
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = n; j >= 1; j--) {
      int c = grid[i][j] == 'C';
      if (mx2[i][j + 1] + c > mx2[i][j]) {
        mx2[i][j] = mx2[i][j + 1] + c;
        dp2[i][j] = dp2[i][j + 1];
      } else if (mx2[i][j + 1] + c == mx2[i][j]) {
        dp2[i][j] = add(dp2[i][j], dp2[i][j + 1]);
      }
      if (mx2[i + 1][j] + c > mx2[i][j]) {
        mx2[i][j] = mx2[i + 1][j] + c;
        dp2[i][j] = dp2[i + 1][j];
      } else if (mx2[i + 1][j] + c == mx2[i][j]) {
        dp2[i][j] = add(dp2[i][j], dp2[i + 1][j]);
      }
    }
  }
  scanf("%d", &q);
  while (q--) {
    int r1, c1, r2, c2; scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    r1++, c1++, r2++, c2++;
    int val = 0;
    for (int c = c2 + 1, r = r1 - 1; c <= n && r > 0; c++, r--) {
      val = max(val, mx1[r][c] + mx2[r + 1][c]);
      val = max(val, mx1[r][c] + mx2[r][c + 1]);
    }
    for (int c = c1 - 1, r = r2 + 1; c > 0; c--) {
      val = max(val, mx1[r][c] + mx2[r][c + 1]);
      val = max(val, mx1[r][c] + mx2[r + 1][c]);
    }
    int ans = 1;
    for (int c = c2 + 1, r = r1 - 1; c <= n && r > 0; c++, r--) {
      if (mx1[r][c] + mx2[r + 1][c] == val) {
        ans = add(ans, mul(dp1[r][c], dp2[r + 1][c]));
      }
      if (mx1[r][c] + mx2[r][c + 1] == val) {
        ans = add(ans, mul(dp1[r][c], dp2[r][c + 1]));
      }
    }
    for (int c = c1 - 1, r = r2 + 1; c > 0; c--, r++) {
      if (mx1[r][c] + mx2[r][c + 1] == val) {
        ans = add(ans, mul(dp1[r][c], dp2[r][c + 1]));
      }
      if (mx1[r][c] + mx2[r + 1][c] == val) {
        ans = add(ans, mul(dp1[r][c], dp2[r + 1][c]));
      }
    }
    printf("%d %d\n", val, ans - 1);
  }
  return 0;
}