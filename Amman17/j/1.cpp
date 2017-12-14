#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int T;
int have[N];
string s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> T;
  getline(cin, s);
  while (T--) {
    memset(have, 0, sizeof have);
    string s; getline(cin, s);
    int n = (int) s.size();
    while (s.back() == ' ') s.pop_back();
    for (int i = 0; i < n; i++) {
      if (s[i] == ' ') {
        have[i] = true;
      }
    }
    have[n] = true;
    bool ans = false;
    for (int i = 1; i < N; i++) {
      bool ok = true;
      bool reach = false;
      int cnt = 0;
      for (int j = 1; (long long) i * j + j - 1 <= n; j++) {
        if (!have[i * j + j - 1]) {
          ok = false;
          break;
        }
        if (i * j + j - 1 == n) reach = true;
        cnt++;
      }
      ok &= reach;
      ok &= (cnt > 1);
      if (ok) {
        ans = true;
        break;
      }
    } 
    if (ans) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}