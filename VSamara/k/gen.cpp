#include <bits/stdc++.h>

using namespace std;


int main() {
  srand(time(0));
  for (int i = 0; i < 12345; i++) {
    int n = rand() % 11 + 1;
    for (int j = 0; j < n; j++) {
      int r = rand() % 2;
      if (r == 0) putchar('1');
      else putchar('3');
    }
    puts("");
  }
  return 0;
}