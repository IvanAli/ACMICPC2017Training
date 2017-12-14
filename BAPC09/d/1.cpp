#include <bits/stdc++.h>

using namespace std;

const int N = 21;

char s[N];
long long fact[N];

int main() {
  int T;
  scanf("%d", &T);
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = (long long) i * fact[i - 1];
  while (T--) {
    scanf("%s", s);
    int n = strlen(s);
    long long ans = 0;
    vector<int> have(26);
    for (int i = 0; i < n; i++) {
      have[s[i] - 'A']++;
    }
    for (int t = 0; t < n; t++) {
      for (int i = 0; i < s[t] - 'A'; i++) {
        if (have[i] > 0) {
          have[i]--;
          long long cur = fact[n - t - 1];
          for (int j = 0; j < 26; j++) cur /= fact[have[j]];
          have[i]++;
          ans += cur;
        }
      }
      have[s[t] - 'A']--;
    }
    printf("%lld\n", ans);
  }
  return 0;
}