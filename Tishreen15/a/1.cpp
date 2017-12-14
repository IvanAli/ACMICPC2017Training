#include <bits/stdc++.h>

using namespace std;


int main() {
  int T;
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    printf("Case %d: ", tc + 1);
    int h1, m1, s1, h2, m2, s2;
    scanf("%d %d %d %d %d %d", &h1, &m1, &s1, &h2, &m2, &s2);
    int t1 = h1 * 3600 + m1 * 60 + s1;
    int t2 = h2 * 3600 + m2 * 60 + s2;
    if (t1 == t2) puts("Yes");
    else puts("No");
  }
  return 0;
}