#include <bits/stdc++.h>

using namespace std;


int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w+", stdout);
  int n, k;
  scanf("%d %d", &n, &k);
  if (n == 1) {
    puts("0");
    return 0;
  }
  long long cur = k + 1;
  for (int i = 1; ; i++) {
    if (cur >= n) {
      printf("%d\n", i);
      return 0;
    }
    cur *= (long long) (k + 1);
  }
  assert(0);
  return 0;
}