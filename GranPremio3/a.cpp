#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

int T;
int n, k;
long long pre[N], suf[N];
int mem[N];
char ss[N][N];
char s[N];
long long what[256];
vector<int> graph[N];
int len[N];

int solve(int v = 0) {
  if (mem[v] != -1) return mem[v];
  int ret = 0;
  for (int to : graph[v]) {
    ret = max(ret, solve(to) + 1);
  }
  return mem[v] = ret;
}


int main() {
  scanf("%d", &T);
/*  ma['A'] = 0;
  ma['T'] = 1;
  ma['C'] = 2;
  ma['G'] = 3;
*/
  what['A'] = 1;
  what['T'] = 1002;
  what['C'] = 1002 * 1002;
  what['G'] = (long long) 1002 * 1002 * 1002;
  while (T--) {
    memset(mem, -1, sizeof mem);
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    for (int i = 0; i <= n; i++) {
      graph[i].clear();
      pre[i] = 0;
      suf[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      scanf("%s", ss[i]);
      len[i] = strlen(ss[i]);
    }
    for (int i = 0; i < n; i++) {
      long long cur = 0;
      for (int j = 0; j < len[i]; j++) {
        cur += what[ss[i][j]];
        if (j + 1 == k) {
          pre[i] = cur;
          break;
        }
      }
      cur = 0;
      for (int j = len[i] - 1, t = 0; j >= 0; j--, t++) {
        cur += what[ss[i][j]];
        if (t + 1 == k) {
          suf[i] = cur;
          break;
        }
      }
    }
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
      if (suf[i] == pre[j]) {
        graph[i + 1].push_back(j + 1);
      }
    }
    long long m = 0;
    int ll = strlen(s);
    for (int i = ll - 1, j = 0; i >= 0; i--, j++) {
      m += what[s[i]];
      if (j + 1 == k) {
        break;
      } 
    }
    for (int i = 0; i < n; i++) if (m == pre[i]) graph[0].push_back(i + 1);
    int ans = solve();
    printf("%d\n", ans);
  }
  return 0;
}
