#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  scanf("%d", &n);
  printf("%d\n", (1 << (n + 1)) - 1);
  return 0;
}