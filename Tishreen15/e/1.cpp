#include <bits/stdc++.h>

using namespace std;

const int N = 12;

int s[N];
int x[N];

bool ok() {
/*  for (int i = 0; i < 4; i++) {
    if (x[i] > x[i + 1]) return false;
  }*/         
  map<int, int> ma;
  for (int i = 1; i <= 10; i++) ma[s[i]]++;
  for (int i = 0; i < 5; i++) for (int j = i + 1; j < 5; j++) {
    int sum = x[i] + x[j];
    if (ma[sum] == 0) return false;
    ma[sum]--;
  }

  return true;
  for (int i = 0; i < 5; i++) {
    if (x[i] <= 0) return false;
  }
  return true;
  for (int i = 1; i <= 10; i++) ma[s[i]]++;
  for (int i = 0; i < 5; i++) for (int j = i + 1; j < 5; j++) {
    int sum = x[i] + x[j];
    if (ma[sum] == 0) return false;
    ma[sum]--;
  }
  for (int i = 1; i <= 10; i++) if (ma[s[i]] > 0) return false;
  return true;
}


int main() {
  int T;
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    printf("Case %d: ", tc + 1);
    for (int i = 0; i < 10; i++) scanf("%d", s + i + 1);
    sort(s + 1, s + 11);
    bool flag = false;
    for (int i = 3; i <= 8; i++) {
      if ((s[1] + s[2] - s[i]) % 2 == 0) {
        int x1 = (s[1] + s[2] - s[i]) / 2;
        int x2 = s[1] - x1;
        int x3 = s[2] - x1;
        int x5 = s[9] - x3;
        int x4 = s[10] - x5;
        x[0] = x1, x[1] = x2, x[2] = x3, x[3] = x4, x[4] = x5;
        if (ok()) {
          printf("%d %d %d %d %d\n", x1, x2, x3, x4, x5);
          flag = true;
          break;
        }
      }
    }
    if (!flag) assert(0);
  }
  return 0;
}