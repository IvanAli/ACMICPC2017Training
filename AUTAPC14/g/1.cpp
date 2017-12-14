#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int l1 = -1, l2 = -1;
  int d1 = 0, d2 = 0;
  int ans1 = 0, ans2 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      d1 += i - l1 - 1;
      ans1 += d1;
      l1 = i;
    } else if (s[i] == '2') {
      d2 += i - l2 - 1;
      ans2 += d2;
      l2 = i;
    }
  }
  printf("%d\n", min(ans1, ans2));
  return 0;
}