#include <bits/stdc++.h>

using namespace std;

const int N = 666;

int d[N];
vector<int> g[N];
map<string, int> ma;
map<int, string> mb;
char s[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n; scanf("%d", &n);
    int sz = 0;
    ma.clear();
    mb.clear();
    for (int i = 0; i < N; i++) g[i].clear();
    for (int i = 0; i < n; i++) {
      vector<int> ve;
      for (int j = 0; j < 3; j++) {
        scanf("%s", s);
        string str = string(s);
        if (!ma.count(s)) {
          ma[s] = sz;
          mb[sz] = s;
          sz++;
        }
        ve.push_back(ma[s]);
      }
      for (int i = 0; i < 3; i++) for (int j = i + 1; j < 3; j++) {
        g[ve[i]].push_back(ve[j]);
        g[ve[j]].push_back(ve[i]);
      }
    }
    queue<int> q;
    memset(d, -1, sizeof d);
    int s = ma["Ahmad"];
    q.emplace(s);
    d[s] = 0;
    while (!q.empty()) {
      int v = q.front(); q.pop();
      for (int to : g[v]) {
        if (d[to] == -1) {
          d[to] = d[v] + 1;
          q.emplace(to);
        }
      }
    }
    vector< pair<int, string> > ans;
    for (int i = 0; i < sz; i++) {
      if (d[i] == -1) {
        ans.emplace_back((int) 1e9, mb[i]);
      } else {
        ans.emplace_back(d[i], mb[i]);
      }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", sz);
    for (auto it : ans) {
      if (it.first == (int) 1e9) {
        printf("%s undefined\n", it.second.c_str());
      } else {
        printf("%s %d\n", it.second.c_str(), it.first);
      }
    }
  }
  return 0;
}
