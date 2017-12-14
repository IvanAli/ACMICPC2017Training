#include <bits/stdc++.h>

using namespace std;


int main() {
  int n;
  scanf("%d", &n);
  map<int, int> have;
  for (int i = 0; i < n; i++) {
    int x; scanf("%d", &x);
    have[x]++;
  }
  int ans = 0;
  for (auto it : have) {
    ans += it.second - 1;
  }
  printf("%d\n", ans);
  return 0;
}