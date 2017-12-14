#include <bits/stdc++.h>
using namespace std;

const int mod = 100;

int T;
char s[10005];
int all[] = {76, 16, 56, 96, 36};

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    if (strcmp(s, "0") == 0) {
      printf("1\n");
    } else if (strcmp(s, "1") == 0) {
      printf("66\n");
    } else {
      int len = strlen(s);
      int d = s[len - 1] - '0';
      printf("%d\n", all[d % 5]);
    }
  } 
  return 0;
}