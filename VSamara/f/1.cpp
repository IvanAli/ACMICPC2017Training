#include <bits/stdc++.h>

using namespace std;

const int N = 66666;

int n;
vector<int> g[N];
int from[N];
int used[N];
char s[122];
char ss[N][122];

void build() {
  int v = n - 1;
  vector<int> ans;
  while (from[v] > -1) {
    ans.push_back(v);
    v = from[v];
  }
  ans.push_back(0);
  reverse(ans.begin(), ans.end());
  printf("%d\n", (int) ans.size());
  for (int i = 0; i < (int) ans.size(); i++) {
//    printf("%d", ans[i] + 1);
    printf("%s\n", ss[ans[i]]);
  }
  puts("");
}

long long hsh(int b, int e) {
  long long ret = 0;
  for (int i = b; i < e; i++) {
    ret = ret * 27 + (s[i] - 'a' + 1);
  }
  return ret;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w+", stdout);
  scanf("%d", &n);
  map< pair<long long, long long>, vector<int> > ma;
  for (int i = 0; i < n; i++) {
    scanf("%s", ss[i]);
    for (int j = 0; ss[i][j]; j++) s[j] = ss[i][j];
    int len = strlen(s);
    for (int j = 0; j < len; j++) {
      long long f = hsh(0, j);
      long long s = hsh(j + 1, len);
      pair<long long, long long> pr(f, s);
      ma[pr].push_back(i);
    }
  }
  for (auto it : ma) {
    vector<int> &ve = it.second;
    for (int i = 0; i < (int) ve.size(); i++) {
      for (int j = i + 1; j < (int) ve.size(); j++) {
        if (i != j) {
          g[ve[i]].push_back(ve[j]);
          g[ve[j]].push_back(ve[i]);
        }
      }
    }
    /*
    for (int i = 0; i + 1 < (int) ve.size(); i++) {
      int j = i + 1;
      g[ve[i]].push_back(ve[j]);
      g[ve[j]].push_back(ve[i]);
    }
    */
  }
  queue<int> q;
  q.push(0);
  memset(from, -1, sizeof from);
  used[0] = 1;
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (int to : g[v]) {
      if (!used[to]) {
        from[to] = v;
        used[to] = true;
        if (to == n - 1) {
          build();
          return 0;
        }
        q.push(to);
      }
    }
  }
  puts("FAIL");
  return 0;
}