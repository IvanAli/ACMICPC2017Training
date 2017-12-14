#include <bits/stdc++.h>

using namespace std;

int T;
string s;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> T;
  getline(cin, s);
  while (T--) {
//    getline(cin, s);
    getline(cin, s);
    for (int i = 0; i < (int) s.size(); i++) {
      cout << s[i];
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
        cout << 'p' << s[i];
      }
    }
    cout << '\n';
  }
  return 0;
}