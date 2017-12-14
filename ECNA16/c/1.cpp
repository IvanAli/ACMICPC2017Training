#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

char c[N], p[N], s[N];

int main() {
  scanf("%s %s", c, p);
  int p_len = strlen(p);
  int c_len = strlen(c);
  for (int i = 0; i < min(p_len, c_len); i++) {
    int pi = p[i] - 'A';
    int ci = c[i] - 'A';
    if (ci >= pi) s[i] = ci - pi + 'A';
    else s[i] = 26 + ci - pi + 'A';
  }
  for (int i = min(p_len, c_len); i < c_len; i++) {
    int ci = c[i] - 'A';
    int si = s[i - min(p_len, c_len)] - 'A';
    if (ci >= si) s[i] = ci - si + 'A';
    else s[i] = 26 + ci - si + 'A';
  }
  printf("%s\n", s);
  return 0;
}