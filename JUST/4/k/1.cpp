#include <bits/stdc++.h>

using namespace std;

const int N = 21;

long long fact[N];
char s[N];
int have[26];

bool ok() {
  int odd = 0;
  for (int i = 0; i < 26; i++) {
    if (have[i] % 2) odd++;
  }
  return odd <= 1;
}

long long c(int n, int k) {
  if (n < k) return 1;
  long long ret = fact[n];
  ret /= fact[n - k];
  ret /= fact[k];
  return ret;
}

int main() {
  int T;
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i;
  scanf("%d", &T);
  while (T--) {
    int n; scanf("%d", &n);
    scanf("%s", s);
    memset(have, 0, sizeof have);
    for (int i = 0; i < n; i++) {
      have[s[i] - 'a']++;
    }
    if (!ok()) puts("0");
    else {
      n /= 2;
      long long ans = 1;
      for (int i = 0; i < 26; i++) {
        if (have[i] > 1) {
          ans *= c(n, have[i] / 2);
          n -= have[i] / 2;
        }
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}