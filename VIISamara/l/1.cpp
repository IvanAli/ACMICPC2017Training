#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int cost[N];
int bound[N];
int p[N];
vector<int> event[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  memset(bound, -1, sizeof bound);
  for (int i = 0; i < n; i++) {
    p[i] = i;
    int k, c; scanf("%d %d", &k, &c);
    cost[i] = c;
    for (int j = 0; j < k; j++) {
      int x; scanf("%d", &x);
      x--;
      event[i].push_back(x);
    }
  }
  sort(p, p + n, [&](const int i, const int j) {
    return cost[i] < cost[j];
  });
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j : event[p[i]]) {
      if (bound[j] == -1 || bound[j] == cost[p[i]]) {
        bound[j] = cost[p[i]];
        cnt++;
      }
    }
    if (cnt == 0) {
      puts("Poor memory");
      return 0;
    }
  }
  puts("Good memory");
  for (int i = 0; i < m; i++) {
//    assert(bound[i] > -1);
    if (bound[i] == -1) bound[i] = 1;
    if (i > 0) putchar(' ');
    printf("%d", bound[i]);
  }
  return 0;
}