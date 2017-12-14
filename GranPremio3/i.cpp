#include <bits/stdc++.h>

using namespace std;

const int N = 1324567;

int T;
int n, m;
int from[N];
vector<pair<int, pair<int, int> > > edges;

int find(int x) {
  if (x == from[x]) return x;
  return from[x] = find(from[x]);
}

int main() {
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) from[i] = i;
    edges.clear();
    for (int i = 0; i < m; i++) {
      int a, b, c; scanf("%d %d %d", &a, &b, &c);
      edges.push_back(make_pair(c, make_pair(a, b)));
    }
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    int ans = (int) 2e9;
    for (int i = 0; i < (int) edges.size(); i++) {
      int c = edges[i].first, a = edges[i].second.first, b = edges[i].second.second;
      int x = find(a), y = find(b);
      if (x != y) {
        from[x] = y;
        ans = min(ans, c);
      }
    }
    printf("Case #%d: %d\n", tc + 1, ans);
  }
  return 0;
}
