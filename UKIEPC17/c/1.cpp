#include <bits/stdc++.h>

using namespace std;

const int N = 25;

map<string, int> ma;
char ss[N][26];

int main() {
  int n;
  scanf("%d", &n);
  ma["red"] = 1;
  ma["yellow"] = 2;
  ma["green"] = 3;
  ma["brown"] = 4;
  ma["blue"] = 5;
  ma["pink"] = 6;
  ma["black"] = 7;
  int mx = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%s", ss[i]);
    mx = max(mx, ma[string(ss[i])]);
  }
  if (mx == 1) {
    puts("1");
    return 0;
  }
  int onecnt = 0;
  for (int i = 0; i < n; i++) {
    int val = ma[string(ss[i])];
    if (val == 1) {
      onecnt++;
    }
    if (val != mx) sum += val;
  }
  printf("%d\n", mx * (onecnt + 1) + sum);
  return 0;
}