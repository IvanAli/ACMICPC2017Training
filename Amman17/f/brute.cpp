#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int T;
int n, k;
int a[N];
map<int, int> ma;
int last[N];
int nxt[N];

int have[N];
int fol[N];

bool cmp(int i, int j) {
  return fol[i] > fol[j];
}

set<int, bool(*) (int, int)> far(cmp);

int main() {
  scanf("%d", &T);
  while (T--) {
    memset(have, 0, sizeof have);
    scanf("%d %d", &n, &k);
    ma.clear();
    far.clear();
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    set<int> have;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (ans >= k) {
        if (have.count(a[i])) continue;
        map<int, int> ma;
        for (auto it : have) ma[it] = n;
        for (int j = i + 1; j < n; j++) {
          if (have.count(a[j])) ma[a[j]] = min(ma[a[j]], j);
        }
        int mx = *have.begin();
        for (auto it : have) {
          if (ma[it] > ma[mx]) mx = it;
        }
        have.erase(mx);
        have.insert(a[i]);
        ans++;
      } else {
        if (have.count(a[i])) continue;
        have.insert(a[i]);
        ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}