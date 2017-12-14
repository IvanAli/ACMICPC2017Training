#include <bits/stdc++.h>

using namespace std;

const int N = 123;

int n;
int a[N];

bool ok(int dif) {
  for (int i = 0; i + 1 < n; i++) {
    if (a[i + 1] - a[i] != dif) return false;
  }
  return true;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int dif = a[1] - a[0];
  if (ok(dif)) printf("%d\n", a[n - 1] + dif);
  else printf("%d\n", a[n - 1]); 
  return 0;
}