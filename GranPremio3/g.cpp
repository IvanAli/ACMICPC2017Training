#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int T;
int a[N];
int n;
char s[N];

int main() {
  scanf("%d", &T);
  getc(stdin);
  while (T--) {
    fgets(s, N, stdin);
    int cur = 0;
    n = 0;
    for (int i = 0; s[i]; i++) {
      if ('0' <= s[i] && s[i] <= '9') {
        cur = cur * 10 + s[i] - '0';
      } else {
        a[n++] = cur;
        cur = 0;
      }
    }
    if (cur > 0) a[n++] = cur;
    int max_val = 0;
    for (int i = 0; i < n; i++) {
      max_val = max(max_val, a[i]);
    }
    vector<int> pos;
    for (int i = 0; i < n; i++) if (a[i] == max_val) pos.push_back(i);
    int ans = 0;
    for (int i = 0; i < (int) pos.size(); i += 2) {
      if (i + 1 < (int) pos.size()) ans += pos[i + 1] - pos[i] + 1;
    }
    if ((int) pos.size() % 2) ans += n - pos.back();
    printf("%d\n", ans);
  }  
  return 0;
}
