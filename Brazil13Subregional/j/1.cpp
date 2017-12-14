#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int n, m, s;
vector<pair<int, pair<int, int>>> edges;
int from[N], size[N];
vector<int> st[N];
vector<pair<int, pair<int, int>>> join[N];

int find(int x) {
  if (x == from[x]) return x;
  return from[x] = find(from[x]);
}

int main() {
  scanf("%d %d %d", &n, &m, &s);
  for (int i = 0; i < m; i++) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c); a--, b--;
    edges.push_back(make_pair(c, make_pair(a, b)));
  }
  sort(edges.begin(), edges.end());
  reverse(edges.begin(), edges.end());
  for (int i = 0; i < n; i++) {
    from[i] = i;
    size[i] = 1;
    st[i].push_back(i);
    join[i].push_back(make_pair(i, make_pair(0, 0)));
  }
  for (int i = 0; i < (int) edges.size(); i++) {
    auto it = edges[i];
    int a = it.second.first, b = it.second.second, w = it.first;
    int x = find(a), y = find(b);
    if (x != y) {
      if (size[x] < size[y]) {
        for (auto e : st[x]) {
          join[e].push_back(make_pair(y, make_pair(w, i + 1)));
          st[y].push_back(e);
        }
        size[y] += size[x];
        size[x] = 0;
        st[x].clear();
        from[x] = y;
      } else {
        for (auto e : st[y]) {
          join[e].push_back(make_pair(x, make_pair(w, i + 1)));
          st[x].push_back(e);
        }
        size[x] += size[y];
        size[y] = 0;
        st[y].clear();
        from[y] = x;
      }
    }
  }
  while (s--) {
    int a, b; scanf("%d %d", &a, &b); a--, b--;
    int i = (int) join[a].size() - 1, j = (int) join[b].size() - 1; 
    while (true) {
      int sa = join[a][i].first, sb = join[b][j].first;
      int wa = join[a][i].second.first, wb = join[b][j].second.first;
      int ta = join[a][i].second.second, tb = join[b][j].second.second;
      assert(sa == sb);
      if (ta < tb) {
        printf("%d\n", wb);
        break;
      } else if (ta > tb) {
        printf("%d\n", wa);
        break;
      } else {
        i--, j--;
      }
    }
  }
  return 0;
}