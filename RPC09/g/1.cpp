#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int n;
vector<int> graph[N];
int in[N];
int level[N], dep[N];
char ssa[N][60], ssb[N][60];

int main() {
  while (scanf("%d", &n) == 1) {
    map<string, int> ma;
    map<int, string> mb;
    memset(in, 0, sizeof in);
    for (int i = 0; i < n + n; i++) graph[i].clear();
    for (int i = 0; i < n; i++) {
      scanf("%s %s", ssa[i], ssb[i]);
      ma[string(ssa[i])];
      ma[string(ssb[i])];
    }
    int sz = 0;
    for (auto &it : ma) {
      it.second = sz;
      mb[sz] = it.first;
      sz++;
    }
    for (int i = 0; i < n; i++) {
      int a = ma[string(ssa[i])];
      int b = ma[string(ssb[i])];
      graph[a].push_back(b);
      in[b]++;
    }
    queue<pair<int, int> > q;
    for (int i = 0; i < sz; i++) {
      dep[i] = in[i];
      if (in[i] == 0) q.push(make_pair(i, 1));
    }
    while (!q.empty()) {
      pair<int, int> ft = q.front(); q.pop();
      int v = ft.first, l = ft.second;
      level[v] = l;
      for (int to : graph[v]) {
        in[to]--;
        if (in[to] == 0) {
          q.push(make_pair(to, l + 1));
        }
      }
    }
    vector<pair<pair<int, int>, string> > ans;
    for (int i = 0; i < sz; i++) {
      ans.push_back(make_pair(make_pair(level[i], dep[i]), mb[i]));
    }
    sort(ans.begin(), ans.end());
    for (auto it : ans) {
      printf("%d.%d %s\n", it.first.first, it.first.second, it.second.c_str());
    }
  }
  return 0;
}        