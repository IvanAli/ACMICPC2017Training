#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    if (a >= b + c) {
      puts("NO");
      return 0;
    }
    if (b >= a + c) {
      puts("NO");
      return 0;
    }
    if (c >= a + b) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}