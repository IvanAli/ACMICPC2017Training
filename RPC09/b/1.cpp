#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int n;
int a[N];

int main() {
  while (scanf("%d", &n) == 1) {
    set<int> have;
    map<int, int> all;
    vector<pair<int, int> > pr;
    for (int i = 0; i < n - 2; i++) {
      scanf("%d", a + i);
      a[i]--;
      all[a[i]]++;
    }
    for (int i = 0; i < n; i++) if (!all.count(i)) have.insert(i);
    bool ok = true;
    for (int i = 0; i < n - 2; i++) {
      if (have.empty()) {
        ok = false;
        break;
      }
      auto it = have.begin();
      pr.push_back(make_pair(min(*it, a[i]), max(*it, a[i])));
      have.erase(it);
      all[a[i]]--;
      if (all[a[i]] == 0) have.insert(a[i]);
    }
    if ((int) have.size() != 2) ok = false;
    else {
      auto x = have.begin();
      have.erase(x);
      auto y = have.begin();
      have.erase(y);
      pr.push_back(make_pair(min(*x, *y), max(*x, *y)));
    }
    if (!ok) puts("-1");
    else {
      sort(pr.begin(), pr.end());
      for (auto it : pr) {
        printf("%d %d\n", it.first + 1, it.second + 1);
      }
    }
  }
  return 0;
}