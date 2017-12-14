#include <bits/stdc++.h>

using namespace std;

int n, b;

int main() {
  while (scanf("%d %d", &n, &b) == 2) {
    int res = (1 << n) - b;
    vector<char> what;
    printf("Instructions: ");
    while (res > 1) {
      if (res % 2 == 0) {
        what.push_back('L');
      } else {
        what.push_back('R');
      }
      res /= 2;
    }
    reverse(what.begin(), what.end());
    for (auto it : what) putchar(it);
    puts("");
  }
  return 0;
}
