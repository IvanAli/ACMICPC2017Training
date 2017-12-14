#include <bits/stdc++.h>

using namespace std;

int T;
int a, b;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &a, &b);
    if (a % 2 == 0 && b % 2 == 0) puts("abdullah");
    else puts("hasan");
  }
  return 0;
}