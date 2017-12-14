#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

map<string, int> ma;
map<int, string> mb;
char s[N];
bool first[N];

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
  for (int i = 0; i < 4; i++) first[i] = true;
  scanf("%s", s);
  int wo = 0, bo = 1, wd = 2, bd = 3;
  int mx = 0;
  for (int i = 0, cur = 0, last = -1; s[i]; i++) {
    if (last != s[i]) {
      cur = 1;
      if (cur > mx) {
        mx = cur;
      }
    } else {
      cur++;
      if (cur > mx) {
        mx = cur;
      }
    }
    last = s[i];
  }
  vector<int> ve;
  for (int i = 0, cur = 0, last = -1; s[i]; i++) {
    if (last != s[i]) {
      cur = 1;
      if (cur == mx) {
        ve.push_back(i - mx + 1);
      }
    } else {
      cur++;
      if (cur == mx) {
        ve.push_back(i - mx + 1);
      }
    }
    last = s[i];
  }
  for (int i = 0, j = 0; s[i]; i++) {
    if (s[i] == 'W') {
      if (j < (int) ve.size() && ve[j] == i) {
        if (i == 0) {
          printf("%s %s\n", mb[wo].c_str(), mb[wd].c_str());
        } else {
          printf("%s %s\n", mb[wd].c_str(), mb[wo].c_str());
        }
        j++;
      }
      swap(wo, wd);
      first[bd] = false;
      q.push(bd);
      bd = bo;
      bo = q.front();
      q.pop();
    } else if (s[i] == 'B') {
      if (j < (int) ve.size() && ve[j] == i) {
        if (i == 0) {
          printf("%s %s\n", mb[bo].c_str(), mb[bd].c_str());
        } else {
          printf("%s %s\n", mb[bd].c_str(), mb[bo].c_str());
        }
        j++;
      }
      swap(bo, bd);
      first[wd] = false;
      q.push(wd);
      wd = wo;
      wo = q.front();
      q.pop();
    } else assert(0);
  }
  return 0;
}