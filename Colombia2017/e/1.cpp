#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

char s[N], t[N];
int k;
int len[N];
int f[N];

int main() {
//  scanf("%s %s %d", s, t, &k);
  fgets(s, N, stdin);
  fgets(t, N, stdin);
  scanf("%d", &k);
  int len_s = strlen(s);
  int len_t = strlen(t);
  f[0] = -1;
  for (int i = 0, j = -1; i < len_t; i++, j++) {
    while (j > -1 && t[i] != t[j]) j = f[j];
    f[i + 1] = j + 1;
  }
  for (int i = 0, j = 0; i < len_s; i++, j++) {
    while (j > -1 && s[i] != t[j]) {
      j = f[j];
//      if (j > -1) len[j]++;
    }
    len[j + 1]++;
    if (j + 1 == len_t) {
      j = f[j + 1] - 1;
    }
  }
  for (int i = len_t; i >= 0; i--) len[f[i]] += len[i];
  for (int i = len_t; i > 0; i--) {
    if (len[i] >= k) {
      for (int j = 0; j < i; j++) putchar(t[j]);
      puts("");
      return 0;
    }
  }
  puts("IMPOSSIBLE");
  return 0;
}