#include <bits/stdc++.h>

using namespace std;

pair<int, string> pr[3];
int T;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d %d", &pr[0].first, &pr[1].first, &pr[2].first);
    pr[0].second = "First";
    pr[1].second = "Second";
    pr[2].second = "Third";
    sort(pr, pr + 3);
    printf("%s\n", pr[0].second.c_str());
  }
  return 0;
}