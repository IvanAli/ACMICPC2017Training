#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;
const int MAX = 21;
const int mod = (int) 1e9 + 7;

int n;
bitset<N> prime;
vector<int> primes;
int dp[MAX + 2][MAX + 2][MAX + 2][MAX + 2][MAX + 2];

void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

vector<int> fact(int n) {
  vector<int> ret;
  for (int i = 0; i < (int) primes.size() && (long long) primes[i] * primes[i] <= n; i++) {
    while (n % primes[i] == 0) {
      ret.push_back(primes[i]);
      n /= primes[i];
    }
  }
  if (n > 1) ret.push_back(n);
  return ret;
}

vector<int> split(vector<int> v) {
  vector<int> ret;
  for (auto it : v) {
    if (it == 0) assert(0);
    while (it > 0) {
      int d = it % 10;
      ret.push_back(d);
      it /= 10;
    }
  }
  return ret;
}

int main() {
  prime.set();
  for (int i = 2; i < N; i++) {
    if (prime[i]) {
      primes.push_back(i);
      for (long long j = (long long) i * i; j < N; j += i) prime[j] = 0;
    }
  }
  while (scanf("%d", &n) == 1) {
    vector<int> f = fact(n);
    f = split(f);
    memset(dp, 0, sizeof dp);
    dp[0][0][0][0][0] = 1; 
    int len = (int) f.size();
    for (int i = 0; i < len; i++) {
      for (int l1 = 0; l1 < MAX; l1++) for (int l2 = 0; l2 < MAX; l2++) for (int l6 = 0; l6 < MAX; l6++) for (int l9 = 0; l9 < MAX; l9++) {
        if (f[i] == 1) {
          if (l1 > 0) add(dp[i + 1][l1 - 1][l2][l6][l9], dp[i][l1][l2][l6][l9]);
         //  add(dp[i + 1][l1 + 1][l2][l6][l9], dp[i][l1][l2][l6][l9]);
          if (l2 > 0) add(dp[i + 1][l1][l2 - 1][l6][l9], dp[i][l1][l2][l6][l9]);
          if (l2 > 0) add(dp[i + 1][l1][l2 - 1][l6][l9], dp[i][l1][l2][l6][l9]);
          if (l6 > 0) add(dp[i + 1][l1][l2][l6 - 1][l9], dp[i][l1][l2][l6][l9]);
          if (l9 > 0) add(dp[i + 1][l1][l2][l6][l9 - 1], dp[i][l1][l2][l6][l9]);
          add(dp[i + 1][l1 + 1][l2][l6][l9], dp[i][l1][l2][l6][l9]);
        } else if (f[i] == 2) {
          if (l1 > 0) add(dp[i + 1][l1 - 1][l2][l6][l9], dp[i][l1][l2][l6][l9]);
          if (l1 > 0) add(dp[i + 1][l1 - 1][l2][l6][l9], dp[i][l1][l2][l6][l9]);
          if (l2 > 0) add(dp[i + 1][l1][l2 - 1][l6][l9], dp[i][l1][l2][l6][l9]);
          if (l6 > 0) add(dp[i + 1][l1][l2][l6 - 1][l9], dp[i][l1][l2][l6][l9]);
          add(dp[i + 1][l1][l2 + 1][l6][l9], dp[i][l1][l2][l6][l9]);
        } else if (f[i] <= 6) {
          if (l1 > 0) add(dp[i + 1][l1 - 1][l2][l6][l9], dp[i][l1][l2][l6][l9]);
          if (l2 > 0) add(dp[i + 1][l1][l2 - 1][l6][l9], dp[i][l1][l2][l6][l9]);
          add(dp[i + 1][l1][l2][l6 + 1][l9], dp[i][l1][l2][l6][l9]);
        } else if (f[i] <= 9) {
          if (l1 > 0) add(dp[i + 1][l1 - 1][l2][l6][l9], dp[i][l1][l2][l6][l9]);
          add(dp[i + 1][l1][l2][l6][l9 + 1], dp[i][l1][l2][l6][l9]);
        } else assert(0);
      }
    }
    int ans = 0;
    for (int l1 = 0; l1 < MAX; l1++) for (int l2 = 0; l2 < MAX; l2++) for (int l6 = 0; l6 < MAX; l6++) for (int l9 = 0; l9 < MAX; l9++) {
      add(ans, dp[len][l1][l2][l6][l9]);
    }
    printf("%d\n", ans);
  }
  return 0;
}