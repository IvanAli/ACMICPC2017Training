#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int n;
char s[N];
vector<int> pacman, food;

bool ok(int t) {
  int j = 0;
  for (int i = 0; i < (int) pacman.size(); i++) {
    int x = pacman[i];
    int lf = x, rg = x;
    while (j < (int) food.size()) {
      lf = min(lf, food[j]);
      rg = max(rg, food[j]);
      int used = rg - lf + min(rg - x, x - lf);
      if (used > t) break;
      j++;
    }
  }
  if (j == (int) food.size()) return true;
  return false;
}
      

int main() {
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'P') pacman.push_back(i);
    if (s[i] == '*') food.push_back(i);
  }
  int low = 0, high = 2 * n, mid;
  while (low < high) {
    mid = low + high >> 1;
    if (ok(mid)) high = mid;
    else low = mid + 1;
  }
  printf("%d\n", low);
  return 0;
}