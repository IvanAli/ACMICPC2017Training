#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

map<string, int> ma;
map<int, string> mb;
char s[N];
map<pair<int, int>, int> now, best, now_time, best_time;
int best_in_time[N];
int now_in_time[N];

int main() {
  int n;
  scanf("%d", &n);
  queue<int> q;
  int sz = 0;
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    ma[string(s)] = sz;
    if (i >= 4) q.push(sz);
    mb[sz] = string(s);
    sz++;
  }
  int wo = 0, bo = 1, wd = 2, bd = 3;
  for (int i = 0; i < 4; i++) now_in_time[i] = i - 4;
  now_time[make_pair(wo, wd)] = -2;
  now_time[make_pair(bo, bd)] = -1;
  scanf("%s", s);
  for (int i = 0; s[i]; i++) {
    if (s[i] == 'W') {
      pair<int, int> pr;
      if (now_in_time[wo] < now_in_time[wd]) pr = make_pair(wo, wd);
      else pr = make_pair(wd, wo);
      int opt = best[pr];
      int cur = now[pr];
      now[pr] = cur + 1;
      if (cur == 0 && i > 0) now_time[pr] = i;
      // best[make_pair(mn, mx)] = max(opt, cur + 1);
      if (cur + 1 > opt) {
        best[pr] = cur + 1;
        best_time[pr] = now_time[pr];
        best_in_time[wo] = now_in_time[wo];
        best_in_time[wd] = best_in_time[wd];
      }
      swap(wo, wd);
      pair<int, int> opr;
      if (now_in_time[bo] < now_in_time[bd]) opr = make_pair(bo, bd);
      else opr = make_pair(bd, bo);
      now[opr] = 0;
      q.push(bd);
      bd = bo;
      bo = q.front();
      q.pop();
      now_in_time[bd] = now_in_time[bo];
      now_in_time[bo] = i;
    } else if (s[i] == 'B') {
      pair<int, int> pr;
      if (now_in_time[bo] < now_in_time[bd]) pr = make_pair(bo, bd);
      else pr = make_pair(bd, bo);
      int opt = best[pr];
      int cur = now[pr];
      now[pr] = cur + 1;
      if (cur == 0 && i > 0) now_time[pr] = i;
//      best[make_pair(mn, mx)] = max(opt, cur + 1);
      if (cur + 1 > opt) {
        best[pr] = cur + 1;
        best_time[pr] = now_time[pr];
        best_in_time[bo] = now_in_time[bo];
        best_in_time[bd] = best_in_time[bd];
      }
      swap(bo, bd);
      pair<int, int> opr;
      if (now_in_time[wo] < now_in_time[wd]) opr = make_pair(wo, wd);
      else opr = make_pair(wd, wo);
      now[opr] = 0;
      q.push(wd);
      wd = wo;
      wo = q.front();
      q.pop();
      now_in_time[wd] = now_in_time[wo];
      now_in_time[wo] = i;
    }
  }
  vector< pair<int, pair<int, int> > > ans;
  int mx = 0;
  for (auto it : best) mx = max(mx, it.second);
  for (auto it : best) {
    if (it.second == mx) {
      ans.push_back(make_pair(best_time[it.first], it.first));
    }
  }
  sort(ans.begin(), ans.end());
  for (auto it : ans) {
//    if (best_in_time[it.second.first] < best_in_time[it.second.second]) {
      printf("%s %s\n", mb[it.second.first].c_str(), mb[it.second.second].c_str());
  }
  return 0;
}