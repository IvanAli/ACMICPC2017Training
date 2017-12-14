#include <bits/stdc++.h>

using namespace std;

void go(int v) {
  used[v] = 1;
  int slow = v;
  int fast = v;
  bool start = false;
  while (!start || slow != fast) {
    start = true;
    used[slow] = 1;
    used[fast] = 1;
    slow = graph[slow].first;
    fast = graph[graph[fast].first].first;
  }
  assert(slow == fast);  
  v = slow;
  start = false;
  long double sum = 0;
  while (!start || v != slow) {
    start = true;
    cycle[v] = true;
    which[v] = cyc;
    about[v] = make_pair(make_pair(0, 0), cyc);
    sum += graph[v].second;
    v = graph[v].first;
  }
  start = false;
  total[cyc] = sum;
  sum = 0;
  int len = 0;
  while (!start || cycle[v]) {
    if (start) about[v] = make_pair(make_pair(len, sum), cyc);
    start = true;
    sum += tgraph[v].second;
    v = tgraph[v].first;
    len++;
  }  
}

int main() {
  while (scanf("%d", &n)) {
    memset(used, 0, sizeof used);
    for (int i = 0; i < n; i++) {
      int foo, bar; scanf("%d %d", &foo, &bar);
      foo--;
      graph[i] = make_pair(foo, bar);
      tgraph[foo] = make_pair(i, bar);
    }
    cyc = 1;
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        go(i);
        cyc++;
      }
    }
    scanf("%d", &fr);
    scanf("%d", &q);
    while (q--) {
      for (int i = 0; i < fr; i++) {
        int a, b; scanf("%d %d", &a, &b);

    }
  }
  return 0;
}
