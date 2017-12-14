#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

int n;
char ss[N][10];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", ss[i]);
  }
  int ans = 0;
  for (int j = 0; j < 7; j++) {
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += ss[i][j] - '0';
    ans = max(ans, cnt);
  }
  printf("%d\n", ans);
  return 0;
}