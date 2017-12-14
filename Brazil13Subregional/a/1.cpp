#include <bits/stdc++.h>

using namespace std;


int a, b, c;

int main() {
  scanf("%d %d %d", &a, &b, &c);
  if (b != a && c != a) printf("A\n");
  else if (a != b && c != b) printf("B\n");
  else if (a != c && b != c) printf("C\n");
  else printf("*\n");
  return 0;
}