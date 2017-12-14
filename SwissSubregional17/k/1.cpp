#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i + 3 <= n; i++) {
    if (s[i] == 'A' && s[i + 1] == 'C' && s[i + 2] == 'M') {
      puts("Fun!");
      return 0;
    }
  }
  puts("boring...");
  return 0;
}