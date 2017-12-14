#include <bits/stdc++.h>

using namespace std;

void build() {
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w+", stdout);
  int n;
  scanf("%d", &n);
  vector<int> stv;
  set<int> fin;
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    int len = strlen(s);
    for (int j = 0; j < n; j++) {
      long long f = hsh(0, j);
      long long s = hsh(j + 1, n);
      pair<long long, long long> pr(f, s);
      g[pr].insert(i);
      if (i == 0) stv.push_back(pr);
      if (i == n - 1) fin.insert(pr);
    }
  }
  for (auto it : stv) {
    queue< pair<int, int> > q;
    set< pair<int, int> > used;
    q.push(it);
    memset(from, -1, sizeof from);
    used.insert(it);
    while (!q.empty()) {
      pair<int, int> ft = q.front(); q.pop();
      for (auto e : g[ft]) {
        if (used.count(e)) continue;
        f
        if (fin.count(e)) {
          build();
          return 0;
        }
        used.insert(e);
        q.push(e);
      }
    }
  }
  puts("FAIL");
  return 0;
}