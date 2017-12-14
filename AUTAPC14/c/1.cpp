#include <bits/stdc++.h>

using namespace std;

int s;

bool ok(int mid) {
  return (long long) mid * (mid - 1) <= 2 * s;
}

int main() {
  scanf("%d", &s);
  int low = 1, high = 12345, mid;
  if (s == 2 || s == 5) {
    puts("Impossible");
    return 0;
  }
  if (s == 9) {
    puts("4 3");
    puts("1 3");
    puts("2 3");
    puts("3 4");
    return 0;
  }
  while (low < high) {
    mid = low + high + 1 >> 1;
    if (ok(mid)) low = mid;
    else high = mid - 1;
  }
  int n = low;
  int val = n * (n - 1) / 2;
  int t = n;
  if (val + t < s) {
    assert(0);
    puts("Impossible");
    return 0;
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
        edges.push_back(make_pair(i + 1, j + 1));
      }
    }
  }
  int m = (int) edges.size();
  printf("%d %d\n", n, m);
  for (auto it : edges) printf("%d %d\n", it.first, it.second);
  return 0;
}