#include <bits/stdc++.h>

using namespace std;


int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a1, b1, c1, a2, b2, c2; 
    scanf("%d %d %d %d %d %d", &a1, &b1, &c1, &a2, &b2, &c2);
    if (a1 == a2) {
      if (b1 == b2) {
        if (c1 == c2) {
          puts("Tie");
        } else if (c1 < c2) {
          puts("Player1");
        } else {
          puts("Player2");
        }
      } else if (b1 < b2) {
        puts("Player1");
      } else {
        puts("Player2");
      }
    } else if (a1 < a2) {
      puts("Player1");
    } else {
      puts("Player2");
    }
  }
  return 0;
}