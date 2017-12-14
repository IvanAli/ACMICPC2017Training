#include <bits/stdc++.h>

using namespace std;

const int N = 123;

int n;
char s[N];

bool match(int b, string &t) {
  for (int i = 0; i < (int) t.size(); i++) {
    if (s[i + b] != t[i]) return false;
  }
  return true;
}

int solve(string &t) {
  int ret = n;
  for (int i = 0; i + (int) t.size() <= n; i++) {
    if (match(i, t)) {
      ret -= (int) t.size() - 1;
      i += (int) t.size() - 1;
    }
  }
  return ret + (int) t.size();
}

int main() {
  scanf("%s", s);
  n = strlen(s);
  int ans = n;
  for (int i = 0; i < n; i++) {
    string macro;
    for (int j = i; j < n; j++) {
      macro.push_back(s[j]);
      ans = min(ans, solve(macro));
    }
  }
  printf("%d\n", ans);
  return 0;
}