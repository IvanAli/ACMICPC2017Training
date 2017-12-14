#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int row[10];
int col[10];
char grid[10][10];

bool solve(int r = 1, int c = 1) {
  if (r == n + 1) {
    for (int j = 1; j <= n; j++) {
      int cnt_up = 0;
      int large_up = 0;
      int cnt_down = 0;
      int large_down = 0;
      if (grid[0][j] != '-') {
        for (int i = 1; i <= n; i++) {
          if (grid[i][j] - '0' > large_up) {
            cnt_up++;
            large_up = grid[i][j] - '0';
          }
        }
        if (cnt_up != grid[0][j] - '0') return false;
      }
      if (grid[n + 1][j] != '-') {
        for (int i = n; i >= 1; i--) {
          if (grid[i][j] - '0' > large_down) {
            cnt_down++;
            large_down = grid[i][j] - '0';
          }
        }
        if (cnt_down != grid[n + 1][j] - '0') return false;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) putchar(grid[i][j]);
      putchar('\n');
    }
    return true;
  }
  if (c == n + 1) {
    if (grid[r][0] != '-') {
      int cnt_left = 0;
      int large_left = 0;
      for (int i = 1; i <= n; i++) {
        if (grid[r][i] - '0' > large_left) {
          cnt_left++;
          large_left = grid[r][i] - '0';
        }
      }
      if (cnt_left != grid[r][0] - '0') return false;
    }
    if (grid[r][n + 1] != '-') {
      int cnt_right = 0;
      int large_right = 0;
      for (int i = n; i >= 1; i--) {
        if (grid[r][i] - '0' > large_right) {
          cnt_right++;
          large_right = grid[r][i] - '0';
        }
      }
      if (cnt_right != grid[r][n + 1] - '0') return false;
    }
    if (solve(r + 1, 1)) return true;
  } 
  if (grid[r][c] == '-') {
    for (int d = 1; d <= n; d++) {
      if (!(row[r] & (1 << d)) && !(col[c] & (1 << d))) {
        grid[r][c] = d + '0';
        int prv_row = row[r];
        int prv_col = col[c];
        row[r] |= 1 << d;
        col[c] |= 1 << d;
        if (solve(r, c + 1)) return true;
        grid[r][c] = '-';
        row[r] = prv_row;
        col[c] = prv_col;
      }
    }
  } else {
    if (solve(r, c + 1)) return true;
  }
  return false;
}

int main() {
  scanf("%d", &T);
  while (T--) {
    memset(row, 0, sizeof row);
    memset(col, 0, sizeof col);
    scanf("%d", &n);
    for (int i = 0; i <= n + 1; i++) scanf("%s", grid[i]);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
      if (grid[i][j] != '-') {
        row[i] |= 1 << (grid[i][j] - '0');
        col[j] |= 1 << (grid[i][j] - '0');
      }
    }
    if (!solve()) printf("no\n");
    printf("\n");
  }
  return 0;
}