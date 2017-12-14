#include <bits/stdc++.h>

using namespace std;

int a[4][4];
int ans[4][4];
bool have[17];
int sum;
bool init;

bool first() {
  for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) if (ans[i][j] > -1) return false;
  return true;
}

bool better() {
  for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
    if (ans[i][j] < a[i][j]) return false;
    if (ans[i][j] > a[i][j]) return true;
  }
  return false;
}

void update() {
  if (first()) {
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) ans[i][j] = a[i][j];
  } else {
    if (better()) {
      for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) ans[i][j] = a[i][j];
    } 
  }
}

void solve(int r = 0, int c = 0) {
  if (r == 4) {
    for (int j = 0; j < 4; j++) {
      int cur = 0;
      for (int i = 0; i < 4; i++) {
        assert(a[i][j] > -1);
        cur += a[i][j];
      }
      if (cur != sum) return;
    }
    update();
    return;
  }
  if (a[r][c] == -1) {
    for (int i = 1; i <= 16; i++) {
      if (have[i]) continue;
      have[i] = true;
      a[r][c] = i;
      if (c + 1 == 4) {
        int cur = 0;
        for (int j = 0; j < 4; j++) {
          assert(a[r][j] > -1);
          cur += a[r][j];
        }
        bool rev = false;
        if (sum == -1) {
          sum = cur;
          rev = true;
        }
        if (cur == sum) {
          solve(r + 1, 0);
        }
        if (rev) sum = -1;
      } else {
        solve(r, c + 1);
      }
      have[i] = false;
    }
    a[r][c] = -1;
  } else {
    if (c + 1 == 4) {
      int cur = 0;
      for (int j = 0; j < 4; j++) {
        assert(a[r][j] > -1);
        cur += a[r][j];
      }
      bool rev = false;
      if (sum == -1) {
        sum = cur;
        rev = true;
      }
      if (cur == sum) {
        solve(r + 1, 0);
      }
      if (rev) sum = -1;
    } else {
      solve(r, c + 1);
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    printf("Case %d:\n", tc + 1);
    sum = -1;
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) scanf("%d", a[i] + j);
    memset(have, 0, sizeof have);
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
      if (a[i][j] > -1) have[a[i][j]] = true;
      ans[i][j] = -1;
    }
    for (int i = 0; i < 4; i++) {
      int cur = 0;
      for (int j = 0; j < 4; j++) {
        if (a[i][j] > -1) {
          cur += a[i][j]; 
        } else {
          cur = -1;
          break;
        }
      }
      if (cur > -1) {
        if (sum == -1) sum = cur;
        else assert(sum == cur);
      }
    }
    for (int j = 0; j < 4; j++) {
      int cur = 0;
      for (int i = 0; i < 4; i++) {
        if (a[i][j] > -1) cur += a[i][j];
        else {
          cur = -1;
          break;
        }
      }
      if (cur > -1) {
        if (sum == -1) sum = cur;
        else assert(sum == cur);
      }
    }
    if (sum > -1) init = true;
    solve();
    if (ans[0][0] == -1) assert(0);
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (j > 0) putchar(' ');
        printf("%d", ans[i][j]);
      }
      puts("");
    }
  }
  return 0;
}