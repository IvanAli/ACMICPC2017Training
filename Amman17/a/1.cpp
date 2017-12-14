#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int T;
int n;
int have[N];
char s[N];

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 11111; i <= 99999; i++) have[i] = 0;
    for (int i = 0; i < n; i++) {
      int foo; scanf("%s %d", s, &foo);
      have[foo]++;
    }
    int ans = 11111;
    for (int i = 11111; i <= 99999; i++) {
      if (have[i] > have[ans]) ans = i;
    }
    printf("%d\n", ans);
  }
  return 0;
}