#include <bits/stdc++.h>

using namespace std;

const int HR = 1;
const int H = 2;
const int S = 3;
const int O = 4;

string s;
int cnt[10];
map<string, int> ma;

int main() {
  ma["(FBF)"] = HR;
  ma["(CS)"] = H;
  ma["(FBS)"] = S;
  ma["(CF)"] = S;
  string cur;
  while (getline(cin, s)) {
    vector<int> plays;
    memset(cnt, 0, sizeof cnt);
    int n = (int) s.size();
    for (int i = 1; i < n - 1; i++) {
      if (s[i] == '(' || s[i] == ')' || ('A' <= s[i] && s[i] <= 'Z')) cur.push_back(s[i]);
      if (s[i] == ')') {
        cerr << "play: " << cur << endl;
        plays.push_back(ma[cur]);
        cur = "";
      }
    }
    for (int it : plays) assert(it > 0);
    for (int it : plays) {
      if (it == HR) {
        cnt[HR] += cnt[H] + 1;
        cnt[H] = 0;
      } else if (it == S) {
        cnt[S]++;
        if (cnt[S] == 3) {
          cnt[O]++;
          cnt[S] = 0;
        }
      } else if (it == H) {
        cnt[H]++;
        if (cnt[H] == 3) {
          cnt[HR]++;
          cnt[H] = 0;
        }
      }
    }
    printf("%d\n", cnt[HR]);
  }
  return 0;
}