#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;
const int M = 2222;

char s[N];
int mat[M][M];

int main() {
  while (fgets(s, N, stdin)) {
    int row = 0, col = 0;
    int n = strlen(s);
    int cur = 0;
    int sgn = 1;
    for (int i = 0; i < n; i++) {
      if ('0' <= s[i] && s[i] <= '9') {
        cur = cur * 10 + s[i] - '0';
      } else if (s[i] == ',') {
        mat[row][col++] = cur * sgn;
        cur = 0;
        sgn = 1;
      } else if (s[i] == ';') {
        mat[row++][col] = cur * sgn;
        cur = 0;
        col = 0;
        sgn = 1;
      } else if (s[i] == '-') {
        sgn = -1;
      }
    }
    mat[row++][col] = cur * sgn;
    bool ok = true;
    for (int i = 0; i < row; i++) for (int j = 0; j < row; j++) {
      if (mat[i][j] != mat[j][i]) {
        ok = false;
        break;
      }
    }
    if (ok) puts("Symmetric");
    else puts("Not symmetric");
  }
  return 0;
}