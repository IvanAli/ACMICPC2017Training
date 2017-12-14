#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int n, m, k;
int used[N];
vector<int> graph[N];

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    int a, b; scanf("%d %d", &a, &b); a--, b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  queue<pair<int, int> > q;
//  q.push(make_pair(0, 1));
//  used[0] = 1;
  for (int i = 0; i < n; i++) {
    if (used[i] == 0) {
      q.push(make_pair(i, 1));
      used[i] = 1;
    }
    while (!q.empty()) {
      auto ft = q.front(); q.pop();
      int v = ft.first, c = ft.second;
      for (int to : graph[v]) {
        if (used[to]) {
          if (used[v] == used[to]) {
            puts("-1");
            return 0;
          }
          continue;
        }
        used[to] = c + 1;
        if (used[to] > k) used[to] = 1;
        q.push(make_pair(to, used[to]));
      }
    }
  }
  for (int i = 0; i < n; i++) printf("%d\n", used[i]);
  return 0;
}