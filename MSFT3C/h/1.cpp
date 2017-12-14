#include <bits/stdc++.h>
#define y1 yy1

using namespace std;

const int N = 1234567;

int T;
int y1[N], y2[N];
vector<long double> at[N];
vector<int> what[N];
vector<pair<int, long double> > graph[N];
map<int, pair<int, int> > rev;
long double dist[N];

long double euclid(pair<int, int> a, pair<int, int> b) {
  long double x1 = a.first, y1 = at[a.first][a.second];
  long double x2 = b.first, y2 = at[b.first][b.second];
  long double ret = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  return sqrt(ret);
}

int main() {
  scanf("%d", &T);
  while (T--) {
    int n, x, y; scanf("%d %d", &n, &y);
    rev.clear();
    y1[0] = y;
    y2[0] = y;
    for (int i = 0; i <= N; i++) {
      graph[i].clear();
      at[i].clear();
      what[i].clear();
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d %d", y1 + i, y2 + i);
    }
    int sz = 0;
    at[0].push_back(y);
    for (int i = 1; i <= n; i++) {
      for (int j = y1[i]; j < y2[i]; j++) {
        int K = 1035;
        long double inc = 1. / K;
        long double cur = 0;
        for (int k = 0; k < K; k++) {
          at[i].push_back((double) j + cur);
          cur += inc;
        }
      }
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < (int) at[i].size(); j++) {
        what[i].push_back(sz);
        rev[sz] = make_pair(i, j);
        sz++;
      }
    }
    for (int i = 0; i < n; i++) {
      int j = i + 1;
      for (auto ii : what[i]) {
        for (auto jj : what[j]) {
          graph[ii].push_back(make_pair(jj, euclid(rev[ii], rev[jj])));
        }
      }
    }
    for (int i = 0; i < N; i++) dist[i] = 1e18;
    priority_queue<pair<long double, int>, vector<pair<long double, int> > , greater<pair<long double, int> > > pq;
    pq.push(make_pair(0, 0));
    dist[0] = 0;
    while (!pq.empty()) {
      auto ft = pq.top(); pq.pop();
      int v = ft.second;
      long double d = ft.first;
      if (d > dist[v]) continue;
      for (int i = 0; i < (int) graph[v].size(); i++) {
        auto to = graph[v][i];
        if (dist[v] + to.second < dist[to.first]) {
          dist[to.first] = dist[v] + to.second;
          pq.push(make_pair(dist[to.first], to.first));
        }
      }
    }
    long double ans = 1e20;
    for (auto it : what[n]) {
      ans = min(ans, dist[it]);
    }
    cout << setprecision(4) << fixed << ans << endl;
  }
  return 0;
}