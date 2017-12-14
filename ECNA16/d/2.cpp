#include <bits/stdc++.h>

using namespace std;

const int N = 123;

int n, m;
pair<int, long long> cost[N][N];
char s[N], a[N], b[N];
map<string, int> ma;
int parent[N];

int main() {
  scanf("%d %d", &n, &m);
  int sz = 0;
  int eng = -1;
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    ma[string(s)] = sz;
    if (strcmp("English", s) == 0) eng = sz;
    sz++;
  }
  if (eng == -1) {
    ma["English"] = sz;
    eng = sz++;
  }
  for (int i = 0; i < sz; i++) for (int j = 0; j < sz; j++) cost[i][j] = make_pair((int) 1e9, (int) 1e9);
  for (int i = 0; i < sz; i++) cost[i][i] = make_pair(0, 0);
  for (int i = 0; i < m; i++) {
    int c; scanf("%s %s %d", a, b, &c);
    int wa = ma[string(a)];
    int wb = ma[string(b)];
    cost[wa][wb].first = 1;
    cost[wb][wa].first = 1;
    if (c < cost[wa][wb].second) {
      cost[wa][wb].second = c;
      cost[wb][wa].second = cost[wa][wb].second;
    }
  }
  memset(parent, -1, sizeof parent);
  for (int k = 0; k < sz; k++) for (int i = 0; i < sz; i++) for (int j = 0; j < sz; j++) {
//    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
    if (cost[i][k].first + cost[k][j].first < cost[i][j].first) {
      cost[i][j].first = cost[i][k].first + cost[k][j].first;
      cost[i][j].second = cost[i][k].second + cost[k][j].second;
      parent[j] = k;
    } else if (cost[i][k].first + cost[k][j].first == cost[i][j].first && cost[i][k].second + cost[k][j].second < cost[i][j].second) {
      cost[i][j].second = cost[i][k].second + cost[k][j].second;
      parent[j] = k;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += cost[eng][i].second;
  }
  if (ans >= (int) 1e9) puts("Impossible");
  else printf("%lld\n", ans);
  return 0;
}