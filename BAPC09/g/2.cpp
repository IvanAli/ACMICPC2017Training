#include <bits/stdc++.h>

using namespace std;

int n, h, o;
int mat[2][2], aux[2][2];

void go(long long &x, long long &y, int s) {
  mat[0][0] = 0;
  mat[0][1] = 1;
  mat[1][1] = 2;
  mat[1][0] = 3;
  int pw = 1;
  for (int i = 0; i < n - 1; i++) pw *= 4;
  for (int i = n; i > 0; i--) {
    int where = s / pw;
    if (mat[0][0] == where) {
      aux[0][0] = mat[0][0];
      aux[0][1] = mat[1][0];
      aux[1][1] = mat[1][1];
      aux[1][0] = mat[0][1];
      for (int x = 0; x < 2; x++) for (int y = 0; y < 2; y++) mat[x][y] = aux[x][y];
    }
    if (mat[0][1] == where) {
      x += (1 << (i - 1)) * 10;
    }
    if (mat[1][1] == where) {
      x += (1 << (i - 1)) * 10;
      y += (1 << (i - 1)) * 10;
    }
    if (mat[1][0] == where) {
      aux[0][0] = mat[1][1];
      aux[0][1] = mat[0][1];
      aux[1][1] = mat[0][0];
      aux[1][0] = mat[1][0];
      for (int x = 0; x < 2; x++) for (int y = 0; y < 2; y++) mat[x][y] = aux[x][y];
      y += (1 << (i - 1)) * 10;
    }
    s %= pw;
    pw /= 4;
  }
}

int main() {
  int T; scanf("%d", &T);
  while (T--) {
    scanf("%d %d %d", &n, &h, &o);
    h--, o--;
    long long xh = 0, yh = 0;
    long long xo = 0, yo = 0;
    go(xh, yh, h);
    go(xo, yo, o);
    long long d2 = (xh - xo) * (xh - xo) + (yh - yo) * (yh - yo);
    long long ans = round(sqrt(d2));
    printf("%lld\n", ans);
  }
  return 0;
}