#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;
const char desmond[] = "desmond";

int n, m;
char s[N];

void ans() {
  puts("I love you, Desmond!");
}

void err() {
  puts("Goodbye, my love!");
}

bool match(int b) {
  if (b < 0 || b + 7 > n) return false;
  for (int i = 0; i < 7; i++) {
    if (desmond[i] != s[b + i]) return false;
  }
  return true;
}

int main() {
  scanf("%s", s);
  n = strlen(s);
  scanf("%d", &m);
  for (int i = 0; i + 7 <= n; i++) {
    if (match(i)) {
      ans();
      printf("%d\n", 0);
      return 0;
    }
  }
  for (int i = 0; i < m; i++) {
    int a; char c;
    scanf("%d %c", &a, &c);
    a--;
    s[a] = c;
    for (int j = a - 7; j <= a + 7; j++) {
      if (match(j)) {
        ans();
        printf("%d\n", i + 1);
        return 0;
      }
    }
  }
  err();
  return 0;
}