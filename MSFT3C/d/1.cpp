#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

char s[N];

int main() {
  while (fgets(s, N, stdin)) {
    string cur;
    int n = strlen(s);
    bool ok = false;
    vector<string> dir;
    for (int i = 0; i < n; i++) {
      if (s[i] == '\n' || s[i] == '\r') continue;
      if (s[i] == '\\') {
        if (i == 0) continue;
        if ((int) cur.size() == 1 && cur[0] == '.') {
          ok = false;
          cur = "";
          continue;
        }
        if (!cur.empty()) {
          if (ok && (int) cur.size() == 1 && cur[0] == '*') ok = false;
          if (ok) {
            dir.push_back(cur);
            fprintf(stderr, "yes: %s\n", cur.c_str());
          } else {
            fprintf(stderr, "no: %s\n", cur.c_str());
            if (cur.empty()) assert(0);
            if (cur[0] == '.') {
              cerr << "ok" << endl;
              for (int j = 0; j < (int) cur.size() - 1; j++) {
                if (dir.empty()) break;
                dir.pop_back();
              }
            } else if (cur[0] == '*') {
              dir.clear();
            } else {
              cerr << "cur was: " << cur << endl;
              assert(0);
            }
          }
        }
        ok = false;
        cur = "";
      } else {
        if (s[i] != '.') ok = true;
        cur.push_back(s[i]);
      }
    }
    if (!cur.empty()) {
      if ((int) cur.size() == 1 && cur[0] == '.') {
      } else {
        if (ok && (int) cur.size() == 1 && cur[0] == '*') ok = false;
        if (ok) {
          dir.push_back(cur);
        } else {
          if (cur[0] == '.') {
            for (int j = 0; j < (int) cur.size() - 1; j++) {
              if (dir.empty()) break;
              dir.pop_back();
            }
          } else if (cur[0] == '*') {
            dir.clear();
          } else {
            assert(0);
          }
        }
      }
    }
    if (dir.empty()) putchar('\\');
    for (int i = 0; i < (int) dir.size(); i++) {
      putchar('\\');
      printf("%s", dir[i].c_str());
    }
    puts("");
  }
  return 0;
}