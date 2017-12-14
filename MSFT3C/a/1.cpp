#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

char s[N];

vector<string> val;
vector<char> sym;
map<string, string> ma;

int main() {
  while (fgets(s, N, stdin)) {
    val.clear();
    sym.clear();
    ma.clear();
    int n = strlen(s);
    int word = 0;
    string a, b;
    string cur;
    int ptr = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == ' ') {
        word++;
        continue;
      }
      if (word == 0) {
        if ('0' <= s[i] && s[i] <= '9') {
          cur.push_back(s[i]);
        } else {
          sym.push_back(s[i]);
          val.push_back(cur);
          cur = "";
        }
      } else if (word == 1) {
        if (!cur.empty()) {
          val.push_back(cur);
          cur = "";
        }
        if (ptr < (int) sym.size() && s[i] == sym[ptr]) {
          ma[a] = val[ptr];
          ptr++;
          a = "";
        } else {
          a.push_back(s[i]);
        }
      } else if (word == 2) {
        if (!a.empty()) {
          ma[a] = val[ptr];
          a = "";
        }
        if (ma.count(b)) {
          printf("%s", ma[b].c_str());
          putchar(s[i]);
          b = "";
        } else {
          b.push_back(s[i]);
        }
      }
    }
    if (!b.empty()) printf("%s", ma[b].c_str());
    puts("");
  }
  return 0;
}