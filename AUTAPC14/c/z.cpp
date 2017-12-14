#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

vector<int> g[N];
int d[N][N];

bool check(int n, int s) {
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) d[i][j] = (int) 1e9;
  for (int i = 0; i < n; i++) d[i][i] = 0;
  for (int i = 0; i < n; i++) {
    for (int to : g[i]) {
      d[i][to] = 1;
    }
  }
  for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  }
  int sum = 0;
  for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) sum += d[i][j];
  fprintf(stderr, "sum: %d\n", sum);
  return sum == s;
}

bool ok(int mid, int s) {
  return (long long) mid * (mid - 1) <= 2 * s;
}

int main() {
  for (int s = 1; s <= 100000; s++) {
    fprintf(stderr, "s: %d\n", s);
    for (int i = 0; i < N; i++) g[i].clear();
    int low = 1, high = 12345, mid;
    if (s == 2 || s == 5 || s == 9) {
      puts("Impossible");
      continue;
    }
    int n;
    if (s == 9) {
      n = 4;
      g[0].push_back(1);
      g[1].push_back(0);
      g[1].push_back(2);
      g[2].push_back(1);
      g[2].push_back(3);
      g[3].push_back(2);
      if (!check(n, s)) {
        fprintf(stderr, "bad s: %d\n", s);
        assert(0);
      }
      continue;
    } else {
      while (low < high) {
        mid = low + high + 1 >> 1;
        if (ok(mid, s)) low = mid;
        else high = mid - 1;
      }
      n = low;
      int val = n * (n - 1) / 2;
      int t = n;
      if (val + t < s) {
        fprintf(stderr, "fail at %d\n", s);
        assert(0);
        puts("Impossible");
        continue;
      }
      set<pair<int, int> > bad;
      for (int v = 0; v < s - val; v++) {
        int u = v + 2;
        if (u >= n) u -= n;
        bad.insert(make_pair(min(v, u), max(v, u)));
      }
      vector<pair<int, int> > edges;
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          if (!bad.count(make_pair(i, j))) {
            g[i].push_back(j);
            g[j].push_back(i);
            edges.push_back(make_pair(i + 1, j + 1));
          }
        }
      }
      if (!check(n, s)) {
        fprintf(stderr, "bad s: %d\n", s);
        assert(0);
      }
      int m = (int) edges.size();
      printf("%d %d\n", n, m);
      for (auto it : edges) printf("%d %d\n", it.first, it.second);
    }
  }
  return 0;
}