#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

char s[N];
int a[N], b[N];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w+", stdout);
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') a[i]++;
    if (i > 0) a[i] += a[i - 1];
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '3') b[i]++;
    b[i] += b[i + 1];
  }
  int ans = b[0];
  for (int i = 0; i < n; i++) {
    ans = min(ans, a[i] + b[i + 1]);
  }
  printf("%d\n", ans);
  return 0;
}