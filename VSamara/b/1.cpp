#include <bits/stdc++.h>

using namespace std;

const int N = 22;

int dp[N];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w+", stdout);
  dp[0] = 0;
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x; scanf("%d", &x);
    ans += x - 1;
  }
  if (ans % 2) puts("Constantine");
  else puts("Mike");
  return 0;
}