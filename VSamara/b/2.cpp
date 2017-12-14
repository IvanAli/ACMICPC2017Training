#include <bits/stdc++.h>

using namespace std;

const int N = 22;

int dp[N];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w+", stdout);
  dp[0] = 0;
  for (int i = 1; i < N; i++) {
    set<int> st;
    for (int j = 1; j < i; j++) {
      st.insert(dp[j]);
    }
    int mex = 0;
    while (st.count(mex)) mex++;
    dp[i] = mex;
  }
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x; scanf("%d", &x);
    ans ^= dp[x];
  }
  if (ans > 0) puts("Constantine");
  else puts("Mike");
  return 0;
}