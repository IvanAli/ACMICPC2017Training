#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];


int main() {
  srand(time(0));
  int T = 123;
  cout << T << endl;
  while (T--) {
  
    int n = rand() % 6 + 1;
    cout << n << endl;
    for (int i = 0; i < n; i++) a[i] = i + 1;
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        int r = rand() % i;
        swap(a[r], a[i]);
      }
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) putchar(' ');
      printf("%d", a[i]);
    }
    putchar('\n');
  }
  return 0;
}