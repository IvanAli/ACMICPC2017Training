#include <bits/stdc++.h>

using namespace std;

int T;
int n, k;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &k);
    printf("%d\n", n + k - 1);
  }
  return 0;
}