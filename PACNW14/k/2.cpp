#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int row[10];
int col[10];
char grid[10][10];


void solve(int r = 1, int c = 1) {
//  cerr << "r : " << r << ' ' << "c : " << c << endl;
  if (r == n + 1) {
    cerr << "end" << endl;
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
        if (cnt_up != grid[0][j] - '0') return;
      }
      if (grid[n + 1][j] != '-') {
        for (int i = n; i >= 1; i--) {
          if (grid[i][j] - '0' > large_down) {
            cnt_down++;
            large_down = grid[i][j] - '0';
          }
        }
        if (cnt_down != grid[n + 1][j]) return;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) putchar(grid[i][j]);
      putchar('\n');
    }
    exit(0);
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
      if (cnt_left != grid[r][0] - '0') return;
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
      if (cnt_right != grid[r][n + 1] - '0') return;
    }
    solve(r + 1, 1);
    return; 
  } 
  if (grid[r][c] == '-') {
    for (int d = 1; d <= n; d++) {
      if (!(row[r] & (1 << d)) && !(col[c] & (1 << d))) {
        grid[r][c] = d + '0';
        /*
        if (c == n) {
          if (grid[r][0] != '-') {
            int cnt_left = 0;
            int large_left = 0;
            for (int i = 1; i <= n; i++) {
              if (grid[r][i] - '0' > large_left) {
                cnt_left++;
                large_left = grid[r][i] - '0';
              }
            }
            if (cnt_left != grid[r][0] - '0') return;
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
            if (cnt_right != grid[r][n + 1] - '0') return;
          }
          solve(r + 1, 1); 
        } else {
          if (c > n) assert(0);
          fprintf(stderr, "ok r: %d c: %d\n", r, c);
          solve(r, c + 1);
        }   */
        solve(r, c + 1);
      }
    }
  } else {
    solve(r, c + 1);
  }
}

int main() {
  scanf("%d", &T);
  while (T--) {
    memset(row, 0, sizeof row);
    memset(col, 0, sizeof col);
    scanf("%d", &n);
    for (int i = 0; i < n + 1; i++) scanf("%s", grid[i]);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
      if (grid[i][j] != '-') {
//        row[i][j] -= 1;
        row[i] |= 1 << (grid[i][j] - '0');
        col[j] |= 1 << (grid[i][j] - '0');
      }
    }
    solve();
  }
  return 0;
}