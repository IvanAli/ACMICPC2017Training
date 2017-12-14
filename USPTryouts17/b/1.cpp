#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  scanf("%d", &n);
  if (n % 4 == 0) {
    for (int i = 0; i < n; i += 4) printf("-++-");
  } else if ((n + 1) % 4 == 0) {
    for (int i = 0; i < n - 1; i += 2) {
      if (i < n / 2 - 1) printf("+-");
      else if (i == n / 2 - 1) printf("++");
      else printf("-+");
    }
    puts("-");
  } else {
    puts("-1");
  }
  return 0;
}