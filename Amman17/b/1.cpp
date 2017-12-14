#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int T;
char a[N], b[N];
int have[26];

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%s %s", a, b);
    memset(have, 0, sizeof have);
    int len_a = strlen(a);
    int len_b = strlen(b);
    for (int i = 0; i < len_b; i++) {
      have[b[i] - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < len_a; i++) {
      if (have[a[i] - 'a']) {
        ans++;
        have[a[i] - 'a']--;
      } else break;
    }
    printf("%d\n", ans);
  }
  return 0;
}