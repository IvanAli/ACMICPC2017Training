#include <bits/stdc++.h>

using namespace std;

const int N = 1345;

int n, a, b, k, f;
char ssa[N][25], ssb[N][25];

map<string, int> ma;
map<int, string> mb;
int wa[N], wb[N];
int cost[N][N];
int sz;

int main() {
  scanf("%d %d %d %d %d", &n, &a, &b, &k, &f);
  for (int i = 0; i < n; i++) {
    scanf("%s %s", ssa[i], ssb[i]);
    ma[string(ssa[i])];
    ma[string(ssb[i])];
  }
  for (auto &it : ma) {
    it.second = sz;
    mb[sz] = it.first;
    sz++;
  }
  for (int i = 0; i < n; i++) {
    wa[i] = ma[string(ssa[i])];
    wb[i] = ma[string(ssb[i])];
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      if (wa[i] == wb[i - 1]) {
        cost[min(wa[i], wb[i])][max(wa[i], wb[i])] += b;
      } else {
        cost[min(wa[i], wb[i])][max(wa[i], wb[i])] += a;
      }
    } else {
      cost[min(wa[i], wb[i])][max(wa[i], wb[i])] += a;
    }
  }
  int ans = 0;
  vector<int> ww;
  for (int i = 0; i < N; i++) for (int j = i + 1; j < N; j++) {
    if (cost[i][j] > 0) ww.push_back(cost[i][j]);
    ans += cost[i][j];
  }
  sort(ww.begin(), ww.end());
  reverse(ww.begin(), ww.end());
  for (int i = 0; i < min((int) ww.size(), k); i++) {
    if (ww[i] > f) {
      ans = ans - ww[i] + f;
    }
  }  
  printf("%d\n", ans);
  return 0;
}