#include <bits/stdc++.h>

using namespace std;

const int N = 623456;

int n;
char s[1234];
int tree[N][64];
int sz = 2;
bool leaf[N];

bool insert(string &s) {
  int n = (int) s.size();
  int id = 1;
  for (int i = 0; i < n; i++) {
    int c = s[i];
    if ('a' <= s[i] && s[i] <= 'z') c = s[i] - 'a';
    if ('A' <= s[i] && s[i] <= 'Z') c = s[i] - 'A' + 26;
    if ('0' <= s[i] && s[i] <= '9') c = s[i] - '0' + 52;
    if (tree[id][c] == 0) {
      tree[id][c] = sz++;
    }
    id = tree[id][c];
  }
  if (!leaf[id]) {
    leaf[id] = true;
    return true;
  }
  return false;
}

int main() {
  scanf("%s", s);
  n = strlen(s);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      string aux;
      aux.push_back(s[i - 1]);
      aux.push_back(s[j - 1]);
      int pr = i;
      int cur = j;
      while (true) {
        int ne = cur + pr;
        if (ne > n) break;
        aux.push_back(s[ne - 1]);
        pr = cur;
        cur = ne;
      }
      ans += insert(aux);
    }
  }
  printf("%d\n", ans);
  return 0;
}