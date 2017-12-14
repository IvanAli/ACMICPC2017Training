#include <bits/stdc++.h>

using namespace std;


int main() {
  int t = 123;
  printf("%d\n", t);
  for (int i = 0; i < t; i++) {
    int n = rand() % 12345;
    int k = 9 * n;
    printf("%d %d\n", n, k);
  }
  return 0;
 }